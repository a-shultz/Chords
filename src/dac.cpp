#include "Arduino.h"
#include "dac.h"

#include <SPI.h>

void setup() {
    const int CS_PIN = 9;
    const int LDAC_PIN = 8;

    pinMode(CS_PIN, OUTPUT);
    pinMode(LDAC_PIN, OUTPUT);

    SPI.setDataMode(SPI_MODE0);
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    SPI.setBitOrder(MSBFIRST);

    SPI.begin();
    digitalWrite(CS_PIN, HIGH);
    digitalWrite(LDAC_PIN, HIGH);
}

void write(int data) {
    digitalWrite(CS_ADC_BAR, LOW);
    
    SPI.transfer(((data >> 8) & 0x0f) | 0x70);
    SPI.transfer(data & 0xff);

    digitalWrite(CS_ADC_BAR, HIGH);
    digitalWrite(AD_LATCH, LOW);
    digitalWrite(AD_LATCH, HIGH);
}