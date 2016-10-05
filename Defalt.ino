#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 2
#define TOGGLE_PIN 4

#define PATTERN_INDEX_MAX 26 // The maximum index allowed for the patterns
#define DEBOUNCE_DELAY 300 // The delay for the debouncing of the button to stop false positives
bool patternToggled = true; // Every function must check this between frames in order to allow for a quick response to the button
unsigned long lastDebounceTime; // The last time when the button was triggered
int patternIndex = 0;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(218, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  attachInterrupt(TOGGLE_PIN, togglePattern, FALLING); // This will allow you to create a button that triggers the patternChange
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(10);
}

void loop() {
  
switch(patternIndex)
    {
        case 0:
           power();
             glitch();
             clean();
           patternIndex++;
            break;
        case 1:
          indexrandom();
          for(int j=0; j<6 && !patternToggled; j++) {
            defalt();
              glitch();
              clean();
              delay(200);
          }
            break;
            //---------------------------------------watchdogs--------------------------------------------
        case 2:
            patternIndex = 1;
          for(int j=0; j<4 && !patternToggled; j++) {
            delogo(); 
              glitch();
              clean();
              delay(200);
          }
            break;
        case 3:
            patternIndex = 1;
          for(int j=0; j<4 && !patternToggled; j++) {
            fullmetal();
              glitch();
              clean();
              delay(200);
          }
            //indexrandom();
            break;
        case 4:
            patternIndex = 1;
            ctos();
              glitch();
              clean();
              delay(200);
            //indexrandom();
            break;
        case 5:
           patternIndex = 1;
           terminal();
             glitch();
             clean();
             delay(200);
           break;
        case 6:
           patternIndex = 1;
          for(int j=0; j<4 && !patternToggled; j++) {
           dedsec();
           glitch();
           clean();
           delay(200);
          }
           break;
           //------------------------------------emojies--------------------------------------------
        case 7:
           patternIndex = 1;
            glitch();
            clean();
            delay(200);
          for(int j=0; j<6 && !patternToggled; j++) {
            upup();
            glitch();
            clean();
            delay(200);
          }
            break;
        case 8:
            patternIndex = 1;
            glitch();
            clean();
            delay(200);
          for(int j=0; j<6 && !patternToggled; j++) {
            oo();
            glitch();
            clean();
            delay(200);
          }
            break;
        case 9:
            patternIndex = 1;
            glitch();
            clean();
            delay(200);
          for(int j=0; j<6 && !patternToggled; j++) {
            xx();
            glitch();
            clean();
            delay(200);
          }
            break;
        case 10:
            patternIndex = 1;
            glitch();
            clean();
            delay(200);
           for(int j=0; j<6 && !patternToggled; j++) {
            atat();
            glitch();
            clean();
            delay(200);
           }
            break;
        case 11:
            patternIndex = 1;
            glitch();
            clean();
            delay(200);
           for(int j=0; j<6 && !patternToggled; j++) {
            alert();
            glitch();
            clean();
            delay(200);
           }
            break;
        case 12:
            patternIndex = 1;
            glitch();
            clean();
            delay(200);
           for(int j=0; j<6 && !patternToggled; j++) {
            heart();
            glitch();
            clean();
            delay(200);
           }
            break;
        case 13:
            patternIndex = 1;
              glitch();
              clean();
              delay(200);
              for(int j=0; j<6 && !patternToggled; j++) {
             blush();
              glitch();
              clean();
              delay(200);
              }
            break;
        //------------------------------------games--------------------------------------------
        case 14:
            patternIndex = 1;
            for(int j=0; j<4 && !patternToggled; j++) {
              triforce();
                glitch();
                clean();
                delay(200);
              fourchan();
                glitch();
                clean();
                delay(200);
            }
             break;
         case 15:
              patternIndex = 1;
            for(int j=0; j<4 && !patternToggled; j++) {
              bluePortal();
                glitch();
                clean();
                delay(200);
              cube();
                glitch();
                clean();
                delay(200);
              orangePortal();
                glitch();
                clean();
                delay(200);
            }
            break;
         case 16:
            patternIndex = 1;
          for(int j=0; j<4 && !patternToggled; j++) {
            borderlands();
              glitch();
              clean();
              delay(200);
          }
            break;
         case 17:
            patternIndex = 1;
          for(int j=0; j<4 && !patternToggled; j++) {
            halflife();
              glitch();
              clean();
              delay(200);
            three();
              glitch();
              clean();
              delay(200);
          }
            break;
         case 18:
            patternIndex = 1;
          for(int j=0; j<4 && !patternToggled; j++) {
            console();
              glitch();
              clean();
              delay(200);
            delay(200);
            rrod();
              glitch();
              clean();
              delay(200);
            delay(200);
          }
          break;
          //------------------------------------anime--------------------------------------------
        case 19:
            patternIndex = 1;
            for(int j=0; j<4 && !patternToggled; j++) {
              fullmetal();
              glitch();
              clean();
              delay(200);
            }
             break;
        case 20:
            patternIndex = 1;
            for(int j=0; j<4 && !patternToggled; j++) {
              rwbyR();
                glitch();
                clean();
                delay(200);
              rwbyW();
                glitch();
                clean();
                delay(200);
              rwbyB();
                glitch();
                clean();
                delay(200);
              rwbyY();
                glitch();
                clean();
                delay(200);
            }
             break;
        case 21:
            patternIndex = 1;
            for(int j=0; j<4 && !patternToggled; j++) {
              pokemon();
                glitch();
                clean();
                delay(200);
              pokeball();
                glitch();
                clean();
                delay(200);
            }
             break;
             //------------------------------------patterns--------------------------------------------
        case 22:
            patternIndex = 1;
            for(int j=0; j<4 && !patternToggled; j++) {
              hex(1000);
              glitch();
              clean();
            }
             break;
        case 23:
            patternIndex = 1;
            for(int j=0; j<2 && !patternToggled; j++) {
              rainbowCycle(10); //50 = 2:27s - 10 = 45
              glitch();
              clean();
            }
             break;
        case 24:
            patternIndex = 1;
            for(int j=0; j<2 && !patternToggled; j++) {
              for(int j=0; j<1 && !patternToggled; j++) {
                theaterChase(strip.Color(127, 0, 0), 50);
              }
              for(int j=0; j<1 && !patternToggled; j++) {
                theaterChase(strip.Color(0, 0, 127), 50);
              }
              for(int j=0; j<1 && !patternToggled; j++) {
                theaterChase(strip.Color(0, 127, 0), 50);
              }
              for(int j=0; j<1 && !patternToggled; j++) {
                colorWipe(strip.Color(255, 0, 0), 50); // Red
              }
              for(int j=0; j<1 && !patternToggled; j++) {
                colorWipe(strip.Color(0, 255, 0), 50); // Green
              }
              for(int j=0; j<1 && !patternToggled; j++) {
                colorWipe(strip.Color(0, 0, 255), 50); // Blue
              }
            }
             break;
             //------------------------------------additions--------------------------------------------
         case 25:
            patternIndex = 1;
            for(int j=0; j<4 && !patternToggled; j++) {
              hmm();
                glitch();
                clean();
                delay(200);
              huh();
                glitch();
                clean();
                delay(200);
            }
             break;
          case 26:
            patternIndex = 1;
            for(int j=0; j<4 && !patternToggled; j++) {
              deadmou5();
                glitch();
                clean();
                delay(200);
             deadmou5evil();
                glitch();
                clean();
                delay(200);
            }
             break;

        default:
            defalt();
            break;
    }
    if(patternToggled){
        patternToggled = false;
    }

}

  // Some example procedures showing how to display to the pixels:
  //colorWipe(strip.Color(255, 0, 0), 50); // Red
  //colorWipe(strip.Color(0, 255, 0), 50); // Green
  //colorWipe(strip.Color(0, 0, 255), 50); // Blue
  //colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
  //theaterChase(strip.Color(127, 127, 127), 50); // White
  //theaterChase(strip.Color(127, 0, 0), 50); // Red
  //theaterChase(strip.Color(0, 0, 127), 50); // Blue

  //rainbow();
  //rainbowCycle(20);
  //theaterChaseRainbow(50);
  //defalt(20); done
  //hex();
  //----------emojies--
  //upup(20);
  //oo(20);
  //xx(20);
  //atat(20);
  //alert(20);
  //heart();
  //------------watchdogs--
  //delogo(); done (make better?)
  //ctos(); done
  //terminal(); done
  //dedsec(); done
  //-----------games----
  //triforce(); done (only once)
  //portal(); done (sort cube?)
  //borderlands(); done (make better?)
  //halflife(); done
  //console(); done
  //metalgear();
  //-----------animes----
  //fullmetal(); done-
  //rwby(); done
  //pokemon(); kill pika

  
void indexrandom(){
    int iDefalt = rand() % 26 + 1;
    patternIndex = iDefalt;
}

// Signals the stop of the pattern and increments the pattern index
void togglePattern(){
    if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) //if current time minus the last trigger time is greater than
    {                                                  //the delay (debounce) time, button is completley closed.
        lastDebounceTime = millis();

        //switch was pressed, do whatever you need to here
        int iDefalt = rand() % 7 + 1;
        patternIndex = iDefalt + 6;
        
        if(patternIndex > PATTERN_INDEX_MAX)
        {
            patternIndex = 1;
        }
        patternToggled = true;
    }
}

void power(){
  strip.setPixelColor(17, 255, 0, 0, 000);
  strip.setPixelColor(41, 255, 0, 0, 000);
  strip.setPixelColor(66, 255, 0, 0, 000);
  strip.setPixelColor(89, 255, 0, 0, 000);
  strip.setPixelColor(55, 255, 0, 0, 000);
  strip.setPixelColor(64, 255, 0, 0, 000);
  strip.setPixelColor(87, 255, 0, 0, 000);
  strip.setPixelColor(100, 255, 0, 0, 000);
  strip.setPixelColor(111, 255, 0, 0, 000);
  strip.setPixelColor(120, 255, 0, 0, 000);
  strip.setPixelColor(108, 255, 0, 0, 000);
  strip.setPixelColor(104, 255, 0, 0, 000);
  strip.setPixelColor(91, 255, 0, 0, 000);
  strip.setPixelColor(68, 255, 0, 0, 000);
  strip.setPixelColor(52, 255, 0, 0, 000);
  strip.show();
  delay(5000);
}

//-----------------------------------------------------patterns-------
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
//defalt
void defalt() {
  //strip.setPixelColor(n, red, green, blue, white);
  strip.setPixelColor(0, 16, 57, 197, 000);
  strip.setPixelColor(198, 16, 57, 197, 000);
  strip.setPixelColor(73, 16, 57, 197, 000);
  strip.setPixelColor(7, 16, 57, 197, 000);
  strip.setPixelColor(4, 16, 57, 197, 000);
  strip.setPixelColor(77, 16, 57, 197, 000);
  strip.setPixelColor(10, 16, 57, 197, 000);
  strip.setPixelColor(21, 16, 57, 197, 000);
  strip.setPixelColor(19, 16, 57, 197, 000);
  strip.setPixelColor(12, 16, 57, 197, 000);
  strip.setPixelColor(31, 16, 57, 197, 000);
  strip.setPixelColor(30, 16, 57, 197, 000);
  strip.setPixelColor(28, 16, 57, 197, 000);
  strip.setPixelColor(46, 16, 57, 197, 000);
  strip.setPixelColor(37, 16, 57, 197, 000);
  strip.setPixelColor(50, 16, 57, 197, 000);
  strip.setPixelColor(51, 16, 57, 197, 000);
  strip.setPixelColor(52, 16, 57, 197, 000);
  strip.setPixelColor(54, 16, 57, 197, 000);
  strip.setPixelColor(64, 16, 57, 197, 000);
  strip.setPixelColor(57, 16, 57, 197, 000);
  strip.setPixelColor(71, 16, 57, 197, 000);
  strip.setPixelColor(69, 16, 57, 197, 000);
  strip.setPixelColor(65, 16, 57, 197, 000);
  strip.setPixelColor(61, 16, 57, 197, 000);
  strip.setPixelColor(60, 16, 57, 197, 000);
  strip.setPixelColor(75, 16, 57, 197, 000);
  strip.setPixelColor(78, 16, 57, 197, 000);
  strip.setPixelColor(82, 16, 57, 197, 000);
  strip.setPixelColor(84, 16, 57, 197, 000);
  strip.setPixelColor(93, 16, 57, 197, 000);
  strip.setPixelColor(92, 16, 57, 197, 000);
  strip.setPixelColor(88, 16, 57, 197, 000);
  strip.setPixelColor(86, 16, 57, 197, 000);
  strip.setPixelColor(85, 16, 57, 197, 000);
  strip.setPixelColor(95, 16, 57, 197, 000);
  strip.setPixelColor(96, 16, 57, 197, 000);
  strip.setPixelColor(98, 16, 57, 197, 000);
  //bridge
  strip.setPixelColor(104, 16, 57, 197, 000);
  strip.setPixelColor(103, 16, 57, 197, 000);
  strip.setPixelColor(102, 16, 57, 197, 000);
  strip.setPixelColor(101, 16, 57, 197, 000);
  strip.setPixelColor(100, 16, 57, 197, 000);
  strip.setPixelColor(108, 16, 57, 197, 000);
  strip.setPixelColor(109, 16, 57, 197, 000);
  strip.setPixelColor(110, 16, 57, 197, 000);
  strip.setPixelColor(111, 16, 57, 197, 000);
  strip.setPixelColor(121, 16, 57, 197, 000);
  strip.setPixelColor(120, 16, 57, 197, 000);
  strip.setPixelColor(119, 16, 57, 197, 000);
  strip.setPixelColor(129, 16, 57, 197, 000);
  strip.setPixelColor(130, 16, 57, 197, 000);
  strip.setPixelColor(131, 16, 57, 197, 000);
  strip.setPixelColor(141, 16, 57, 197, 000);
  strip.setPixelColor(140, 16, 57, 197, 000);
  strip.setPixelColor(139, 16, 57, 197, 000);
  strip.setPixelColor(148, 16, 57, 197, 000);
  strip.setPixelColor(149, 16, 57, 197, 000);
  strip.setPixelColor(150, 16, 57, 197, 000);
  strip.setPixelColor(151, 16, 57, 197, 000);
  strip.setPixelColor(160, 16, 57, 197, 000);
  strip.setPixelColor(159, 16, 57, 197, 000);
  strip.setPixelColor(158, 16, 57, 197, 000);
  strip.setPixelColor(167, 16, 57, 197, 000);
  strip.setPixelColor(168, 16, 57, 197, 000);
  strip.setPixelColor(176, 16, 57, 197, 000);
  strip.setPixelColor(175, 16, 57, 197, 000);
  strip.setPixelColor(175, 16, 57, 197, 000);
  strip.setPixelColor(181, 16, 57, 197, 000);
  strip.setPixelColor(182, 16, 57, 197, 000);
  strip.setPixelColor(188, 16, 57, 197, 000);
  strip.setPixelColor(187, 16, 57, 197, 000);
  strip.setPixelColor(186, 16, 57, 197, 000);
  strip.setPixelColor(192, 16, 57, 197, 000);
  strip.setPixelColor(193, 16, 57, 197, 000);
  strip.setPixelColor(132, 16, 57, 197, 000);
  strip.setPixelColor(174, 16, 57, 197, 000);
  strip.show();
    delay(5000);
}
//GLITCH
void glitch() {
  //strip.setPixelColor(n, red, green, blue, white);
  for(int j=0; j<40; j++) {
    uint32_t color = strip.getPixelColor(j);
    /* generate secret number between 1 and 10: */
    int iSecret = rand() % 2 + 1;
    if (iSecret % 2) {
         strip.setPixelColor(j, 000, 000, 000, 000);  
      strip.setPixelColor(j+1,color); }
      else
      {    strip.setPixelColor(j, 000, 000, 000, 000);
        strip.setPixelColor(j-1,color);
    }
    strip.show();
}
}
//clear
void clean() {
  //strip.setPixelColor(n, red, green, blue, white);
  for(int j=0; j<218; j++) {
   strip.setPixelColor(j, 000, 000, 000, 000);
  }
  strip.show();
}
//hex
void hex(int wait) {
for(int j=0; j<50 && !patternToggled; j++) {
  int iSecret = rand() % 28 + 1;
  if(iSecret == 1){
    part1();
    delay(wait);
  }else if(iSecret == 2){
    part2();
    delay(wait);
  }else if(iSecret == 3){
    part3();
    delay(wait);
  }else if(iSecret == 4){
    part4();
    delay(wait);
  }else if(iSecret == 5){
    part5();
    delay(wait);
  }else if(iSecret == 6){
    part6();
    delay(wait);
  }else if(iSecret == 7){
    part7();
    delay(wait);
  }else if(iSecret == 8){
    part8();
    delay(wait);
  }else if(iSecret == 9){
    part9();
    delay(wait);
  }else if(iSecret == 10){
    part10();
    delay(wait);
  }else if(iSecret == 11){
    part11();
    delay(wait);
  }else if(iSecret == 12){
    part12();
    delay(wait);
  }else if(iSecret == 13){
    part13();
    delay(wait);
  }else if(iSecret == 14){
    part14();
    delay(wait);
  }else if(iSecret == 15){
    part15();
    delay(wait);
  }else if(iSecret == 16){
    part16();
    delay(wait);
  }else if(iSecret == 17){
    part17();
    delay(wait);
  }else if(iSecret == 18){
    part18();
    delay(wait);
  }else if(iSecret == 19){
    part19();
    delay(wait);
  }else if(iSecret == 20){
    part20();
    delay(wait);
  }else if(iSecret == 21){
    part21();
    delay(wait);
  }else if(iSecret == 22){
    part22();
    delay(wait);
  }else if(iSecret == 23){
    part23();
    delay(wait);
  }else if(iSecret == 24){
    part24();
    delay(wait);
  }else if(iSecret == 25){
    part25();
    delay(wait);
  }else if(iSecret == 26){
    part26();
    delay(wait);
  }else if(iSecret == 27){
    part27();
    delay(wait);
  }else if(iSecret == 28){
    part28();
    delay(wait);
  }
 }
}

  //1
void part1(){
  strip.setPixelColor(18, 164, 49, 255, 000);
  strip.setPixelColor(17, 164, 49, 255, 000);
  strip.setPixelColor(16, 164, 49, 255, 000);
  strip.setPixelColor(30, 164, 49, 255, 000);
  strip.setPixelColor(39, 164, 49, 255, 000);
  strip.setPixelColor(55, 164, 49, 255, 000);
  strip.setPixelColor(65, 164, 49, 255, 000);
  strip.setPixelColor(66, 164, 49, 255, 000);
  strip.setPixelColor(67, 164, 49, 255, 000);
  strip.setPixelColor(52, 164, 49, 255, 000);
  strip.setPixelColor(43, 164, 49, 255, 000);
  strip.setPixelColor(27, 164, 49, 255, 000);
  strip.show();
 }
void part2(){
  strip.setPixelColor(67, 164, 49, 255, 000);
  strip.setPixelColor(66, 164, 49, 255, 000);
  strip.setPixelColor(65, 164, 49, 255, 000);
  strip.setPixelColor(80, 164, 49, 255, 000);
  strip.setPixelColor(87, 164, 49, 255, 000);
  strip.setPixelColor(98, 164, 49, 255, 000);
  strip.setPixelColor(101, 164, 49, 255, 000);
  strip.setPixelColor(102, 164, 49, 255, 000);
  strip.setPixelColor(103, 164, 49, 255, 000);
  strip.setPixelColor(95, 164, 49, 255, 000);
  strip.setPixelColor(91, 164, 49, 255, 000);
  strip.setPixelColor(77, 164, 49, 255, 000);
  strip.show();
 }
void part3(){
  strip.setPixelColor(103, 164, 49, 255, 000);
  strip.setPixelColor(102, 164, 49, 255, 000);
  strip.setPixelColor(101, 164, 49, 255, 000);
  strip.setPixelColor(111, 164, 49, 255, 000);
  strip.setPixelColor(118, 164, 49, 255, 000);
  strip.setPixelColor(132, 164, 49, 255, 000);
  strip.setPixelColor(139, 164, 49, 255, 000);
  strip.setPixelColor(140, 164, 49, 255, 000);
  strip.setPixelColor(141, 164, 49, 255, 000);
  strip.setPixelColor(129, 164, 49, 255, 000);
  strip.setPixelColor(122, 164, 49, 255, 000);
  strip.setPixelColor(108, 164, 49, 255, 000);
  strip.show();
 }
void part4(){
  strip.setPixelColor(141, 164, 49, 255, 000);
  strip.setPixelColor(140, 164, 49, 255, 000);
  strip.setPixelColor(139, 164, 49, 255, 000);
  strip.setPixelColor(151, 164, 49, 255, 000);
  strip.setPixelColor(157, 164, 49, 255, 000);
  strip.setPixelColor(169, 164, 49, 255, 000);
  strip.setPixelColor(174, 164, 49, 255, 000);
  strip.setPixelColor(175, 164, 49, 255, 000);
  strip.setPixelColor(176, 164, 49, 255, 000);
  strip.setPixelColor(166, 164, 49, 255, 000);
  strip.setPixelColor(161, 164, 49, 255, 000);
  strip.setPixelColor(148, 164, 49, 255, 000);
  strip.show();
 }
void part5(){
  strip.setPixelColor(176, 164, 49, 255, 000);
  strip.setPixelColor(175, 164, 49, 255, 000);
  strip.setPixelColor(174, 164, 49, 255, 000);
  strip.setPixelColor(183, 164, 49, 255, 000);
  strip.setPixelColor(185, 164, 49, 255, 000);
  strip.setPixelColor(194, 164, 49, 255, 000);
  strip.setPixelColor(197, 164, 49, 255, 000);
  strip.setPixelColor(198, 164, 49, 255, 000);
  strip.setPixelColor(199, 164, 49, 255, 000);
  strip.setPixelColor(191, 164, 49, 255, 000);
  strip.setPixelColor(189, 164, 49, 255, 000);
  strip.setPixelColor(180, 164, 49, 255, 000);
  strip.show();
 }
void part6(){
  strip.setPixelColor(199, 164, 49, 255, 000);
  strip.setPixelColor(198, 164, 49, 255, 000);
  strip.setPixelColor(197, 164, 49, 255, 000);
  strip.setPixelColor(204, 164, 49, 255, 000);
  strip.setPixelColor(212, 164, 49, 255, 000);
  strip.setPixelColor(213, 164, 49, 255, 000);
  strip.setPixelColor(214, 164, 49, 255, 000);
  strip.setPixelColor(201, 164, 49, 255, 000);
  strip.show();
 }
void part7(){
  strip.setPixelColor(4, 164, 49, 255, 000);
  strip.setPixelColor(8, 164, 49, 255, 000);
  strip.setPixelColor(027, 164, 49, 255, 000);
  strip.setPixelColor(043, 164, 49, 255, 000);
  strip.setPixelColor(044, 164, 49, 255, 000);
  strip.setPixelColor(045, 164, 49, 255, 000);
  strip.setPixelColor(024, 164, 49, 255, 000);
  strip.setPixelColor(022, 164, 49, 255, 000);
  strip.setPixelColor(001, 164, 49, 255, 000);
  strip.show();
 }
void part8(){
  strip.setPixelColor(45, 164, 49, 255, 000);
  strip.setPixelColor(44, 164, 49, 255, 000);
  strip.setPixelColor(43, 164, 49, 255, 000);
  strip.setPixelColor(52, 164, 49, 255, 000);
  strip.setPixelColor(67, 164, 49, 255, 000);
  strip.setPixelColor(77, 164, 49, 255, 000);
  strip.setPixelColor(91, 164, 49, 255, 000);
  strip.setPixelColor(92, 164, 49, 255, 000);
  strip.setPixelColor(93, 164, 49, 255, 000);
  strip.setPixelColor(74, 164, 49, 255, 000);
  strip.setPixelColor(71, 164, 49, 255, 000);
  strip.setPixelColor(49, 164, 49, 255, 000);
  strip.show();
 }
void part9(){
  strip.setPixelColor(93, 164, 49, 255, 000);
  strip.setPixelColor(92, 164, 49, 255, 000);
  strip.setPixelColor(91, 164, 49, 255, 000);
  strip.setPixelColor(95, 164, 49, 255, 000);
  strip.setPixelColor(103, 164, 49, 255, 000);
  strip.setPixelColor(108, 164, 49, 255, 000);
  strip.setPixelColor(122, 164, 49, 255, 000);
  strip.setPixelColor(123, 164, 49, 255, 000);
  strip.setPixelColor(124, 164, 49, 255, 000);
  strip.setPixelColor(106, 164, 49, 255, 000);
  strip.show();
 }
void part10(){
  strip.setPixelColor(124, 164, 49, 255, 000);
  strip.setPixelColor(123, 164, 49, 255, 000);
  strip.setPixelColor(122, 164, 49, 255, 000);
  strip.setPixelColor(129, 164, 49, 255, 000);
  strip.setPixelColor(141, 164, 49, 255, 000);
  strip.setPixelColor(148, 164, 49, 255, 000);
  strip.setPixelColor(161, 164, 49, 255, 000);
  strip.setPixelColor(162, 164, 49, 255, 000);
  strip.setPixelColor(163, 164, 49, 255, 000);
  strip.setPixelColor(126, 164, 49, 255, 000);
  strip.show();
}
void part11(){
  strip.setPixelColor(10, 164, 49, 255, 000);
  strip.setPixelColor(12, 164, 49, 255, 000);
  strip.setPixelColor(33, 164, 49, 255, 000);
  strip.setPixelColor(37, 164, 49, 255, 000);
  strip.setPixelColor(38, 164, 49, 255, 000);
  strip.setPixelColor(39, 164, 49, 255, 000);
  strip.setPixelColor(30, 164, 49, 255, 000);
  strip.setPixelColor(16, 164, 49, 255, 000);
  strip.setPixelColor(7, 164, 49, 255, 000);
  strip.show();
}
void part12(){
  strip.setPixelColor(39, 164, 49, 255, 000);
  strip.setPixelColor(38, 164, 49, 255, 000);
  strip.setPixelColor(37, 164, 49, 255, 000);
  strip.setPixelColor(58, 164, 49, 255, 000);
  strip.setPixelColor(61, 164, 49, 255, 000);
  strip.setPixelColor(83, 164, 49, 255, 000);
  strip.setPixelColor(85, 164, 49, 255, 000);
  strip.setPixelColor(86, 164, 49, 255, 000);
  strip.setPixelColor(87, 164, 49, 255, 000);
  strip.setPixelColor(80, 164, 49, 255, 000);
  strip.setPixelColor(65, 164, 49, 255, 000);
  strip.setPixelColor(55, 164, 49, 255, 000);  
  strip.show();
}
void part13(){
  strip.setPixelColor(87, 164, 49, 255, 000);
  strip.setPixelColor(86, 164, 49, 255, 000);
  strip.setPixelColor(85, 164, 49, 255, 000);
  strip.setPixelColor(113, 164, 49, 255, 000);
  strip.setPixelColor(116, 164, 49, 255, 000);
  strip.setPixelColor(117, 164, 49, 255, 000);
  strip.setPixelColor(118, 164, 49, 255, 000);
  strip.setPixelColor(111, 164, 49, 255, 000);
  strip.setPixelColor(101, 164, 49, 255, 000);
  strip.setPixelColor(98, 164, 49, 255, 000);
  strip.show();
 }
void part14(){
  strip.setPixelColor(118, 164, 49, 255, 000);
  strip.setPixelColor(117, 164, 49, 255, 000);
  strip.setPixelColor(116, 164, 49, 255, 000);
  strip.setPixelColor(135, 164, 49, 255, 000);
  strip.setPixelColor(154, 164, 49, 255, 000);
  strip.setPixelColor(155, 164, 49, 255, 000);
  strip.setPixelColor(156, 164, 49, 255, 000);
  strip.setPixelColor(157, 164, 49, 255, 000);
  strip.setPixelColor(151, 164, 49, 255, 000);
  strip.setPixelColor(139, 164, 49, 255, 000);
  strip.setPixelColor(132, 164, 49, 255, 000);
  strip.show();
 }
void part15(){
  strip.setPixelColor(163, 164, 49, 255, 000);
  strip.setPixelColor(162, 164, 49, 255, 000);
  strip.setPixelColor(161, 164, 49, 255, 000);
  strip.setPixelColor(166, 164, 49, 255, 000);
  strip.setPixelColor(176, 164, 49, 255, 000);
  strip.setPixelColor(180, 164, 49, 255, 000);
  strip.setPixelColor(189, 164, 49, 255, 000);
  strip.show();
 }
void part16(){
  strip.setPixelColor(157, 164, 49, 255, 000);
  strip.setPixelColor(156, 164, 49, 255, 000);
  strip.setPixelColor(155, 164, 49, 255, 000);
  strip.setPixelColor(185, 164, 49, 255, 000);
  strip.setPixelColor(183, 164, 49, 255, 000);
  strip.setPixelColor(174, 164, 49, 255, 000);
  strip.setPixelColor(169, 164, 49, 255, 000);
  strip.show();
 }
void part17(){
  strip.setPixelColor(189, 164, 49, 255, 000);
  strip.setPixelColor(193, 164, 49, 255, 000);
  strip.setPixelColor(199, 164, 49, 255, 000);
  strip.setPixelColor(201, 164, 49, 255, 000);
  strip.show();
 }
void part18(){
  strip.setPixelColor(185, 164, 49, 255, 000);
  strip.setPixelColor(204, 164, 49, 255, 000);
  strip.setPixelColor(197, 164, 49, 255, 000);
  strip.setPixelColor(194, 164, 49, 255, 000);
  strip.show();
 }
void part19(){
  strip.setPixelColor(106, 164, 49, 255, 000);
  strip.setPixelColor(124, 164, 49, 255, 000);
  strip.setPixelColor(126, 164, 49, 255, 000);
  strip.show();
 }
void part20(){
  strip.setPixelColor(135, 164, 49, 255, 000);
  strip.setPixelColor(116, 164, 49, 255, 000);
  strip.setPixelColor(113, 164, 49, 255, 000);
  strip.show();
 }
void part21(){
  strip.setPixelColor(72, 164, 49, 255, 000);
  strip.setPixelColor(71, 164, 49, 255, 000);
  strip.setPixelColor(74, 164, 49, 255, 000);
  strip.setPixelColor(93, 164, 49, 255, 000);
  strip.show();
 }
void part22(){
  strip.setPixelColor(61, 164, 49, 255, 000);
  strip.setPixelColor(60, 164, 49, 255, 000);
  strip.setPixelColor(85, 164, 49, 255, 000);
  strip.setPixelColor(83, 164, 49, 255, 000);
  strip.show();
 }
void part23(){
  strip.setPixelColor(22, 164, 49, 255, 000);
  strip.setPixelColor(24, 164, 49, 255, 000);
  strip.setPixelColor(45, 164, 49, 255, 000);
  strip.setPixelColor(49, 164, 49, 255, 000);
  strip.setPixelColor(71, 164, 49, 255, 000);
  strip.setPixelColor(72, 164, 49, 255, 000);
  strip.show();
 }
void part24(){
  strip.setPixelColor(12, 164, 49, 255, 000);
  strip.setPixelColor(60, 164, 49, 255, 000);
  strip.setPixelColor(61, 164, 49, 255, 000);
  strip.setPixelColor(58, 164, 49, 255, 000);
  strip.setPixelColor(37, 164, 49, 255, 000);
  strip.setPixelColor(33, 164, 49, 255, 000);
  strip.show();
 }
void part25(){
  strip.setPixelColor(1, 164, 49, 255, 000);
  strip.setPixelColor(22, 164, 49, 255, 000);
  strip.show();
  strip.show();
 }
void part26(){
  strip.setPixelColor(7, 164, 49, 255, 000);
  strip.setPixelColor(16, 164, 49, 255, 000);
  strip.setPixelColor(17, 164, 49, 255, 000);
  strip.setPixelColor(18, 164, 49, 255, 000);
  strip.setPixelColor(4, 164, 49, 255, 000);
  strip.show();
 }
void part27(){
  strip.setPixelColor(10, 164, 49, 255, 000);
  strip.setPixelColor(12, 164, 49, 255, 000);
  strip.show();
 }
void part28(){
  strip.setPixelColor(214, 164, 49, 255, 000);
  strip.setPixelColor(213, 164, 49, 255, 000);
  strip.setPixelColor(212, 164, 49, 255, 000);
  strip.show();
 }
 
 //console
void console() {
  for(int j=0; j<10 && !patternToggled; j++) {
  //x
  strip.setPixelColor(95, 145, 176, 225, 000);
  strip.setPixelColor(98, 145, 176, 225, 000);
  strip.setPixelColor(103, 145, 176, 225, 000);
  strip.setPixelColor(101, 145, 176, 225, 000);
  strip.setPixelColor(109, 145, 176, 225, 000);
  strip.setPixelColor(110, 145, 176, 225, 000);
  strip.setPixelColor(120, 145, 176, 225, 000);
  strip.setPixelColor(130, 145, 176, 225, 000);
  strip.setPixelColor(131, 145, 176, 225, 000);
  strip.setPixelColor(139, 145, 176, 225, 000);
  strip.setPixelColor(141, 145, 176, 225, 000);
  strip.setPixelColor(148, 145, 176, 225, 000);
  strip.setPixelColor(151, 145, 176, 225, 000);
  //o
  strip.setPixelColor(32, 208, 92, 109, 000);
  strip.setPixelColor(33, 208, 92, 109, 000);
  strip.setPixelColor(34, 208, 92, 109, 000);
  strip.setPixelColor(38, 208, 92, 109, 000);
  strip.setPixelColor(35, 208, 92, 109, 000);
  strip.setPixelColor(63, 208, 92, 109, 000);
  strip.setPixelColor(60, 208, 92, 109, 000);
  strip.setPixelColor(82, 208, 92, 109, 000);
  strip.setPixelColor(83, 208, 92, 109, 000);
  strip.setPixelColor(84, 208, 92, 109, 000);
  //^
  strip.setPixelColor(17, 84, 219, 214, 000);
  strip.setPixelColor(28, 84, 219, 214, 000);
  strip.setPixelColor(29, 84, 219, 214, 000);
  strip.setPixelColor(42, 84, 219, 214, 000);
  strip.setPixelColor(40, 84, 219, 214, 000);
  strip.setPixelColor(52, 84, 219, 214, 000);
  strip.setPixelColor(55, 84, 219, 214, 000);
  strip.setPixelColor(68, 84, 219, 214, 000);
  strip.setPixelColor(67, 84, 219, 214, 000);
  strip.setPixelColor(66, 84, 219, 214, 000);
  strip.setPixelColor(65, 84, 219, 214, 000);
  strip.setPixelColor(64, 84, 219, 214, 000);
  //[]
  strip.setPixelColor(23, 207, 140, 194, 000);
  strip.setPixelColor(24, 207, 140, 194, 000);
  strip.setPixelColor(25, 207, 140, 194, 000);
  strip.setPixelColor(48, 207, 140, 194, 000);
  strip.setPixelColor(50, 207, 140, 194, 000);
  strip.setPixelColor(73, 207, 140, 194, 000);
  strip.setPixelColor(74, 207, 140, 194, 000);
  strip.setPixelColor(75, 207, 140, 194, 000);
  strip.show();
  delay(1000);
  }
}
void rrod(){
 for(int j=0; j<5 && !patternToggled; j++) {
  strip.setPixelColor(66, 249, 204, 43, 000);
  strip.setPixelColor(102, 249, 204, 43, 000);
  strip.setPixelColor(90, 249, 204, 43, 000);
  strip.setPixelColor(89, 249, 204, 43, 000);
  strip.setPixelColor(88, 249, 204, 43, 000);
  strip.setPixelColor(98, 249, 204, 43, 000);
  strip.setPixelColor(111, 249, 204, 43, 000);
  strip.setPixelColor(119, 249, 204, 43, 000);
  strip.setPixelColor(120, 249, 204, 43, 000);
  strip.setPixelColor(121, 249, 204, 43, 000);
  strip.setPixelColor(108, 249, 204, 43, 000);
  strip.setPixelColor(95, 249, 204, 43, 000);
  //(
  strip.setPixelColor(74, 249, 204, 43, 000);
  strip.setPixelColor(70, 249, 204, 43, 000);
  strip.setPixelColor(50, 249, 204, 43, 000);
  strip.setPixelColor(44, 249, 204, 43, 000);
  strip.setPixelColor(26, 249, 204, 43, 000);
  strip.setPixelColor(27, 249, 204, 43, 000);
  strip.setPixelColor(30, 249, 204, 43, 000);
  strip.setPixelColor(31, 249, 204, 43, 000);
  strip.setPixelColor(38, 249, 204, 43, 000);
  strip.setPixelColor(57, 249, 204, 43, 000);
  strip.setPixelColor(62, 249, 204, 43, 000);
  strip.setPixelColor(83, 249, 204, 43, 000);
  strip.setPixelColor(106, 249, 204, 43, 000);
  strip.setPixelColor(124, 249, 204, 43, 000);
  strip.setPixelColor(127, 249, 204, 43, 000);
  strip.setPixelColor(143, 249, 204, 43, 000);
  strip.setPixelColor(147, 249, 204, 43, 000);
  strip.setPixelColor(148, 249, 204, 43, 000);
  strip.setPixelColor(149, 249, 204, 43, 000);
  strip.show();
    delay(1000);
 }
}
//-------------------------------------------------------emojis
//^^
 void upup() {
  //strip.setPixelColor(n, red, green, blue, white);
  //left eye
  strip.setPixelColor(45, 000, 000, 255, 000);
  strip.setPixelColor(49, 000, 000, 255, 000);
  strip.setPixelColor(50, 000, 000, 255, 000);
  strip.setPixelColor(71, 000, 000, 255, 000);
  strip.setPixelColor(69, 000, 000, 255, 000);
  strip.setPixelColor(73, 000, 000, 255, 000);
  strip.setPixelColor(76, 000, 000, 255, 000);
  //right eye
  strip.setPixelColor(37, 000, 000, 255, 000);
  strip.setPixelColor(57, 000, 000, 255, 000);
  strip.setPixelColor(58, 000, 000, 255, 000);
  strip.setPixelColor(63, 000, 000, 255, 000);
  strip.setPixelColor(61, 000, 000, 255, 000);
  strip.setPixelColor(81, 000, 000, 255, 000);
  strip.setPixelColor(84, 000, 000, 255, 000);
  strip.show();
  delay(5000);
 }
//O-O
 void oo() {
  //strip.setPixelColor(n, red, green, blue, white);
  //left eye
  strip.setPixelColor(23, 000, 000, 255, 000);
  strip.setPixelColor(24, 000, 000, 255, 000);
  strip.setPixelColor(25, 000, 000, 255, 000);
  strip.setPixelColor(47, 000, 000, 255, 000);
  strip.setPixelColor(44, 000, 000, 255, 000);
  strip.setPixelColor(72, 000, 000, 255, 000);
  strip.setPixelColor(74, 000, 000, 255, 000);
  strip.setPixelColor(75, 000, 000, 255, 000);
  strip.setPixelColor(69, 000, 000, 255, 000);
  strip.setPixelColor(73, 000, 000, 255, 000);
  //right eye
  strip.setPixelColor(32, 000, 000, 255, 000);
  strip.setPixelColor(33, 000, 000, 255, 000);
  strip.setPixelColor(34, 000, 000, 255, 000);
  strip.setPixelColor(38, 000, 000, 255, 000);
  strip.setPixelColor(35, 000, 000, 255, 000);
  strip.setPixelColor(63, 000, 000, 255, 000);
  strip.setPixelColor(60, 000, 000, 255, 000);
  strip.setPixelColor(82, 000, 000, 255, 000);
  strip.setPixelColor(83, 000, 000, 255, 000);
  strip.setPixelColor(84, 000, 000, 255, 000);
  strip.show();
  delay(5000);
}
//XX
 void xx() {
  //strip.setPixelColor(n, red, green, blue, white);
  //left eye
  strip.setPixelColor(23, 255, 000, 000, 000);
  strip.setPixelColor(25, 255, 000, 000, 000);
  strip.setPixelColor(45, 255, 000, 000, 000);
  strip.setPixelColor(46, 255, 000, 000, 000);
  strip.setPixelColor(49, 255, 000, 000, 000);
  strip.setPixelColor(70, 255, 000, 000, 000);
  strip.setPixelColor(71, 255, 000, 000, 000);
  strip.setPixelColor(73, 255, 000, 000, 000);
  strip.setPixelColor(75, 255, 000, 000, 000);
  //right eye
  strip.setPixelColor(32, 255, 000, 000, 000);
  strip.setPixelColor(34, 255, 000, 000, 000);
  strip.setPixelColor(36, 255, 000, 000, 000);
  strip.setPixelColor(37, 255, 000, 000, 000);
  strip.setPixelColor(58, 255, 000, 000, 000);
  strip.setPixelColor(62, 255, 000, 000, 000);
  strip.setPixelColor(61, 255, 000, 000, 000);
  strip.setPixelColor(84, 255, 000, 000, 000);
  strip.setPixelColor(82, 255, 000, 000, 000);
  strip.show();
  delay(5000);
}
//@@
 void atat() {
  //strip.setPixelColor(n, red, green, blue, white);
  //left eye
  strip.setPixelColor(22, 000, 255, 000, 000);
  strip.setPixelColor(21, 000, 255, 000, 000);
  strip.setPixelColor(23, 000, 255, 000, 000);
  strip.setPixelColor(25, 000, 255, 000, 000);
  strip.setPixelColor(47, 000, 255, 000, 000);
  strip.setPixelColor(44, 000, 255, 000, 000);
  strip.setPixelColor(49, 000, 255, 000, 000);
  strip.setPixelColor(70, 000, 255, 000, 000);
  strip.setPixelColor(69, 000, 255, 000, 000);
  strip.setPixelColor(72, 000, 255, 000, 000);
  strip.setPixelColor(73, 000, 255, 000, 000);
  strip.setPixelColor(93, 000, 255, 000, 000);
  strip.setPixelColor(92, 000, 255, 000, 000);
  //right eye
  strip.setPixelColor(13, 000, 255, 000, 000);
  strip.setPixelColor(12, 000, 255, 000, 000);
  strip.setPixelColor(32, 000, 255, 000, 000);
  strip.setPixelColor(34, 000, 255, 000, 000);
  strip.setPixelColor(38, 000, 255, 000, 000);
  strip.setPixelColor(35, 000, 255, 000, 000);
  strip.setPixelColor(49, 000, 255, 000, 000);
  strip.setPixelColor(58, 000, 255, 000, 000);
  strip.setPixelColor(63, 000, 255, 000, 000);
  strip.setPixelColor(62, 000, 255, 000, 000);
  strip.setPixelColor(60, 000, 255, 000, 000);
  strip.setPixelColor(84, 000, 255, 000, 000);
  strip.setPixelColor(85, 000, 255, 000, 000);
  strip.setPixelColor(86, 000, 255, 000, 000);
  strip.show();
  delay(5000);
}
//!!
 void alert() {
  //left eye
  strip.setPixelColor(1, 255, 000, 000, 000);
  strip.setPixelColor(21, 255, 000, 000, 000);
  strip.setPixelColor(2, 255, 000, 000, 000);
  strip.setPixelColor(24, 255, 000, 000, 000);
  strip.setPixelColor(25, 255, 000, 000, 000);
  strip.setPixelColor(45, 255, 000, 000, 000);
  strip.setPixelColor(49, 255, 000, 000, 000);
  strip.setPixelColor(50, 255, 000, 000, 000);
  strip.setPixelColor(70, 255, 000, 000, 000);
  strip.setPixelColor(93, 255, 000, 000, 000);
  //right eye
  strip.setPixelColor(9, 255, 000, 000, 000);
  strip.setPixelColor(10, 255, 000, 000, 000);
  strip.setPixelColor(13, 255, 000, 000, 000);
  strip.setPixelColor(32, 255, 000, 000, 000);
  strip.setPixelColor(33, 255, 000, 000, 000);
  strip.setPixelColor(37, 255, 000, 000, 000);
  strip.setPixelColor(57, 255, 000, 000, 000);
  strip.setPixelColor(58, 255, 000, 000, 000);
  strip.setPixelColor(62, 255, 000, 000, 000);
  strip.setPixelColor(85, 255, 000, 000, 000);
  strip.show();
  delay(5000);
}

 void heart() {
  //left eye
  strip.setPixelColor(23, 255, 105, 180, 000);
  strip.setPixelColor(25, 255, 105, 180, 000);
  strip.setPixelColor(47, 255, 105, 180, 000);
  strip.setPixelColor(46, 255, 105, 180, 000);
  strip.setPixelColor(45, 255, 105, 180, 000);
  strip.setPixelColor(44, 255, 105, 180, 000);
  strip.setPixelColor(48, 255, 105, 180, 000);
  strip.setPixelColor(49, 255, 105, 180, 000);
  strip.setPixelColor(50, 255, 105, 180, 000);
  strip.setPixelColor(71, 255, 105, 180, 000);
  strip.setPixelColor(70, 255, 105, 180, 000);
  strip.setPixelColor(74, 255, 105, 180, 000);
  //right eye
  strip.setPixelColor(32, 255, 105, 180, 000);
  strip.setPixelColor(34, 255, 105, 180, 000);
  strip.setPixelColor(38, 255, 105, 180, 000);
  strip.setPixelColor(37, 255, 105, 180, 000);
  strip.setPixelColor(36, 255, 105, 180, 000);
  strip.setPixelColor(35, 255, 105, 180, 000);
  strip.setPixelColor(57, 255, 105, 180, 000);
  strip.setPixelColor(58, 255, 105, 180, 000);
  strip.setPixelColor(59, 255, 105, 180, 000);
  strip.setPixelColor(62, 255, 105, 180, 000);
  strip.setPixelColor(61, 255, 105, 180, 000);
  strip.setPixelColor(83, 255, 105, 180, 000);
  strip.show();
  delay(5000);
}

void blush() {
  //left eye
  strip.setPixelColor(47, 222, 93, 131, 000);
  strip.setPixelColor(48, 222, 93, 131, 000);
  strip.setPixelColor(71, 222, 93, 131, 000);
  strip.setPixelColor(49, 222, 93, 131, 000);
  strip.setPixelColor(45, 222, 93, 131, 000);
  strip.setPixelColor(50, 222, 93, 131, 000);
  strip.setPixelColor(69, 222, 93, 131, 000);
  strip.setPixelColor(162, 222, 93, 131, 000);
  strip.setPixelColor(164, 222, 93, 131, 000);
  strip.setPixelColor(165, 222, 93, 131, 000);
  strip.setPixelColor(178, 222, 93, 131, 000);
  //right eye
  strip.setPixelColor(63, 222, 93, 131, 000);
  strip.setPixelColor(57, 222, 93, 131, 000);
  strip.setPixelColor(37, 222, 93, 131, 000);
  strip.setPixelColor(58, 222, 93, 131, 000);
  strip.setPixelColor(61, 222, 93, 131, 000);
  strip.setPixelColor(59, 222, 93, 131, 000);
  strip.setPixelColor(35, 222, 93, 131, 000);
  strip.setPixelColor(156, 222, 93, 131, 000);
  strip.setPixelColor(170, 222, 93, 131, 000);
  strip.setPixelColor(171, 222, 93, 131, 000);
  strip.setPixelColor(172, 222, 93, 131, 000);
  strip.show();
  delay(5000);
}

//-----------------------------------------------------watch dogs---------
 void delogo() {
  //strip.setPixelColor(n, red, green, blue, white);
  strip.setPixelColor(24, 255, 255, 000, 000);
  strip.setPixelColor(49, 255, 255, 000, 000);
  strip.setPixelColor(74, 255, 255, 000, 000);
  strip.setPixelColor(106, 255, 255, 000, 000);
  strip.setPixelColor(126, 255, 255, 000, 000);
  strip.setPixelColor(127, 255, 255, 000, 000);
  strip.setPixelColor(128, 255, 255, 000, 000);
  strip.setPixelColor(129, 255, 255, 000, 000);
  strip.setPixelColor(130, 255, 255, 000, 000);
  strip.setPixelColor(131, 255, 255, 000, 000);
  strip.setPixelColor(132, 255, 255, 000, 000);
  strip.setPixelColor(133, 255, 255, 000, 000);
  strip.setPixelColor(134, 255, 255, 000, 000);
  strip.setPixelColor(135, 255, 255, 000, 000);
  strip.setPixelColor(113, 255, 255, 000, 000);
  strip.setPixelColor(83, 255, 255, 000, 000);
  strip.setPixelColor(58, 255, 255, 000, 000);
  strip.setPixelColor(33, 255, 255, 000, 000);
  strip.setPixelColor(41, 255, 255, 000, 000);
  strip.setPixelColor(53, 255, 255, 000, 000);
  strip.setPixelColor(54, 255, 255, 000, 000);
  strip.setPixelColor(67, 255, 255, 000, 000);
  strip.setPixelColor(65, 255, 255, 000, 000);
  strip.setPixelColor(77, 255, 255, 000, 000);
  strip.setPixelColor(80, 255, 255, 000, 000);
  strip.setPixelColor(91, 255, 255, 000, 000);
  strip.setPixelColor(87, 255, 255, 000, 000);
  strip.setPixelColor(94, 255, 255, 000, 000);
  strip.setPixelColor(99, 255, 255, 000, 000);
  strip.setPixelColor(107, 255, 255, 000, 000);
  strip.setPixelColor(124, 255, 255, 000, 000);
  strip.setPixelColor(112, 255, 255, 000, 000);
  strip.setPixelColor(116, 255, 255, 000, 000);
  strip.setPixelColor(141, 255, 255, 000, 000);
  strip.setPixelColor(139, 255, 255, 000, 000);
  strip.setPixelColor(167, 255, 255, 000, 000);
  strip.setPixelColor(168, 255, 255, 000, 000);
  strip.setPixelColor(175, 255, 255, 000, 000);
  strip.setPixelColor(50, 255, 255, 000, 000);
  strip.setPixelColor(57, 255, 255, 000, 000);
  strip.setPixelColor(92, 255, 255, 000, 000);
  strip.setPixelColor(86, 255, 255, 000, 000);
  strip.show();
  delay(5000);
}
//ctos
void ctos() {
  //strip.setPixelColor(n, red, green, blue, white);
  //Main
  strip.setPixelColor(41, 000, 00, 255, 000);
  strip.setPixelColor(53, 000, 00, 255, 000);
  strip.setPixelColor(54, 000, 00, 255, 000);
  strip.setPixelColor(67, 000, 00, 255, 000);
  strip.setPixelColor(65, 000, 00, 255, 000);
  strip.setPixelColor(77, 000, 00, 255, 000);
  strip.setPixelColor(80, 000, 00, 255, 000);
  strip.setPixelColor(91, 000, 00, 255, 000);
  strip.setPixelColor(87, 000, 00, 255, 000);
  strip.setPixelColor(94, 000, 00, 255, 000);
  strip.setPixelColor(99, 000, 00, 255, 000);
  strip.setPixelColor(107, 000, 00, 255, 000);
  strip.setPixelColor(124, 000, 00, 255, 000);
  strip.setPixelColor(112, 000, 00, 255, 000);
  strip.setPixelColor(116, 000, 00, 255, 000);
  strip.setPixelColor(127, 000, 00, 255, 000);
  strip.setPixelColor(143, 000, 00, 255, 000);
  strip.setPixelColor(147, 000, 00, 255, 000);
  strip.setPixelColor(161, 000, 00, 255, 000);
  strip.setPixelColor(166, 000, 00, 255, 000);
  strip.setPixelColor(176, 000, 00, 255, 000);
  strip.setPixelColor(181, 000, 00, 255, 000);
  strip.setPixelColor(187, 000, 00, 255, 000);
  strip.setPixelColor(182, 000, 00, 255, 000);
  strip.setPixelColor(174, 000, 00, 255, 000);
  strip.setPixelColor(169, 000, 00, 255, 000);
  strip.setPixelColor(157, 000, 00, 255, 000);
  strip.setPixelColor(152, 000, 00, 255, 000);
  strip.setPixelColor(137, 000, 00, 255, 000);
  strip.setPixelColor(134, 000, 00, 255, 000);
  strip.setPixelColor(120, 000, 00, 255, 000);
  strip.setPixelColor(130, 000, 00, 255, 000);
  strip.setPixelColor(131, 000, 00, 255, 000);
  strip.setPixelColor(141, 000, 00, 255, 000);
  strip.setPixelColor(140, 000, 00, 255, 000);
  strip.setPixelColor(139, 000, 00, 255, 000);
  strip.setPixelColor(149, 000, 00, 255, 000);
  strip.setPixelColor(150, 000, 00, 255, 000);
  strip.setPixelColor(159, 000, 00, 255, 000);
  strip.setPixelColor(175, 000, 00, 255, 000);
  strip.setPixelColor(128, 000, 00, 255, 000);
  strip.setPixelColor(133, 000, 00, 255, 000);
  strip.setPixelColor(66, 000, 00, 255, 000);
  strip.setPixelColor(89, 000, 00, 255, 000);
  strip.setPixelColor(102, 000, 00, 255, 000);
  delay(3000);
for (uint16_t i=0; i < 6 && !patternToggled; i++) {
  //C
  strip.setPixelColor(22, 000, 00, 255, 000);
  strip.setPixelColor(21, 000, 00, 255, 000);
  strip.setPixelColor(23, 000, 00, 255, 000);
  strip.setPixelColor(48, 000, 00, 255, 000);
  strip.setPixelColor(71, 000, 00, 255, 000);
  strip.setPixelColor(70, 000, 00, 255, 000);
  //T
  strip.setPixelColor(14, 000, 00, 255, 000);
  strip.setPixelColor(13, 000, 00, 255, 000);
  strip.setPixelColor(12, 000, 00, 255, 000);
  strip.setPixelColor(37, 000, 00, 255, 000);
  strip.setPixelColor(62, 000, 00, 255, 000);
  strip.show();
  delay(3000);
  strip.setPixelColor(22, 000, 00, 0, 000);
  strip.setPixelColor(21, 000, 00, 0, 000);
  strip.setPixelColor(23, 000, 00, 0, 000);
  strip.setPixelColor(48, 000, 00, 0, 000);
  strip.setPixelColor(71, 000, 00, 0, 000);
  strip.setPixelColor(70, 000, 00, 0, 000);
  strip.setPixelColor(14, 000, 00, 0, 000);
  strip.setPixelColor(13, 000, 00, 0, 000);
  strip.setPixelColor(12, 000, 00, 0, 000);
  strip.setPixelColor(37, 000, 00, 0, 000);
  strip.setPixelColor(62, 000, 00, 0, 000);
  //O
  strip.setPixelColor(22, 000, 00, 255, 000);
  strip.setPixelColor(21, 000, 00, 255, 000);
  strip.setPixelColor(23, 000, 00, 255, 000);
  strip.setPixelColor(48, 000, 00, 255, 000);
  strip.setPixelColor(71, 000, 00, 255, 000);
  strip.setPixelColor(70, 000, 00, 255, 000);
  strip.setPixelColor(25, 000, 00, 255, 000);
  strip.setPixelColor(50, 000, 00, 255, 000);
  //T
  strip.setPixelColor(13, 000, 00, 255, 000);
  strip.setPixelColor(12, 000, 00, 255, 000);
  strip.setPixelColor(32, 000, 00, 255, 000);
  strip.setPixelColor(37, 000, 00, 255, 000);
  strip.setPixelColor(36, 000, 00, 255, 000);
  strip.setPixelColor(59, 000, 00, 255, 000);
  strip.setPixelColor(61, 000, 00, 255, 000);
  strip.setPixelColor(62, 000, 00, 255, 000);
  strip.show();
  delay(3000);
  strip.setPixelColor(22, 000, 00, 0, 000);
  strip.setPixelColor(21, 000, 00, 0, 000);
  strip.setPixelColor(23, 000, 00, 0, 000);
  strip.setPixelColor(48, 000, 00, 0, 000);
  strip.setPixelColor(71, 000, 00, 0, 000);
  strip.setPixelColor(70, 000, 00, 0, 000);
  strip.setPixelColor(25, 000, 00, 0, 000);
  strip.setPixelColor(50, 000, 00, 0, 000);
  strip.setPixelColor(13, 000, 00, 0, 000);
  strip.setPixelColor(12, 000, 00, 0, 000);
  strip.setPixelColor(32, 000, 00, 0, 000);
  strip.setPixelColor(37, 000, 00, 0, 000);
  strip.setPixelColor(36, 000, 00, 0, 000);
  strip.setPixelColor(59, 000, 00, 0, 000);
  strip.setPixelColor(61, 000, 00, 0, 000);
  strip.setPixelColor(62, 000, 00, 0, 000);
  strip.show();
}
  delay(2000);
}
//Terminal
void terminal() {
  //strip.setPixelColor(n, red, green, blue, white);
  for(int j=0; j<4 && !patternToggled; j++) {
    strip.setPixelColor(0, 235, 246, 34, 000);
    strip.setPixelColor(23, 235, 246, 34, 000);
    strip.show();
    delay(2000);
    strip.setPixelColor(0, 000, 000, 000, 000);
    strip.setPixelColor(23, 000, 000, 000, 000);
    strip.show();
    delay(500);
  }
  delay(1000);
  for(int j=21; j<217 && !patternToggled; j++) {
    uint32_t color = strip.getPixelColor(j);
    /* generate secret number between 1 and 10: */
    int iSecret = rand() % 2 + 1;
    if (iSecret % 2) {
         strip.setPixelColor(j, 235, 246, 34, 000); 
       }
    strip.show();
  }
  delay(1000);
}

//Dedsec
void dedsec() {
  //strip.setPixelColor(n, red, green, blue, white);
    //left eye
    strip.setPixelColor(24, 179, 190, 186, 000);
    strip.setPixelColor(25, 179, 190, 186, 000);
    strip.setPixelColor(26, 179, 190, 186, 000);
    strip.setPixelColor(27, 179, 190, 186, 000);
    strip.setPixelColor(46, 179, 190, 186, 000);
    strip.setPixelColor(42, 179, 190, 186, 000);
    strip.setPixelColor(71, 179, 190, 186, 000);
    strip.setPixelColor(67, 179, 190, 186, 000);
    strip.setPixelColor(74, 179, 190, 186, 000);
    strip.setPixelColor(77, 179, 190, 186, 000);
    strip.setPixelColor(93, 179, 190, 186, 000);
    strip.setPixelColor(92, 179, 190, 186, 000);
    strip.setPixelColor(91, 179, 190, 186, 000);
    //right eye
    strip.setPixelColor(30, 109, 120, 116, 000);
    strip.setPixelColor(31, 109, 120, 116, 000);
    strip.setPixelColor(32, 109, 120, 116, 000);
    strip.setPixelColor(33, 109, 120, 116, 000);
    strip.setPixelColor(40, 109, 120, 116, 000);
    strip.setPixelColor(36, 109, 120, 116, 000);
    strip.setPixelColor(65, 109, 120, 116, 000);
    strip.setPixelColor(61, 109, 120, 116, 000);
    strip.setPixelColor(83, 109, 120, 116, 000);
    strip.setPixelColor(80, 109, 120, 116, 000);
    strip.setPixelColor(87, 109, 120, 116, 000);
    strip.setPixelColor(86, 109, 120, 116, 000);
    strip.setPixelColor(85, 109, 120, 116, 000);
    //nose
    strip.setPixelColor(96, 109, 120, 116, 000);
    strip.setPixelColor(97, 179, 190, 186, 000);
    strip.setPixelColor(103, 179, 190, 186, 000);
    strip.setPixelColor(101, 109, 120, 116, 000);
    strip.setPixelColor(108, 109, 120, 116, 000);
    strip.setPixelColor(109, 179, 190, 186, 000);
    strip.setPixelColor(110, 109, 120, 116, 000);
    strip.setPixelColor(111, 109, 120, 116, 000);
    //mouth
    strip.setPixelColor(127, 88, 99, 95, 000);
    strip.setPixelColor(143, 88, 99, 95, 000);
    strip.setPixelColor(142, 88, 99, 95, 000);
    strip.setPixelColor(141, 88, 99, 95, 000);
    strip.setPixelColor(140, 88, 99, 95, 000);
    strip.setPixelColor(139, 88, 99, 95, 000);
    strip.setPixelColor(138, 88, 99, 95, 000);
    strip.setPixelColor(137, 88, 99, 95, 000);
    strip.setPixelColor(153, 88, 99, 95, 000);
    strip.setPixelColor(156, 88, 99, 95, 000);
    strip.setPixelColor(170, 88, 99, 95, 000);
    strip.setPixelColor(169, 88, 99, 95, 000);
    strip.setPixelColor(168, 88, 99, 95, 000);
    strip.setPixelColor(159, 88, 99, 95, 000);
    strip.setPixelColor(160, 88, 99, 95, 000);
    strip.setPixelColor(161, 88, 99, 95, 000);
    strip.setPixelColor(146, 88, 99, 95, 000);
  strip.show();
  delay(5000);
}


///-------------------------------------------------------------random games----
//triforce
void triforce() {
  //Main
for(int j=0; j<10 && !patternToggled; j++) {
 strip.setPixelColor(17, 255, 255, 000, 000);
  strip.setPixelColor(28, 255, 255, 000, 000);
  strip.setPixelColor(42, 255, 255, 000, 000);
  strip.setPixelColor(52, 255, 255, 000, 000);
  strip.setPixelColor(68, 255, 255, 000, 000);
  strip.setPixelColor(76, 255, 255, 000, 000);
  strip.setPixelColor(91, 255, 255, 000, 000);
  strip.setPixelColor(92, 255, 255, 000, 000);
  strip.setPixelColor(90, 255, 255, 000, 000);
  strip.setPixelColor(89, 255, 255, 000, 000);
  strip.setPixelColor(88, 255, 255, 000, 000);
  strip.setPixelColor(87, 255, 255, 000, 000);
  strip.setPixelColor(86, 255, 255, 000, 000);
  strip.setPixelColor(81, 255, 255, 000, 000);
  strip.setPixelColor(64, 255, 255, 000, 000);
  strip.setPixelColor(55, 255, 255, 000, 000);
  strip.setPixelColor(40, 255, 255, 000, 000);
  strip.setPixelColor(29, 255, 255, 000, 000);  //top tri
  strip.setPixelColor(94, 255, 255, 000, 000);
  strip.setPixelColor(104, 255, 255, 000, 000);
  strip.setPixelColor(108, 255, 255, 000, 000);
  strip.setPixelColor(121, 255, 255, 000, 000);
  strip.setPixelColor(130, 255, 255, 000, 000);
  strip.setPixelColor(140, 255, 255, 000, 000);
  strip.setPixelColor(141, 255, 255, 000, 000);
  strip.setPixelColor(142, 255, 255, 000, 000);
  strip.setPixelColor(143, 255, 255, 000, 000);
  strip.setPixelColor(144, 255, 255, 000, 000);
  strip.setPixelColor(125, 255, 255, 000, 000);
  strip.setPixelColor(106, 255, 255, 000, 000);
  strip.setPixelColor(113, 255, 255, 000, 000);
  strip.setPixelColor(115, 255, 255, 000, 000);
  strip.setPixelColor(136, 255, 255, 000, 000);
  strip.setPixelColor(137, 255, 255, 000, 000);
  strip.setPixelColor(138, 255, 255, 000, 000);
  strip.setPixelColor(139, 255, 255, 000, 000);
  strip.setPixelColor(131, 255, 255, 000, 000);
  strip.setPixelColor(119, 255, 255, 000, 000);
  strip.setPixelColor(111, 255, 255, 000, 000);
  strip.setPixelColor(100, 255, 255, 000, 000);
  strip.setPixelColor(99, 255, 255, 000, 000);
  strip.show();
  delay(1000);
  }
}
void fourchan(){
 for(int j=0; j<6 && !patternToggled; j++) {
  strip.setPixelColor(20, 255, 255, 000, 000);
  strip.setPixelColor(25, 255, 255, 000, 000);
  strip.setPixelColor(45, 255, 255, 000, 000);
  strip.setPixelColor(49, 255, 255, 000, 000);
  strip.setPixelColor(71, 255, 255, 000, 000);
  strip.setPixelColor(73, 255, 255, 000, 000);
  strip.setPixelColor(93, 255, 255, 000, 000);
  strip.setPixelColor(92, 255, 255, 000, 000);
  strip.setPixelColor(91, 255, 255, 000, 000);
  strip.setPixelColor(90, 255, 255, 000, 000);
  strip.setPixelColor(89, 255, 255, 000, 000);
  strip.setPixelColor(78, 255, 255, 000, 000);
  strip.setPixelColor(67, 255, 255, 000, 000);
  strip.setPixelColor(52, 255, 255, 000, 000);
  strip.setPixelColor(43, 255, 255, 000, 000);
  strip.setPixelColor(26, 255, 255, 000, 000);

  strip.setPixelColor(94, 255, 255, 000, 000);
  strip.setPixelColor(104, 255, 255, 000, 000);
  strip.setPixelColor(108, 255, 255, 000, 000);
  strip.setPixelColor(121, 255, 255, 000, 000);
  strip.setPixelColor(130, 255, 255, 000, 000);
  strip.setPixelColor(140, 255, 255, 000, 000);
  strip.setPixelColor(141, 255, 255, 000, 000);
  strip.setPixelColor(142, 255, 255, 000, 000);
  strip.setPixelColor(143, 255, 255, 000, 000);
  strip.setPixelColor(144, 255, 255, 000, 000);
  strip.setPixelColor(125, 255, 255, 000, 000);
  strip.setPixelColor(106, 255, 255, 000, 000);
  strip.setPixelColor(113, 255, 255, 000, 000);
  strip.setPixelColor(115, 255, 255, 000, 000);
  strip.setPixelColor(136, 255, 255, 000, 000);
  strip.setPixelColor(137, 255, 255, 000, 000);
  strip.setPixelColor(138, 255, 255, 000, 000);
  strip.setPixelColor(139, 255, 255, 000, 000);
  strip.setPixelColor(131, 255, 255, 000, 000);
  strip.setPixelColor(119, 255, 255, 000, 000);
  strip.setPixelColor(111, 255, 255, 000, 000);
  strip.setPixelColor(100, 255, 255, 000, 000);
  strip.setPixelColor(99, 255, 255, 000, 000);
  strip.show();
  delay(1000);
  }
}
//portal
void cube() {
   for(int j=0; j<6 && !patternToggled; j++) {
    strip.setPixelColor(67, 197, 53, 141, 000);
    strip.setPixelColor(65, 197, 53, 141, 000);
    strip.setPixelColor(77, 197, 53, 141, 000);
    strip.setPixelColor(78, 197, 53, 141, 000);
    strip.setPixelColor(79, 197, 53, 141, 000);
    strip.setPixelColor(80, 197, 53, 141, 000);
    strip.setPixelColor(90, 197, 53, 141, 000);
    strip.setPixelColor(89, 197, 53, 141, 000);
    strip.setPixelColor(88, 197, 53, 141, 000);
    strip.setPixelColor(96, 197, 53, 141, 000);
    strip.setPixelColor(97, 197, 53, 141, 000);
    strip.setPixelColor(102, 197, 53, 141, 000);
    strip.setPixelColor(52, 204, 223, 227, 127);
    strip.setPixelColor(53, 204, 223, 227, 127);
    strip.setPixelColor(54, 204, 223, 227, 127);
    strip.setPixelColor(55, 204, 223, 227, 127);
    strip.setPixelColor(68, 204, 223, 227, 127);
    strip.setPixelColor(66, 204, 223, 227, 127);
    strip.setPixelColor(64, 204, 223, 227, 127);
    strip.setPixelColor(76, 204, 223, 227, 127);
    strip.setPixelColor(81, 204, 223, 227, 127);
    strip.setPixelColor(91, 204, 223, 227, 127);
    strip.setPixelColor(87, 204, 223, 227, 127);
    strip.setPixelColor(95, 204, 223, 227, 127);
    strip.setPixelColor(94, 204, 223, 227, 127);
    strip.setPixelColor(98, 204, 223, 227, 127);
    strip.setPixelColor(99, 204, 223, 227, 127);
    strip.setPixelColor(104, 204, 223, 227, 127);
    strip.setPixelColor(103, 204, 223, 227, 127);
    strip.setPixelColor(101, 204, 223, 227, 127);
    strip.setPixelColor(100, 204, 223, 227, 127);
    strip.setPixelColor(109, 204, 223, 227, 127);
    strip.setPixelColor(110, 204, 223, 227, 127);
    strip.setPixelColor(108, 204, 223, 227, 127);
    strip.setPixelColor(111, 204, 223, 227, 127);
    strip.setPixelColor(120, 204, 223, 227, 127);
    strip.setPixelColor(41, 204, 223, 227, 127);
    strip.setPixelColor(42, 204, 223, 227, 127);
    strip.setPixelColor(40, 204, 223, 227, 127);
    strip.setPixelColor(121, 204, 223, 227, 127);
    strip.setPixelColor(119, 204, 223, 227, 127);
    //outer
    strip.setPixelColor(1, 204, 223, 227, 127);
    strip.setPixelColor(2, 204, 223, 227, 127);
    strip.setPixelColor(3, 204, 223, 227, 127);
    strip.setPixelColor(5, 204, 223, 227, 127);
    strip.setPixelColor(6, 204, 223, 227, 127);
    strip.setPixelColor(21, 204, 223, 227, 127);
    strip.setPixelColor(20, 204, 223, 227, 127);
    strip.setPixelColor(24, 204, 223, 227, 127);
    strip.setPixelColor(25, 204, 223, 227, 127);
    strip.setPixelColor(45, 204, 223, 227, 127);
    strip.setPixelColor(49, 204, 223, 227, 127);
    strip.setPixelColor(106, 204, 223, 227, 127);
    strip.setPixelColor(124, 204, 223, 227, 127);
    strip.setPixelColor(126, 204, 223, 227, 127);
    strip.setPixelColor(127, 204, 223, 227, 127);
    strip.setPixelColor(144, 204, 223, 227, 127);
    strip.setPixelColor(143, 204, 223, 227, 127);
    strip.setPixelColor(145, 204, 223, 227, 127);
    strip.setPixelColor(146, 204, 223, 227, 127);
    strip.setPixelColor(147, 204, 223, 227, 127);
    strip.setPixelColor(149, 204, 223, 227, 127);
    strip.setPixelColor(150, 204, 223, 227, 127);
    strip.setPixelColor(152, 204, 223, 227, 127);
    strip.setPixelColor(153, 204, 223, 227, 127);
    strip.setPixelColor(154, 204, 223, 227, 127);
    strip.setPixelColor(137, 204, 223, 227, 127);
    strip.setPixelColor(136, 204, 223, 227, 127);
    strip.setPixelColor(134, 204, 223, 227, 127);
    strip.setPixelColor(135, 204, 223, 227, 127);
    strip.setPixelColor(116, 204, 223, 227, 127);
    strip.setPixelColor(113, 204, 223, 227, 127);
    strip.setPixelColor(58, 204, 223, 227, 127);
    strip.setPixelColor(37, 204, 223, 227, 127);
    strip.setPixelColor(32, 204, 223, 227, 127);
    strip.setPixelColor(33, 204, 223, 227, 127);
    strip.setPixelColor(14, 204, 223, 227, 127);
    strip.setPixelColor(13, 204, 223, 227, 127);
    strip.setPixelColor(8, 204, 223, 227, 127);
    strip.setPixelColor(10, 204, 223, 227, 127);
  strip.show();
  delay(1000);
   }
}
void bluePortal() {
  //blue portal
for(int j=0; j<10 && !patternToggled; j++) {
  strip.setPixelColor(6, 3, 85, 209, 000);
  strip.setPixelColor(16, 3, 85, 209, 000);
  strip.setPixelColor(17, 3, 85, 209, 000);
  strip.setPixelColor(29, 3, 85, 209, 000);
  strip.setPixelColor(28, 3, 85, 209, 000);
  strip.setPixelColor(41, 3, 85, 209, 000);
  strip.setPixelColor(42, 3, 85, 209, 000);
  strip.setPixelColor(27, 3, 85, 209, 000);
  strip.setPixelColor(52, 3, 85, 209, 000);
  strip.setPixelColor(68, 3, 85, 209, 000);
  strip.setPixelColor(43, 3, 85, 209, 000);
  strip.setPixelColor(76, 3, 85, 209, 000);
  strip.setPixelColor(51, 3, 85, 209, 000);
  strip.setPixelColor(92, 3, 85, 209, 000);
  strip.setPixelColor(91, 3, 85, 209, 000);
  strip.setPixelColor(94, 3, 85, 209, 000);
  strip.setPixelColor(107, 3, 85, 209, 000);
  strip.setPixelColor(124, 3, 85, 209, 000);
  strip.setPixelColor(123, 3, 85, 209, 000);
  strip.setPixelColor(127, 3, 85, 209, 000);
  strip.setPixelColor(128, 3, 85, 209, 000);
  strip.setPixelColor(144, 3, 85, 209, 000);
  strip.setPixelColor(143, 3, 85, 209, 000);
  strip.setPixelColor(146, 3, 85, 209, 000);
  strip.setPixelColor(147, 3, 85, 209, 000);
  strip.setPixelColor(163, 3, 85, 209, 000);
  strip.setPixelColor(162, 3, 85, 209, 000);
  strip.setPixelColor(164, 3, 85, 209, 000);
  strip.setPixelColor(165, 3, 85, 209, 000);
  strip.setPixelColor(178, 3, 85, 209, 000);
  strip.setPixelColor(179, 3, 85, 209, 000);
  strip.setPixelColor(189, 3, 85, 209, 000);
  strip.setPixelColor(190, 3, 85, 209, 000);
  strip.setPixelColor(191, 3, 85, 209, 000);
  strip.setPixelColor(198, 3, 85, 209, 000);
  strip.setPixelColor(199, 3, 85, 209, 000);
  strip.setPixelColor(197, 3, 85, 209, 000);
  strip.setPixelColor(194, 3, 85, 209, 000);
  strip.setPixelColor(185, 3, 85, 209, 000);
  strip.setPixelColor(184, 3, 85, 209, 000);
  strip.setPixelColor(172, 3, 85, 209, 000);
  strip.setPixelColor(171, 3, 85, 209, 000);
  strip.setPixelColor(155, 3, 85, 209, 000);
  strip.setPixelColor(154, 3, 85, 209, 000);
  strip.setPixelColor(136, 3, 85, 209, 000);
  strip.setPixelColor(135, 3, 85, 209, 000);
  strip.setPixelColor(115, 3, 85, 209, 000);
  strip.setPixelColor(113, 3, 85, 209, 000);
  strip.setPixelColor(114, 3, 85, 209, 000);
  strip.setPixelColor(83, 3, 85, 209, 000);
  strip.setPixelColor(84, 3, 85, 209, 000);
  strip.setPixelColor(62, 3, 85, 209, 000);
  strip.setPixelColor(61, 3, 85, 209, 000);
  strip.setPixelColor(57, 3, 85, 209, 000);
  strip.setPixelColor(58, 3, 85, 209, 000);
  strip.setPixelColor(37, 3, 85, 209, 000);
  strip.setPixelColor(32, 3, 85, 209, 000);
  strip.setPixelColor(33, 3, 85, 209, 000);
  strip.setPixelColor(15, 3, 85, 209, 000);
  strip.setPixelColor(14, 3, 85, 209, 000);
  strip.setPixelColor(13, 3, 85, 209, 000);
  strip.setPixelColor(7, 3, 85, 209, 000);
  strip.setPixelColor(8, 3, 85, 209, 000);
  strip.show();
  delay(1000);
  }
}
void orangePortal() {
  //orange portal
for(int j=0; j<10 && !patternToggled; j++) {
  strip.setPixelColor(6, 214, 107, 8, 000);
  strip.setPixelColor(16, 214, 107, 8, 000);
  strip.setPixelColor(17, 214, 107, 8, 000);
  strip.setPixelColor(29, 214, 107, 8, 000);
  strip.setPixelColor(28, 214, 107, 8, 000);
  strip.setPixelColor(41, 214, 107, 8, 000);
  strip.setPixelColor(42, 214, 107, 8, 000);
  strip.setPixelColor(27, 214, 107, 8, 000);
  strip.setPixelColor(52, 214, 107, 8, 000);
  strip.setPixelColor(68, 214, 107, 8, 000);
  strip.setPixelColor(43, 214, 107, 8, 000);
  strip.setPixelColor(76, 214, 107, 8, 000);
  strip.setPixelColor(51, 214, 107, 8, 000);
  strip.setPixelColor(92, 214, 107, 8, 000);
  strip.setPixelColor(91, 214, 107, 8, 000);
  strip.setPixelColor(94, 214, 107, 8, 000);
  strip.setPixelColor(107, 214, 107, 8, 000);
  strip.setPixelColor(124, 214, 107, 8, 000);
  strip.setPixelColor(123, 214, 107, 8, 000);
  strip.setPixelColor(127, 214, 107, 8, 000);
  strip.setPixelColor(128, 214, 107, 8, 000);
  strip.setPixelColor(144, 214, 107, 8, 000);
  strip.setPixelColor(143, 214, 107, 8, 000);
  strip.setPixelColor(146, 214, 107, 8, 000);
  strip.setPixelColor(147, 214, 107, 8, 000);
  strip.setPixelColor(163, 214, 107, 8, 000);
  strip.setPixelColor(162, 214, 107, 8, 000);
  strip.setPixelColor(164, 214, 107, 8, 000);
  strip.setPixelColor(165, 214, 107, 8, 000);
  strip.setPixelColor(178, 214, 107, 8, 000);
  strip.setPixelColor(179, 214, 107, 8, 000);
  strip.setPixelColor(189, 214, 107, 8, 000);
  strip.setPixelColor(190, 214, 107, 8, 000);
  strip.setPixelColor(191, 214, 107, 8, 000);
  strip.setPixelColor(198, 214, 107, 8, 000);
  strip.setPixelColor(199, 214, 107, 8, 000);
  strip.setPixelColor(197, 214, 107, 8, 000);
  strip.setPixelColor(194, 214, 107, 8, 000);
  strip.setPixelColor(185, 214, 107, 8, 000);
  strip.setPixelColor(184, 214, 107, 8, 000);
  strip.setPixelColor(172, 214, 107, 8, 000);
  strip.setPixelColor(171, 214, 107, 8, 000);
  strip.setPixelColor(155, 214, 107, 8, 000);
  strip.setPixelColor(154, 214, 107, 8, 000);
  strip.setPixelColor(136, 214, 107, 8, 000);
  strip.setPixelColor(135, 214, 107, 8, 000);
  strip.setPixelColor(115, 214, 107, 8, 000);
  strip.setPixelColor(113, 214, 107, 8, 000);
  strip.setPixelColor(114, 214, 107, 8, 000);
  strip.setPixelColor(83, 214, 107, 8, 000);
  strip.setPixelColor(84, 214, 107, 8, 000);
  strip.setPixelColor(62, 214, 107, 8, 000);
  strip.setPixelColor(61, 214, 107, 8, 000);
  strip.setPixelColor(57, 214, 107, 8, 000);
  strip.setPixelColor(58, 214, 107, 8, 000);
  strip.setPixelColor(37, 214, 107, 8, 000);
  strip.setPixelColor(32, 214, 107, 8, 000);
  strip.setPixelColor(33, 214, 107, 8, 000);
  strip.setPixelColor(15, 214, 107, 8, 000);
  strip.setPixelColor(14, 214, 107, 8, 000);
  strip.setPixelColor(13, 214, 107, 8, 000);
  strip.setPixelColor(7, 214, 107, 8, 000);
  strip.setPixelColor(8, 214, 107, 8, 000);
  strip.show();
  delay(1000);
  }
}

//borderlands
void borderlands() {
  //strip.setPixelColor(n, red, green, blue, white);
  //Main
  strip.setPixelColor(17, 238, 222, 25, 000);
  strip.setPixelColor(18, 238, 222, 25, 000);
  strip.setPixelColor(27, 238, 222, 25, 000);
  strip.setPixelColor(26, 238, 222, 25, 000);
  strip.setPixelColor(44, 238, 222, 25, 000);
  strip.setPixelColor(50, 238, 222, 25, 000);
  strip.setPixelColor(49, 238, 222, 25, 000);
  strip.setPixelColor(70, 238, 222, 25, 000);
  strip.setPixelColor(71, 238, 222, 25, 000);
  strip.setPixelColor(74, 238, 222, 25, 000);
  strip.setPixelColor(73, 238, 222, 25, 000);
  strip.setPixelColor(105, 238, 222, 25, 000);
  strip.setPixelColor(125, 238, 222, 25, 000);
  strip.setPixelColor(126, 238, 222, 25, 000);
  strip.setPixelColor(144, 238, 222, 25, 000);
  strip.setPixelColor(145, 238, 222, 25, 000);
  strip.setPixelColor(146, 238, 222, 25, 000);
  strip.setPixelColor(147, 238, 222, 25, 000);
  strip.setPixelColor(163, 238, 222, 25, 000);
  strip.setPixelColor(162, 238, 222, 25, 000);
  strip.setPixelColor(165, 238, 222, 25, 000);
  strip.setPixelColor(166, 238, 222, 25, 000);
  strip.setPixelColor(167, 238, 222, 25, 000);
  strip.setPixelColor(176, 238, 222, 25, 000);
  strip.setPixelColor(168, 238, 222, 25, 000);
  strip.setPixelColor(175, 238, 222, 25, 000);
  strip.setPixelColor(169, 238, 222, 25, 000);
  strip.setPixelColor(174, 238, 222, 25, 000);
  strip.setPixelColor(170, 238, 222, 25, 000);
  strip.setPixelColor(156, 238, 222, 25, 000);
  strip.setPixelColor(152, 238, 222, 25, 000);
  strip.setPixelColor(153, 238, 222, 25, 000);
  strip.setPixelColor(155, 238, 222, 25, 000);
  strip.setPixelColor(136, 238, 222, 25, 000);
  strip.setPixelColor(135, 238, 222, 25, 000);
  strip.setPixelColor(115, 238, 222, 25, 000);
  strip.setPixelColor(114, 238, 222, 25, 000);
  strip.setPixelColor(83, 238, 222, 25, 000);
  strip.setPixelColor(62, 238, 222, 25, 000);
  strip.setPixelColor(61, 238, 222, 25, 000);
  strip.setPixelColor(57, 238, 222, 25, 000);
  strip.setPixelColor(58, 238, 222, 25, 000);
  strip.setPixelColor(38, 238, 222, 25, 000);
  strip.setPixelColor(84, 238, 222, 25, 000);
  strip.setPixelColor(30, 238, 222, 25, 000);
  strip.setPixelColor(31, 238, 222, 25, 000);
  strip.setPixelColor(16, 238, 222, 25, 000);
  strip.setPixelColor(143, 238, 222, 25, 000);
  strip.setPixelColor(142, 238, 222, 25, 000);
  strip.setPixelColor(128, 238, 222, 25, 000);
  strip.setPixelColor(122, 238, 222, 25, 000);
  strip.setPixelColor(108, 238, 222, 25, 000);
  strip.setPixelColor(104, 238, 222, 25, 000);
  strip.setPixelColor(95, 238, 222, 25, 000);
  strip.setPixelColor(90, 238, 222, 25, 000);
  strip.setPixelColor(77, 238, 222, 25, 000);
  strip.setPixelColor(67, 238, 222, 25, 000);
  strip.setPixelColor(53, 238, 222, 25, 000);
  strip.setPixelColor(54, 238, 222, 25, 000);
  strip.setPixelColor(65, 238, 222, 25, 000);
  strip.setPixelColor(80, 238, 222, 25, 000);
  strip.setPixelColor(88, 238, 222, 25, 000);
  strip.setPixelColor(98, 238, 222, 25, 000);
  strip.setPixelColor(100, 238, 222, 25, 000);
  strip.setPixelColor(111, 238, 222, 25, 000);
  strip.setPixelColor(118, 238, 222, 25, 000);
  strip.setPixelColor(133, 238, 222, 25, 000);
  strip.setPixelColor(138, 238, 222, 25, 000);
  strip.setPixelColor(137, 238, 222, 25, 000);
  strip.show();
  delay(5000);
}
//halflife
void halflife() {
  //strip.setPixelColor(n, red, green, blue, white);
  //Main
for(int d=0; d<10 && !patternToggled; d++) {
  strip.setPixelColor(17, 243, 123, 33, 000);
  strip.setPixelColor(18, 243, 123, 33, 000);
  strip.setPixelColor(27, 243, 123, 33, 000);
  strip.setPixelColor(26, 243, 123, 33, 000);
  strip.setPixelColor(44, 243, 123, 33, 000);
  strip.setPixelColor(50, 243, 123, 33, 000);
  strip.setPixelColor(49, 243, 123, 33, 000);
  strip.setPixelColor(70, 243, 123, 33, 000);
  strip.setPixelColor(71, 243, 123, 33, 000);
  strip.setPixelColor(74, 243, 123, 33, 000);
  strip.setPixelColor(73, 243, 123, 33, 000);
  strip.setPixelColor(105, 243, 123, 33, 000);
  strip.setPixelColor(125, 243, 123, 33, 000);
  strip.setPixelColor(126, 243, 123, 33, 000);
  strip.setPixelColor(144, 243, 123, 33, 000);
  strip.setPixelColor(145, 243, 123, 33, 000);
  strip.setPixelColor(146, 243, 123, 33, 000);
  strip.setPixelColor(163, 243, 123, 33, 000);
  strip.setPixelColor(162, 243, 123, 33, 000);
  strip.setPixelColor(165, 243, 123, 33, 000);
  strip.setPixelColor(166, 243, 123, 33, 000);
  strip.setPixelColor(167, 243, 123, 33, 000);
  strip.setPixelColor(176, 243, 123, 33, 000);
  strip.setPixelColor(168, 243, 123, 33, 000);
  strip.setPixelColor(175, 243, 123, 33, 000);
  strip.setPixelColor(169, 243, 123, 33, 000);
  strip.setPixelColor(174, 243, 123, 33, 000);
  strip.setPixelColor(170, 243, 123, 33, 000);
  strip.setPixelColor(156, 243, 123, 33, 000);
  strip.setPixelColor(153, 243, 123, 33, 000);
  strip.setPixelColor(155, 243, 123, 33, 000);
  strip.setPixelColor(136, 243, 123, 33, 000);
  strip.setPixelColor(135, 243, 123, 33, 000);
  strip.setPixelColor(115, 243, 123, 33, 000);
  strip.setPixelColor(114, 243, 123, 33, 000);
  strip.setPixelColor(83, 243, 123, 33, 000);
  strip.setPixelColor(62, 243, 123, 33, 000);
  strip.setPixelColor(61, 243, 123, 33, 000);
  strip.setPixelColor(57, 243, 123, 33, 000);
  strip.setPixelColor(58, 243, 123, 33, 000);
  strip.setPixelColor(38, 243, 123, 33, 000);
  strip.setPixelColor(84, 243, 123, 33, 000);
  strip.setPixelColor(30, 243, 123, 33, 000);
  strip.setPixelColor(31, 243, 123, 33, 000);
  strip.setPixelColor(16, 243, 123, 33, 000);
  strip.setPixelColor(67, 243, 123, 33, 000);
  strip.setPixelColor(68, 243, 123, 33, 000);
  strip.setPixelColor(78, 243, 123, 33, 000);
  strip.setPixelColor(96, 243, 123, 33, 000);
  strip.setPixelColor(89, 243, 123, 33, 000);
  strip.setPixelColor(97, 243, 123, 33, 000);
  strip.setPixelColor(103, 243, 123, 33, 000);
  strip.setPixelColor(102, 243, 123, 33, 000);
  strip.setPixelColor(101, 243, 123, 33, 000);
  strip.setPixelColor(108, 243, 123, 33, 000);
  strip.setPixelColor(122, 243, 123, 33, 000);
  strip.setPixelColor(111, 243, 123, 33, 000);
  strip.setPixelColor(118, 243, 123, 33, 000);
  strip.setPixelColor(117, 243, 123, 33, 000);
  strip.show();
  delay(1000);
}
}
void three(){
 for(int j=0; j<5 && !patternToggled; j++) {
  strip.setPixelColor(26, 243, 123, 33, 000);
  strip.setPixelColor(18, 243, 123, 33, 000);
  strip.setPixelColor(17, 243, 123, 33, 000);
  strip.setPixelColor(16, 243, 123, 33, 000);
  strip.setPixelColor(15, 243, 123, 33, 000);
  strip.setPixelColor(32, 243, 123, 33, 000);
  strip.setPixelColor(37, 243, 123, 33, 000);
  strip.setPixelColor(58, 243, 123, 33, 000);
  strip.setPixelColor(83, 243, 123, 33, 000);
  strip.setPixelColor(85, 243, 123, 33, 000);
  strip.setPixelColor(100, 243, 123, 33, 000);
  strip.setPixelColor(112, 243, 123, 33, 000);
  strip.setPixelColor(116, 243, 123, 33, 000);
  strip.setPixelColor(135, 243, 123, 33, 000);
  strip.setPixelColor(154, 243, 123, 33, 000);
  strip.setPixelColor(155, 243, 123, 33, 000);
  strip.setPixelColor(171, 243, 123, 33, 000);
  strip.setPixelColor(173, 243, 123, 33, 000);
  strip.setPixelColor(174, 243, 123, 33, 000);
  strip.setPixelColor(175, 243, 123, 33, 000);
  strip.setPixelColor(176, 243, 123, 33, 000);
  strip.setPixelColor(177, 243, 123, 33, 000);
  strip.setPixelColor(164, 243, 123, 33, 000);
  strip.setPixelColor(146, 243, 123, 33, 000);
  strip.setPixelColor(161, 243, 123, 33, 000);
  strip.setPixelColor(160, 243, 123, 33, 000);
  strip.setPixelColor(159, 243, 123, 33, 000);
  strip.setPixelColor(158, 243, 123, 33, 000);
  strip.setPixelColor(177, 243, 123, 33, 000);
  strip.setPixelColor(164, 243, 123, 33, 000);
  strip.setPixelColor(146, 243, 123, 33, 000);
  strip.setPixelColor(161, 243, 123, 33, 000);
  strip.setPixelColor(160, 243, 123, 33, 000);
  strip.setPixelColor(159, 243, 123, 33, 000);
  strip.setPixelColor(158, 243, 123, 33, 000);
  strip.setPixelColor(151, 243, 123, 33, 000);
  strip.setPixelColor(138, 243, 123, 33, 000);
  strip.setPixelColor(132, 243, 123, 33, 000);
  strip.setPixelColor(119, 243, 123, 33, 000);
  strip.setPixelColor(110, 243, 123, 33, 000);
  strip.setPixelColor(109, 243, 123, 33, 000);
  strip.setPixelColor(108, 243, 123, 33, 000);
  strip.setPixelColor(95, 243, 123, 33, 000);
  strip.setPixelColor(96, 243, 123, 33, 000);
  strip.setPixelColor(97, 243, 123, 33, 000);
  strip.setPixelColor(88, 243, 123, 33, 000);
  strip.setPixelColor(80, 243, 123, 33, 000);
  strip.setPixelColor(64, 243, 123, 33, 000);
  strip.setPixelColor(55, 243, 123, 33, 000);
  strip.setPixelColor(40, 243, 123, 33, 000);
  strip.setPixelColor(41, 243, 123, 33, 000);
  strip.setPixelColor(42, 243, 123, 33, 000);
  strip.setPixelColor(51, 243, 123, 33, 000);
  strip.show();
  delay(1000);
  }
}
void huh(){ //!
 for(int j=0; j<5 && !patternToggled; j++) {
  strip.setPixelColor(18, 255, 000, 000, 000);
  strip.setPixelColor(17, 255, 000, 000, 000);
  strip.setPixelColor(16, 255, 000, 000, 000);
  strip.setPixelColor(28, 255, 000, 000, 000);
  strip.setPixelColor(29, 255, 000, 000, 000);
  strip.setPixelColor(41, 255, 000, 000, 000);
  strip.setPixelColor(53, 255, 000, 000, 000);
  strip.setPixelColor(54, 255, 000, 000, 000);
  strip.setPixelColor(66, 255, 000, 000, 000);
  strip.setPixelColor(42, 255, 000, 000, 000);
  strip.setPixelColor(89, 255, 000, 000, 000);
  strip.setPixelColor(102, 255, 000, 000, 000);
  strip.setPixelColor(140, 255, 000, 000, 000);
  strip.setPixelColor(120, 255, 000, 000, 000);
  strip.setPixelColor(40, 255, 000, 000, 000);
  strip.setPixelColor(67, 255, 000, 000, 000);
  strip.setPixelColor(65, 255, 000, 000, 000);
  strip.setPixelColor(78, 255, 000, 000, 000);
  strip.setPixelColor(79, 255, 000, 000, 000);
  strip.setPixelColor(96, 255, 000, 000, 000);
  strip.setPixelColor(97, 255, 000, 000, 000);
  strip.setPixelColor(109, 255, 000, 000, 000);
  strip.setPixelColor(110, 255, 000, 000, 000);
  strip.setPixelColor(130, 255, 000, 000, 000);
  strip.setPixelColor(131, 255, 000, 000, 000);
  strip.setPixelColor(159, 255, 000, 000, 000);
  strip.setPixelColor(175, 255, 000, 000, 000);
  strip.setPixelColor(90, 255, 000, 000, 000);
  strip.setPixelColor(88, 255, 000, 000, 000);
  strip.setPixelColor(149, 255, 000, 000, 000);
  strip.setPixelColor(150, 255, 000, 000, 000);
  strip.setPixelColor(198, 255, 000, 000, 000);
  strip.setPixelColor(202, 255, 000, 000, 000);
  strip.setPixelColor(203, 255, 000, 000, 000);
  strip.setPixelColor(206, 255, 000, 000, 000);
  strip.show();
  delay(1000);
  }
}
void hmm(){ //?
 for(int j=0; j<10 && !patternToggled; j++) {
  strip.setPixelColor(91, 000, 000, 255, 000);
  strip.setPixelColor(76, 000, 000, 255, 000);
  strip.setPixelColor(69, 000, 000, 255, 000);
  strip.setPixelColor(44, 000, 000, 255, 000);
  strip.setPixelColor(26, 000, 000, 255, 000);
  strip.setPixelColor(19, 000, 000, 255, 000);
  strip.setPixelColor(5, 000, 000, 255, 000);
  strip.setPixelColor(6, 000, 000, 255, 000);
  strip.setPixelColor(15, 000, 000, 255, 000);
  strip.setPixelColor(31, 000, 000, 255, 000);
  strip.setPixelColor(38, 000, 000, 255, 000);
  strip.setPixelColor(63, 000, 000, 255, 000);
  strip.setPixelColor(81, 000, 000, 255, 000);
  strip.setPixelColor(87, 000, 000, 255, 000);
  strip.setPixelColor(98, 000, 000, 255, 000);
  strip.setPixelColor(102, 000, 000, 255, 000);
  strip.setPixelColor(120, 000, 000, 255, 000);
  strip.setPixelColor(140, 000, 000, 255, 000);
  strip.setPixelColor(175, 000, 000, 255, 000);
  strip.show();
  delay(1000);
 }
}
//----------------------------------------------anime---------
//fullmetal
void fullmetal() {
  //strip.setPixelColor(n, red, green, blue, white);
    strip.setPixelColor(23, 154, 000, 000, 000);
    strip.setPixelColor(24, 154, 000, 000, 000);
    strip.setPixelColor(25, 154, 000, 000, 000);
    strip.setPixelColor(44, 154, 000, 000, 000);
    strip.setPixelColor(51, 154, 000, 000, 000);
    strip.setPixelColor(68, 154, 000, 000, 000);
    strip.setPixelColor(50, 154, 000, 000, 000);
    strip.setPixelColor(49, 154, 000, 000, 000);
    strip.setPixelColor(46, 154, 000, 000, 000);
    strip.setPixelColor(19, 154, 000, 000, 000);
    strip.setPixelColor(17, 154, 000, 000, 000);
    strip.setPixelColor(15, 154, 000, 000, 000);
    strip.setPixelColor(39, 154, 000, 000, 000);
    strip.setPixelColor(40, 154, 000, 000, 000);
    strip.setPixelColor(41, 154, 000, 000, 000);
    strip.setPixelColor(42, 154, 000, 000, 000);
    strip.setPixelColor(43, 154, 000, 000, 000);
    strip.setPixelColor(17, 154, 000, 000, 000);
    strip.setPixelColor(28, 154, 000, 000, 000);
    strip.setPixelColor(29, 154, 000, 000, 000);
    strip.setPixelColor(64, 154, 000, 000, 000);
    strip.setPixelColor(56, 154, 000, 000, 000);
    strip.setPixelColor(57, 154, 000, 000, 000);
    strip.setPixelColor(58, 154, 000, 000, 000);
    strip.setPixelColor(36, 154, 000, 000, 000);
    strip.setPixelColor(34, 154, 000, 000, 000);
    strip.setPixelColor(33, 154, 000, 000, 000);
    strip.setPixelColor(32, 154, 000, 000, 000);
    strip.setPixelColor(38, 154, 000, 000, 000);
    //main
    strip.setPixelColor(66, 154, 000, 000, 000);
    strip.setPixelColor(89, 154, 000, 000, 000);
    strip.setPixelColor(102, 154, 000, 000, 000);
    strip.setPixelColor(120, 154, 000, 000, 000);
    strip.setPixelColor(140, 154, 000, 000, 000);
    strip.setPixelColor(159, 154, 000, 000, 000);
    strip.setPixelColor(175, 154, 000, 000, 000);
    strip.setPixelColor(187, 154, 000, 000, 000);
    strip.setPixelColor(198, 154, 000, 000, 000);
    strip.setPixelColor(206, 154, 000, 000, 000);
    strip.setPixelColor(107, 154, 000, 000, 000);
    strip.setPixelColor(108, 154, 000, 000, 000);
    strip.setPixelColor(109, 154, 000, 000, 000);
    strip.setPixelColor(110, 154, 000, 000, 000);
    strip.setPixelColor(111, 154, 000, 000, 000);
    strip.setPixelColor(112, 154, 000, 000, 000);
    strip.setPixelColor(129, 154, 000, 000, 000);
    strip.setPixelColor(122, 154, 000, 000, 000);
    strip.setPixelColor(104, 154, 000, 000, 000);
    strip.setPixelColor(95, 154, 000, 000, 000);
    strip.setPixelColor(90, 154, 000, 000, 000);
    strip.setPixelColor(88, 154, 000, 000, 000);
    strip.setPixelColor(98, 154, 000, 000, 000);
    strip.setPixelColor(100, 154, 000, 000, 000);
    strip.setPixelColor(118, 154, 000, 000, 000);
    strip.setPixelColor(132, 154, 000, 000, 000);
    strip.setPixelColor(139, 154, 000, 000, 000);
    strip.setPixelColor(149, 154, 000, 000, 000);
    strip.setPixelColor(160, 154, 000, 000, 000);
    strip.setPixelColor(166, 154, 000, 000, 000);
    strip.setPixelColor(176, 154, 000, 000, 000);
    strip.setPixelColor(181, 154, 000, 000, 000);
    strip.setPixelColor(193, 154, 000, 000, 000);
    strip.setPixelColor(197, 154, 000, 000, 000);
    strip.setPixelColor(202, 154, 000, 000, 000);
  strip.show();
  delay(5000);
}

//rwby
void rwbyR() {
for(int d=0; d<4 && !patternToggled; d++) {
  //R
    strip.setPixelColor(20, 214, 000, 000, 000);
    strip.setPixelColor(19, 214, 000, 000, 000);
    strip.setPixelColor(18, 214, 000, 000, 000);
    strip.setPixelColor(17, 214, 000, 000, 000);
    strip.setPixelColor(30, 214, 000, 000, 000);
    strip.setPixelColor(39, 214, 000, 000, 000);
    strip.setPixelColor(56, 214, 000, 000, 000);
    strip.setPixelColor(64, 214, 000, 000, 000);
    strip.setPixelColor(80, 214, 000, 000, 000);
    strip.setPixelColor(90, 214, 000, 000, 000);
    strip.setPixelColor(89, 214, 000, 000, 000);
    strip.setPixelColor(97, 214, 000, 000, 000);
    strip.setPixelColor(101, 214, 000, 000, 000);
    strip.setPixelColor(111, 214, 000, 000, 000);
    strip.setPixelColor(118, 214, 000, 000, 000);
    strip.setPixelColor(133, 214, 000, 000, 000);
    strip.setPixelColor(137, 214, 000, 000, 000);
    strip.setPixelColor(153, 214, 000, 000, 000);
    strip.setPixelColor(26, 214, 000, 000, 000);
    strip.setPixelColor(51, 214, 000, 000, 000);
    strip.setPixelColor(76, 214, 000, 000, 000);
    strip.setPixelColor(94, 214, 000, 000, 000);
    strip.setPixelColor(128, 214, 000, 000, 000);
    strip.setPixelColor(147, 214, 000, 000, 000);
    strip.setPixelColor(165, 214, 000, 000, 000);
    strip.setPixelColor(162, 214, 000, 000, 000);
    strip.setPixelColor(146, 214, 000, 000, 000);   
  strip.show();
  delay(1000);
  }
}
void rwbyW(){
  for(int d=0; d<4 && !patternToggled; d++) {
  //W
    strip.setPixelColor(22, 176, 180, 183, 000);
    strip.setPixelColor(23, 176, 180, 183, 000);
    strip.setPixelColor(46, 176, 180, 183, 000);
    strip.setPixelColor(49, 176, 180, 183, 000);
    strip.setPixelColor(93, 176, 180, 183, 000);
    strip.setPixelColor(123, 176, 180, 183, 000);
    strip.setPixelColor(128, 176, 180, 183, 000);
    strip.setPixelColor(142, 176, 180, 183, 000);
    strip.setPixelColor(122, 176, 180, 183, 000);
    strip.setPixelColor(95, 176, 180, 183, 000);
    strip.setPixelColor(67, 176, 180, 183, 000);
    strip.setPixelColor(28, 176, 180, 183, 000);
    strip.setPixelColor(17, 176, 180, 183, 000);
    strip.setPixelColor(29, 176, 180, 183, 000);
    strip.setPixelColor(65, 176, 180, 183, 000);
    strip.setPixelColor(98, 176, 180, 183, 000);
    strip.setPixelColor(118, 176, 180, 183, 000);
    strip.setPixelColor(137, 176, 180, 183, 000);
    strip.setPixelColor(134, 176, 180, 183, 000);
    strip.setPixelColor(117, 176, 180, 183, 000);
    strip.setPixelColor(85, 176, 180, 183, 000);
    strip.setPixelColor(36, 176, 180, 183, 000);
    strip.setPixelColor(34, 176, 180, 183, 000);
    strip.setPixelColor(12, 176, 180, 183, 000);  
  strip.show();
  delay(1000);
  }
}
void rwbyB(){
  for(int d=0; d<4 && !patternToggled; d++) {
    strip.setPixelColor(20, 96, 96, 96, 000);
    strip.setPixelColor(19, 96, 96, 96, 000);
    strip.setPixelColor(18, 96, 96, 96, 000);
    strip.setPixelColor(17, 96, 96, 96, 000);
    strip.setPixelColor(30, 96, 96, 96, 000);
    strip.setPixelColor(39, 96, 96, 96, 000);
    strip.setPixelColor(56, 96, 96, 96, 000);
    strip.setPixelColor(64, 96, 96, 96, 000);
    strip.setPixelColor(80, 96, 96, 96, 000);
    strip.setPixelColor(90, 96, 96, 96, 000);
    strip.setPixelColor(89, 96, 96, 96, 000);
    strip.setPixelColor(98, 96, 96, 96, 000);
    strip.setPixelColor(100, 96, 96, 96, 000);
    strip.setPixelColor(112, 96, 96, 96, 000);
    strip.setPixelColor(118, 96, 96, 96, 000);
    strip.setPixelColor(132, 96, 96, 96, 000);
    strip.setPixelColor(140, 96, 96, 96, 000);
    strip.setPixelColor(141, 96, 96, 96, 000);
    strip.setPixelColor(142, 96, 96, 96, 000);
    strip.setPixelColor(143, 96, 96, 96, 000);
    strip.setPixelColor(128, 96, 96, 96, 000);
    strip.setPixelColor(94, 96, 96, 96, 000);
    strip.setPixelColor(76, 96, 96, 96, 000);
    strip.setPixelColor(51, 96, 96, 96, 000);
    strip.setPixelColor(26, 96, 96, 96, 000);
  strip.show();
  delay(1000);
  }
}
void rwbyY(){
  for(int d=0; d<4 && !patternToggled; d++) {
    strip.setPixelColor(20, 162, 151, 001, 000);
    strip.setPixelColor(19, 162, 151, 001, 000);
    strip.setPixelColor(13, 162, 151, 001, 000);
    strip.setPixelColor(43, 162, 151, 001, 000);
    strip.setPixelColor(52, 162, 151, 001, 000);
    strip.setPixelColor(67, 162, 151, 001, 000);
    strip.setPixelColor(78, 162, 151, 001, 000);
    strip.setPixelColor(89, 162, 151, 001, 000);
    strip.setPixelColor(32, 162, 151, 001, 000);
    strip.setPixelColor(38, 162, 151, 001, 000);
    strip.setPixelColor(56, 162, 151, 001, 000);
    strip.setPixelColor(64, 162, 151, 001, 000);
    strip.setPixelColor(80, 162, 151, 001, 000);
    strip.setPixelColor(88, 162, 151, 001, 000);
    strip.setPixelColor(97, 162, 151, 001, 000);
    strip.setPixelColor(102, 162, 151, 001, 000);
    strip.setPixelColor(109, 162, 151, 001, 000);
    strip.setPixelColor(121, 162, 151, 001, 000);
    strip.setPixelColor(129, 162, 151, 001, 000);
    strip.setPixelColor(142, 162, 151, 001, 000);
  strip.show();
  delay(1000);
  }
}

//pokemon
void pokemon() {
  //strip.setPixelColor(n, red, green, blue, white);
 for(int d=0; d<4 && !patternToggled; d++) {
  //eyes
    strip.setPixelColor(24, 051, 051, 051, 000);
    strip.setPixelColor(25, 051, 051, 051, 000);
    strip.setPixelColor(26, 051, 051, 051, 000);
    strip.setPixelColor(31, 051, 051, 051, 000);
    strip.setPixelColor(32, 051, 051, 051, 000);
    strip.setPixelColor(33, 051, 051, 051, 000);
    strip.setPixelColor(46, 051, 051, 051, 000);
    strip.setPixelColor(43, 051, 051, 051, 000);
    strip.setPixelColor(39, 051, 051, 051, 000);
    strip.setPixelColor(36, 051, 051, 051, 000);
    strip.setPixelColor(71, 051, 051, 051, 000);
    strip.setPixelColor(68, 051, 051, 051, 000);
    strip.setPixelColor(64, 051, 051, 051, 000);
    strip.setPixelColor(61, 051, 051, 051, 000);
    strip.setPixelColor(74, 051, 051, 051, 000);
    strip.setPixelColor(75, 051, 051, 051, 000);
    strip.setPixelColor(76, 051, 051, 051, 000);
    strip.setPixelColor(81, 051, 051, 051, 000);
    strip.setPixelColor(82, 051, 051, 051, 000);
    strip.setPixelColor(83, 051, 051, 051, 000);
    strip.setPixelColor(45, 255, 255, 255, 000);
    strip.setPixelColor(38, 255, 255, 255, 000);
   //nose 
    strip.setPixelColor(78, 000, 007, 000, 000);
    strip.setPixelColor(79, 000, 007, 000, 000);
    strip.setPixelColor(89, 000, 007, 000, 000);
   //mouth
    strip.setPixelColor(94, 000, 007, 000, 000);
    strip.setPixelColor(104, 000, 007, 000, 000);
    strip.setPixelColor(103, 000, 007, 000, 000);
    strip.setPixelColor(96, 000, 007, 000, 000);
    strip.setPixelColor(97, 000, 007, 000, 000);
    strip.setPixelColor(101, 000, 007, 000, 000);
    strip.setPixelColor(100, 000, 007, 000, 000);
    strip.setPixelColor(99, 000, 007, 000, 000);
    strip.setPixelColor(108, 221, 102, 106, 000);
    strip.setPixelColor(111, 221, 102, 106, 000);
    strip.setPixelColor(129, 221, 102, 106, 000);
    strip.setPixelColor(132, 221, 102, 106, 000);
    strip.setPixelColor(141, 221, 102, 106, 000);
    strip.setPixelColor(139, 221, 102, 106, 000);
    strip.setPixelColor(149, 221, 102, 106, 000);
    strip.setPixelColor(150, 221, 102, 106, 000);
    strip.setPixelColor(159, 221, 102, 106, 000);
   //cheek
    strip.setPixelColor(105, 231, 074, 057, 000);
    strip.setPixelColor(106, 231, 074, 057, 000);
    strip.setPixelColor(107, 231, 074, 057, 000);
    strip.setPixelColor(123, 231, 074, 057, 000);
    strip.setPixelColor(143, 231, 074, 057, 000);
    strip.setPixelColor(145, 231, 074, 057, 000);
    strip.setPixelColor(146, 231, 074, 057, 000);
    strip.setPixelColor(112, 231, 074, 057, 000);
    strip.setPixelColor(113, 231, 074, 057, 000);
    strip.setPixelColor(114, 231, 074, 057, 000);
    strip.setPixelColor(117, 231, 074, 057, 000);
    strip.setPixelColor(137, 231, 074, 057, 000);
    strip.setPixelColor(153, 231, 074, 057, 000);
    strip.setPixelColor(154, 231, 074, 057, 000);
    strip.show();
    delay(1000);
  }
}
//pokeball
void pokeball() {
  //top
  for(int d=0; d<10 && !patternToggled; d++) {
    strip.setPixelColor(27, 255, 28, 28, 000);
    strip.setPixelColor(28, 255, 28, 28, 000);
    strip.setPixelColor(29, 255, 28, 28, 000);
    strip.setPixelColor(30, 255, 28, 28, 000);
    strip.setPixelColor(44, 255, 28, 28, 000);
    strip.setPixelColor(43, 255, 28, 28, 000);
    strip.setPixelColor(42, 255, 28, 28, 000);
    strip.setPixelColor(41, 255, 28, 28, 000);
    strip.setPixelColor(40, 255, 28, 28, 000);
    strip.setPixelColor(39, 255, 28, 28, 000);
    strip.setPixelColor(38, 255, 28, 28, 000);
    strip.setPixelColor(49, 255, 28, 28, 000);
    strip.setPixelColor(50, 255, 28, 28, 000);
    strip.setPixelColor(51, 255, 28, 28, 000);
    strip.setPixelColor(52, 255, 28, 28, 000);
    strip.setPixelColor(53, 255, 28, 28, 000);
    strip.setPixelColor(54, 255, 28, 28, 000);
    strip.setPixelColor(55, 255, 28, 28, 000);
    strip.setPixelColor(56, 255, 28, 28, 000);
    strip.setPixelColor(57, 255, 28, 28, 000);
    strip.setPixelColor(58, 255, 28, 28, 000);
    strip.setPixelColor(61, 255, 28, 28, 000);
    strip.setPixelColor(62, 255, 28, 28, 000);
    strip.setPixelColor(63, 255, 28, 28, 000);
    strip.setPixelColor(64, 255, 28, 28, 000);
    strip.setPixelColor(65, 255, 28, 28, 000);
    strip.setPixelColor(66, 255, 28, 28, 000);
    strip.setPixelColor(67, 255, 28, 28, 000);
    strip.setPixelColor(68, 255, 28, 28, 000);
    strip.setPixelColor(69, 255, 28, 28, 000);
    strip.setPixelColor(70, 255, 28, 28, 0000);
    strip.setPixelColor(71, 255, 28, 28, 000);
    strip.setPixelColor(73, 255, 28, 28, 000);
    strip.setPixelColor(74, 255, 28, 28, 000);
    strip.setPixelColor(75, 255, 28, 28, 000);
    strip.setPixelColor(76, 255, 28, 28, 000);
    strip.setPixelColor(77, 255, 28, 28, 000);
    strip.setPixelColor(78, 255, 28, 28, 000);
    strip.setPixelColor(79, 255, 28, 28, 000);
    strip.setPixelColor(80, 255, 28, 28, 000);
    strip.setPixelColor(81, 255, 28, 28, 000);
    strip.setPixelColor(82, 255, 28, 28, 000);
    strip.setPixelColor(83, 255, 28, 28, 000);
    strip.setPixelColor(84, 255, 28, 28, 000);
    strip.setPixelColor(85, 255, 28, 28, 000);
    strip.setPixelColor(86, 255, 28, 28, 000);
    strip.setPixelColor(87, 255, 28, 28, 000);
    strip.setPixelColor(88, 255, 28, 28, 000);
    strip.setPixelColor(89, 255, 28, 28, 000);
    strip.setPixelColor(90, 255, 28, 28, 000);
    strip.setPixelColor(91, 255, 28, 28, 000);
    strip.setPixelColor(92, 255, 28, 28, 000);
    strip.setPixelColor(93, 255, 28, 28, 000);
    strip.setPixelColor(94, 255, 28, 28, 000);
    strip.setPixelColor(95, 255, 28, 28, 000);
    strip.setPixelColor(96, 255, 28, 28, 000);
    strip.setPixelColor(97, 255, 28, 28, 000);
    strip.setPixelColor(98, 255, 28, 28, 000);
    strip.setPixelColor(99, 255, 28, 28, 000);
    strip.setPixelColor(104, 255, 28, 28, 000);
    strip.setPixelColor(100, 255, 28, 28, 000);
    strip.setPixelColor(105, 255, 28, 28, 000);
    strip.setPixelColor(106, 255, 28, 28, 000);
    strip.setPixelColor(107, 255, 28, 28, 000);
    strip.setPixelColor(112, 255, 28, 28, 000);
    strip.setPixelColor(113, 255, 28, 28, 000);
    strip.setPixelColor(114, 255, 28, 28, 000);
  //bottom
    strip.setPixelColor(126, 255, 255, 255, 000);
    strip.setPixelColor(127, 255, 255, 255, 000);
    strip.setPixelColor(128, 255, 255, 255, 000);
    strip.setPixelColor(133, 255, 255, 255, 000);
    strip.setPixelColor(134, 255, 255, 255, 000);
    strip.setPixelColor(135, 255, 255, 255, 000);
    strip.setPixelColor(144, 255, 255, 255, 000);
    strip.setPixelColor(143, 255, 255, 255, 000);
    strip.setPixelColor(142, 255, 255, 255, 000);
    strip.setPixelColor(138, 255, 255, 255, 000);
    strip.setPixelColor(137, 255, 255, 255, 000);
    strip.setPixelColor(136, 255, 255, 255, 000);
    strip.setPixelColor(145, 255, 255, 255, 000);
    strip.setPixelColor(146, 255, 255, 255, 000);
    strip.setPixelColor(147, 255, 255, 255, 000);
    strip.setPixelColor(148, 255, 255, 255, 000);
    strip.setPixelColor(149, 255, 255, 255, 000);
    strip.setPixelColor(150, 255, 255, 255, 000);
    strip.setPixelColor(151, 255, 255, 255, 000);
    strip.setPixelColor(152, 255, 255, 255, 000);
    strip.setPixelColor(153, 255, 255, 255, 000);
    strip.setPixelColor(154, 255, 255, 255, 000);
    strip.setPixelColor(155, 255, 255, 255, 000);
    strip.setPixelColor(156, 255, 255, 255, 000);
    strip.setPixelColor(157, 255, 255, 255, 000);
    strip.setPixelColor(158, 255, 255, 255, 000);
    strip.setPixelColor(160, 255, 255, 255, 000);
    strip.setPixelColor(161, 255, 255, 255, 000);
    strip.setPixelColor(162, 255, 255, 255, 000);
    strip.setPixelColor(163, 255, 255, 255, 000);
    strip.setPixelColor(164, 255, 255, 255, 000);
    strip.setPixelColor(165, 255, 255, 255, 000);
    strip.setPixelColor(166, 255, 255, 255, 000);
    strip.setPixelColor(167, 255, 255, 255, 000);
    strip.setPixelColor(168, 255, 255, 255, 000);
    strip.setPixelColor(169, 255, 255, 255, 000);
    strip.setPixelColor(170, 255, 255, 255, 000);
    strip.setPixelColor(171, 255, 255, 255, 000);
    strip.setPixelColor(172, 255, 255, 255, 000);
    strip.setPixelColor(173, 255, 255, 255, 000);
    strip.setPixelColor(174, 255, 255, 255, 000);
    strip.setPixelColor(175, 255, 255, 255, 000);
    strip.setPixelColor(176, 255, 255, 255, 000);
    strip.setPixelColor(177, 255, 255, 255, 000);
    strip.setPixelColor(178, 255, 255, 255, 000);
    strip.setPixelColor(179, 255, 255, 255, 000);
    strip.setPixelColor(180, 255, 255, 255, 000);
    strip.setPixelColor(181, 255, 255, 255, 000);
    strip.setPixelColor(182, 255, 255, 255, 000);
    strip.setPixelColor(183, 255, 255, 255, 000);
    strip.setPixelColor(184, 255, 255, 255, 000);
    strip.setPixelColor(185, 255, 255, 255, 000);
    strip.setPixelColor(186, 255, 255, 255, 000);
    strip.setPixelColor(187, 255, 255, 255, 000);
    strip.setPixelColor(188, 255, 255, 255, 000);
    strip.setPixelColor(189, 255, 255, 255, 000);
    strip.setPixelColor(191, 255, 255, 255, 000);
    strip.setPixelColor(192, 255, 255, 255, 000);
    strip.setPixelColor(193, 255, 255, 255, 000);
    strip.setPixelColor(194, 255, 255, 255, 000);
    strip.setPixelColor(151, 255, 255, 255, 000);
   //button
    strip.setPixelColor(109, 255, 255, 255, 000);
    strip.setPixelColor(110, 255, 255, 255, 000);
    strip.setPixelColor(121, 255, 255, 255, 000);
    strip.setPixelColor(119, 255, 255, 255, 000);
    strip.setPixelColor(130, 255, 255, 255, 000);
    strip.setPixelColor(131, 255, 255, 255, 000);
    strip.show();
    delay(1000);
  }
}

void deadmou5(){
  for(int d=0; d<10 && !patternToggled; d++) {
    //eyesL
    strip.setPixelColor(21, 255, 255, 255, 000);
    strip.setPixelColor(22, 255, 255, 255, 000);
    strip.setPixelColor(23, 255, 255, 255, 000);
    strip.setPixelColor(24, 255, 255, 255, 000);
    strip.setPixelColor(25, 255, 255, 255, 000);
    strip.setPixelColor(45, 255, 255, 255, 000);
    strip.setPixelColor(46, 255, 255, 255, 000);
    strip.setPixelColor(47, 255, 255, 255, 000);
    strip.setPixelColor(48, 255, 255, 255, 000);
    strip.setPixelColor(49, 255, 255, 255, 000);
    strip.setPixelColor(50, 255, 255, 255, 000);
    strip.setPixelColor(70, 255, 255, 255, 000);
    strip.setPixelColor(71, 255, 255, 255, 000);
    //eyesR
    strip.setPixelColor(12, 255, 255, 255, 000);
    strip.setPixelColor(13, 255, 255, 255, 000);
    strip.setPixelColor(32, 255, 255, 255, 000);
    strip.setPixelColor(33, 255, 255, 255, 000);
    strip.setPixelColor(34, 255, 255, 255, 000);
    strip.setPixelColor(35, 255, 255, 255, 000);
    strip.setPixelColor(36, 255, 255, 255, 000);
    strip.setPixelColor(37, 255, 255, 255, 000);
    strip.setPixelColor(57, 255, 255, 255, 000);
    strip.setPixelColor(58, 255, 255, 255, 000);
    strip.setPixelColor(59, 255, 255, 255, 000);
    strip.setPixelColor(61, 255, 255, 255, 000);
    strip.setPixelColor(62, 255, 255, 255, 000);
    //mouth
    strip.setPixelColor(115, 255, 255, 000, 000);
    strip.setPixelColor(116, 255, 255, 000, 000);
    strip.setPixelColor(124, 255, 255, 000, 000);
    strip.setPixelColor(125, 255, 255, 000, 000);
    strip.setPixelColor(126, 255, 255, 000, 000);
    strip.setPixelColor(127, 255, 255, 000, 000);
    strip.setPixelColor(128, 255, 255, 000, 000);
    strip.setPixelColor(129, 255, 255, 000, 000);
    strip.setPixelColor(130, 255, 255, 000, 000);
    strip.setPixelColor(131, 255, 255, 000, 000);
    strip.setPixelColor(132, 255, 255, 000, 000);
    strip.setPixelColor(133, 255, 255, 000, 000);
    strip.setPixelColor(134, 255, 255, 000, 000);
    strip.setPixelColor(135, 255, 255, 000, 000);
    strip.setPixelColor(136, 255, 255, 000, 000);
    strip.setPixelColor(137, 255, 255, 000, 000);
    strip.setPixelColor(138, 255, 255, 000, 000);
    strip.setPixelColor(139, 255, 255, 000, 000);
    strip.setPixelColor(140, 255, 255, 000, 000);
    strip.setPixelColor(141, 255, 255, 000, 000);
    strip.setPixelColor(142, 255, 255, 000, 000);
    strip.setPixelColor(143, 255, 255, 000, 000);
    strip.setPixelColor(144, 255, 255, 000, 000);
    strip.setPixelColor(146, 255, 255, 000, 000);
    strip.setPixelColor(147, 255, 255, 000, 000);
    strip.setPixelColor(148, 255, 255, 000, 000);
    strip.setPixelColor(149, 255, 255, 000, 000);
    strip.setPixelColor(150, 255, 255, 000, 000);
    strip.setPixelColor(151, 255, 255, 000, 000);
    strip.setPixelColor(152, 255, 255, 000, 000);
    strip.setPixelColor(153, 255, 255, 000, 000);
    strip.setPixelColor(156, 255, 255, 000, 000);
    strip.setPixelColor(157, 255, 255, 000, 000);
    strip.setPixelColor(158, 255, 255, 000, 000);
    strip.setPixelColor(159, 255, 255, 000, 000);
    strip.setPixelColor(160, 255, 255, 000, 000);
    strip.setPixelColor(161, 255, 255, 000, 000);
    strip.setPixelColor(162, 255, 255, 000, 000);
    strip.setPixelColor(166, 255, 255, 000, 000);
    strip.setPixelColor(167, 255, 255, 000, 000);
    strip.setPixelColor(168, 255, 255, 000, 000);
    strip.setPixelColor(169, 255, 255, 000, 000);
    strip.show();
    delay(1000);
  }
}
void deadmou5evil(){
  for(int d=0; d<8 && !patternToggled; d++) {
    //eyesL
    strip.setPixelColor(23, 255, 0, 0, 000);
    strip.setPixelColor(24, 255, 0, 0, 000);
    strip.setPixelColor(47, 255, 0, 0, 000);
    strip.setPixelColor(46, 255, 0, 0, 000);
    strip.setPixelColor(45, 255, 0, 0, 000);
    strip.setPixelColor(48, 255, 0, 0, 000);
    strip.setPixelColor(49, 255, 0, 0, 000);
    strip.setPixelColor(50, 255, 0, 0, 000);
    strip.setPixelColor(71, 255, 0, 0, 000);
    strip.setPixelColor(70, 255, 0, 0, 000);
    strip.setPixelColor(69, 255, 0, 0, 000);
    //eyesR
    strip.setPixelColor(33, 255, 0, 0, 000);
    strip.setPixelColor(34, 255, 0, 0, 000);
    strip.setPixelColor(37, 255, 0, 0, 000);
    strip.setPixelColor(36, 255, 0, 0, 000);
    strip.setPixelColor(35, 255, 0, 0, 000);
    strip.setPixelColor(57, 255, 0, 0, 000);
    strip.setPixelColor(58, 255, 0, 0, 000);
    strip.setPixelColor(59, 255, 0, 0, 000);
    strip.setPixelColor(63, 255, 0, 0, 000);
    strip.setPixelColor(62, 255, 0, 0, 000);
    strip.setPixelColor(61, 255, 0, 0, 000);
    //mouth
    strip.setPixelColor(115, 255, 255, 000, 000);
    strip.setPixelColor(116, 255, 255, 000, 000);
    strip.setPixelColor(124, 255, 255, 000, 000);
    strip.setPixelColor(125, 255, 255, 000, 000);
    strip.setPixelColor(126, 255, 255, 000, 000);
    strip.setPixelColor(127, 255, 255, 000, 000);
    strip.setPixelColor(128, 255, 255, 000, 000);
    strip.setPixelColor(129, 255, 255, 000, 000);
    strip.setPixelColor(130, 255, 255, 000, 000);
    strip.setPixelColor(131, 255, 255, 000, 000);
    strip.setPixelColor(132, 255, 255, 000, 000);
    strip.setPixelColor(133, 255, 255, 000, 000);
    strip.setPixelColor(134, 255, 255, 000, 000);
    strip.setPixelColor(135, 255, 255, 000, 000);
    strip.setPixelColor(136, 255, 255, 000, 000);
    strip.setPixelColor(137, 255, 255, 000, 000);
    strip.setPixelColor(138, 255, 255, 000, 000);
    strip.setPixelColor(139, 255, 255, 000, 000);
    strip.setPixelColor(140, 255, 255, 000, 000);
    strip.setPixelColor(141, 255, 255, 000, 000);
    strip.setPixelColor(142, 255, 255, 000, 000);
    strip.setPixelColor(143, 255, 255, 000, 000);
    strip.setPixelColor(144, 255, 255, 000, 000);
    strip.setPixelColor(146, 255, 255, 000, 000);
    strip.setPixelColor(147, 255, 255, 000, 000);
    strip.setPixelColor(148, 255, 255, 000, 000);
    strip.setPixelColor(149, 255, 255, 000, 000);
    strip.setPixelColor(150, 255, 255, 000, 000);
    strip.setPixelColor(151, 255, 255, 000, 000);
    strip.setPixelColor(152, 255, 255, 000, 000);
    strip.setPixelColor(153, 255, 255, 000, 000);
    strip.setPixelColor(156, 255, 255, 000, 000);
    strip.setPixelColor(157, 255, 255, 000, 000);
    strip.setPixelColor(158, 255, 255, 000, 000);
    strip.setPixelColor(159, 255, 255, 000, 000);
    strip.setPixelColor(160, 255, 255, 000, 000);
    strip.setPixelColor(161, 255, 255, 000, 000);
    strip.setPixelColor(162, 255, 255, 000, 000);
    strip.setPixelColor(166, 255, 255, 000, 000);
    strip.setPixelColor(167, 255, 255, 000, 000);
    strip.setPixelColor(168, 255, 255, 000, 000);
    strip.setPixelColor(169, 255, 255, 000, 000);
    strip.show();
    delay(1000);
  }
}
