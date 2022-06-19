#include <MIDI.h>
#include "tabsToValue.h"
#include "combinations.h"
#include <ShiftRegister74HC595.h>

ShiftRegister74HC595<3> sr(11, 9, 10);

MIDI_CREATE_INSTANCE(HardwareSerial,Serial, midiOut); // create a MIDI object called midiOut

boolean pistons_mode = false;

//Combinations rows
const int acc_row = 0;
const int great_row1 = 13;
const int great_row2 = 12;
//const int solo_row = ;
//const int effects_row = ;

//rows (J 1 to 6 = PD2 to PD7)
const int row1 = 2; 
const int row2 = 3;
const int row3 = 4;
const int row4 = 5;
const int row5 = 6;
const int row6 = 7;
const int row7 = 8;

unsigned int keyToMidiMap[127];

boolean pistonPressed[72];
boolean keyPressed[127];
boolean keyPressed2[127];


void setup() {
  
  // Map scan matrix of tabs.
  keyToMidiMap[0] = 1;
  keyToMidiMap[1] = 2;
  keyToMidiMap[2] = 3;
  keyToMidiMap[3] = 4;
  keyToMidiMap[4] = 5;
  keyToMidiMap[5] = 6;
  keyToMidiMap[6] = 7;
  keyToMidiMap[7] = 8;
  keyToMidiMap[8] = 9;
  keyToMidiMap[9] = 10;
  keyToMidiMap[10] = 11;
  keyToMidiMap[11] = 12;
  keyToMidiMap[12] = 13;
  keyToMidiMap[13] = 14;
  keyToMidiMap[14] = 15;
  keyToMidiMap[15] = 16;
  keyToMidiMap[16] = 17;
  keyToMidiMap[17] = 18;
  keyToMidiMap[18] = 19;
  keyToMidiMap[19] = 20;
  keyToMidiMap[20] = 21;
  keyToMidiMap[21] = 22;
  keyToMidiMap[22] = 24;
  keyToMidiMap[23] = 25;

  keyToMidiMap[24] = 26;
  keyToMidiMap[1+24] = 27;
  keyToMidiMap[2+24] = 28;
  keyToMidiMap[3+24] = 29;
  keyToMidiMap[4+24] = 30;
  keyToMidiMap[5+24] = 31;
  keyToMidiMap[6+24] = 32;
  keyToMidiMap[7+24] = 33;
  keyToMidiMap[8+24] = 34;
  keyToMidiMap[9+24] = 35;
  keyToMidiMap[10+24] = 36;
  keyToMidiMap[11+24] = 37;
  keyToMidiMap[12+24] = 38;
  keyToMidiMap[13+24] = 39;
  keyToMidiMap[14+24] = 40;
  keyToMidiMap[15+24] = 41;
  keyToMidiMap[16+24] = 42;
  keyToMidiMap[17+24] = 44;
  keyToMidiMap[18+24] = 45;
  keyToMidiMap[19+24] = 46;
  keyToMidiMap[20+24] = 47;
  keyToMidiMap[21+24] = 48;
  keyToMidiMap[22+24] = 49;
  keyToMidiMap[23+24] = 50;


  keyToMidiMap[48] = 51;
  keyToMidiMap[1+48] = 52;
  keyToMidiMap[2+48] = 53;
  keyToMidiMap[3+48] = 54;
  keyToMidiMap[4+48] = 55;
  keyToMidiMap[5+48] = 56;
  keyToMidiMap[6+48] = 57;
  keyToMidiMap[7+48] = 58;
  keyToMidiMap[8+48] = 59;
  keyToMidiMap[9+48] = 60;
  keyToMidiMap[10+48] = 61;
  keyToMidiMap[11+48] = 62;
  keyToMidiMap[12+48] = 63;
  keyToMidiMap[13+48] = 64;
  keyToMidiMap[14+48] = 65;
  keyToMidiMap[15+48] = 66;
  keyToMidiMap[16+48] = 67;
  keyToMidiMap[17+48] = 68;
  keyToMidiMap[18+48] = 69;
  keyToMidiMap[19+48] = 70;
  keyToMidiMap[20+48] = 71;
  keyToMidiMap[21+48] = 72;
  keyToMidiMap[22+48] = 73;
  keyToMidiMap[23+48] = 74;

  keyToMidiMap[72] = 75;
  keyToMidiMap[1+72] = 76;
  keyToMidiMap[2+72] = 77;
  keyToMidiMap[3+72] = 78;
  keyToMidiMap[4+72] = 79;
  keyToMidiMap[5+72] = 80;
  keyToMidiMap[6+72] = 81;
  keyToMidiMap[7+72] = 82;
  keyToMidiMap[8+72] = 83;
  keyToMidiMap[9+72] = 84;
  keyToMidiMap[10+72] = 85;
  keyToMidiMap[11+72] = 86;
  keyToMidiMap[12+72] = 87;
  keyToMidiMap[13+72] = 88;
  keyToMidiMap[14+72] = 89;
  keyToMidiMap[15+72] = 90;
  keyToMidiMap[16+72] = 91;
  keyToMidiMap[17+72] = 92;
  keyToMidiMap[18+72] = 93;
  keyToMidiMap[19+72] = 94;
  keyToMidiMap[20+72] = 95;
  keyToMidiMap[21+72] = 96;
  keyToMidiMap[22+72] = 97;
  keyToMidiMap[23+72] = 98;

    keyToMidiMap[96] = 99;
  keyToMidiMap[1+96] = 100;
  keyToMidiMap[2+96] = 101;
  keyToMidiMap[3+96] = 102;
  keyToMidiMap[4+96] = 103;
  keyToMidiMap[5+96] = 104;
  keyToMidiMap[6+96] = 105;
  keyToMidiMap[7+96] = 106;
  keyToMidiMap[8+96] = 107;
  keyToMidiMap[9+96] = 108;
  keyToMidiMap[10+96] = 109;
  keyToMidiMap[11+96] = 110;
  keyToMidiMap[12+96] = 111;
  keyToMidiMap[13+96] = 112;
  keyToMidiMap[14+96] = 113;
  keyToMidiMap[15+96] = 114;
  keyToMidiMap[16+96] = 115;
  keyToMidiMap[17+96] = 116;
  keyToMidiMap[18+96] = 117;
  keyToMidiMap[19+96] = 118;
  keyToMidiMap[20+96] = 119;
  keyToMidiMap[21+96] = 120;
  keyToMidiMap[22+96] = 121;
  keyToMidiMap[23+96] = 122;

      keyToMidiMap[120] = 123;
  keyToMidiMap[1 + 120] = 124;
  keyToMidiMap[2 + 120] = 125;
  keyToMidiMap[3 + 120] = 126;
  keyToMidiMap[4 + 120] = 127;
  keyToMidiMap[5 + 120] = 0;

 delay(1000);

  pinMode(row1, INPUT);
  pinMode(row2, INPUT);
  pinMode(row3, INPUT);
  pinMode(row4, INPUT);
  pinMode(row5, INPUT);
  pinMode(row6, INPUT);
  pinMode(row7, INPUT);

  pinMode(acc_row, INPUT);
  pinMode(great_row1, INPUT);
  pinMode(great_row2, INPUT);

    delay(1000);
    Serial.begin(31250);
    delay(1000);

}

void pull_in_accomp(){
  for(int i = 0; i< sizeof(accomp_stops); i++){
    midiOut.sendControlChange(81, accomp_stops[i], 16);
  }
  //Exceptions (ex. put trems here AND switches that are not controlled by pistons)
  //put control number in {}, deliminate next elements with 


  //if some stops are off on 82 just add them here manually
  /*
  int exceptions[] = {17, 14, 12, 15, 10, 19, 22, 21, 25, 18, 8, 7, 6, 5};  //in my case: trems, couplers, pdedals2t.
  int except_size = sizeof(exceptions);

  for(int i = 0; i < except_size; i++){
    midiOut.sendControlChange(81, exceptions[i], 16);
  }
  */
}


void pull_in_great(){
  for(int i = 0; i< sizeof(great_stops); i++){
    midiOut.sendControlChange(81, great_stops[i], 16);
  }

}



void expression(){
    int solo=analogRead(A0);
    int main=analogRead(A1);
    int cres=analogRead(A2);
    
    midiOut.sendControlChange(11,solo,15); 
    midiOut.sendControlChange(7, main,15); 
    midiOut.sendControlChange(8, cres, 15);
}

void manual_tabs(){
 for (int col = 0; col < 24; col++){

  sr.setAllLow();
  delay(10);
  sr.set(col, HIGH);
    
    // check if any stops were pressed - rows will have HIGH output in this case corresponding
    int groupValue1 = digitalRead(row1);
    int groupValue2 = digitalRead(row2);
    int groupValue3 = digitalRead(row3);
    int groupValue4 = digitalRead(row4);
    int groupValue5 = digitalRead(row5);
    int groupValue6 = digitalRead(row6);
    int groupValue7 = digitalRead(row7);
    
    if (groupValue1 != 0 || groupValue2 != 0 || groupValue3 != 0
        || groupValue4 != 0 || groupValue5 !=0 || groupValue6 !=0 || groupValue7 !=0) {

      if (groupValue1 != 0 && !keyPressed[col]) {
        keyPressed[col] = true;
        midiOut.sendControlChange(81,keyToMidiMap[col],16);
      }

      if (groupValue2 != 0 && !keyPressed[col + 24]) {
        keyPressed[col + 24] = true;
        midiOut.sendControlChange(81,keyToMidiMap[col + 24],16);
      }

      if (groupValue3 != 0 && !keyPressed[col + 48]) {
        keyPressed[col + 48] = true;
         midiOut.sendControlChange(81,keyToMidiMap[col + 48],16);
      }

      if (groupValue4 != 0 && !keyPressed[col + 72]) {
        keyPressed[col + 72] = true;
          midiOut.sendControlChange(81,keyToMidiMap[col + 72],16);
      }
        if (groupValue5 != 0 && !keyPressed[col + 96]) {
        keyPressed[col + 96] = true;
          midiOut.sendControlChange(81,keyToMidiMap[col + 96],16);
      }
        if (groupValue6 != 0 && !keyPressed2[col + 48]) {
        keyPressed2[col + 48] = true;
          midiOut.sendControlChange(83,keyToMidiMap[col + 48],16);
      }

        if (groupValue7 != 0 && !keyPressed2[col + 72]) {
        keyPressed2[col + 72] = true;
          midiOut.sendControlChange(83,keyToMidiMap[col + 72],16);
      }
      
        
    }


    //  process if any combination of keys released
    if (groupValue1 == 0 && keyPressed[col]) {
      keyPressed[col] = false;
      midiOut.sendControlChange(80,keyToMidiMap[col],16);
    }

    if (groupValue2 == 0 && keyPressed[col + 24]) {
      keyPressed[col + 24] = false;
      midiOut.sendControlChange(80,keyToMidiMap[col + 24],16);
    }

    if (groupValue3 == 0 && keyPressed[col + 48]) {
      keyPressed[col + 48] = false;
      midiOut.sendControlChange(80,keyToMidiMap[col + 48],16);
    }

    if (groupValue4 == 0 && keyPressed[col + 72]) {
      keyPressed[col + 72] = false;
      midiOut.sendControlChange(80,keyToMidiMap[col + 72],16);
    }

     if (groupValue5 == 0 && keyPressed[col + 96]) {
      keyPressed[col + 96] = false;
      midiOut.sendControlChange(80,keyToMidiMap[col + 96],16);
    }

     if (groupValue6 == 0 && keyPressed2[col + 48]) {
      keyPressed2[col + 48] = false;
      midiOut.sendControlChange(82,keyToMidiMap[col + 48],16);
    }
    
     if (groupValue7 == 0 && keyPressed2[col + 72]) {
      keyPressed2[col + 72] = false;
      midiOut.sendControlChange(82,keyToMidiMap[col + 72],16);
    }

    }
}

void pistons_Tabs_acc(){
   for (int col = 0; col < 24; col++) {
    sr.setAllLow();
    delay(10);
    sr.set(col, HIGH);
    int pistons_acc = digitalRead(acc_row);

    //Check if combination buttons on accomp were pressed
    if (pistons_acc != 0){
      pull_in_accomp();  //disable current stops on accomp division
      pistons_mode = true;      //add pistons mode _acc _grt?
      
      if (pistons_acc !=0 && !pistonPressed[col]){
        pistonPressed[col] = true;
        switch(col){
          case 1:{
            //int general_1[] = {bourdon_16_acc, diapason_8_acc};
            int general_1size = sizeof(general_1);
             for(int i = 0; i < general_1size; i++){
              midiOut.sendControlChange(81, general_1[i], 16);     //potential bug? IF there is problem with old scombination staying on after new is pressed withouth releasing to main code, add pull in EACH case
             }
            break;
        }
          case 2:{
            //int general_1[] = {bourdon_16_acc, diapason_8_acc};
            int general_1size = sizeof(general_1);
             for(int i = 0; i < general_1size; i++){
              midiOut.sendControlChange(81, general_1[i], 16);
             }
            break;
        }        
          case 3:{
            //int general_1[] = {bourdon_16_acc, diapason_8_acc};
            int general_1size = sizeof(general_1);
             for(int i = 0; i < general_1size; i++){
              midiOut.sendControlChange(81, general_1[i], 16);
             }
            break;
        }
          case 4:{
            //int general_1[] = {bourdon_16_acc, diapason_8_acc};
            int general_1size = sizeof(general_1);
             for(int i = 0; i < general_1size; i++){
              midiOut.sendControlChange(81, general_1[i], 16);
             }
            break;
        }
          case 5:{
            //int general_1[] = {bourdon_16_acc, diapason_8_acc};
            int general_1size = sizeof(general_1);
             for(int i = 0; i < general_1size; i++){
              midiOut.sendControlChange(81, general_1[i], 16);
             }
          }
            break;
          case 6:{
            pistons_mode = false; //return to manlual switching of tabs.
            break;
          }
         

               
      }
      
      
     }
    }


 }
}


void loop() 
{
  //pcheck if any comnination piston was pressed, code will stuck in piston_Tabs() untill mode button is pressed
  //pistons_tabs changes boolean pistons_mode to false if mode button is pressed. If there is problem try decloaring piston_Tabs as an bool not void and return the mode at the end
  pistons_Tabs_acc();
 // pistons_Tabs_grt();  //there might be problem with other divisions not working if any mode in entered, solution: clean and divide everything into divisions including manual tabs - lots of work.
 //Solution of last rtesort treat each piston as a general combination for the whole organ - not that bad anyway.

  
  if(pistons_mode = false){
    manual_tabs();
  }

 
}
