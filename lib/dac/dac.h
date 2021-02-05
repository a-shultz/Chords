#ifndef DAC_H
#define DAC_H

#define CS_ADC_BAR 10
#define AD_LATCH 6

namespace dac {
/**
 * Setup MCP4921 chip for CV output.
 */
void setup();
/**
 * Write data to SPI pin for CV DAC output.
 * 
 * @param data 12 bit representation of note for 0-5v DAC output.
 */
void write(int data);
} // namespace dac

#endif /* DAC_H */