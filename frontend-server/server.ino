#include <ESP8266WiFi.h>

const char* ssid = "VETORIAL_CASA_301";
const char* password = "htfriis2016";
IPAddress ip(192,168,2,110);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

WiFiServer server(80);
//define os pinos a serem utilizados
#define led 2

//declara os estados
bool ledStatus = false;

//declara os protótipos das funções
void requisicao(String);

//Pagina HTML
#include "room.h"

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(led, OUTPUT);
  digitalWrite(led, !ledStatus);
  Serial.println("");
  Serial.println("");
  Serial.print("Conectando a ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectando a rede sem fio ");
  Serial.println(ssid);
  server.begin();
  Serial.println("Servidor iniciado");
  Serial.print("IP para se conectar: ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
 }

void loop() {
  WiFiClient client = server.available();
  if(!client){
    return;
  }
  Serial.println("Novo cliente");
  while(!client.available()){
      delay(1);
   }
   String request = client.readStringUntil('\r');
   requisicao(request);
   Serial.println(request);
   client.flush();
   client.println("HTTP/1.1 200 OK");
   client.println("Content-Type: text/html");
   client.println("");
   client.println(room);

   
   delay(1);
   Serial.println("Cliente desconectado");
   Serial.println("");
 }

 void requisicao(String request){
    
 }
