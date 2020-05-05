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
Below is a guide to assembling the hardware components.
Note that this guide is for connecting 2 light strips but the same can be done with 1 by omitting the second. 
The light strips can be housed inside any transparent structure of your choice - for this project, the lights were housed inside of a hexagon structure made from transparent vinyl sheets and glue.

![Hex-ight Assembly Image](https://github.com/gyjin/hex-ights-esp8266/blob/master/Hex-ights_Assembly_Image.png)

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


### Demo
Below is a demo of my final project, showcasing a run-through of all colors and patterns available in this repo. 

![Demo Video 1/2](https://github.com/gyjin/hex-ights-esp8266/blob/master/IMG_0442%202.MOV)

Hex-ights is a capstone project developed at [Ada Developers Academy](https://adadevelopersacademy.org/) in Seattle, WA by Ga-Young Jin. 
