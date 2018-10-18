
# include < iostream >//biblioteca de funções para entradas e saídas
# include < fstream >//biblioteca de stream aplicado em arquivos
# include < string >// para usar a função de string
# include < unistd .h >//habilita diversas constantes e funções simbólicos
 using namespace std ; //usa o namespace da biblioteca std para não ter que usar no início de funções como string

# define GPIO_AM "16"
# define GPIO_VM "20"
# define GPIO_VR "21"

# define GPIO_path_AM "/ sys / class / gpio / gpio16 /"
# define GPIO_path_VM "/ sys / class / gpio / gpio20 /"
# define GPIO_path_VR "/ sys / class / gpio / gpio21 /"
# define GPIO_SYSFS "/ sys / class / gpio /"

void writeGPIO ( string path , string filename , string value ){ //criação de ponteiro fs
	fstream fs ;
	fs . open (( path + filename ). c_str () , fstream :: out );
	fs << value ;
	fs . close () ;);
int main(){
	writeGPIO ( string(GPIO_SYSFS) " export ", GPIO_AM ); //Habilitando as GPIOs, string() para usar o valor de string de cada gpio_path e do gpio_sysfs
	writeGPIO ( string(GPIO_SYSFS) " export ", GPIO_VM );
	writeGPIO ( string(GPIO_SYSFS) " export ", GPIO_VR );
	usleep (1000000) ; // aguarda 1000 ms
	int a;
	for (a=0;a<5; a = a+1){
		writeGPIO ( string(GPIO_path_AM) " direction ", " out ");//Definindo como saídas
		writeGPIO ( string(GPIO_path_VM) " direction ", " out ");
		writeGPIO ( string(GPIO_path_VR) " direction ", " out ");
		writeGPIO ( string(GPIO_path_VM) " value ", "1");
		usleep (2000000) ; // aguarda 2000 ms
		writeGPIO ( string(GPIO_path_VM) " value ", "0");
		writeGPIO ( string(GPIO_path_VR) " value ", "1");
		usleep (1000000) ; // aguarda 1000 ms
		writeGPIO ( string(GPIO_path_VR) " value ", "0");
		writeGPIO ( string(GPIO_path_AM) " value ", "1");
		usleep (1000000) ; // aguarda 1000 ms
		writeGPIO ( string(GPIO_path_AM) " value ", "0");
	}

	writeGPIO ( string(GPIO_SYSFS) " unexport ", GPIO_AM ); //Desabilitando as GPIOs
	writeGPIO ( string(GPIO_SYSFS) " unexport ", GPIO_VM );
	writeGPIO ( string(GPIO_SYSFS) " unexport ", GPIO_VR );
return 0
}