*************************************************************************  EcoFrost project README  ****************************************************************************************
This is the micro-controller and IoT integration code for an esp32 module that is compiled in Arduino ide.


--> This folder contains a .ino file to be edited with an Arduino ide


EcoFrost is an an innovative agro refrigeration chamber utilizing thermoelectric cooling principles; achieved a temperature reduction of up to 13 degrees Celsius, optimizing storage conditions for perishable goods.

The Model uses a peltier (TEC1-12706) module to cool the chamber. The model proposes the use of Phase Change Materials and highlights its efficiency in maintaining a cold environment in the 
chamber. The us of PCM also make the model energy efficient.

Components Required:
1. ESP32
2. DHT11 Temperature and Humidity Sensor
3. 2-Channel Relay Module
4. Peltier Module
5. Power Supply for Peltier (appropriate voltage and current rating)
6. Blynk App Installed on a Smartphone or the web version.	

CONTROL SYSTEM
--> The esp32 controller gets humidity and temperature data from a dht11 sensor through the serial port by the I2C protocol. 
--> The esp32 can be configured to transmit this data to a custom MQTT server. This project utilises the services of Blynk IoT
## Blynk is a tool available for free for upto 2 IoT devices. This tool allows us to create immersive dashboards with graphs and button controls.
--> As soon as the chamber reaches sub 5°C temperature, The controller sends a control signal to a relay module which then cuts off the power supply to the plant (EcoFrost model).
--> When the temp goes above 5°C, the controller turns the plant back on. Hence reducing the power usage.

** THis model is solar powered. We used a 20W solar panel with a 7Ah battery to power the plant. The control system was powered separately using a 5V DC source(Power bank).
## The tec1-12706 takes upto 6Amps of current. making 7Ah ideal.

--> Follow this link for the solar charging circuit : https://www.circuits-diy.com/12-volt-solar-battery-charger-circuit/

Connections:

1.DHT11 sensor to the ESP32:
	-> VCC to 3.3V on ESP32
	-> GND to GND on ESP32
	-> Data to GPIO 4 on ESP32
2. wiring 
	-> VCC pin of the relay module to the 5V output of the ESP32 
	-> GND of the relay module to the GND of the ESP32.
	-> IN1 to digital GPIO pin 5 on the ESP32.
	-> positive terminal of the 12V DC battery to the NO (Normally Open) terminal of Relay 1.
	-> COM (Common) terminal of Relay 1 to the positive terminal of the Peltier module.
	-> negative terminal of the 12V battery directly to the negative terminal of the Peltier module.
 
Blynk Setup:
-> Create a new template in the Blynk app.
-> Add two labels for displaying the temperature and humidity readings.
-> Note the Template ID, Device Name, and Auth Token, and replace them in the code above.

Libraries for Arduino IDE:
-> DHT sensor library" by Adafruit
-> "Blynk" by Volodymyr Shymanskyy.

********************************************************************************************************************************************************************************************