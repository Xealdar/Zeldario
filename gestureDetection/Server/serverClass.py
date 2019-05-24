from socket import socket
from socket import AF_INET
from socket import SOCK_STREAM
import time
import cv2
import numpy as np
from detectionClass import Detection
from PIL import Image
from time import sleep

class CustomServer:

	def __init__(self, addr = None, port = None): 
		# Set attribute following provided arguments.
		# If none, we use default value 
		self.addr = addr if addr != None else 'localhost' 
		self.port = port if addr != None else 10000

		# Create socket as TCP socket.
		self.sock = socket(AF_INET, SOCK_STREAM)
		# Bind the socket to the address and port we just configured.
		self.sock.bind((self.addr, self.port))

		print('Initiliaze server on the following address {}:{}.'.format(self.addr, self.port))

	def __del__(self):
		# We properly close the socket to avoid conflict when restarting the server
		self.sock.close()

	def listen(self, nbConnection = None):
		# Get number of maximum simultaneous connection to the server.
		# If none, set the value to 1 
		self.nbConnection = nbConnection if nbConnection != None else 1
		self.sock.listen(self.nbConnection) 	

	def launch(self):

		labels = ['default', 'goDown', 'goLeft', 'goRight', 'goUp']
		clientSocket = None

		predictor = Detection("../green_glove_yes")

		cap = cv2.VideoCapture(0)

		while True:
			# Wait for a client to send a message to the server
			
			if(clientSocket is None):
				clientSocket = self.waitForClientToConnect()

			try:
				ret, image_np = cap.read()

				image_base = image_np.copy()

				image_np = predictor.getBlackWhite(image_np)
				image_base_bw = image_np.copy()

				cv2.imwrite("img_temp.jpg", image_np)
				pil_img = Image.open("img_temp.jpg")
				pil_img = pil_img.resize((160,160), 0)
				pil_img = pil_img.convert('RGB')

				image_np = np.asarray(pil_img)

				image_np = cv2.normalize(image_np, None, alpha=0, beta=1, norm_type=cv2.NORM_MINMAX, dtype=cv2.CV_32F)


				predictions = predictor.predict(image_np)					

				labelResult = labels[np.argmax(predictions)]

				if predictions[0][np.argmax(predictions)] < 0.7:
					labelResult = 'default'

				cv2.imshow("frame", image_base)
				cv2.imshow("detection", image_base_bw)
				cv2.imshow("detection2", image_base_bw)

				print(labelResult)

				self.sendDataToClient(clientSocket, bytearray(labelResult,'utf-8'))

				if cv2.waitKey(25) & 0xFF == ord('q'):
					cv2.destroyAllWindows()
					self.sendDataToClient(clientSocket, bytearray("disconnect",'utf-8'))
					#self.sock.close()
					#break

				
				# data = self.getDataFromClient(clientSocket)
				# data = self.doSomethingWithData(data)
				# self.sendDataToClient(clientSocket, data)

			except KeyboardInterrupt:
				print('KeyboardInterrupt ... Stopping process.')
				cv2.destroyAllWindows()
				self.sock.close()
				break

	def waitForClientToConnect(self):
		# We have to return clientSocket to send him back data
		clientSocket, clientAddress = self.sock.accept()
		print('Connection received from {}'.format(clientAddress))
		return clientSocket
		

	def getDataFromClient(self, clientSocket):
		# 1024 is the size of the chunk read by the recv() method. 
		# Other value can fit too. 
		data = clientSocket.recv(1024)
		return data

	def sendDataToClient(self, clientSocket, data):
		# We send back data to client and then closed the associated socket
		clientSocket.sendall(data)
		#clientSocket.close()

	def doSomethingWithData(self, data):
		# Do some stuff with the data received from client
		return data.upper()
	
