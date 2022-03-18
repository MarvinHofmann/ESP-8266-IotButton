#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#define RTCMEMORYSTART 65

extern "C" {
#include "user_interface.h"
}

typedef struct {
  int index;
} rtcStore;

rtcStore rtcMem;
WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.begin(ssid, pass);   
  while (WiFi.status() != WL_CONNECTED) {  
    delay(50);
    Serial.println("Waiting for connection");
  }
  Serial.println(WiFi.localIP());
  Serial.println("");
  Serial.println("Waking up...");
  Serial.print("Reading ");
  readFromRTCMemory();
  Serial.print("Writing ");
  writeToRTCMemory();
  Serial.print("Sleeping.");
  ESP.deepSleep(0);
}

void loop() {}

void readFromRTCMemory() {
  system_rtc_mem_read(RTCMEMORYSTART, &rtcMem, sizeof(rtcMem));

  Serial.print("index = ");
  Serial.println(rtcMem.index);
  yield();
}

void writeToRTCMemory() {
  if(rtcMem.index == 0){
    Serial.println("1");
    HTTPClient http;
          http.begin(client,"http://youDomain/");     
          http.addHeader("Content-Type", "application/json");  
          int httpCode = http.GET(); 
          http.end();  //Close connection
    rtcMem.index = 1;    
    system_rtc_mem_write(RTCMEMORYSTART, &rtcMem, 4);
  }else{
    HTTPClient http;   
          http.begin(client,"http://yourDomain/");      
          http.addHeader("Content-Type", "application/json");  
          int httpCode = http.GET(); 
          http.end();  //Close connection
    Serial.println("0");
    rtcMem.index = 0;
    system_rtc_mem_write(RTCMEMORYSTART, &rtcMem, 4);
  }
  yield();
}
