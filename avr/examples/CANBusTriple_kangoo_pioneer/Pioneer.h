#ifndef Pioneer_H
#define Pioneer_H

#include "DigiPot.h"

#define SLEEVE_COUPLER A5
#define ESCAPE_RESISTOR A4

DigiPot dp = DigiPot();

class Pioneer
{
  public:
    void begin();
    void source();
    void mute();
    void displayInfo();
    void nextTrack();
    void previousTrack();
    void volumeUp();
    void volumeDown();
    void folderUp();
    void folderDown();
    void escape();
  private:
    void sendToDigiPot(int dpval);
    void sendToDigiPotWithSleeve(int dpval);
};

void Pioneer::sendToDigiPot(int dpval){
  dp.setVal(dpval); //sendval
  delay(50);        //wait for head unit detection
  dp.setVal(0);     //reset
}

void Pioneer::sendToDigiPotWithSleeve(int dpval){
  digitalWrite(SLEEVE_COUPLER, HIGH); //couple
  delay(5);
  sendToDigiPot(dpval);
  digitalWrite(SLEEVE_COUPLER, LOW); //decouple
  delay(50);
}

void Pioneer::begin(){
  dp.begin();
  pinMode(SLEEVE_COUPLER, OUTPUT); //optocoupler
  digitalWrite(SLEEVE_COUPLER, LOW); //unselect
  //pinMode(ESCAPE_RESISTOR, OUTPUT); //optocoupler
  //digitalWrite(ESCAPE_RESISTOR, HIGH); //unselect

  
}


/*
 * 6 = 1.20Ω // source
 */
void Pioneer::source()
{
  sendToDigiPot(6);
}

/*
 * 20 = 3.50Ω //mute / ATT
 */
void Pioneer::mute()
{
  sendToDigiPot(20);
}

/*
 * 33 = 5.69Ω // display / song info
 */
void Pioneer::displayInfo()
{
  sendToDigiPot(33);
}

/*
 * 50 = 8.51Ω // next track / tune up
 */
void Pioneer::nextTrack()
{
  sendToDigiPot(50);
}

/*
 * 70 = 11.80Ω // previous track  / tune down
 */
void Pioneer::previousTrack()
{
  sendToDigiPot(70);
}

/*
 * 96 = 15.98Ω // volume up
 */
void Pioneer::volumeUp()
{
  sendToDigiPot(96);
}

/*
 * 127 = 20.00Ω // volume down
 */
void Pioneer::volumeDown()
{
  sendToDigiPot(127);
}

/*
 * 50 = 8.51Ω + sleeve // folder / preset up
 */
void Pioneer::folderUp()
{
  sendToDigiPotWithSleeve(50);
}

/*
 * 70 = 11.80Ω + sleeve // folder / preset down
 */
void Pioneer::folderDown()
{
  sendToDigiPotWithSleeve(70);
}

/*
 * DOES NOT WORK, Jumper to bypass
 * 33 = 5.69Ω + escape_resistor => XXXΩ // band/escape
 */
void Pioneer::escape()
{
  //digitalWrite(ESCAPE_RESISTOR, LOW); //disable bypass
  //delay(5);
  //sendToDigiPot(33);
  //digitalWrite(ESCAPE_RESISTOR, HIGH); //enableisable bypass
  //delay(5);
}



  //dp.setVal(6);   // 1.20Ω // source
  //dp.setVal(20);  // 3.50Ω //mute / ATT
  //dp.setVal(33);  // 5.69Ω // display / song info
  //dp.setVal(50);  // 8.51Ω //next track / tune up
  //dp.setVal(70);  //11.80Ω // previous track  / tune down
  //dp.setVal(96);  //15.98Ω // volume up
  //dp.setVal(127); //20.00Ω // volume down

  //specials with sleeve closed
  //dp.setVal(50);  // 8.51Ω // folder / preset up
  //dp.setVal(70);  //11.80Ω // folder / preset down



#endif
