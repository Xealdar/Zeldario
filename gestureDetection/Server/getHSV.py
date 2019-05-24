import cv2
import numpy as np

img = None


def onMouse(event, x, y, flags, param):
    img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    HSV = img_hsv[y, x]
    print(HSV)


cap = cv2.VideoCapture(0)


while True:

    ret, img = cap.read()
    cv2.imshow("image", img)
    cv2.setMouseCallback('image', onMouse)

    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    # Generating mask to detect red color
    lower_red = np.array([55, 65, 22])
    upper_red = np.array([95, 255, 255])
    
    mask1 = cv2.inRange(hsv, lower_red, upper_red)
    mask1 = cv2.morphologyEx(mask1, cv2.MORPH_OPEN,
		 						np.ones((3, 3), np.uint8), iterations=2)
    mask1 = cv2.dilate(mask1, np.ones((3, 3), np.uint8), iterations=1)
    #mask1 = cv2.Canny(mask1,150,200)
    
    contour, hier = cv2.findContours(mask1,cv2.RETR_CCOMP,cv2.CHAIN_APPROX_SIMPLE)
    # print(len(contour))
    mask2 = mask1.copy()

    for cnt in contour:
        cv2.drawContours(mask2,[cnt],0,255,-1)

    #mask2 = cv2.morphologyEx(mask1, cv2.MORPH_CLOSE, np.ones((5,5)))

    #maks2 = cv2.floodFill(mask2,)

    # mask1 = cv2.bitwise_not(mask1)
    #mask2 = cv2.bitwise_not(mask2)

    #im2, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    cv2.imshow("mask1", mask1)
    cv2.imshow("mask2", mask2)

    if cv2.waitKey(25) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        break
