1 /** Programa baseado no c d i g o disponibilizado em:
2 * Derek Molloy , Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux ,
3 * Wiley 2016 , ISBN 978 -1 -119 -1868 -1 , http :// www. exploringrpi . com /
4 */
5
6 # include < stdio .h >
7 # include < stdlib .h >
8 # include < string .h >
9
10 # define GPIO_NUMBER "16"
14
11 # define GPIO4_PATH "/ sys / class / gpio / gpio16 /"
12 # define GPIO_SYSFS "/ sys / class / gpio /"
13
14 void writeGPIO ( char filename [] , char value []) {
15 FILE * fp ; // cria um ponteiro fp
16 fp = fopen ( filename , "w+") ; // abre o arquivo para escrita
17 fprintf (fp , "%s", value ) ; // grava o valor no arquivo
18 fclose ( fp ); // fecha o arquivo
19 }
20
21 int main ( int argc , char * argv []) {
22 if( argc !=2) { // o nome do programa eh o argumento 1
23 printf (" Numero incorreto de argumentos \n") ;
24 printf (" uso : ./ LED_c comando \n");
25 printf (" onde comando pode ser: setup , on , off , status , ou close \n");
26 return 2; // numero invalido de argumentos
27 }
28 printf (" Iniciando o programa em C para alterar a gpio %s.\n", GPIO_NUMBER );
29 if( strcmp ( argv [1] ," setup ") ==0) {
30 printf (" Habilitando a gpio \n");
31 writeGPIO ( GPIO_SYSFS " export ", GPIO_NUMBER );
32 usleep (100000) ; // aguarda 100 ms
33 writeGPIO ( GPIO4_PATH " direction ", " out ");
34 }
35 else if( strcmp ( argv [1] ," close ") ==0) {
36 printf (" Desabilitando a gpio \n");
37 writeGPIO ( GPIO_SYSFS " unexport ", GPIO_NUMBER );
38 }
39 else if( strcmp ( argv [1] ,"on") ==0) {
40 printf (" Acendendo o LED\n");
41 writeGPIO ( GPIO4_PATH " value ", "1");
42 }
43 else if ( strcmp ( argv [1] ," off ") ==0) {
44 printf (" Desligando o LED \n");
45 writeGPIO ( GPIO4_PATH " value ", "0");
46 }
47 else if ( strcmp ( argv [1] ," status ") ==0) {
48 FILE * fp ; // cria um ponteiro fp
49 char line [80] , fullFilename [100];
50 sprintf ( fullFilename , GPIO4_PATH "/ value ");
51 fp = fopen ( fullFilename , "rt"); // abre o arquivo para leitura de texto
52 while ( fgets ( line , 80 , fp ) != NULL ){
53 printf ("O estado do LED eh %s", line );
54 }
55 fclose ( fp );
56 }
57 else {
58 printf (" Comando invalido !\n");
59 }
60 printf (" Fim do programa em C.\n");
61 return 0;
62 }