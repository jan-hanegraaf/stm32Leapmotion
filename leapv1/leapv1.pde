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
  int locX = (int)stabilizedPosition.getX();
  if(locX <-250){
    locX=0;
  }
  int locZ = (int)stabilizedPosition.getZ();
    if(locZ <-250){
    locX=0;
  }
  int locXBounds = (int)map(locX, -250, 250, 0, 127);
  int locZBounds = (int)map(locZ, -250, 250, 0, 63);
  String locationX="";
  String locationZ="";
  if (locXBounds%10 != locXBounds)
  locationX = "00" + locXBounds;
    if (locXBounds%100 != locXBounds)
  locationX = "0" + locXBounds;
    if (locXBounds%1000 != locXBounds)
  locationX =""+locXBounds;
   if (locXBounds==0)
  locationX ="00"+locXBounds;
  
    if (locZBounds%10 != locZBounds)
  locationZ = "00" + locZBounds;
    if (locZBounds%100 != locZBounds)
  locationZ = "0" + locZBounds;
    if (locZBounds%1000 != locZBounds)
  locationZ =""+locZBounds;
  if (locZBounds==0)
  locationX ="00"+locZBounds;
  text( locationX+locationZ+"zone", 50, 200 );
  myPort.write(locationX+locationZ);
  delay(20);
}
