
//Temp sensor
  #include "DHT.h"     //DHT Sensor Library
  #define DHTPIN 2     //Digital pin connected to the DHT sensor
  #define DHTTYPE DHT11   // DHT 11 sensor
  DHT dht(DHTPIN, DHTTYPE);//pin 2, type DH11

//Switch
  int switchPin = 12;  // assign switch pin number
  int switchState = 0; // variable for reading the switch status

//ultrasonic sensor 
  const int trigPin = 9; // assign sensor pin number
  const int echoPin = 10;// assign sensor pin number
  long duration; // defines variable
  int distance;  // defines variable

//servos
  #include <Servo.h>// includes servo library
  Servo servo1;  // 1st servo (Left)
  Servo servo2;  // 2nd servo
  Servo servo3;  // 3rd servo
  Servo servo4;  // 4th servo (Right)
  int servoMap1 = 0; //defines variable for servo map value1
  int servoMap2 = 0; //defines variable for servo map value2
  int servoMap3 = 0; //defines variable for servo map value3
  int servoMap4 = 0; //defines variable for servo map value4



  
void setup() {
Serial.begin(9600);//start serial port

//temp sensor
  Serial.println(F("DHT11 test!"));
  dht.begin();

//Switch
  pinMode(switchPin, INPUT);// initialize switchPin as an input

//ultrasonic sensor 
  pinMode(trigPin, OUTPUT); // initialize trigPin as an Output
  pinMode(echoPin, INPUT); // initialize echoPin as an Input

//servos
  servo1.attach(7);  // assign servo1 pin number
  servo2.attach(3);  // assign servo2 pin number
  servo3.attach(4);  // assign servo3 pin number
  servo4.attach(6);  // assign servo4 pin number
}




void loop() {
  delay(50); // delay 
  
//temp sensor
  float t = dht.readTemperature();  // Read temperature as Celsius
  Serial.print(F("Temperature: "));//print text
  Serial.print(t);      //print tempreture value
  Serial.print(F("°C "));//print text
  if (isnan(t)) {      // Check if any tempreture reads failed and exit early (to try again)
    Serial.println(F("Failed to read from DHT sensor!"));
    return;}

//switch
  switchState = digitalRead(switchPin); // read the state of the switch value
  Serial.print(switchState);//displays switchState 1 or 0 in serial port
 
//ultrasonic sensor
  digitalWrite(trigPin, LOW); // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2; // Calculating the distance
  Serial.print("Distance: "); // Prints to Serial Monitor
  Serial.println(distance);

//servos
  //servo1.write(0); // 1st servo to resting position, range, 0(resting)-150(toggle switch)(most left servo)
  //servo2.write(5); // 2nd servo to resting position, range, 5-135
  //servo3.write(175); //2nd servo to resting position, range,175-44 
  //servo4.write(180); //2nd servo to resting position, range,180-57 (most right servo)


//servo 1 movement
  if (t<=16 && switchState == HIGH){// if temp is below 20 the switch has been flipped
    delay(500);//delay to allow user to move finger away
    servo1.write(160); //servo 1 switch return position
    servo2.write(5); //servo 2 base position
    servo3.write(175);//servo 3 base position
    servo4.write(180);//servo 4 base position
  }

  if (t<=16 && switchState == LOW){//if temp is below 20 and the switch is down
    Serial.print("SERVO1");
    servo2.write(5);  //servo 2 base position
    servo3.write(175);//servo 3 base position
    servo4.write(180);//servo 4 base position
    
    if (6<distance<100){// is ultrasonic reading is between 6 and 100
      servoMap1=map(distance,6,100,130,75);//mapping servo value to correct range compared to distance readings
    servo1.write(servoMap1);//servo position is determined by mapped value from distance
    //Serial.print(servoMap1);//used for checking value
    }
    if (distance<6){//is untrasonic reading is less than 6
    servo1.write(130);//servo 3 close to switch
    }
    if (distance>100){
      servo1.write(75);
    }
  }


//servo 2 movement
  if (16<t && t<=22 && switchState == HIGH){// if temp is between 20 and 25 and the switch has been flipped
    delay(500);//delay to allow user to move finger away
    servo1.write(0); //servo 1 base position
    servo2.write(135);//servo 2 switch return position
    servo3.write(175);//servo 3 base position
    servo4.write(180);//servo 4 base position
  }

  if (16<t && t<=22 && switchState == LOW){//if temp is between 20 and 25 and the switch is down
    Serial.print("SERVO2");
    servo1.write(0);  //servo 1 base position
    servo3.write(175);//servo 3 base position
    servo4.write(180);//servo 4 base position
    
    if (6<distance<100){// is ultrasonic reading is between 6 and 100
      servoMap2=map(distance,6,100,114,80);//mapping servo value to correct range compared to distance readings
    servo2.write(servoMap2);//servo position is determined by mapped value from distance
    //Serial.print(servoMap2);//used for checking value
    }
    if (distance<6){//is untrasonic reading is less than 6
    servo2.write(114);//servo 3 close to switch
    }
    if (distance>100){
      servo2.write(80);
    }
  }


//servo 3 movement
  if (22<t && t<=28 && switchState == HIGH){// if temp is between 25 and 30 and the switch has been flipped
    delay(500);//delay to allow user to move finger away
    servo1.write(0); //servo 1 base position
    servo2.write(5); //servo 2 base position
    servo3.write(40);//servo 3 switch return position
    servo4.write(180);//servo 4 base position
  }

  if (22<t && t<=28 && switchState == LOW){//if temp is between 25 and 30 and the switch is down
    Serial.print("SERVO3");
    servo1.write(0);  //servo 1 base position
    servo2.write(5);  //servo 2 base position
    servo4.write(180);//servo 4 base position
    
    if (6<distance<100){// is ultrasonic reading is between 6 and 100
      servoMap1=map(distance,6,100,60,100);//mapping servo value to correct range compared to distance readings
    servo3.write(servoMap1);//servo position is determined by mapped value from distance
    //Serial.print(servoMap1);//used for checking value
    }
    if (distance<6){//is untrasonic reading is less than 6
    servo3.write(60);//servo 3 close to switch
    }
    if (distance>100){
      servo3.write(100);
    }
  }


//servo 4 movement
  if (28<t && switchState == HIGH){// if temp is over 30 and the switch has been flipped
    delay(500);//delay to allow user to move finger away
    servo1.write(0); //servo 1 base position
    servo2.write(5); //servo 2 base position
    servo3.write(175);//servo 3 base position
    servo4.write(30);//servo 4 return switch position
  }

  if (28<t && switchState == LOW){//if temp is over 30 and the switch is down
    Serial.print("SERVO4");
    servo1.write(0);//servo 1 base position
    servo2.write(5);  //servo 2 base position
    servo3.write(175);  //servo 3 base position
    
    if (6<distance<100){// is ultrasonic reading is between 6 and 100
    servoMap4=map(distance,6,100,58,105);//mapping servo value to correct range compared to distance readings
    servo4.write(servoMap4);//servo position is determined by mapped value from distance
    //Serial.print(servoMap4);//used for checking value
    }
    if (distance<6){//is untrasonic reading is less than 6
    servo4.write(58);//servo 3 close to switch
    }
    if (distance>100){
      servo4.write(105);
    }
  }

}


  
