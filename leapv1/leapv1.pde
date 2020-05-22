import com.leapmotion.leap.*;
import processing.serial.*;

Controller controller = new Controller();

Serial myPort;  
void setup(){
  size( 200, 200 );
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw(){
  background(0);
  Frame frame = controller.frame();
  text( frame.hands().count() + " Hands", 50, 50 );
  text( frame.fingers().count() + " Fingers", 50, 100 );
  HandList hands = frame.hands();

Pointable pointable = frame.pointables().frontmost();
Vector stabilizedPosition = pointable.stabilizedTipPosition();//Finger frontFinger = hand.fingers().frontmost();
  text( stabilizedPosition+"zone", 50, 150 );
  
  myPort.write(stabilizedPosition+"");
  delay(20);
}
