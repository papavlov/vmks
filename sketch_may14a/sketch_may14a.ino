/*************************************************************************
 * 
 * Arduino frequency counter.
 * This is a free software with NO WARRANTY.
 * https://simple-circuit.com/
 *
 ************************************************************************/
 
#include <FreqCount.h>
#include <LiquidCrystal.h>    // include Arduino LCD library
 
// LCD module connections (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 6, 7, 8);
 
void setup(void) {
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  lcd.print("FREQUENCY:");
  // initialize freqCount library with time basis of 1000ms (1 second)
  // Arduino counts number of pulses during period of 1 second
  FreqCount.begin(1000);
 
}
 
// main loop
void loop() {
  
  if (FreqCount.available()) {
    unsigned long count = FreqCount.read();
 
    lcd.setCursor(0, 1);
    lcd.print(count);  // print frequency value in Hz
    lcd.print(" Hz      ");
  }
 
}
 
// end of code.
