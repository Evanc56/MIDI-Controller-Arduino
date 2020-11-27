This repository contains the Arduino code for my MIDI jog wheel.

The EvansController file is the main file that imports libraries and creates instances of the rotary encoder and capacitance sensor using the imported libraries. It constantly loops the readCapacitance and readRotation functions, and creates the MIDI messages that are sent out of the controller to be received by a serial to MIDI converter program.

The readCapacitance function senses if anything is touching the capacitive sensor on the jog wheel, and sends a MIDI message containing a button press or button release whenever the device is touched or released.

The readRotation function senses the rotary encoder's raw displacement over a set interval, and uses it to calculate the wheel’s rotational velocity. Based on the velocity, the correct MIDI message is sent to indicate the speed and direction of the wheel’s rotation.

Developed by:
Evan Costello, Matthew Miceli, and Dylan Larkin
