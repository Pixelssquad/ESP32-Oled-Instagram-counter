#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <SSD1306Wire.h>
#include <InstaFollowers.h>

// Network credentials / credenziali della tia wifi
const char* ssid = "OOZTEST";
const char* password = "diegodiego";

// Inizializza wifi (client)
WiFiClientSecure client;
//inizializza counter ig
InstaFollowers instaStats("instagram-scraper-api2.p.rapidapi.com", "e27d9580afmshd5112c34d056974p1b74c0jsn1286cc636e9e");  //tua chiave api 

// parametri display oledoled , indirizzo e pin
SSD1306Wire display(0x3c, 21, 22);




void setup() {
  // Initialize Serial communication
  Serial.begin(115200);

  // Connect to WiFi network
  Serial.print("Connecting to WiFi network: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  // Initialize OLED display
  display.init();
  display.flipScreenVertically();
}


void loop() {

 int FollowersCount= instaStats.GetUserFollowersCount("ps_diegooz");   /tuo id istagram

  // Display data on OLED display
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  // Instagram logo on the top   by Instagram Followers Counter With ESP32 And OLED Display
  display.drawHorizontalLine(7, 5, 15);
  display.drawVerticalLine(5, 7, 15);
  display.drawVerticalLine(23, 7, 15);
  display.drawHorizontalLine(7, 23, 15);
  display.setPixel(6, 6);
  display.setPixel(6, 22);
  display.setPixel(22, 6);
  display.setPixel(22, 22);
  display.setPixel(19, 9);
  display.drawCircle(14, 14, 4);
  display.drawCircle(19, 9, 1);
  display.setFont(ArialMT_Plain_10);
  display.drawString(30, 5, "INSTAGRAM");
  display.drawString(30, 15, "PS_Diegooz");


Serial.print("Follower count:"+String(FollowersCount));
    

  display.setFont(ArialMT_Plain_24);
  display.drawString(38, 32, String(FollowersCount));
  display.display();
    delay(1800000); // ogni 30 minuti
    //delay(5000);

  }
