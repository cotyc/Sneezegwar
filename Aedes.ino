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
// Commented out for LED tests to secondary Teensy
// #define LED_RED_PIN 3      
// #define LED_GREEN_PIN 4      
#define LED_BLUE_PIN 5      

// Not implemented
// #define MODE_LED_PIN A14

// Buttons
// Commented out for LED tests to secondary Teensy
// #define BTN_PIN_0 0      
// #define BTN_PIN_1 1      
// #define BTN_PIN_2 2   

#define BTN_PIN_0 2      
#define BTN_PIN_1 3      
#define BTN_PIN_2 4         
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
AudioSynthWaveformDc     lfoenvelope;    //xy=321,831
AudioSynthWaveform       lfo;            //xy=409,1037
AudioMixer4              mixer1;         //xy=452,892
AudioAnalyzePeak         peak1;          //xy=681,755
AudioSynthWaveform       voice8b;        //xy=917,1806
AudioSynthNoiseWhite     voice8n;        //xy=917,1841
AudioSynthWaveform       voice8a;        //xy=919,1768
AudioSynthWaveform       voice4a;        //xy=938,790
AudioSynthWaveform       voice4b;        //xy=939,828
AudioSynthNoiseWhite     voice4n;        //xy=939,863
AudioSynthWaveform       voice5b;        //xy=940,1084
AudioSynthNoiseWhite     voice5n;        //xy=940,1119
AudioSynthWaveform       voice5a;        //xy=945,1041
AudioSynthWaveform       voice7b;        //xy=949,1575
AudioSynthNoiseWhite     voice7n;        //xy=949,1610
AudioSynthWaveform       voice6b;        //xy=952,1338
AudioSynthNoiseWhite     voice6n;        //xy=952,1373
AudioSynthWaveform       voice6a;        //xy=954,1300
AudioSynthWaveform       voice7a;        //xy=954,1532
AudioSynthWaveform       voice3b;        //xy=960,580
AudioSynthNoiseWhite     voice3n;        //xy=960,615
AudioSynthWaveform       voice3a;        //xy=965,537
AudioSynthWaveform       voice1b;        //xy=990,114
AudioSynthNoiseWhite     voice1n;        //xy=993,158
AudioSynthWaveform       voice2b;        //xy=993,348
AudioSynthNoiseWhite     voice2n;        //xy=993,383
AudioSynthWaveform       voice1a;        //xy=995,71
AudioSynthWaveform       voice2a;        //xy=995,310
AudioSynthWaveformDc     voice8filterenv; //xy=1045,1952
AudioSynthWaveformDc     voice8env;      //xy=1059,1891
AudioMixer4              voice8mix;      //xy=1062,1826
AudioSynthWaveformDc     voice4filterenv; //xy=1067,974
AudioSynthWaveformDc     voice5filterenv; //xy=1068,1230
AudioSynthWaveformDc     voice7filterenv; //xy=1077,1721
AudioSynthWaveformDc     voice4env;      //xy=1081,913
AudioSynthWaveformDc     voice6filterenv; //xy=1080,1484
AudioSynthWaveformDc     voice5env;      //xy=1082,1169
AudioMixer4              voice4mix;      //xy=1084,848
AudioMixer4              voice5mix;      //xy=1085,1104
AudioSynthWaveformDc     voice3filterenv; //xy=1088,726
AudioSynthWaveformDc     voice7env;      //xy=1091,1660
AudioSynthWaveformDc     voice6env;      //xy=1094,1423
AudioMixer4              voice7mix;      //xy=1094,1595
AudioMixer4              voice6mix;      //xy=1097,1358
AudioSynthWaveformDc     voice3env;      //xy=1102,665
AudioMixer4              voice3mix;      //xy=1105,600
AudioSynthWaveformDc     voice1filterenv; //xy=1119,250
AudioSynthWaveformDc     voice2filterenv; //xy=1121,494
AudioMixer4              voice1mix;      //xy=1135,134
AudioSynthWaveformDc     voice2env;      //xy=1135,433
AudioSynthWaveformDc     voice1env;      //xy=1136,199
AudioMixer4              voice2mix;      //xy=1138,368
AudioEffectMultiply      voice8multiply; //xy=1226,1864
AudioMixer4              voice8filtermodmixer; //xy=1236,1980
AudioEffectMultiply      voice4multiply; //xy=1248,886
AudioEffectMultiply      voice5multiply; //xy=1249,1142
AudioMixer4              voice4filtermodmixer; //xy=1258,1002
AudioEffectMultiply      voice7multiply; //xy=1258,1633
AudioEffectMultiply      voice6multiply; //xy=1261,1396
AudioMixer4              voice5filtermodmixer; //xy=1266,1252
AudioEffectMultiply      voice3multiply; //xy=1269,638
AudioMixer4              voice6filtermodmixer; //xy=1271,1512
AudioMixer4              voice7filtermodmixer; //xy=1275,1743
AudioMixer4              voice3filtermodmixer; //xy=1286,748
AudioEffectMultiply      voice1multiply; //xy=1299,172
AudioEffectMultiply      voice2multiply; //xy=1302,406
AudioMixer4              voice2filtermodmixer; //xy=1312,522
AudioMixer4              voice1filtermodmixer; //xy=1316,282
AudioFilterStateVariable voice8filter;   //xy=1409,1887
AudioFilterStateVariable voice5filter;   //xy=1429,1186
AudioFilterStateVariable voice4filter;   //xy=1431,909
AudioFilterStateVariable voice7filter;   //xy=1438,1677
AudioFilterStateVariable voice6filter;   //xy=1444,1419
AudioFilterStateVariable voice3filter;   //xy=1449,682
AudioFilterStateVariable voice2filter;   //xy=1485,429
AudioFilterStateVariable voice1filter;   //xy=1502,224
AudioPlaySerialflashRaw  playFlashRaw7;  //xy=1812,1897
AudioPlaySerialflashRaw  playFlashRaw6;  //xy=1815,1843
AudioPlaySerialflashRaw  playFlashRaw3;  //xy=1817,1653
AudioPlaySerialflashRaw  playFlashRaw2;  //xy=1818,1608
AudioPlaySerialflashRaw  playFlashRaw5;  //xy=1818,1787
AudioPlaySerialflashRaw  playFlashRaw8;  //xy=1819,1952
AudioPlaySerialflashRaw  playFlashRaw1;  //xy=1821,1551
AudioPlaySerialflashRaw  playFlashRaw4;  //xy=1829,1712
AudioMixer4              last4premix;    //xy=1909,1159
AudioMixer4              first4premix;   //xy=1910,1075
AudioMixer4              mixer2;         //xy=2061,1606
AudioMixer4              mixer3;         //xy=2062,1762
AudioMixer4              mixer4;         //xy=2241,1674
AudioEffectBitcrusher    bitcrusher1;    //xy=2265,1846
AudioFilterStateVariable delayFilter;    //xy=2359,1269
AudioMixer4              mainOutMixer;   //xy=2430,1152
AudioEffectDelay         delay1;         //xy=2488,1464
AudioOutputI2S           i2s1;           //xy=2656,1150
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
AudioConnection          patchCord84(playFlashRaw7, 0, mixer3, 2);
AudioConnection          patchCord85(playFlashRaw6, 0, mixer3, 1);
AudioConnection          patchCord86(playFlashRaw3, 0, mixer2, 2);
AudioConnection          patchCord87(playFlashRaw2, 0, mixer2, 1);
AudioConnection          patchCord88(playFlashRaw5, 0, mixer3, 0);
AudioConnection          patchCord89(playFlashRaw8, 0, mixer3, 3);
AudioConnection          patchCord90(playFlashRaw1, 0, mixer2, 0);
AudioConnection          patchCord91(playFlashRaw4, 0, mixer2, 3);
AudioConnection          patchCord92(last4premix, 0, mainOutMixer, 1);
AudioConnection          patchCord93(first4premix, 0, mainOutMixer, 0);
AudioConnection          patchCord94(mixer2, 0, mixer4, 0);
AudioConnection          patchCord95(mixer3, 0, mixer4, 1);
AudioConnection          patchCord96(mixer4, bitcrusher1);
AudioConnection          patchCord97(bitcrusher1, 0, mainOutMixer, 2);
AudioConnection          patchCord98(delayFilter, 0, mainOutMixer, 3);
AudioConnection          patchCord99(mainOutMixer, 0, i2s1, 0);
AudioConnection          patchCord100(mainOutMixer, 0, i2s1, 1);
AudioConnection          patchCord101(mainOutMixer, delay1);
AudioConnection          patchCord102(delay1, 0, delayFilter, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=2393,919
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

int colorIndex = 0;
int keyIndex = 0;

float noteFreq[7][8] = {

                         //5       1       6      2      7      3      8     4
                         {220.00,246.94,277.18,293.66,329.63,369.99,415.30,440.00},
                         {246.94,277.18,311.13,329.63,369.99,415.30,466.16,493.88},
                         {261.63,293.66,329.63,349.23,392.00,440.00,493.88,523.25},
                         {293.66,329.63,369.99,392.00,440.00,493.88,554.37,587.33},
                         {329.63,369.99,415.30,440.00,493.88,554.37,622.25,659.25},
                         {349.23,392.00,440.00,466.16,523.25,587.33,659.25,698.46},
                         {392.00,440.00,493.88,523.25,587.33,659.25,739.99,783.99},
                       };



// Original pattern where notes were not linear
//float noteFreq[7][8] = {
//
//                         //5       1       6      2      7      3      8     4
//                         {329.63,220.00,369.99,246.94,415.30,277.18,440.00,293.66},
//                         {369.99,246.94,415.30,277.18,466.16,311.13,493.88,329.63},
//                         {392.00,261.63,440.00,293.66,493.88,329.63,523.25,349.23},
//                         {440.00,293.66,493.88,329.63,554.37,369.99,587.33,392.00},
//                         {493.88,329.63,554.37,369.99,622.25,415.30,659.25,440.00},
//                         {523.25,349.23,587.33,392.00,659.25,440.00,698.46,466.16},
//                         {587.33,392.00,659.25,440.00,739.99,493.88,783.99,523.25},
//                       };




const char *sampleNames[] = {"1TR_10.WAV", "1TR_16.WAV", "1TR_19.WAV", "1TR_21.WAV", "1TR_24.WAV", "1TR_46.WAV", "1TR_58.WAV", "1TR_59.WAV"};

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


// Bitcrusher
int current_CrushBits = 16; //this defaults to passthrough.
int current_SampleRate = 44100; // this defaults to passthrough.


bool firstRunRead = true;




void setup() {

#if DEBUG
  Serial.begin(115200);
#endif

  SPI.setMOSI( 7 );   // MOSI_PIN for audio board
  SPI.setSCK( 14 );   // SCK_PIN for audio board

  if ( !SerialFlash.begin() )
      Serial.println( "Unable to access SPI Flash chip" );

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

  bitcrusher1.bits(current_CrushBits); 
  bitcrusher1.sampleRate(current_SampleRate); 

  playChime(2);

}






void loop() {

  setVolumes();
  DebounceButton::updateAll();

  if (analogRead(MODE_TOGGLE_PIN) < 200) {
    DEBUG_PRINTS("\nToggle Mode Button Pressed.");
    if (currentMode == 0) currentMode = 1;
    else if (currentMode == 1) currentMode = 0;
    delay(75);  // !! temporary debounce method
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
    envelopeFilter = digitalRead(ENVELOPE_SWITCH_PIN);
    processPotsMuxerValues_DrumMode();
    processPotsDirectValues_DrumMode();
    
  }
  firstRunRead = false;
}
