import time, serial, io

userID = input("Please enter the userID for testing: ")
numErrors = 0
start = 0
midTime = 0
currentTime = 0
difTime = 0
sensorValue = 0
previousSensor = 0

ser = serial.Serial()
ser.baudrate = 9600
ser.port = '/dev/tty.usbserial-A10133KB'
ser.open()
timeout = None
data = int(ser.readline())

if start == 0:
    if data < 800:
        start = time.time()
else:
    if data < 800:
        midTime = time.time()
        previousSensor = data
    else:
        currentTime = time.time()
        difTime = currentTime - midTime
        'difTime = currentTime.time() - midTime.time()'
        if previousSensor < 800:
            numErrors += 1
            previousSensor = data
        else:
            previousSensor = data
            if difTime > 1000:
                ser.close()


 

print("Results for user: ", userID)
print("Time to complete: ", midTime - start)
print("Number of errors: ", numErrors)

            
