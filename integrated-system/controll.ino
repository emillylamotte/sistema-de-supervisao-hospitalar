#include <ESP8266WiFi.h>

const char* ssid = "VETORIAL_CASA_301";
const char* password = "htfriis2016";
IPAddress ip(192,168,2,110);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

WiFiServer server(80);

//declara os protótipos das funções
// void requisicao(bool);

bool statusBotao = false;
//Pagina HTML
#include "room.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Leitura do botão");
   pinMode(D1,INPUT);
   pinMode(D4,OUTPUT);
  
  delay(10);
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

int state = 0;

void loop() {
  WiFiClient client = server.available();
  if(!client){
    return;
  }
  Serial.println("Novo cliente");
  while(!client.available()){
      delay(1);
   }

  //  bool request = digitalRead(D1);
  //  statusBotao = requisicao(request);
  //  Serial.println(request);
   client.flush();
   client.println("HTTP/1.1 200 OK");
   client.println("Content-Type: text/html");
   client.println("");
   
   client.println(room); 
    statusBotao ? client.println("<div class='leito-aux-on'>") : client.println("<div class='leito'>");
  if (digitalRead(D1) == HIGH and state == 0) {
    Serial.println("Botão pressiado");
    digitalWrite(D4, HIGH);
    // client.println("<div class='leito-aux-on'>");
    statusBotao = true;
    state = 1;
    // client.flush();
  }
    digitalWrite(D4, LOW);
  if (state != 1) {
    // client.println("<div class='leito'>");
    statusBotao = false;
    client.flush();
  } 
 
  client.flush();
   client.println("<h1 class='item-head'>Leito 2</h1>");
   client.println(" <div class='state'>");
   client.println(" <p class='aux'>Auxílio</p>");
   client.println("<p class='emergency'>Emergência</p>");
   client.println("</div>");
   client.println("</div>");
   client.println(roomDown);
   Serial.println("Cliente desconectado");
   Serial.println("");
 }

//  bool requisicao(bool request){
//     if(request == 0) {
//         Serial.println("Botão não pressionado");
//         digitalWrite(D4, LOW);
//         return false;
//     } else {
//        Serial.println("Botão pressionado");
//        digitalWrite(D4, HIGH);
//        return true;  
//     }
//  }
