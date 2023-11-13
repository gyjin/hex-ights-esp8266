// resource used for:
// firebase library: https://github.com/mobizt/Firebase-ESP8266
// ESP8266 library on Arduino: https://arduino-esp8266.readthedocs.io/en/3.1.2/esp8266wifi/readme.html
// setting up led strip: https://learn.adafruit.com/neopixel-painter/test-neopixel-strip
// led strip color patterns: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/#MakeyoureffectscoolerDiffuseLighttoiletpapermagic

#include <Arduino.h>
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
 
#define PIN D6
#define NUM_LEDS 24
 
#define WIFI_SSID "NETWORK NAME"
#define WIFI_PASSWORD "PASSWROD"

#define DATABASE_URL "DATABASE URL"

FirebaseData firebaseData;
FirebaseAuth auth;
FirebaseConfig config;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
// Current color values
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
String pattern = "";
 
void setup() {
  Serial.begin(115200);
  connectWifi();

  config.database_url = DATABASE_URL;
  config.signer.test_mode = true;
  
  strip.begin();
  
  Firebase.begin(&config, &auth);
}
 
void loop() {
  Serial.print("start of loop");
  
  if (Firebase.getInt(firebaseData, "/red")) {
    if  (firebaseData.dataType() == "int") {
      int val = firebaseData.intData();
      if (val != redValue) {
        redValue = val;
        Serial.print("the red value changed to: ");
        Serial.print(redValue);
        Serial.print("\n");
      } else {
        Serial.print("the red value stayed the same at: ");
        Serial.print(redValue);
        Serial.print("\n");
      }
    }
  } else {
    Serial.print("no red value");
  }
 
  if (Firebase.getInt(firebaseData, "/green")) {
    if  (firebaseData.dataType() == "int") {
      int val = firebaseData.intData();
      if (val != greenValue) {
        greenValue = val;
        Serial.print("the green value changed to: ");
        Serial.print(greenValue);
        Serial.print("\n");
      } else {
        Serial.print("the green value stayed the same at: ");
        Serial.print(greenValue);
        Serial.print("\n");
      }
    }
  } else {
    Serial.print("no green value");
  }
 
  if (Firebase.getInt(firebaseData, "/blue")) {
    if  (firebaseData.dataType() == "int") {
      int val = firebaseData.intData();
      if (val != blueValue) {
        blueValue = val;
        Serial.print("the blue value changed to: ");
        Serial.print(blueValue);
        Serial.print("\n");
      } else {
        Serial.print("the blue value stayed the same at: ");
        Serial.print(blueValue);
        Serial.print("\n");
      }
    }
  } else {
    Serial.print("no blue value");
  }

  if (Firebase.getString(firebaseData, "/pattern")) {
      String val = firebaseData.stringData();
      if (val != pattern) {
        pattern = val;
        Serial.print("the pattern changed to: ");
        Serial.print(pattern);
        Serial.print("\n");
      } else {
        Serial.print("the pattern stayed the same at: ");
        Serial.print(pattern);
        Serial.print("\n");
      }
  } else {
    Serial.print("no pattern value");
  }

  delay(500);
  Serial.print("\n");
  
  setupStrip();
}
 
void connectWifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println(".......");
  Serial.println("WiFi Connected....IP Address:");
  Serial.println(WiFi.localIP());
}
 
void setupStrip() {
  if (pattern == "solid") {
    Solid();
  } else if (pattern == "blink") {
    Blink();
  } else if (pattern == "wave") {
    Wave();
  } else if (pattern == "fade") {
    FadeInOut();
  } else if (pattern == "twinkle") {
    Twinkle();
  } else if (pattern == "run") {
    Run();
  } else if (pattern == "off") {
    Off();
  }
}

void Solid() {
  for (int i=0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(redValue, greenValue, blueValue));
    strip.show();
  }
}

void Blink() {
  strip.fill(strip.Color(redValue, greenValue, blueValue), 0); // turn all lights on
  strip.show();
  delay(700);
  strip.fill(strip.Color(0, 0, 0), 0); // turn all lights off
  strip.show();
  delay(200);
}

void Wave() {
  for(int i=0; i < strip.numPixels()+5; i++) {
    strip.setPixelColor(i, strip.Color(redValue, greenValue, blueValue)); // draw new pixel
    strip.setPixelColor(i-5, 0); // erase pixel a few steps back
    strip.show();
    delay(50);
  }
}

void FadeInOut() {
  float red = redValue;
  float green = greenValue;
  float blue = blueValue;
  float r, g, b;
      
  for(int k = 0; k < 255; k=k+1) { // fade lights on
    r = (k/255.0)*red;
    g = (k/255.0)*green;
    b = (k/255.0)*blue;
    strip.fill(strip.Color(r, g, b), 0);
    strip.show();
    delay(10);
  }
     
  for(int k = 255; k >= 0; k=k-2) { // fade lights off
    r = (k/255.0)*red;
    g = (k/255.0)*green;
    b = (k/255.0)*blue;
    strip.fill(strip.Color(r, g, b), 0);
    strip.show();
    delay(10);
  }
}

void Twinkle() {
  float red = redValue;
  float green = greenValue;
  float blue = blueValue;
  int Count = 10;
  int SpeedDelay = 100;
  boolean OnlyOne = false;

  strip.fill(strip.Color(0, 0, 0), 0);
 
  for (int i=0; i<Count; i++) {
     strip.setPixelColor(random(NUM_LEDS), strip.Color(red,green,blue));
     strip.show();
     delay(SpeedDelay);
     if(OnlyOne) {
       strip.fill(strip.Color(0, 0, 0), 0);
     }
   }
  delay(SpeedDelay);
}

void Run() {
  float red = redValue;
  float green = greenValue;
  float blue = blueValue;
  int WaveDelay = 125;
  int Position = 0;

  for(int j=0; j<NUM_LEDS*2; j++) {
    Position++; // = 0; Position + Rate;
    
    for(int i=0; i<NUM_LEDS; i++) {
      // sine wave, 3 offset waves make a rainbow!
      // float level = sin(i+Position) * 127 + 128;
      // setPixel(i,level,0,0);
      strip.setPixelColor(i,((sin(i+Position) * 127 + 128)/255)*red,
                 ((sin(i+Position) * 127 + 128)/255)*green,
                 ((sin(i+Position) * 127 + 128)/255)*blue);
    }
     
      strip.show();
      delay(WaveDelay);
  }
}

void Off() {
  strip.clear();
  strip.show();
}
