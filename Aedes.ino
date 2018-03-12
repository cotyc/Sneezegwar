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

// GUItool: begin automatically generated code
AudioSynthWaveformDc     lfoenvelope;          //xy=589.047534942627,966.6665487289429
AudioSynthWaveform       lfo;            //xy=677.4761581420898,1172.523769378662
AudioMixer4              mixer1;         //xy=720.9047355651855,1027.666706085205
AudioAnalyzePeak         peak1;          //xy=949.0476112365723,890.8095207214355
AudioSynthWaveform       voice8b;        //xy=1185.6190299987793,1941.6666355133057
AudioSynthNoiseWhite     voice8n;        //xy=1185.6190299987793,1976.6666355133057
AudioSynthWaveform       voice8a;        //xy=1187.6190299987793,1903.6666355133057
AudioSynthWaveform       voice4a;        //xy=1206.6190299987793,925.6666355133057
AudioSynthWaveform       voice4b;        //xy=1207.6190299987793,963.6666355133057
AudioSynthNoiseWhite     voice4n;        //xy=1207.6190299987793,998.6666355133057
AudioSynthWaveform       voice5b;        //xy=1208.6190299987793,1219.6666355133057
AudioSynthNoiseWhite     voice5n;        //xy=1208.6190299987793,1254.6666355133057
AudioSynthWaveform       voice5a;        //xy=1213.6190299987793,1176.6666355133057
AudioSynthWaveform       voice7b;        //xy=1217.6190299987793,1710.6666355133057
AudioSynthNoiseWhite     voice7n;        //xy=1217.6190299987793,1745.6666355133057
AudioSynthWaveform       voice6b;        //xy=1220.6190299987793,1473.6666355133057
AudioSynthNoiseWhite     voice6n;        //xy=1220.6190299987793,1508.6666355133057
AudioSynthWaveform       voice6a;        //xy=1222.6190299987793,1435.6666355133057
AudioSynthWaveform       voice7a;        //xy=1222.6190299987793,1667.6666355133057
AudioSynthWaveform       voice3b;        //xy=1228.6190299987793,715.6666355133057
AudioSynthNoiseWhite     voice3n;        //xy=1228.6190299987793,750.6666355133057
AudioSynthWaveform       voice3a;        //xy=1233.6190299987793,672.6666355133057
AudioSynthWaveform       voice1b;        //xy=1258.6190299987793,249.66663551330566
AudioSynthNoiseWhite     voice1n;        //xy=1261.6190299987793,293.66663551330566
AudioSynthWaveform       voice2b;        //xy=1261.6190299987793,483.66663551330566
AudioSynthNoiseWhite     voice2n;        //xy=1261.6190299987793,518.6666355133057
AudioSynthWaveform       voice1a;        //xy=1263.6190299987793,206.66663551330566
AudioSynthWaveform       voice2a;        //xy=1263.6190299987793,445.66663551330566
AudioSynthWaveformDc     voice8filterenv; //xy=1313.6190299987793,2087.6666355133057
AudioSynthWaveformDc     voice8env;      //xy=1327.6190299987793,2026.6666355133057
AudioMixer4              voice8mix;      //xy=1330.6190299987793,1961.6666355133057
AudioSynthWaveformDc     voice4filterenv; //xy=1335.6190299987793,1109.6666355133057
AudioSynthWaveformDc     voice5filterenv; //xy=1336.6190299987793,1365.6666355133057
AudioSynthWaveformDc     voice7filterenv; //xy=1345.6190299987793,1856.6666355133057
AudioSynthWaveformDc     voice4env;      //xy=1349.6190299987793,1048.6666355133057
AudioSynthWaveformDc     voice6filterenv; //xy=1348.6190299987793,1619.6666355133057
AudioSynthWaveformDc     voice5env;      //xy=1350.6190299987793,1304.6666355133057
AudioMixer4              voice4mix;      //xy=1352.6190299987793,983.6666355133057
AudioMixer4              voice5mix;      //xy=1353.6190299987793,1239.6666355133057
AudioSynthWaveformDc     voice3filterenv; //xy=1356.6190299987793,861.6666355133057
AudioSynthWaveformDc     voice7env;      //xy=1359.6190299987793,1795.6666355133057
AudioSynthWaveformDc     voice6env;      //xy=1362.6190299987793,1558.6666355133057
AudioMixer4              voice7mix;      //xy=1362.6190299987793,1730.6666355133057
AudioMixer4              voice6mix;      //xy=1365.6190299987793,1493.6666355133057
AudioSynthWaveformDc     voice3env;      //xy=1370.6190299987793,800.6666355133057
AudioMixer4              voice3mix;      //xy=1373.6190299987793,735.6666355133057
AudioSynthWaveformDc     voice1filterenv; //xy=1387.6190299987793,385.66663551330566
AudioSynthWaveformDc     voice2filterenv; //xy=1389.6190299987793,629.6666355133057
AudioMixer4              voice1mix;      //xy=1403.6190299987793,269.66663551330566
AudioSynthWaveformDc     voice2env;      //xy=1403.6190299987793,568.6666355133057
AudioSynthWaveformDc     voice1env;      //xy=1404.6190299987793,334.66663551330566
AudioMixer4              voice2mix;      //xy=1406.6190299987793,503.66663551330566
AudioEffectMultiply      voice8multiply; //xy=1494.6190299987793,1999.6666355133057
AudioMixer4              voice8filtermodmixer; //xy=1504.6190299987793,2115.6666355133057
AudioEffectMultiply      voice4multiply; //xy=1516.6190299987793,1021.6666355133057
AudioEffectMultiply      voice5multiply; //xy=1517.6190299987793,1277.6666355133057
AudioMixer4              voice4filtermodmixer; //xy=1526.6190299987793,1137.6666355133057
AudioEffectMultiply      voice7multiply; //xy=1526.6190299987793,1768.6666355133057
AudioEffectMultiply      voice6multiply; //xy=1529.6190299987793,1531.6666355133057
AudioMixer4              voice5filtermodmixer; //xy=1534.6190299987793,1387.6666355133057
AudioEffectMultiply      voice3multiply; //xy=1537.6190299987793,773.6666355133057
AudioMixer4              voice6filtermodmixer; //xy=1539.6190299987793,1647.6666355133057
AudioMixer4              voice7filtermodmixer; //xy=1543.6190299987793,1878.6666355133057
AudioMixer4              voice3filtermodmixer; //xy=1554.6190299987793,883.6666355133057
AudioEffectMultiply      voice1multiply; //xy=1567.6190299987793,307.66663551330566
AudioEffectMultiply      voice2multiply; //xy=1570.6190299987793,541.6666355133057
AudioMixer4              voice2filtermodmixer; //xy=1580.6190299987793,657.6666355133057
AudioMixer4              voice1filtermodmixer; //xy=1584.6190299987793,417.66663551330566
AudioFilterStateVariable voice8filter;   //xy=1677.6190299987793,2022.6666355133057
AudioFilterStateVariable voice5filter;   //xy=1697.6190299987793,1321.6666355133057
AudioFilterStateVariable voice4filter;   //xy=1699.6190299987793,1044.6666355133057
AudioFilterStateVariable voice7filter;   //xy=1706.6190299987793,1812.6666355133057
AudioFilterStateVariable voice6filter;   //xy=1712.6190299987793,1554.6666355133057
AudioFilterStateVariable voice3filter;   //xy=1717.6190299987793,817.6666355133057
AudioFilterStateVariable voice2filter;   //xy=1753.6190299987793,564.6666355133057
AudioFilterStateVariable voice1filter;   //xy=1770.6190299987793,359.66663551330566
AudioMixer4              last4premix;    //xy=2177.6190299987793,1294.6666355133057
AudioMixer4              first4premix;   //xy=2178.6190299987793,1210.6666355133057
AudioFilterStateVariable delayFilter;    //xy=2627.6190299987793,1404.6666355133057
AudioMixer4              mainOutMixer;   //xy=2698.6190299987793,1287.6666355133057
AudioEffectDelay         delay1;         //xy=2756.6190299987793,1599.6666355133057
AudioOutputI2S           i2s1;           //xy=2924.6190299987793,1285.6666355133057
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
AudioConnection          patchCord86(delayFilter, 0, mainOutMixer, 3);
AudioConnection          patchCord87(mainOutMixer, 0, i2s1, 0);
AudioConnection          patchCord88(mainOutMixer, 0, i2s1, 1);
AudioConnection          patchCord89(mainOutMixer, delay1);
AudioConnection          patchCord90(delay1, 0, delayFilter, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=2661.6190299987793,1054.6666355133057
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
DebounceButton modeToggle = DebounceButton(MODE_TOGGLE_PIN, DBTN_PULLUP_INTERNAL, 20, 2000);


// Buttons
//int noteBtnPins[8] = {BTN_PIN_0, BTN_PIN_1, BTN_PIN_2, BTN_PIN_3, BTN_PIN_4, BTN_PIN_5, BTN_PIN_6, BTN_PIN_7};
//
//Bounce noteBounce[] = {
//                        Bounce(BTN_PIN_0,10),
//                        Bounce(BTN_PIN_1,10),
//                        Bounce(BTN_PIN_2,10),
//                        Bounce(BTN_PIN_3,10),
//                        Bounce(BTN_PIN_4,10),
//                        Bounce(BTN_PIN_5,10),
//                        Bounce(BTN_PIN_6,10),
//                        Bounce(BTN_PIN_7,10),
//
//                      };

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



//int btnState[8];
//int btnStatePrevious[8];


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

//  for(int i=0; i<8; i++){
//    pinMode(noteBtnPins[i], INPUT_PULLUP);
//    digitalWrite(noteBtnPins[i], HIGH);
//  }

  playChime(2);

}






void loop() {

  setVolumes();
  DebounceButton::updateAll();

  // Execute code for Synth mode
  if (currentMode == 0) {

    // Operate Synth mode
    envelopeFilter = digitalRead(ENVELOPE_SWITCH_PIN);
    defineNotes();

   // processButtons_SynthMode(); // !! Temporary - need to replace with DebounceButton library and clean up code

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
