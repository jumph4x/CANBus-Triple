#ifndef DigiPot_H
#define DigiPot_H

#include <SPI.h>
#include "Arduino.h"

class DigiPot
{
  public:
    void begin();
    void setVal(int ohm);
};

void DigiPot::begin()
{
  // Set the slaveSelectPin as an output
  pinMode(SCK, OUTPUT);   //clock
  pinMode(MOSI, OUTPUT);  //MasterOut SlaveIn
  pinMode(SS, OUTPUT);    //Slave Select (ChipSelect)
  digitalWrite(SS, HIGH); //unselect

  // Initialize SPI: TODO Check values
  SPI.begin();
  //SPI.setDataMode(SPI_MODE0);
  //SPI.setClockDivider(SPI_CLOCK_DIV2);
  //SPI.setBitOrder(MSBFIRST);

  delay(50);
  this->setVal(0);

  //need reset ??
}

void DigiPot::setVal(int ohm)
{
  digitalWrite(SS, LOW);  //select salve
  SPI.transfer(0);        //command
  SPI.transfer(ohm);      //value
  digitalWrite(SS, HIGH); //deselect slave
}


#endif
