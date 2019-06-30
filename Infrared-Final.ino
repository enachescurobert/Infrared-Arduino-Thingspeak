#include <ESP8266WiFi.h>

int senzor1 = 12;
int senzor2 = 13; //d7
int senzor3 = 14;

int val1 = 0;
int val2 = 0;
int val3 = 0;

String apiWritekey = "IH94122DLUH2Z89Q"; // replace with your THINGSPEAK WRITEAPI key here
const char* ssid = "Robertica"; // your wifi SSID name
const char* password = "Robu~!@#$%^&*()" ;// wifi pasword
//const char* ssid = "Beinur"; // your wifi SSID name
//const char* password = "Legion96" ;// wifi pasword
const char* server = "api.thingspeak.com";
WiFiClient client;


void setup(){

  pinMode(senzor1, INPUT);  
  pinMode(senzor2, INPUT);  
  pinMode(senzor3, INPUT);  

  Serial.begin(9600);
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid, password);
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("NodeMcu connected to wifi...");
  Serial.println(ssid);
  Serial.println();
}
  
void loop()
{
  val1 = digitalRead(senzor1);

  if (val1 == HIGH){
    
   
   client.connect(server,80);
   String tsData = apiWritekey;
           tsData +="&field1=";
           tsData += String(0);
           tsData += "\r\n\r\n";

     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
 
     Serial.print("Field 1:");
     Serial.print(" 0 \n");
     Serial.println("uploaded to Thingspeak server....");

       delay(15000);

           
   
  } else if(val1 == LOW){
    client.connect(server,80);
   String tsData = apiWritekey;
           tsData +="&field1=";
           tsData += String(1);
           tsData += "\r\n\r\n";

     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
 
     Serial.print("Field 1:");
     Serial.print(" 1 \n");
     Serial.println("uploaded to Thingspeak server....");

       delay(15000);

  }

  val2 = digitalRead(senzor2);

  if (val2 == HIGH){
    
   
   client.connect(server,80);
   String tsData = apiWritekey;
           tsData +="&field2=";
           tsData += String(0);
           tsData += "\r\n\r\n";

     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
 
     Serial.print("Field 2:");
     Serial.print(" 0 \n");
     Serial.println("uploaded to Thingspeak server....");

       delay(15000);

           
   
  } else if(val2 == LOW){
    client.connect(server,80);
   String tsData = apiWritekey;
           tsData +="&field2=";
           tsData += String(1);
           tsData += "\r\n\r\n";

     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
 
     Serial.print("Field 2:");
     Serial.print(" 1 \n");
     Serial.println("uploaded to Thingspeak server....");

       delay(15000);

  }

  val3 = digitalRead(senzor3);
  
  if (val3 == HIGH){
    
   
   client.connect(server,80);
   String tsData = apiWritekey;
           tsData +="&field3=";
           tsData += String(0);
           tsData += "\r\n\r\n";

     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
 
     Serial.print("Field 3:");
     Serial.print(" 0 \n");
     Serial.println("uploaded to Thingspeak server....");

       delay(15000);

           
   
  } else if(val3 == LOW){
    client.connect(server,80);
   String tsData = apiWritekey;
           tsData +="&field3=";
           tsData += String(1);
           tsData += "\r\n\r\n";

     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
 
     Serial.print("Field 3:");
     Serial.print(" 1 \n");
     Serial.println("uploaded to Thingspeak server....");

       delay(15000);

  }

  
  
  
  client.stop();
  Serial.println("Waiting to upload next reading...");
  Serial.println();
  // thingspeak needs minimum 15 sec delay between updates
  delay(15000);
  
}
