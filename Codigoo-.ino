#include <PubSubClient.h>

#include <UIPEthernet.h>
#include <utility/logging.h>

#include <SPI.h>


//Define o endereço MAC que será utilizado
byte mac[] = {0x48, 0x67, 0x4B, 0x00, 0x05, 0xB5};

bool mensagem;

//Inicia o cliente Ethernet
EthernetClient client;

PubSubClient mqttClient(client);

int pino2 = 2;
bool estado_sensor;
 
void setup() {
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial
    Serial.begin(9600);


    mqttClient.setServer("54.161.191.80",1883);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

    //Exibe uma linha em branco
    Serial.println("");

   
    pinMode(pino2, INPUT_PULLUP);

}

void loop() {

  mqttClient.connect("GabrielAraujo");

 estado_sensor = digitalRead(pino2);
      
      if(estado_sensor == 0){
         mensagem = mqttClient.publish ("GabrielAraujo-t","FECHADO");
        delay(1000);
        }
        else {
           mensagem = mqttClient.publish ("GabrielAraujo-t","ABERTO");
          delay(1000);
          
          }



    
    
    mqttClient.loop();
    
    delay(500);
}