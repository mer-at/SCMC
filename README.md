# SCMC
Star Citizen Mining Controller

Basic 1 Axis 3 Button USB Joystick.

you need:
1x Arduino Micro Pro <10€
1x Bourns PTL60-15G1-103B2 (Sliding Potentiometer with LED) < 3€
3x Keyboard Keys (afaik i used Gateron Blacks) < 2€ for 10 pieces
+ some cables
+ 1 micro USB cable to connect the Arduino to your PC
This custom library https://github.com/MHeironimus/ArduinoJoystickLibrary

You can use any other Sliding Potentiometer as well, just make sure you use a linear one, and not some logarithmic one (they are used for audio applications).

Connect the wires, install the Joystick Library, flash the code with Arduino IDE. And it should work.

![Alt text](/Schematic.png?raw=true "schematic")
