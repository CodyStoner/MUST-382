//Cody Stoner
//MUST 382
//BANANA Drums set thing

#include <MIDI.h>

const int FLEX_PIN1 = A0; // Pin connected to voltage divider output
const int FLEX_PIN2 = A1;
const int FLEX_PIN3 = A2;
const int FLEX_PIN4 = A3;
// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor


// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 40000.0; // resistance when straight
//const float STRAIGHT_RESISTANCE = 28000.0;
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg
int note = 0;

void setup() 
{
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
  pinMode(FLEX_PIN3, INPUT);
  pinMode(FLEX_PIN4, INPUT);
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC1 = analogRead(FLEX_PIN1);
  int flexADC2 = analogRead(FLEX_PIN2);
  int flexADC3 = analogRead(FLEX_PIN3);
  int flexADC4 = analogRead(FLEX_PIN4);
  float flexV1 = flexADC1 * VCC / 1023.0;
  float flexR1 = R_DIV * (VCC / flexV1 - 1.0);
  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle1 = map(flexR1, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0); //BANANA 4
                   
  float flexV2 = flexADC2 * VCC / 1023.0;
  float flexR2 = R_DIV * (VCC / flexV2 - 1.0);                 
  float angle2 = map(flexR2, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0); //BANANA 2
                   
  float flexV3 = flexADC3 * VCC / 1023.0;
  float flexR3 = R_DIV * (VCC / flexV3 - 1.0);                 
  float angle3 = map(flexR3, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0); //BANANA 3
                   
  float flexV4 = flexADC4 * VCC / 1023.0;
  float flexR4 = R_DIV * (VCC / flexV4 - 1.0);
  float angle4 = map(flexR4, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0); //BANANA 1

  if(angle1>30)   //BANANA 4    CLOSED HIHAT
    MIDI.sendNoteOn(80, 127, 1); 
  else
    MIDI.sendNoteOff(80,127,1);
  
  if(angle2>30)   //BANANA 2  KICKER
    MIDI.sendNoteOn(80, 127, 2); 
  else
    MIDI.sendNoteOff(80,127,2);

   if(angle3>30)   //BANANA 3   SNARE MARCH
    MIDI.sendNoteOn(100, 127, 3); 
  else
    MIDI.sendNoteOff(100,127,3);

  if(angle4>30)    //BANANA 1    KICK POWER
    MIDI.sendNoteOn(20, 127, 4);  
  else
    MIDI.sendNoteOff(20,127,4);  

}


  

  
