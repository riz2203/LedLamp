# ledLamp
Simulation for software to control a simple LED based bicycle lamp.

Design the software to control a simple LED based bicycle lamp. There are 2 buttons on the lamp. Button 1 switches the lamp from off to on red. Pressing Button 1 a second time causes the lamp to flash red. Pressing button 1 a third time switches the lamp to off. Pressing button 2 toggles the colour of the lamp from red to white or white to red.

1. Assumption 1 - Lamp is Off to start with!
2. Assumption 2 - Pressing button 2 while lamp is off has no effect!
3. Assumption 3 - LED driver has the following APIs:redOn(), RedFlash(), ledOff(), whiteOn(), WhiteFlash()

## How to build
To build executable run ./build.sh.
You need gtest-dev rpm to be installed before building it. This application uses google test for automated unit testing.
This will create ledLamp.

## How to run

### Run as a console app with CLI to enter 1 for button1 push effects and 2 for button2 push effects.
./ledLamp
 
Enter 1 to simulate button1 push, 2 for button2 push. Any other key to quit.

### Run for automated testing
./ledlamp test

## Design

The solution is based on std::map which stored function pointers for LED Driver APIs. The key to this map 
is LED Lamp's Button1 and Button2 states.

When Button1 push first time, its state changed from 0 to 1, when it pushed second time state changed from 1 to 2, and
when it pushed 3rd time it state changed from 2 to 0, that is reset back to 0 state.

For Button1 the following are the valid states:
|State (int)|meaning  |
|-----------|---------|
| 0         | Off     |
| 1         | On      |
| 2         | Flashing|

Button2 can have only 2 states when it pushed. Its state toggle from 0 (Red) to 1(white). When Button1 is in Off state, Button1 state reset back to 0.

For Button2 the following are the valid states:
|State (int)|meaning  |
|-----------|---------|
| 0         | Red     |
| 1         | White   |

Based on above states tables combination, std::map would have following possible states->functions mapping:

|Button1 state|Button2 state|LED Lamp       |
|-------------|-------------|---------------|
|0            |0            |Off            |
|0            |1            |Off            |
|1            |0            |Red            |
|1            |1            |White          |
|2            |0            |Red Flashing   |
|2            |1            |White Flashing |


**Note:** The automated test cases are based on googletest. You need to install gtest-dev to compile this application.
