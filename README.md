# automatic-dustbin

**How to connect hardware:**

* **Ultrasonic Sensor (HC-SR04)with arduino uno**
  
 ultrasonic sensor → arduino
 
 	     * VCC → 3V3
 	     * GND → GND
 	     * Trig → Pin 9
  	     * Echo → Pin 10

* **Servo Motor with arduino uno**
  
     Servo → arduino uno
  * Signal → Pin 5
  * VCC → 5V (or external power if high torque)
  * GND → Common GND with Arduino

This code will:

* Measure distance using the ultrasonic sensor.
* If something is within 20 cm, it will open the dustbin lid for 2 seconds, then close it.
