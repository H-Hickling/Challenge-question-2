#include <Servo.h>
Servo servo1;  // 1st servo Left
Servo servo2;  // 2nd servo
Servo servo3; 
Servo servo4;



void setup() {
  servo1.attach(7);  // attach 1st servo to pin
  servo2.attach(3);  // attach 2nd servo
  servo3.attach(4);
  servo4.attach(6);
}

void loop() {

   //servo1.write(100);    // 1st servo to position 0-150
  // servo2.write(82); // 2nd servo to position 5(rest)-130(switch)
   //servo3.write(90); // 175-44 
   //servo4.write(81); // 180-57 cooked one

  servo1.write(0); // 1st servo to resting position, range, 0(resting)-150(toggle switch)(most left servo)
  servo2.write(5); // 2nd servo to resting position, range, 5-135
  servo3.write(100); //2nd servo to resting position, range,175-44 
  servo4.write(180); //2nd servo to resting position, range,180-57 cooked one (most right servo)
                         

}
