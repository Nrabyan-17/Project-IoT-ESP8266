// Import Package Wifi
#include<ESP8266WiFi.h>

const char* ssid = "Lab Sistem Informasi";
const char* password = "belanegara";
WiFiServer server(80);


void setup() {
// Fungsinya untuk menghubungi 
Serial.begin(115200);

pinMode(D0, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);

Serial.println();
Serial.print("Terkoneksi dengan Wifi");
Serial.println(ssid);
WiFi.begin(ssid, password);


  while( WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Terkoneksi");

  server.begin();
  Serial.println("WiFi sudah terkoneksi");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  
}

void loop() {

WiFiClient client = server.available();

if (!client) {
  return;
}

Serial.println("new client");

while(!client.available()) {
  delay(1);
}
String request = client.readStringUntil('\r');
Serial.println(request);
client.flush();

// PARALEL
if (request.indexOf("/led1on") > 0) {
  digitalWrite(D0, HIGH);
}
if (request.indexOf("/led2on") > 0) {
  digitalWrite(D1, HIGH);
}
if (request.indexOf("/led2off") > 0) {
  digitalWrite(D1, LOW);
}
if (request.indexOf("/led3on") > 0) {
  digitalWrite(D2, HIGH);
}
if (request.indexOf("/led3off") > 0) {
  digitalWrite(D2, LOW);
}

// SERI
if (request.indexOf("/led1&2on") > 0) {
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
}
if (request.indexOf("/led1&2off") > 0) {
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
}
if (request.indexOf("/led2&3on") > 0) {
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
}
if (request.indexOf("/led2&3off") > 0) {
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
}
if (request.indexOf("/led1&3on") > 0) {
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
}
if (request.indexOf("/led1&3off") > 0) {
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
}

// SERI SEMUA
if (request.indexOf("/ledallon") > 0) {
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
}
if (request.indexOf("/ledalloff") > 0) {
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
}


// HTML FILE
client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
  client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
  client.println("</head>");
  client.println("<body bgcolor = \"#f7e6ec\">"); 
  client.println("<hr/><hr>");
  client.println("<h3><center> Project IoT : Kontrol 3 LED  </center></h3>");
  client.println("<h4><center> WORKSHOP PEMROGRAMAN IOT  </center></h4>");
  client.println("<hr/><hr>");  
  client.println("<br><br>");
  //client.println("<br><br>");
  client.println("<center>");
  client.println("Lampu 1");
  client.println("<a href=\"/led1on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/led1off\"\"><button>Turn Off </button></a><br />");  
  client.println("</center>");   
  client.println("<br><br>");
  client.println("<center>");
  client.println("Lampu 2");
  client.println("<a href=\"/led2on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/led2off\"\"><button>Turn Off </button></a><br />");  
  client.println("</center>"); 
  client.println("<br><br>");
  client.println("<center>");
  client.println("Lampu 3");
  client.println("<a href=\"/led3on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/led3off\"\"><button>Turn Off </button></a><br />");  
  client.println("</center>"); 
  client.println("<br><br>");
  client.println("<center>");
  client.println("Lampu 1 & 2");
  client.println("<a href=\"/led1&2on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/led1&2off\"\"><button>Turn Off </button></a><br />");  
  client.println("</center>"); 
  client.println("<br><br>");
  client.println("<center>");
  client.println("Lampu 2 & 3");
  client.println("<a href=\"/led2&3on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/led2&3off\"\"><button>Turn Off </button></a><br />");  
  client.println("</center>"); 
  client.println("<br><br>");
  client.println("<center>");
  client.println("Lampu 1 & 3");
  client.println("<a href=\"/led1&3on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/led1&3off\"\"><button>Turn Off </button></a><br />");  
  client.println("</center>"); 
  client.println("<br><br>");
  client.println("<center>");
  client.println("Semua Lampu");
  client.println("<a href=\"/ledallon\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/ledalloff\"\"><button>Turn Off </button></a><br />");  
  client.println("</center>"); 
  client.println("<br><br>");
  client.println("<center>");
  /*client.println("Lampu 4");
  client.println("<a href=\"/led4on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/led4off\"\"><button>Turn Off </button></a><br />");  
  client.println("</center>"); 
  client.println("<br><br>");
  client.println("<center>");*/
  client.println("<table border=\"5\">");
  client.println("<tr>");
  //=====================
  if (digitalRead(D0))
         { 
           client.print("<td>LED 1 = ON</td>");        
         }
  else
          {
            client.print("<td>LED 1 = OFF</td>");
          }     
  client.println("<br />");
  //======================           
  if (digitalRead(D1))
          { 
           client.print("<td>LED 2 = ON</td>");
          }
  else
          {
            client.print("<td>LED 2 = OFF</td>");
          }
  client.println("</tr>");
  //=======================
  client.println("<tr>");
  
  if (digitalRead(D2))
          { 
           client.print("<td>LED 3 = ON</td>");
          }
  else
          {
            client.print("<td>LED 3 = OFF</td>");
          }
  /*if (digitalRead(D3))
          { 
           client.print("<td>LED 4 = ON</td>");
          }
  else
          {
            client.print("<td>LED 4 = OFF</td>");
          }*/
  client.println("</tr>");  
  client.println("</table>");
  client.println("</center>");
  client.println("</html>"); 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");


}
