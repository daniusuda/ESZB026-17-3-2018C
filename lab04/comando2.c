/* Programa baseado no codigo disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/ */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>
#include <wiringPi.h>
#include <softPwm.h>

int main(){
   	int  pino_PWM = 23;                         // pwm por software na GPIO23
	int range = 100;                           // periodo do PWM = 100us*range
	wiringPiSetupGpio();                       // usar a numeracao GPIO, nao WPi
	pinMode(pino_PWM,OUTPUT);	           // configura GPIO23 como saida
	softPwmCreate(pino_PWM, 1, range);         // inicializa PWM por software
   	int file, count, valor, valorporcento;
   
   if ((file = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY))<0){
      perror("Falha ao abrir o arquivo.\n");
      return -1;
   }
   struct termios options;
   tcgetattr(file, &options);
   options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL;
   tcflush(file, TCIFLUSH);
   tcsetattr(file, TCSANOW, &options);
  
   usleep(100000);
	for (;;)
	{
	   unsigned char receive[100];
	   if ((count = read(file, (void*)receive, 100))<0){
	      perror("Falha ao ler da entrada.\n");
	      return -1;
	   }
	   if (count>0){
	      receive[count]=0;  // o Arduino nao envia o caractere nulo (\0=0)
              sscanf(receive,"%d",&valor);
	      valorporcento = (valor*100.0/1023.0);
	      printf("[%d] %s -> %d\n",count,receive,valorporcento);
	      softPwmWrite (pino_PWM, valorporcento); // altera o duty cycle do PWM
	      delay (10);                     // aguarda 10ms
	   }

                
   }
	close(file);
   return 0;
}
