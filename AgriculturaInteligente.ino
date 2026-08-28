#include <ArduinoJson.h> // instalar la version 5.13.1 de ArduinoJson
#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define Largo_Pantalla 128 // Largo de la pantalla en pixeles
#define Ancho_Pantalla 32 // Ancho de la pantalla en pixeles

#define Reset_Oled 4 // pin 4 definido para borrar la pantalla
Adafruit_SSD1306 display(Largo_Pantalla, Ancho_Pantalla, &Wire, Reset_Oled);

#define FIREBASE_HOST "YOUR_FIREBASE_HOST"
#define FIREBASE_AUTH "YOUR_FIREBASE_AUTH"
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

int sensorPin = 35; // pin digital al que está conectado el pin DO del sensor
int sensorValue = 0; // variable para almacenar el valor leído del sensor
const int relay = 23;
String estado = "";

void setup() {
  Serial.begin(9600); // Iniciar el puerto serie
  pinMode(relay, OUTPUT);
 // Configurar el pin como entrada


if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // direccion del display 0x3C para el OLED de
//128x32
Serial.println(F("Existe falla en el SSD1306"));
for(;;); // si falla se marca un loop infinito
}
// Limpia el buffer
display.clearDisplay(); // clearDisplay() borra lo que está en el buffer y pantalla.
// Dibuja un punto en la pantalla
//display.drawPixel(10,30, SSD1306_WHITE); // Muestra un pixel en la posición X=10 y Y=30
display.display();


pinMode(sensorPin,INPUT);

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("conectando");
while (WiFi.status() != WL_CONNECTED){
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("Conectado a la IP: ");
Serial.println(WiFi.localIP());

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);



}

int f=1;


void loop() {

  sensorValue = analogRead(sensorPin); // leer el valor del pin
  String db = "Humedad/humedad";
  String d = db + "" + f;
 

  Serial.print("Nivel de humedad: ");
  Serial.print(sensorValue);
  Serial.println("");
  Serial.println(d);
  Serial.println(f);
  if(f==24){
    f=0;
  }
 delay(1000);
 estado=Firebase.getString("Estado");
  if (sensorValue >= 2500 && estado == "ON" || estado=="on") {
    digitalWrite(relay, HIGH);
     
  } else {
    digitalWrite(relay, LOW);
  }

  delay(100);

display.clearDisplay(); // Limpia en inicio la pantalla
display.setTextSize(2); // 1 es la escala normal
display.setTextColor(SSD1306_WHITE); // Escribe texto en azul sobre fondo negro
display.setCursor(10,0); // X=10 y Y=0
display.println(F("CRACK"));
/* --------------------------------------------------------- */

String yu=" Estado: ";
String lui=yu+""+estado;

display.setTextSize(1); // 2 escala más grande del texto
display.setTextColor(SSD1306_WHITE);
display.println(lui);
/*------------------------------------------------------------*/

String gsf = "Humedad: ";
String as = gsf+""+sensorValue;

display.setTextSize(1); // método setTextSize(tamaño_texto)
display.setTextColor(SSD1306_WHITE); // INTERCAMBIANDO LOS COLORES
display.setCursor(25,25); // coordenadas (x,y) para localizar texto en pantalla
display.println(as);
display.display();
delay(3000);
//display.invertDisplay(true); // elimina los comentarios para ver otra forma de trabajar del display
//delay(1000); // elimina las barras al inicio para que veas la función
display.invertDisplay(false);

  Firebase.setInt(d,sensorValue);
  f=f+1;
  delay(2000); // esperar 1 segundo antes de volver a leer el valor del pin
}