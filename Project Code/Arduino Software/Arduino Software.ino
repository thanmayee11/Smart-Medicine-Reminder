#include <Wire.h>
#include <RTClib.h>
#include <EEPROM.h>

RTC_DS3231 rtc;

int buzz = 13;
int addr=17;

int buttonPin2 = 9;
int buttonPin3 = 8;
int buttonPin1 = A0;
int buttonPin4 = 7; // the pin that the pushbutton is attached to
int val2 = 0;
int val3=0;
int pushVal;
int bS1 = 0;         // current state of the button
int lBS1 = 0;     // previous state of the button


int bS2 = 0;         // current state of the button
int lBS2 = 0;

int bS3 = 0;         // current state of the button
int lBS3 = 0;

int bS4 = 0;         // current state of the button
int lBS4 = 0;

// configure the pins to the right mode
int buzz11amHH = 11;          //    HH - hours         ##Set these for reminder time in 24hr Format 
int buzz11amMM = 30;          //    MM - Minute
int buzz11amSS = 00;         //     SS - Seconds

int buzz3pmHH = 03;          //    HH - hours
int buzz3pmMM = 17;          //    MM - Minute
int buzz3pmSS = 00;          //    SS - Seconds

int buzz20pmHH = 20;          //    HH - hours
int buzz20pmMM = 40;          //    MM - Minute
int buzz20pmSS = 00;          //    SS - Seconds

 

int nowHr, nowMin, nowSec; 

void gwsMessege(){               // print get well soon messege
    Serial.print("Stay Healthy :)\n");     
    Serial.print("Get Well Soon :)\n");
}

void helpScreen() {              
    Serial.print("Press Buttons\n");
    Serial.print("for Reminder...!\n");
 }

void timeScreen() {              // function to display Date and time
  DateTime now = rtc.now();             // take rtc time and print in display
    Serial.print("Time:");
    Serial.println(nowHr = now.hour(), DEC);
    Serial.print(":");
    Serial.println(nowMin = now.minute(), DEC);
    Serial.print(":");
    Serial.println(nowSec = now.second(), DEC);
    
    Serial.print("Date: ");
    Serial.println(now.day(), DEC);
    Serial.print("/");
    Serial.println(now.month(), DEC);
    Serial.print("/");
    Serial.println(now.year(), DEC);
    delay(500);
}

void setup()
{
  Serial.begin(9600);
  rtc.begin();
  Serial.print("Welcome To\n");                                      // print a messege at startup
  Serial.print("Medicine Reminder\n");
  delay(1000);
  gwsMessege();
  delay(3000);
  helpScreen();
  delay(2000);
  timeScreen();
  delay(3000);
   
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buzz, OUTPUT);
  {
  Wire.begin();
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));            // uncomment this to set the current time and then comment in next upload when u set the time
    rtc.adjust(DateTime(2021, 12, 30, 03, 16, 00));   // manual time set
}
}

void ValSet(){
  Serial.println(EEPROM.read(addr));
  val2 = EEPROM.read(addr);                         // read previosuly saved value of push button to start from where it was left previously
  switch (val2) {
    case 1:
    Serial.print("Reminder set ");
    Serial.print("for Once/day !\n");
      pushVal = 1;
      delay(500);
      break;
    case 2:
    Serial.print("Reminder set ");
    Serial.print("for Twice/day !\n");
      pushVal = 2;
      delay(500);
      break;
    case 3:
    Serial.print("Reminder set ");
    Serial.print("for Thrice/day !\n");
      pushVal = 3;
      delay(500);
      break;
  }
}

// the main loop will constantly check to see if the button has been pressed
// if it has, a counter is incremented, and then some action can be taken
void loop() 
{                                         //call to set thrice/day 
    if (pushVal == 1) {                                // if push button 1 pressed then remind at 8am
    at11am();                                           //function to start uzzing at 8am 
  }
  else if (pushVal == 2) {                             // if push button 2 pressed then remind at 8am and 8pm
    at11am();                                            
    at20pm();                                           //function to start uzzing at 8mm
  }
  else if (pushVal == 3) {                             // if push button 3 pressed then remind at 8am and 8pm
    at11am();
    at3pm();                                            //function to start uzzing at 8mm
    at20pm();
  }
  // read the state of the button
  bS1 = digitalRead(buttonPin1);
  bS2 = digitalRead(buttonPin2);
  bS3 = digitalRead(buttonPin3);
  bS4 = digitalRead(buttonPin4);

  // check to see if it different than the last time we checked
  

if (bS2 != lBS2) {
    // either the button was just pressed or just released
    if (bS2 == HIGH) {
      // it was just pressed
      Serial.println("n02");
      EEPROM.write(17,1);
      push1();
      delay(1000);
    }
  }
  lBS2 = bS2;


if (bS3 != lBS3) {
    // either the button was just pressed or just released
    if (bS3 == HIGH) {
      // it was just pressed
      Serial.println("no3");
      EEPROM.write(17,2);
      push2();
      delay(1000);
    }
  }
  lBS3 = bS3;


if (bS4 != lBS4) {
    // either the button was just pressed or just released
    if (bS4 == HIGH) {
      // it was just pressed
      Serial.println("no4");
      EEPROM.write(17,3);
      push3();
      delay(1000);
    }
  }
  lBS4 = bS4;
  
if (bS1 != lBS1) {
    // either the button was just pressed or just released
    if (bS1 == HIGH) {
      val3=EEPROM.read(addr);
      EEPROM.write(17,0);
      digitalWrite(buzz, LOW);
      pinstop();
      EEPROM.write(17,val3);
    }
  }
  lBS1 = bS1;

  timeScreen();
  ValSet();
}
void push1() {                   // function to set reminder once/day                                           //save the state of push button-1 
    Serial.print("Reminder set ");
    Serial.print("for Once/day !\n");
    delay(1200);
    
  }

void push2() {                      //function to set reminder twice/day
    Serial.print("Reminder set ");
    Serial.print("for Twice/day !\n");
    delay(1200);
    
  }

void push3() {                    //function to set reminder thrice/day
    Serial.print("Reminder set ");
    Serial.print("for Thrice/day !\n");
    delay(1200);
    
  }

void pinstop(){                   //function to stop buzzing when user pushes stop push button
    Serial.print("Take Medicine  ");
    Serial.print("with Warm Water");
    delay(5000);
    
  }
void at11am() {                      // function to start buzzing at 8am
  DateTime t = rtc.now();
  if (int(t.hour()) == buzz11amHH && int(t.minute()) == buzz11amMM  && (int(t.second()) == buzz11amSS || int(t.second()) < buzz11amSS+10)) {
        /////////////////////////////////////////////////////
        digitalWrite(buzz,HIGH);
        Serial.print("Time to take ");
        Serial.print("Morning medicines.");
        delay(5000);

        /////////////////////////////////////////////////////
      }
}

void at3pm() {                          // function to start buzzing at 2pm
  DateTime t = rtc.now();
  if (int(t.hour()) == buzz3pmHH && int(t.minute()) == buzz3pmMM  && (int(t.second()) == buzz3pmSS || int(t.second()) < buzz3pmSS+10)) {
        /////////////////////////////////////////////////////
        digitalWrite(buzz,HIGH);
        Serial.print("Time to take ");
        Serial.print("Afternoon medicines.");
        delay(5000);

        /////////////////////////////////////////////////////
      }
}

void at20pm() {                           // function to start buzzing at 8pm
DateTime t = rtc.now();
  if (int(t.hour()) == buzz20pmHH && int(t.minute()) == buzz20pmMM  && (int(t.second()) == buzz20pmSS || int(t.second()) < buzz20pmSS+10)) {
        /////////////////////////////////////////////////////
        digitalWrite(buzz,HIGH);
        Serial.print("Time to take ");
        Serial.print("Night medicines.");
        delay(5000);

        /////////////////////////////////////////////////////
      }
}
