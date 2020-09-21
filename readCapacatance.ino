void readCapacatance() {

  sensorVal = wheelTap.capacitiveSensor(30);
 
  if (sensorVal >1000) {
    buttonstate = 1;
  } 
  else {
    buttonstate = 0;  
  }

if (buttonstate != prevbuttonstate) {
  if (buttonstate == 1) {
    MIDImessage(noteON, 49, velocity);
  } 
  else {
    MIDImessage(noteOFF, 49, velocity);
  }
}

prevbuttonstate = buttonstate;

}
