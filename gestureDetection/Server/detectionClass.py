import cv2
import numpy as np
import time
import argparse
import tensorflow as tf
from scipy import misc


class Detection:

	def __init__(self, model_path):
		self.model_path = model_path
		self.loadModel()

	def getBlackWhite(self,img):
		hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

		# Generating mask to detect red color
		lower_green = np.array([55, 65, 22])
		upper_green = np.array([98, 255, 255])
		
		mask1 = cv2.inRange(hsv, lower_green, upper_green)
		mask1 = cv2.morphologyEx(mask1, cv2.MORPH_OPEN,
									np.ones((3, 3), np.uint8), iterations=2)
		mask1 = cv2.dilate(mask1, np.ones((3, 3), np.uint8), iterations=1)

		return mask1

	def loadModel(self):
		self.model = tf.contrib.saved_model.load_keras_model(self.model_path)

	def predict(self,img):
		#img_black_white = self.getBlackWhite(img)
		img_expanded = np.expand_dims(img, axis=0)
		prediction = self.model.predict(img_expanded)
		
		return prediction
