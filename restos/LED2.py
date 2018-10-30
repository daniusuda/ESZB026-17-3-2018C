import sys
from time import sleep
LED_AM = "/sys/class/gpio/gpio16/"
LED_VM = "/sys/class/gpio/gpio20/"
LED_VD = "/sys/class/gpio/gpio21/"
SYSFS_DIR = "/sys/class/gpio/"
AM = "16"
VM = "20"
VD = "21"
def 	write$LED_AM ( filename, value, path=LED_AM):
	fo=open(path + filename, "w")
	fo.write(value)
	fo.close()
	return
def 	write$LED_VM ( filename, value, path=LED_VM):
	fo=open(path + filename, "w")
	fo.write(value)
	fo.close()
	return
def 	write$LED_VD ( filename, value, path=LED_VD):
	fo=open(path + filename, "w")
	fo.write(value)
	fo.close()
	return
writeLED_AM (filename="export", value=AM, path=SYSFS_DIR)
writeLED_AM (filename="direction", value="out")
writeLED_VM (filename="export", value=VM, path=SYSFS_DIR)
writeLED_VM (filename="direction", value="out")
writeLED_VD (filename="export", value=VD, path=SYSFS_DIR)
writeLED_VD (filename="direction", value="out")
for i in range(1,5)
	writeLED_VM (filename="value", value="1")
		sleep(2)
	writeLED_VM (filename="value", value="0")
	writeLED_VD (filename="value", value="1")
		sleep(1)
	writeLED_VD (filename="value", value="0")
	writeLED_AM (filename="value", value="1")
		sleep(1)
	writeLED_AM (filename="value", value="0")
writeLED_AM (filename="unexport", value=AM, path=SYSFS_DIR)
writeLED_VM (filename="unexport", value=VM, path=SYSFS_DIR)
writeLED_VD (filename="unexport", value=VD, path=SYSFS_DIR)
