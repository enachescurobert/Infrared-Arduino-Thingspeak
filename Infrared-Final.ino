#include <ESP8266WiFi.h>

int senzor1 = 12;
int senzor2 = 13; //d7
int senzor3 = 14;

int val1 = 0;
int val2 = 0;
int val3 = 0;

int stareLoc1 = 0;
int stareLoc2 = 0;
int stareLoc3 = 0;

String apiWritekey = "IH94122DLUH2Z89Q"; // replace with your THINGSPEAK WRITEAPI key here
const char* ssid = "Robertica"; // your wifi SSID name
const char* password = "Robu~!@#$%^&*()" ;// wifi pasword
//const char* ssid = "Beinur"; // your wifi SSID name
//const char* password = "Legion96" ;// wifi pasword
const char* server = "api.thingspeak.com";

// https://api.thingspeak.com/update?api_key=IH94122DLUH2Z89Q&field1=0&field2=0&field3=0

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
  val2 = digitalRead(senzor2);
  val3 = digitalRead(senzor3);

  if (val1 == HIGH){
    stareLoc1 = 0;
  } else {
    stareLoc1 = 1;
  }

  if (val2 == HIGH){
    stareLoc2 = 0;
  } else {
    stareLoc2 = 1;
  }

  if (val3 == HIGH){
    stareLoc3 = 0;
  } else {
    stareLoc3 = 1;
  }
    
   
   client.connect(server,80);
   String tsData = apiWritekey;
           tsData +="&field1=";
           tsData += String(stareLoc1);
           tsData +="&field2=";
           tsData += String(stareLoc2);
           tsData +="&field3=";
           tsData += String(stareLoc3);
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
     Serial.print(stareLoc1);
     Serial.print(" \n");
     Serial.print("Field 2:");
     Serial.print(stareLoc2);
     Serial.print(" \n");
     Serial.print("Field 3:");
     Serial.print(stareLoc3);
     Serial.print(" \n");
     Serial.println("uploaded to Thingspeak server....");

  client.stop();
  Serial.println("Waiting to upload next reading...");
  Serial.println();
  // thingspeak needs minimum 15 sec delay between updates
  delay(15000);
  
}
