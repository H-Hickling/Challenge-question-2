int switchPin = 12;          // the number of the switch pin

int switchState = 0;         // variable for reading the switch status

void setup() {

     
     pinMode(switchPin, INPUT);             // initialize the pushbutton pin as an input:
     Serial.begin(9600);
}

void loop() {

      switchState = digitalRead(switchPin); // read the state of the pushbutton value
      if (switchState == HIGH) {            // if the buttonState is HIGH turn LED on, might now work, try switchstate= 0 ir 1
      }

      Serial.print(switchState);//displays 1 or 0 in serial port
}
