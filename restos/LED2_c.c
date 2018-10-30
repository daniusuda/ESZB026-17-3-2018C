# include < stdio .h > //biblioteca de funções para leitura e gravação
# include < stdlib .h >//biblioteca de funções para memória, processos e conversões
# include < string .h >//biblioteca de funções para strings

# define GPIO_AM "16" //definindo variáveis
# define GPIO_VM "20"
# define GPIO_VR "21"

# define GPIO_path_AM "/ sys / class / gpio / gpio16 /" //definindo caminhos
# define GPIO_path_VM "/ sys / class / gpio / gpio20 /"
# define GPIO_path_VR "/ sys / class / gpio / gpio21 /"
# define GPIO_SYSFS "/ sys / class / gpio /"


void writeGPIO ( char filename [] , char value []) {
 	FILE * fp ; // cria um ponteiro fp
 	fp = fopen ( filename , "w+") ; // abre o arquivo para escrita
 	fprintf (fp , "%s", value ) ; // grava o valor no arquivo
 	fclose ( fp );

int main(){
	writeGPIO ( GPIO_SYSFS " export ", GPIO_AM ); //Habilitando as GPIOs
	writeGPIO ( GPIO_SYSFS " export ", GPIO_VM );
	writeGPIO ( GPIO_SYSFS " export ", GPIO_VR );
	usleep (1000000) ; // aguarda 1000 ms
	int a;
	for (a=0;a<5; a = a+1){
		writeGPIO ( GPIO_path_AM " direction ", " out ");
		writeGPIO ( GPIO_path_VM " direction ", " out ");
		writeGPIO ( GPIO_path_VR " direction ", " out ");
		writeGPIO ( GPIO_path_VM " value ", "1");
		usleep (2000000) ; // aguarda 2000 ms
		writeGPIO ( GPIO_path_VM " value ", "0");
		writeGPIO ( GPIO_path_VR " value ", "1");
		usleep (1000000) ; // aguarda 1000 ms
		writeGPIO ( GPIO_path_VR " value ", "0");
		writeGPIO ( GPIO_path_AM " value ", "1");
		usleep (1000000) ; // aguarda 1000 ms
		writeGPIO ( GPIO_path_AM " value ", "0");
	}

	writeGPIO ( GPIO_SYSFS " unexport ", GPIO_AM ); //Desabilitando as GPIOs
	writeGPIO ( GPIO_SYSFS " unexport ", GPIO_VM );
	writeGPIO ( GPIO_SYSFS " unexport ", GPIO_VR );
	return 0
}