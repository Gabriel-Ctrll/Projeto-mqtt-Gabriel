# Projeto-mqtt-Gabriel
<p>

## Objetivo 
</p>

O objetivo desse projeto é utilizar um Arduino Uno mais um Sensor Magnético para monitorar se a porta de um Rack de Rede está *ABERTO* ou *FECHADO* ; enviar essa informação via internet utilizando o protocolo MQTT(Message Queuing Telemetry) para um servidor MQTT hospedado na Amazon Web Service (AWS) e exibir a informação em um cliente MQTT  ([MQTT Dash](https://play.google.com/store/apps/details?id=net.routix.mqttdash&hl=pt_BR&gl=US)) instalado em um Smartphone, conforme imagem abaixo.

![Projeto](https://github.com/Gabriel-Ctrll/Projeto-mqtt-Gabriel/blob/main/Projeto.PNG)

<p>
Foram utilizado as seguintes bibliotecas:
</p>

[UIPEthernet](https://www.arduinolibraries.info/libraries/uip-ethernet)(conexão do ENC28J60 com o Arduino)

[PubSubClient](https://pubsubclient.knolleary.net/)(cliente MQTT para o Arduino)

<p>

## Materiais

</p>
Arduino Uno

Módulo Ethernet (ENC28J60)

Sensor Magnético (MC-38)

Jumpers
