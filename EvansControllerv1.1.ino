
#include <MIDI.h>
#include <CapacitiveSensor.h>
#include <AS5600.h>

CapacitiveSensor   wheelTap = CapacitiveSensor(2,4); 
int velocity = 100;//velocity of MIDI notes, must be between 0 and 127
 //higher velocity usually makes MIDI instruments louder
int noteON = 144;//144 = 10010000 in binary, note on command
int noteOFF = 128;//128 = 10000000 in binary, note off command

int buttonstate = 0;
int prevbuttonstate = 0;
int sensorVal = 0;

AS5600 encoder;
int angle = 0;
int lastAngle = 0;
int diff = 12;
int anglediff =0;
int w = 0;

void setup() {
  //start serial connection
  Serial.begin(115200);
 wheelTap.set_CS_AutocaL_Millis(200000);
}

void loop() {
readCapacatance();
readRotation();

}
void MIDImessage(byte status, byte MIDInote, byte MIDIvelocity)
{
  Serial.write(status);//send note on or note off command 
  Serial.write(MIDInote);//send pitch data
  Serial.write(MIDIvelocity);//send velocity data
}
