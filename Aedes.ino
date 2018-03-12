#define DEBUG 1       // Switch debug output on or off

#if DEBUG
#define DEBUG_PRINTS(s)   { Serial.print(F(s)); }
#define DEBUG_PRINT(s,v)  { Serial.print(F(s)); Serial.print(v); }
#define DEBUG_PRINTX(s,v) { Serial.print(F(s)); Serial.print(F("0xSerial.print(v, HEX); }
#else
#define DEBUG_PRINTS(s)
#define DEBUG_PRINT(s,v)
#define DEBUG_PRINTX(s,v)
#endif

// DEBUG_PRINTS prints a string     -     DEBUG_PRINTS("\nError check");
// DEBUG_PRINT  prints a string and a value     -     DEBUG_PRINT("\nCurrent state: ", variable);
// DEBUG_PRINTX is the same as above but the value is output has a hexadecimal

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <DebounceButton.h>

// WAV files converted to code by wav2sketch
#include "AudioSampleSnare.h"        // http://www.freesound.org/people/KEVOY/sounds/82583/
#include "AudioSampleKick.h"         // http://www.freesound.org/people/DWSD/sounds/171104/


// LEDs
#define LED_RED_PIN 3      
#define LED_GREEN_PIN 4      
#define LED_BLUE_PIN 5      
#define MODE_LED_PIN A14

// Buttons
#define BTN_PIN_0 0      
#define BTN_PIN_1 1      
#define BTN_PIN_2 2      
#define BTN_PIN_3 8      
#define BTN_PIN_4 16     
#define BTN_PIN_5 17     
#define BTN_PIN_6 20     
#define BTN_PIN_7 21     
#define MODE_TOGGLE_PIN A10    

// Switches
#define ENVELOPE_SWITCH_PIN 32          
#define OUTPUT_SELECT_PIN A11 
#define BASS_BOOST_PIN 33

// Pots direct
#define VOLUME_PIN A1    
#define ENVELOPE_ATTACK_PIN A18         
#define ENVELOPE_DECAY_PIN A19          
#define ENVELOPE_SUSTAIN_PIN A20        
#define ENVELOPE_RELEASE_PIN A12        
#define OCTAVE_PIN A13       

// Multiplexor
#define MUXDATA0_PIN 27     
#define MUXDATA1_PIN 26     
#define MUXDATA2_PIN 25     
#define MUXDATA3_PIN 24     
#define MUXSIGNAL_PIN 28    



// *************************************************************************************************************
// *************************************************************************************************************

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     lfoenvelope;    //xy=543,791
AudioSynthWaveform       lfo;            //xy=631,997
AudioMixer4              mixer1;         //xy=674,852
AudioAnalyzePeak         peak1;          //xy=903,715
AudioSynthWaveform       voice8b;        //xy=1139,1766
AudioSynthNoiseWhite     voice8n;        //xy=1139,1801
AudioSynthWaveform       voice8a;        //xy=1141,1728
AudioSynthWaveform       voice4a;        //xy=1160,750
AudioSynthWaveform       voice4b;        //xy=1161,788
AudioSynthNoiseWhite     voice4n;        //xy=1161,823
AudioSynthWaveform       voice5b;        //xy=1162,1044
AudioSynthNoiseWhite     voice5n;        //xy=1162,1079
AudioSynthWaveform       voice5a;        //xy=1167,1001
AudioSynthWaveform       voice7b;        //xy=1171,1535
AudioSynthNoiseWhite     voice7n;        //xy=1171,1570
AudioSynthWaveform       voice6b;        //xy=1174,1298
AudioSynthNoiseWhite     voice6n;        //xy=1174,1333
AudioSynthWaveform       voice6a;        //xy=1176,1260
AudioSynthWaveform       voice7a;        //xy=1176,1492
AudioSynthWaveform       voice3b;        //xy=1182,540
AudioSynthNoiseWhite     voice3n;        //xy=1182,575
AudioSynthWaveform       voice3a;        //xy=1187,497
AudioSynthWaveform       voice1b;        //xy=1212,74
AudioSynthNoiseWhite     voice1n;        //xy=1215,118
AudioSynthWaveform       voice2b;        //xy=1215,308
AudioSynthNoiseWhite     voice2n;        //xy=1215,343
AudioSynthWaveform       voice1a;        //xy=1217,31
AudioSynthWaveform       voice2a;        //xy=1217,270
AudioSynthWaveformDc     voice8filterenv; //xy=1267,1912
AudioSynthWaveformDc     voice8env;      //xy=1281,1851
AudioMixer4              voice8mix;      //xy=1284,1786
AudioSynthWaveformDc     voice4filterenv; //xy=1289,934
AudioSynthWaveformDc     voice5filterenv; //xy=1290,1190
AudioSynthWaveformDc     voice7filterenv; //xy=1299,1681
AudioSynthWaveformDc     voice4env;      //xy=1303,873
AudioSynthWaveformDc     voice6filterenv; //xy=1302,1444
AudioSynthWaveformDc     voice5env;      //xy=1304,1129
AudioMixer4              voice4mix;      //xy=1306,808
AudioMixer4              voice5mix;      //xy=1307,1064
AudioSynthWaveformDc     voice3filterenv; //xy=1310,686
AudioSynthWaveformDc     voice7env;      //xy=1313,1620
AudioSynthWaveformDc     voice6env;      //xy=1316,1383
AudioMixer4              voice7mix;      //xy=1316,1555
AudioMixer4              voice6mix;      //xy=1319,1318
AudioSynthWaveformDc     voice3env;      //xy=1324,625
AudioMixer4              voice3mix;      //xy=1327,560
AudioSynthWaveformDc     voice1filterenv; //xy=1341,210
AudioSynthWaveformDc     voice2filterenv; //xy=1343,454
AudioMixer4              voice1mix;      //xy=1357,94
AudioSynthWaveformDc     voice2env;      //xy=1357,393
AudioSynthWaveformDc     voice1env;      //xy=1358,159
AudioMixer4              voice2mix;      //xy=1360,328
AudioEffectMultiply      voice8multiply; //xy=1448,1824
AudioMixer4              voice8filtermodmixer; //xy=1458,1940
AudioEffectMultiply      voice4multiply; //xy=1470,846
AudioEffectMultiply      voice5multiply; //xy=1471,1102
AudioMixer4              voice4filtermodmixer; //xy=1480,962
AudioEffectMultiply      voice7multiply; //xy=1480,1593
AudioEffectMultiply      voice6multiply; //xy=1483,1356
AudioMixer4              voice5filtermodmixer; //xy=1488,1212
AudioEffectMultiply      voice3multiply; //xy=1491,598
AudioMixer4              voice6filtermodmixer; //xy=1493,1472
AudioMixer4              voice7filtermodmixer; //xy=1497,1703
AudioMixer4              voice3filtermodmixer; //xy=1508,708
AudioEffectMultiply      voice1multiply; //xy=1521,132
AudioEffectMultiply      voice2multiply; //xy=1524,366
AudioMixer4              voice2filtermodmixer; //xy=1534,482
AudioMixer4              voice1filtermodmixer; //xy=1538,242
AudioFilterStateVariable voice8filter;   //xy=1631,1847
AudioFilterStateVariable voice5filter;   //xy=1651,1146
AudioFilterStateVariable voice4filter;   //xy=1653,869
AudioFilterStateVariable voice7filter;   //xy=1660,1637
AudioFilterStateVariable voice6filter;   //xy=1666,1379
AudioFilterStateVariable voice3filter;   //xy=1671,642
AudioFilterStateVariable voice2filter;   //xy=1707,389
AudioFilterStateVariable voice1filter;   //xy=1724,184
AudioMixer4              last4premix;    //xy=2131,1119
AudioMixer4              first4premix;   //xy=2132,1035
AudioPlayMemory          sound1;       //xy=2199,1478
AudioPlayMemory          sound2;       //xy=2201,1523
AudioPlayMemory          sound3;       //xy=2223,1579
AudioPlayMemory          sound4;       //xy=2242,1632
AudioMixer4              mixer2;         //xy=2410,1499
AudioFilterStateVariable delayFilter;    //xy=2581,1229
AudioMixer4              mainOutMixer;   //xy=2652,1112
AudioEffectDelay         delay1;         //xy=2710,1424
AudioOutputI2S           i2s1;           //xy=2878,1110
AudioConnection          patchCord1(lfoenvelope, 0, mixer1, 0);
AudioConnection          patchCord2(lfo, 0, voice1filtermodmixer, 1);
AudioConnection          patchCord3(lfo, 0, voice2filtermodmixer, 1);
AudioConnection          patchCord4(lfo, 0, voice3filtermodmixer, 1);
AudioConnection          patchCord5(lfo, 0, voice4filtermodmixer, 1);
AudioConnection          patchCord6(lfo, 0, voice5filtermodmixer, 1);
AudioConnection          patchCord7(lfo, 0, voice6filtermodmixer, 1);
AudioConnection          patchCord8(lfo, 0, voice7filtermodmixer, 1);
AudioConnection          patchCord9(lfo, 0, voice8filtermodmixer, 1);
AudioConnection          patchCord10(lfo, 0, mixer1, 1);
AudioConnection          patchCord11(mixer1, peak1);
AudioConnection          patchCord12(voice8b, 0, voice8mix, 1);
AudioConnection          patchCord13(voice8n, 0, voice8mix, 2);
AudioConnection          patchCord14(voice8a, 0, voice8mix, 0);
AudioConnection          patchCord15(voice4a, 0, voice4mix, 0);
AudioConnection          patchCord16(voice4b, 0, voice4mix, 1);
AudioConnection          patchCord17(voice4n, 0, voice4mix, 2);
AudioConnection          patchCord18(voice5b, 0, voice5mix, 1);
AudioConnection          patchCord19(voice5n, 0, voice5mix, 2);
AudioConnection          patchCord20(voice5a, 0, voice5mix, 0);
AudioConnection          patchCord21(voice7b, 0, voice7mix, 1);
AudioConnection          patchCord22(voice7n, 0, voice7mix, 2);
AudioConnection          patchCord23(voice6b, 0, voice6mix, 1);
AudioConnection          patchCord24(voice6n, 0, voice6mix, 2);
AudioConnection          patchCord25(voice6a, 0, voice6mix, 0);
AudioConnection          patchCord26(voice7a, 0, voice7mix, 0);
AudioConnection          patchCord27(voice3b, 0, voice3mix, 1);
AudioConnection          patchCord28(voice3n, 0, voice3mix, 2);
AudioConnection          patchCord29(voice3a, 0, voice3mix, 0);
AudioConnection          patchCord30(voice1b, 0, voice1mix, 1);
AudioConnection          patchCord31(voice1n, 0, voice1mix, 2);
AudioConnection          patchCord32(voice2b, 0, voice2mix, 1);
AudioConnection          patchCord33(voice2n, 0, voice2mix, 3);
AudioConnection          patchCord34(voice1a, 0, voice1mix, 0);
AudioConnection          patchCord35(voice2a, 0, voice2mix, 0);
AudioConnection          patchCord36(voice8filterenv, 0, voice8filtermodmixer, 0);
AudioConnection          patchCord37(voice8env, 0, voice8multiply, 1);
AudioConnection          patchCord38(voice8mix, 0, voice8multiply, 0);
AudioConnection          patchCord39(voice4filterenv, 0, voice4filtermodmixer, 0);
AudioConnection          patchCord40(voice5filterenv, 0, voice5filtermodmixer, 0);
AudioConnection          patchCord41(voice7filterenv, 0, voice7filtermodmixer, 0);
AudioConnection          patchCord42(voice4env, 0, voice4multiply, 1);
AudioConnection          patchCord43(voice6filterenv, 0, voice6filtermodmixer, 0);
AudioConnection          patchCord44(voice5env, 0, voice5multiply, 1);
AudioConnection          patchCord45(voice4mix, 0, voice4multiply, 0);
AudioConnection          patchCord46(voice5mix, 0, voice5multiply, 0);
AudioConnection          patchCord47(voice3filterenv, 0, voice3filtermodmixer, 0);
AudioConnection          patchCord48(voice7env, 0, voice7multiply, 1);
AudioConnection          patchCord49(voice6env, 0, voice6multiply, 1);
AudioConnection          patchCord50(voice7mix, 0, voice7multiply, 0);
AudioConnection          patchCord51(voice6mix, 0, voice6multiply, 0);
AudioConnection          patchCord52(voice3env, 0, voice3multiply, 1);
AudioConnection          patchCord53(voice3mix, 0, voice3multiply, 0);
AudioConnection          patchCord54(voice1filterenv, 0, voice1filtermodmixer, 0);
AudioConnection          patchCord55(voice2filterenv, 0, voice2filtermodmixer, 0);
AudioConnection          patchCord56(voice1mix, 0, voice1multiply, 0);
AudioConnection          patchCord57(voice2env, 0, voice2multiply, 1);
AudioConnection          patchCord58(voice1env, 0, voice1multiply, 1);
AudioConnection          patchCord59(voice2mix, 0, voice2multiply, 0);
AudioConnection          patchCord60(voice8multiply, 0, voice8filter, 0);
AudioConnection          patchCord61(voice8filtermodmixer, 0, voice8filter, 1);
AudioConnection          patchCord62(voice4multiply, 0, voice4filter, 0);
AudioConnection          patchCord63(voice5multiply, 0, voice5filter, 0);
AudioConnection          patchCord64(voice4filtermodmixer, 0, voice4filter, 1);
AudioConnection          patchCord65(voice7multiply, 0, voice7filter, 0);
AudioConnection          patchCord66(voice6multiply, 0, voice6filter, 0);
AudioConnection          patchCord67(voice5filtermodmixer, 0, voice5filter, 1);
AudioConnection          patchCord68(voice3multiply, 0, voice3filter, 0);
AudioConnection          patchCord69(voice6filtermodmixer, 0, voice6filter, 1);
AudioConnection          patchCord70(voice7filtermodmixer, 0, voice7filter, 1);
AudioConnection          patchCord71(voice3filtermodmixer, 0, voice3filter, 1);
AudioConnection          patchCord72(voice1multiply, 0, voice1filter, 0);
AudioConnection          patchCord73(voice2multiply, 0, voice2filter, 0);
AudioConnection          patchCord74(voice2filtermodmixer, 0, voice2filter, 1);
AudioConnection          patchCord75(voice1filtermodmixer, 0, voice1filter, 1);
AudioConnection          patchCord76(voice8filter, 0, last4premix, 3);
AudioConnection          patchCord77(voice5filter, 0, last4premix, 0);
AudioConnection          patchCord78(voice4filter, 0, first4premix, 3);
AudioConnection          patchCord79(voice7filter, 0, last4premix, 2);
AudioConnection          patchCord80(voice6filter, 0, last4premix, 1);
AudioConnection          patchCord81(voice3filter, 0, first4premix, 2);
AudioConnection          patchCord82(voice2filter, 0, first4premix, 1);
AudioConnection          patchCord83(voice1filter, 0, first4premix, 0);
AudioConnection          patchCord84(last4premix, 0, mainOutMixer, 1);
AudioConnection          patchCord85(first4premix, 0, mainOutMixer, 0);
AudioConnection          patchCord86(sound1, 0, mixer2, 0);
AudioConnection          patchCord87(sound2, 0, mixer2, 1);
AudioConnection          patchCord88(sound3, 0, mixer2, 2);
AudioConnection          patchCord89(sound4, 0, mixer2, 3);
AudioConnection          patchCord90(mixer2, 0, mainOutMixer, 2);
AudioConnection          patchCord91(delayFilter, 0, mainOutMixer, 3);
AudioConnection          patchCord92(mainOutMixer, 0, i2s1, 0);
AudioConnection          patchCord93(mainOutMixer, 0, i2s1, 1);
AudioConnection          patchCord94(mainOutMixer, delay1);
AudioConnection          patchCord95(delay1, 0, delayFilter, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=2615,879
// GUItool: end automatically generated code


// *************************************************************************************************************
// *************************************************************************************************************








int currentMode = 0;   // tracks operating mode - 0 = synth, 1 = drum machine, 2 = sampler, etc.


DebounceButton noteOne = DebounceButton(BTN_PIN_0, DBTN_PULLUP_INTERNAL, 10, 8, 8);   // debounce time, hold time, retrigger time
DebounceButton noteTwo = DebounceButton(BTN_PIN_1, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton noteThree = DebounceButton(BTN_PIN_2, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton noteFour = DebounceButton(BTN_PIN_3, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton noteFive = DebounceButton(BTN_PIN_4, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton noteSix = DebounceButton(BTN_PIN_5, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton noteSeven = DebounceButton(BTN_PIN_6, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton noteEight = DebounceButton(BTN_PIN_7, DBTN_PULLUP_INTERNAL, 10, 8, 8);
//DebounceButton modeToggle = DebounceButton(MODE_TOGGLE_PIN, DBTN_PULLUP_INTERNAL, 20, 2000);


int colorIndex = 0;
int keyIndex = 0;




float noteFreq[7][8] = {

                         //5       1       6      2      7      3      8     4
                         {329.63,220.00,369.99,246.94,415.30,277.18,440.00,293.66},
                         {369.99,246.94,415.30,277.18,466.16,311.13,493.88,329.63},
                         {392.00,261.63,440.00,293.66,493.88,329.63,523.25,349.23},
                         {440.00,293.66,493.88,329.63,554.37,369.99,587.33,392.00},
                         {493.88,329.63,554.37,369.99,622.25,415.30,659.25,440.00},
                         {523.25,349.23,587.33,392.00,659.25,440.00,698.46,466.16},
                         {587.33,392.00,659.25,440.00,739.99,493.88,783.99,523.25},
                       };





// Analog Inputs
float potsMuxerValues[16];
float potsMuxerValuesPrevious[16];

int potsDirectPins[5] = {OCTAVE_PIN,ENVELOPE_ATTACK_PIN,ENVELOPE_DECAY_PIN,ENVELOPE_SUSTAIN_PIN,ENVELOPE_RELEASE_PIN};
float potsDirectValues[5];
float potsDirectValuesPrevious[5];
int changeThresh;
int extraChangeThresh;

// LEDS
int redLevel;
int greenLevel;
int blueLevel;
int redLevelArray[7] = {   182, 255, 0,   248, 0,   240,  255};
int greenLevelArray[7] = { 246, 0,   133, 159, 230, 0,    0};
int blueLevelArray[7] = {  41,  129, 252, 0,   255, 180, 40};

// Switches
int envelopeFilter;

float tempPulseWidth;
float tempPeak;
float tempRMS;


// Synth
float mainVolume;
int tempLineOutLevel;
float vcoOneLevel;
float vcoTwoLevel;
int vcoOneOct;
int vcoTwoOct;
int octArray[6] = {1,1,2,4,8,16};
float deTune;
int waveShapeOneIndex;
int waveShapeTwoIndex;
int lfoWaveShapeIndex;
int octOneIndex;
int octTwoIndex;

// WaveShapes
short waveShapes[4] = {
                        WAVEFORM_SINE,
                        WAVEFORM_SAWTOOTH,
                        WAVEFORM_SQUARE,
                        WAVEFORM_PULSE,
                      };
bool voiceBPulse;
float tempDetuneMod;
float deTuneLfo;

// LFO WaveShapes
short lfoWaveShapes[5] = {
                           WAVEFORM_SINE,
                           WAVEFORM_SAWTOOTH,
                           WAVEFORM_SAWTOOTH_REVERSE,
                           WAVEFORM_SQUARE,
                           WAVEFORM_SAMPLE_HOLD,
                         };

// ADSR
int attackTime;
int decayTime;
float sustainLevel;
int releaseTime;

// Filter ADSR
int attackTimeFilter;
int decayTimeFilter;
float sustainLevelFilter;
int releaseTimeFilter;

// Note Timing
bool noteTrigFlag[8];
unsigned long attackWait[8];

bool firstRunRead = true;




void setup() {

#if DEBUG
  Serial.begin(115200);
#endif

  AudioMemory(160);
  sgtl5000_1.enable();
  sgtl5000_1.volume(.7);

  initLEDs();
  initMultiplexor();
  initButtons();

  pinMode(ENVELOPE_SWITCH_PIN, INPUT_PULLUP);


  // Init Mixer
  first4premix.gain(0, .25);
  first4premix.gain(1, .25);
  first4premix.gain(2, .25);
  first4premix.gain(3, .25);
  last4premix.gain(0, .25);
  last4premix.gain(1, .25);
  last4premix.gain(2, .25);
  last4premix.gain(3, .25);

  // Init Voices
  voice1a.begin(.3,440,WAVEFORM_SQUARE);
  voice1b.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice2a.begin(.3,440,WAVEFORM_SQUARE);
  voice2b.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice3a.begin(.3,440,WAVEFORM_SQUARE);
  voice3b.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice4a.begin(.3,440,WAVEFORM_SQUARE);
  voice4b.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice5a.begin(.3,440,WAVEFORM_SQUARE);
  voice5b.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice6a.begin(.3,440,WAVEFORM_SQUARE);
  voice6b.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice7a.begin(.3,440,WAVEFORM_SQUARE);
  voice7b.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice8a.begin(.3,440,WAVEFORM_SQUARE);
  voice8b.begin(.3,440,WAVEFORM_SAWTOOTH);

  delayFilter.frequency(3000);
  delayFilter.resonance(1);
  delay1.delay(0,0);
  mainOutMixer.gain(3,0);
  lfo.begin(1,3,WAVEFORM_SINE);

  vcoOneOct = 1;
  vcoTwoOct = 1;
  deTune = 1;
  mainOutMixer.gain(0,.5);
  lfoenvelope.amplitude(1);
  voiceBPulse = false;

  pinMode(BASS_BOOST_PIN, INPUT_PULLUP);

  playChime(2);

}






void loop() {

  setVolumes();
  DebounceButton::updateAll();

  if (analogRead(MODE_TOGGLE_PIN) < 200) {
    DEBUG_PRINTS("\nToggle Mode Button Pressed.");
    if (currentMode == 0) currentMode = 1;
    else if (currentMode == 1) currentMode = 0;
    delay(500);  // !! temporary debounce method
  }

  if (currentMode == 0) {
    // Operate Synth mode
    envelopeFilter = digitalRead(ENVELOPE_SWITCH_PIN);
    defineNotes();

    processPotsMuxerValues_SynthMode();
    processPotsDirectValues_SynthMode();
    peakProcessing_SynthMode();
  }
  else if (currentMode == 1) {
    // Operate Drum machine mode
    // do drum stuff yo
  }
  firstRunRead = false;
}
