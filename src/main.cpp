#include <Arduino.h>
#include <WiFi.h>
#include <MQTT.h>
#include <llp.h>

#include <constants.h>
#include <connect.h>
#include <giro_sensor.h>

WiFiClient net;
MQTTClient client;
GyroscopeSensor sensor = GyroscopeSensor(0x64, 1, 100);

long reportTimer = millis();
long alarmTimer = millis();
long angulo = 0;

void setup() {
  
 
  Serial.begin(115200);
  WiFi.begin(SSID, SSID_PASSWORD);
  client.begin(BROKER, net);
  connect(Serial, net, client);
  sensor.init();
  
}

void loop() {
  client.loop();
  delay(10);
  angulo = sensor.read();
  Serial.println(angulo);
  if (!client.connected()) {
    connect(Serial, net, client);
  }

  if(millis()-reportTimer >= REPORT_FREQ){
    reportTimer=millis();
    client.publish(String(MQTT_ID)+"/report", String(angulo));
    Serial.println(String(angulo));
  }



}