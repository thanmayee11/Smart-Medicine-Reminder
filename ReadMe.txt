# Smart Medicine Reminder

Smart Medicine Reminder using Arduino

In this project, we have used Arduino for hardware implementation and Android Studio for Android App.

## Prerequisites

What things you need to get for hardware implementation,install the software and how to install them:

1.Hardware Implementation

a) Hardware Requirements

Arduino Uno with USB cable - 1
RTC DS3231 module - 1
Buzzer(B-10) - 1
Breadboard - 1
Push Buttons - 4
Resistors(10K) - 4
Jumper wires 
Single stand wire 2mt

b)Software Requirements

Arduino IDE 1.8.10 - programmable platform for Arduino

2.Software Implementation(Android App)

Requirements :
 
Android Studio

### Hardware components description

1.Arduino Uno with USB cable - The Arduino Uno is an open-source microcontroller board based on the Microchip ATmega328P microcontroller and developed by Arduino.cc. The board is equipped with sets of digital and analog input/output (I/O) pins that may be interfaced to various expansion boards (shields) and other circuits.
USB establishes the connection between Arduino board and Computer.

2.RTC DS3231 module - DS3231 Module is a Bread Board friendly extremely precise I²C real time clock Module.

3.Buzzer - A buzzer is an audio signaling device.For giving the Reminder it produces a alarm sound.

4.Breadboard - A Breadboard used to build and test circuits quickly before finalizing any circuit design.

5.Push Button - In our project three push buttons are used for setting the multiple reminders like to set reminder once/day,Twice/day and Thrice/day and the  fourth push button is for stopping the buzzer sound.

6.Resistors - Commonly used in breadboards and perf boards, these 10K resistors make excellent pull-ups, pull-downs, and current limiters.

7.Jumper wires - A jump wire is an electrical wire, or group of them in a cable, with a connector or pin at each end, which is normally used to interconnect the components of a breadboard.

8.Single stand wire - Single stand wire, also called Solid wire, consists of one piece of metal wire. Solid wire is useful for wiring breadboards.

#### File description - Project Code

1.Arduino software
This file contains the Arduino code, after giving all conections in breadboard and in Arduino board ,we can run this code.

2.Android App
This file contains the Android App building files with the source code.

##### Installing and steps to run the project

**Arduino**

1.The first step would be getting the hardware components and the make connections accordingly. 

2.Install Arduino IDE 1.8.10
You can download Arduino IDE from here : https://www.arduino.cc/en/software

3.Open Arduino IDE get the code from Arduino software file and download the RTC DS3231 library from the github and import it in Arduino IDE using these steps : Sketch(at the top)->include library .Here add that RTC zip file that you have downloaded.
Set the time and date in this line of code - rtc.adjust(DateTime(year, month, day, HH, MM, SS)) and set the buzzer time at what time you need to get reminder in this line of - int buzz8amHH = 8;int buzz8amMM = 30;int buzz8amSS = 00;
Then we can verify our code using verify button and then use upload button to run the code.And at right we can find the serial monitor button click on it,the ouput will be displayed in the serial monitor.After opening serial monitor we can see the printed statements that we have given in the code.And it asks for press push buttons for the reminders with respect to the how many reminders you want.
It will display Date and the time for every one second,when the current time is matches with the setted reminder time ,it will display as "Time to take Morning Medicines" for one reminder and also you will get a buzzer sound.

**Android App**

1.Install the Android studio

2.From Android App file you can get the code and implement the App

Use Cases and What Each Button Does:

In the Home page, you will see 1 buttons in the bottom right of the application. 
*Plus sign: This will take you to the Add Activity where you will be able to create an alarm. The application will automatically link up all the alarms to a specific pill with the same Pill Name. If you attempt to create an alarm to a pill that does not exist, it will automatically create a pill object for you. 
*Calendar sign: This will take you to the Schedule Activity where you can see all the pills and alarms organized by the day of week.



 