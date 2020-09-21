# MIDI-Controller-Arduino
This repository contains the Arduino code for my custom MIDI jog wheel

The EvansController file is the main file that imports libraries and creates instances of the rotary encoder and capacitance sensor using the imported libraries.
It constantly loops the readCapacitance and readRotation functions, and creates the MIDI messages that are sent out of the controller. 

The readCapacitance function senses if anything is touching the capacative sensor on the jog wheel, and sends a MIDI message containing a button press or button relase whenever 
the device is touched or relased.

The readRotation function senses the rotary encoder's raw displacement over a set interval, and uses it to calculate the wheels rotational velocity.
Based on the velocity, the correct MIDI message is sent to indicate the speed and direction of the wheels rotation.
