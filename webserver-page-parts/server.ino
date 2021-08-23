#include <ESP8266WiFi.h>

const char* ssid = "VETORIAL_CASA_301";
const char* password = "htfriis2016";
IPAddress ip(192,168,2,110);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

WiFiServer server(80);

//declara os protótipos das funções
// void requisicao(String);

//Pagina HTML
#include "room.h"

void setup() {
    Serial.begin(115200);
    delay(10);
    Serial.println("");
    Serial.println("");
    Serial.print("Conectando a ");
    Serial.print(ssid);

    WiFi.begin(ssid, password);
    WiFi.config(ip, gateway, subnet);

    while (WiFi.status() != WL_CONNECTED){ // Enquanto não conectar
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

bool buttonPressed = false;

void loop() {
    WiFiClient client = server.available();
    if(!client){
        return;
    }
    // Serial.println("Novo cliente");
    // while(!client.available()){
    //     delay(1);
    // }
    // String request = client.readStringUntil('\r');
    // requisicao(request);
    if (digitalRead(PORTA_BOTAO) == HIGH) {
        buttonPressed = true;
    }
    if (!buttonPressed) {
        return;
    } else {
      // Serial.println(request);
      client.flush();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println(room); 
      client.println("<div class='leito-aux-on'>");
      client.println("<h1 class='item-head'>Leito 2</h1>");
      client.println(" <div class='state'>");
      client.println(" <p class='aux'>Auxílio</p>");
      client.println("<p class='emergency'>Emergência</p>");
      client.println("</div>");
      client.println("</div>");
      client.println(roomDown);
      // Serial.println("Cliente desconectado");
      // Serial.println("");
      buttonPressed = false;
    }
}

//  void requisicao(String request){
    
//  }
 
