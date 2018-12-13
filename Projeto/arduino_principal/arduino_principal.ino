const int PinoECG = A0;
          PinoTemp = A1;//pins do termometro, spo2 e ECG 
          PinoSpo2 = A2;// escolher as portas
void setup(){
   // Configura a serial: baud rate de 115200, 8-bit, sem paridade, 1 stop bit
   Serial.begin(115200, SERIAL_8N1);
 
}

void loop(){
   int valor1 = analogRead(PinoECG);      // le valor no pino A0 usando conversor ADC de 10-bit
   float tensao = valor1 * (5.0f/1023.0f); //valor do sinal de ECG
   Serial.print(valor1);

   
   int valor2 = analogRead(PinoTemp);      // le valor no pino A0 usando conversor ADC de 10-bit
   float potencial = valor2 * (5.0f/1023.0f); // calculo da temperatura
   Serial.print(valor2); 
                      
   int valor3 = analogRead(PinoSpow);      // le valor no pino A0 usando conversor ADC de 10-bit
   float potencial = valor3 * (5.0f/1023.0f); // calculo do SpO2
   Serial.print(valor3); 
   
   delay(100);
}
