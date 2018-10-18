LEDVM=20
LEDAM=16
LEDVD=21

echo $LEDVM >> "/sys/class/gpio/export"
echo $LEDAM >> "/sys/class/gpio/export"
echo $LEDVD >> "/sys/class/gpio/export"

sleep 1s

echo out >> "/sys/class/gpio/gpio$LEDVM/direction"
echo out >> "/sys/class/gpio/gpio$LEDVD/direction"
echo out >> "/sys/class/gpio/gpio$LEDAM/direction"



for i in 1 2 3 4 5
	do
		echo 1 > "/sys/class/gpio/gpio$LEDVM/value"
		sleep 2s
		echo 0 > "/sys/class/gpio/gpio$LEDVM/value"
		echo 1 > "/sys/class/gpio/gpio$LEDVD/value"
		sleep 1s
		echo 0 > "/sys/class/gpio/gpio$LEDVD/value"
		echo 1 > "/sys/class/gpio/gpio$LEDAM/value"
		sleep 1s
		echo 0 > "/sys/class/gpio/gpio$LEDAM/value"
	done

echo LEDVM >> unexport
echo LEDAM >> unexport
echo LEDVD >> unexport
