## Hex-ights

Light up your life! Hex-ights are WiFi-controlled customizable led lights for all light enthusiasts. 
Control the lights from any device that can access the webpage! This is the hardware portion of this project. 
Please refer to the [webpage portion](https://github.com/gyjin/hex-ights-react/blob/master/README.md) to set up the webpage. 

### Hardware Components
1. [ESP8266 Minicontroller Board](https://www.amazon.com/gp/product/B010N1SPRK/)
2. [Basic Starter Kit](https://www.amazon.com/dp/B01HRR7EBG/)
3. [Individual Addressable RGB LED Strip Light](https://www.amazon.com/dp/B01MG49QKD/)
4. [USB Cable - A-Male to Mini-B Cord](https://www.amazon.com/AmazonBasics-USB-2-0-Cable-Male/dp/B00NH13S44/)
5. [5V AC/DC Power Supply](https://www.amazon.com/SoulBay-Universal-Multi-Voltage-Selectable-Electronics/dp/B01N2K48HR/)

### Assembly

### Launch
1. Download [Arduino IDE](https://www.arduino.cc/en/main/software)
2. Follow this [link](https://www.instructables.com/id/Quick-Start-to-Nodemcu-ESP8266-on-Arduino-IDE/) for connecting the IDE to the board
  - Add [ESP8266 for Arduino Library](https://github.com/esp8266/Arduino)
  - Add [Firebase ESP8266 Arduino Library](https://github.com/mobizt/Firebase-ESP8266)
  - Add [Adafruit Neopixel Arduino Library](https://github.com/adafruit/Adafruit_NeoPixel)<br />
3. (if you have not done so already)<br />
- Make a new Realtime Database project on [Firebase](https://firebase.google.com/): 
  - note the firebaseio URL in the database tab and the Web API Key in settings
  - in the realtime database, add 4 variables as below:
    - red: 0
    - green: 0
    - blue: 0
    - pattern: ""
    
4. Clone this repository.
5. Change WiFi configurations in code.
6. Change Firebase configurations in code.
7. Upload codebase onto the board.
8. Confirm in serial monitor that the board is successfully connected to WiFi and retrieving all 4 variables from Firebase.<br />

Hex-ights is a capstone project developed at Ada Developers Academy in Seattle, WA by Ga-Young Jin. 