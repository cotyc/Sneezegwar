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

// Change Threshholds - Change these based on noise you may see on your aganlog inputs
#define STD_THRESHHOLD 8              // 5
#define VCO_SHAPE_THRESHHOLD 250      // 250
#define LFO_SHAPE_THRESHHOLD 200      // 200
#define ENVELOPE_THRESHHOLD 8         // 1
#define KEY_THRESHOLD 144             // 144







// *************************************************************************************************************
// *************************************************************************************************************


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     lfoenvelope;    //xy=767.5,1192.5
AudioSynthWaveform       lfo;            //xy=855.5,1398.5
AudioMixer4              mixerPeak;         //xy=898.5,1253.5
AudioAnalyzePeak         peak1;          //xy=1127.5,1116.5
AudioSynthWaveform       voice8b;        //xy=1363.5,2167.5
AudioSynthNoiseWhite     voice8n;        //xy=1363.5,2202.5
AudioSynthWaveform       voice8a;        //xy=1365.5,2129.5
AudioSynthWaveform       voice4a;        //xy=1384.5,1151.5
AudioSynthWaveform       voice4b;        //xy=1385.5,1189.5
AudioSynthNoiseWhite     voice4n;        //xy=1385.5,1224.5
AudioSynthWaveform       voice5b;        //xy=1386.5,1445.5
AudioSynthNoiseWhite     voice5n;        //xy=1386.5,1480.5
AudioSynthWaveform       voice5a;        //xy=1391.5,1402.5
AudioSynthWaveform       voice7b;        //xy=1395.5,1936.5
AudioSynthNoiseWhite     voice7n;        //xy=1395.5,1971.5
AudioSynthWaveform       voice6b;        //xy=1398.5,1699.5
AudioSynthNoiseWhite     voice6n;        //xy=1398.5,1734.5
AudioSynthWaveform       voice6a;        //xy=1400.5,1661.5
AudioSynthWaveform       voice7a;        //xy=1400.5,1893.5
AudioSynthWaveform       voice3b;        //xy=1406.5,941.5
AudioSynthNoiseWhite     voice3n;        //xy=1406.5,976.5
AudioSynthWaveform       voice3a;        //xy=1411.5,898.5
AudioSynthWaveform       voice1b;        //xy=1436.5,475.5
AudioSynthNoiseWhite     voice1n;        //xy=1439.5,519.5
AudioSynthWaveform       voice2b;        //xy=1439.5,709.5
AudioSynthNoiseWhite     voice2n;        //xy=1439.5,744.5
AudioSynthWaveform       voice1a;        //xy=1441.5,432.5
AudioSynthWaveform       voice2a;        //xy=1441.5,671.5
AudioSynthWaveformDc     voice8filterenv; //xy=1491.5,2313.5
AudioSynthWaveformDc     voice8env;      //xy=1505.5,2252.5
AudioMixer4              voice8mix;      //xy=1508.5,2187.5
AudioSynthWaveformDc     voice4filterenv; //xy=1513.5,1335.5
AudioSynthWaveformDc     voice5filterenv; //xy=1514.5,1591.5
AudioSynthWaveformDc     voice7filterenv; //xy=1523.5,2082.5
AudioSynthWaveformDc     voice4env;      //xy=1527.5,1274.5
AudioSynthWaveformDc     voice6filterenv; //xy=1526.5,1845.5
AudioSynthWaveformDc     voice5env;      //xy=1528.5,1530.5
AudioMixer4              voice4mix;      //xy=1530.5,1209.5
AudioMixer4              voice5mix;      //xy=1531.5,1465.5
AudioSynthWaveformDc     voice3filterenv; //xy=1534.5,1087.5
AudioSynthWaveformDc     voice7env;      //xy=1537.5,2021.5
AudioSynthWaveformDc     voice6env;      //xy=1540.5,1784.5
AudioMixer4              voice7mix;      //xy=1540.5,1956.5
AudioMixer4              voice6mix;      //xy=1543.5,1719.5
AudioSynthWaveformDc     voice3env;      //xy=1548.5,1026.5
AudioMixer4              voice3mix;      //xy=1551.5,961.5
AudioSynthWaveformDc     voice1filterenv; //xy=1565.5,611.5
AudioSynthWaveformDc     voice2filterenv; //xy=1567.5,855.5
AudioMixer4              voice1mix;      //xy=1581.5,495.5
AudioSynthWaveformDc     voice2env;      //xy=1581.5,794.5
AudioSynthWaveformDc     voice1env;      //xy=1582.5,560.5
AudioMixer4              voice2mix;      //xy=1584.5,729.5
AudioEffectMultiply      voice8multiply; //xy=1672.5,2225.5
AudioMixer4              voice8filtermodmixer; //xy=1682.5,2341.5
AudioEffectMultiply      voice4multiply; //xy=1694.5,1247.5
AudioEffectMultiply      voice5multiply; //xy=1695.5,1503.5
AudioMixer4              voice4filtermodmixer; //xy=1704.5,1363.5
AudioEffectMultiply      voice7multiply; //xy=1704.5,1994.5
AudioEffectMultiply      voice6multiply; //xy=1707.5,1757.5
AudioMixer4              voice5filtermodmixer; //xy=1712.5,1613.5
AudioEffectMultiply      voice3multiply; //xy=1715.5,999.5
AudioMixer4              voice6filtermodmixer; //xy=1717.5,1873.5
AudioMixer4              voice7filtermodmixer; //xy=1721.5,2104.5
AudioMixer4              voice3filtermodmixer; //xy=1732.5,1109.5
AudioEffectMultiply      voice1multiply; //xy=1745.5,533.5
AudioEffectMultiply      voice2multiply; //xy=1748.5,767.5
AudioMixer4              voice2filtermodmixer; //xy=1758.5,883.5
AudioMixer4              voice1filtermodmixer; //xy=1762.5,643.5
AudioFilterStateVariable voice8filter;   //xy=1855.5,2248.5
AudioFilterStateVariable voice5filter;   //xy=1875.5,1547.5
AudioFilterStateVariable voice4filter;   //xy=1877.5,1270.5
AudioFilterStateVariable voice7filter;   //xy=1884.5,2038.5
AudioFilterStateVariable voice6filter;   //xy=1890.5,1780.5
AudioFilterStateVariable voice3filter;   //xy=1895.5,1043.5
AudioFilterStateVariable voice2filter;   //xy=1931.5,790.5
AudioFilterStateVariable voice1filter;   //xy=1948.5,585.5
AudioPlaySerialflashRaw  playFlashRaw7;  //xy=2258.5,2258.5
AudioPlaySerialflashRaw  playFlashRaw6;  //xy=2261.5,2204.5
AudioPlaySerialflashRaw  playFlashRaw3;  //xy=2263.5,2014.5
AudioPlaySerialflashRaw  playFlashRaw2;  //xy=2264.5,1969.5
AudioPlaySerialflashRaw  playFlashRaw5;  //xy=2264.5,2148.5
AudioPlaySerialflashRaw  playFlashRaw8;  //xy=2265.5,2313.5
AudioPlaySerialflashRaw  playFlashRaw1;  //xy=2267.5,1912.5
AudioPlaySerialflashRaw  playFlashRaw4;  //xy=2275.5,2073.5
AudioMixer4              mixerVoiceMerge5_8;    //xy=2355.5,1520.5
AudioMixer4              mixerVoiceMerge1_4;   //xy=2356.5,1436.5
AudioSynthWaveform       bloodSine0;     //xy=2452.5000762939453,722.5000114440918
AudioSynthWaveform       bloodSine1;     //xy=2452.5000762939453,762.5000114440918
AudioSynthWaveform       bloodSine2;     //xy=2452.5000762939453,802.5000114440918
AudioSynthWaveform       bloodSine3;     //xy=2452.5000762939453,842.5000114440918
AudioSynthWaveform       bloodSine4;     //xy=2452.5000762939453,882.5000114440918
AudioSynthWaveform       bloodSine5;     //xy=2452.5000762939453,922.5000114440918
AudioSynthWaveform       bloodSine6;     //xy=2452.5000762939453,962.5000114440918
AudioSynthWaveform       bloodSine7;     //xy=2452.5000762939453,1002.5000114440918
AudioSynthWaveform       bloodSine8;     //xy=2452.5000762939453,1042.5000114440918
AudioSynthWaveform       bloodSine9;     //xy=2452.5000762939453,1082.5000114440918
AudioSynthWaveform       bloodSine10;    //xy=2452.5000762939453,1122.5000114440918
AudioSynthWaveform       bloodSine11;    //xy=2452.5000762939453,1162.5000114440918
AudioSynthWaveform       bloodSine12;    //xy=2452.5000762939453,1202.5000114440918
AudioSynthWaveform       bloodSine13;    //xy=2452.5000762939453,1242.5000114440918
AudioSynthWaveform       bloodSine14;    //xy=2452.5000762939453,1282.5000114440918
AudioSynthWaveform       bloodSine15;    //xy=2452.5000762939453,1322.5000114440918
AudioMixer4              mixerDrumMerge1_4;         //xy=2507.5,1967.5
AudioMixer4              mixerDrumMerge5_8;         //xy=2508.5,2123.5
AudioMixer4              mixerPreCrusher;         //xy=2583.5,1583.5
AudioEffectEnvelope      bloodEnv0;      //xy=2612.5000762939453,722.5000114440918
AudioEffectEnvelope      bloodEnv1;      //xy=2612.5000762939453,762.5000114440918
AudioEffectEnvelope      bloodEnv2;      //xy=2612.5000762939453,802.5000114440918
AudioEffectEnvelope      bloodEnv3;      //xy=2612.5000762939453,842.5000114440918
AudioEffectEnvelope      bloodEnv4;      //xy=2612.5000762939453,882.5000114440918
AudioEffectEnvelope      bloodEnv5;      //xy=2612.5000762939453,922.5000114440918
AudioEffectEnvelope      bloodEnv6;      //xy=2612.5000762939453,962.5000114440918
AudioEffectEnvelope      bloodEnv7;      //xy=2612.5000762939453,1002.5000114440918
AudioEffectEnvelope      bloodEnv8;      //xy=2612.5000762939453,1042.5000114440918
AudioEffectEnvelope      bloodEnv9;      //xy=2612.5000762939453,1082.5000114440918
AudioEffectEnvelope      bloodEnv10;     //xy=2612.5000762939453,1122.5000114440918
AudioEffectEnvelope      bloodEnv11;     //xy=2612.5000762939453,1162.5000114440918
AudioEffectEnvelope      bloodEnv12;     //xy=2612.5000762939453,1202.5000114440918
AudioEffectEnvelope      bloodEnv13;     //xy=2612.5000762939453,1242.5000114440918
AudioEffectEnvelope      bloodEnv14;     //xy=2612.5000762939453,1282.5000114440918
AudioEffectEnvelope      bloodEnv15;     //xy=2612.5000762939453,1322.5000114440918
AudioEffectBitcrusher    bitcrusherFX;    //xy=2639.071487426758,1429.2142610549927
AudioMixer4              mixerDrumOutput;         //xy=2687.5,2035.5
AudioFilterStateVariable delayFilter;    //xy=2819.785633087158,1610.4999551773071
AudioMixer4              mixerBloodMerge1_4;    //xy=2875,900
AudioMixer4              mixerBloodMerge5_8;    //xy=2875,980
AudioMixer4              mixerBloodMerge9_12;    //xy=2879,1060
AudioMixer4              mixerBloodMerge13_16;    //xy=2883,1140
AudioEffectDelay         delay1;         //xy=2934.5,1825.5
AudioMixer4              mixerFinalOut;   //xy=2936,1460
AudioMixer4              mixerBloodOutput; //xy=3164.5,1020
AudioOutputI2S           i2s1;           //xy=3212.4999809265137,1467.2142248153687
AudioConnection          patchCord1(lfoenvelope, 0, mixerPeak, 0);
AudioConnection          patchCord2(lfo, 0, voice1filtermodmixer, 1);
AudioConnection          patchCord3(lfo, 0, voice2filtermodmixer, 1);
AudioConnection          patchCord4(lfo, 0, voice3filtermodmixer, 1);
AudioConnection          patchCord5(lfo, 0, voice4filtermodmixer, 1);
AudioConnection          patchCord6(lfo, 0, voice5filtermodmixer, 1);
AudioConnection          patchCord7(lfo, 0, voice6filtermodmixer, 1);
AudioConnection          patchCord8(lfo, 0, voice7filtermodmixer, 1);
AudioConnection          patchCord9(lfo, 0, voice8filtermodmixer, 1);
AudioConnection          patchCord10(lfo, 0, mixerPeak, 1);
AudioConnection          patchCord11(mixerPeak, peak1);
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
AudioConnection          patchCord76(voice8filter, 0, mixerVoiceMerge5_8, 3);
AudioConnection          patchCord77(voice5filter, 0, mixerVoiceMerge5_8, 0);
AudioConnection          patchCord78(voice4filter, 0, mixerVoiceMerge1_4, 3);
AudioConnection          patchCord79(voice7filter, 0, mixerVoiceMerge5_8, 2);
AudioConnection          patchCord80(voice6filter, 0, mixerVoiceMerge5_8, 1);
AudioConnection          patchCord81(voice3filter, 0, mixerVoiceMerge1_4, 2);
AudioConnection          patchCord82(voice2filter, 0, mixerVoiceMerge1_4, 1);
AudioConnection          patchCord83(voice1filter, 0, mixerVoiceMerge1_4, 0);
AudioConnection          patchCord84(playFlashRaw7, 0, mixerDrumMerge5_8, 2);
AudioConnection          patchCord85(playFlashRaw6, 0, mixerDrumMerge5_8, 1);
AudioConnection          patchCord86(playFlashRaw3, 0, mixerDrumMerge1_4, 2);
AudioConnection          patchCord87(playFlashRaw2, 0, mixerDrumMerge1_4, 1);
AudioConnection          patchCord88(playFlashRaw5, 0, mixerDrumMerge5_8, 0);
AudioConnection          patchCord89(playFlashRaw8, 0, mixerDrumMerge5_8, 3);
AudioConnection          patchCord90(playFlashRaw1, 0, mixerDrumMerge1_4, 0);
AudioConnection          patchCord91(playFlashRaw4, 0, mixerDrumMerge1_4, 3);
AudioConnection          patchCord92(mixerVoiceMerge5_8, 0, mixerPreCrusher, 1);
AudioConnection          patchCord93(mixerVoiceMerge1_4, 0, mixerPreCrusher, 0);
AudioConnection          patchCord94(bloodSine0, bloodEnv0);
AudioConnection          patchCord95(bloodSine1, bloodEnv1);
AudioConnection          patchCord96(bloodSine2, bloodEnv2);
AudioConnection          patchCord97(bloodSine3, bloodEnv3);
AudioConnection          patchCord98(bloodSine4, bloodEnv4);
AudioConnection          patchCord99(bloodSine5, bloodEnv5);
AudioConnection          patchCord100(bloodSine6, bloodEnv6);
AudioConnection          patchCord101(bloodSine7, bloodEnv7);
AudioConnection          patchCord102(bloodSine8, bloodEnv8);
AudioConnection          patchCord103(bloodSine9, bloodEnv9);
AudioConnection          patchCord104(bloodSine10, bloodEnv10);
AudioConnection          patchCord105(bloodSine11, bloodEnv11);
AudioConnection          patchCord106(bloodSine12, bloodEnv12);
AudioConnection          patchCord107(bloodSine13, bloodEnv13);
AudioConnection          patchCord108(bloodSine14, bloodEnv14);
AudioConnection          patchCord109(bloodSine15, bloodEnv15);
AudioConnection          patchCord110(mixerDrumMerge1_4, 0, mixerDrumOutput, 0);
AudioConnection          patchCord111(mixerDrumMerge5_8, 0, mixerDrumOutput, 1);
AudioConnection          patchCord112(mixerPreCrusher, bitcrusherFX);
AudioConnection          patchCord113(bloodEnv0, 0, mixerBloodMerge1_4, 0);
AudioConnection          patchCord114(bloodEnv1, 0, mixerBloodMerge1_4, 1);
AudioConnection          patchCord115(bloodEnv2, 0, mixerBloodMerge1_4, 2);
AudioConnection          patchCord116(bloodEnv3, 0, mixerBloodMerge1_4, 3);
AudioConnection          patchCord117(bloodEnv4, 0, mixerBloodMerge5_8, 0);
AudioConnection          patchCord118(bloodEnv5, 0, mixerBloodMerge5_8, 1);
AudioConnection          patchCord119(bloodEnv6, 0, mixerBloodMerge5_8, 2);
AudioConnection          patchCord120(bloodEnv7, 0, mixerBloodMerge5_8, 3);
AudioConnection          patchCord121(bloodEnv8, 0, mixerBloodMerge9_12, 0);
AudioConnection          patchCord122(bloodEnv9, 0, mixerBloodMerge9_12, 1);
AudioConnection          patchCord123(bloodEnv10, 0, mixerBloodMerge9_12, 2);
AudioConnection          patchCord124(bloodEnv11, 0, mixerBloodMerge9_12, 3);
AudioConnection          patchCord125(bloodEnv12, 0, mixerBloodMerge13_16, 0);
AudioConnection          patchCord126(bloodEnv13, 0, mixerBloodMerge13_16, 1);
AudioConnection          patchCord127(bloodEnv14, 0, mixerBloodMerge13_16, 2);
AudioConnection          patchCord128(bloodEnv15, 0, mixerBloodMerge13_16, 3);
AudioConnection          patchCord129(bitcrusherFX, 0, mixerFinalOut, 0);
AudioConnection          patchCord130(mixerDrumOutput, 0, mixerPreCrusher, 3);
AudioConnection          patchCord131(delayFilter, 0, mixerFinalOut, 3);
AudioConnection          patchCord132(mixerBloodMerge1_4, 0, mixerBloodOutput, 0);
AudioConnection          patchCord133(mixerBloodMerge5_8, 0, mixerBloodOutput, 1);
AudioConnection          patchCord134(mixerBloodMerge9_12, 0, mixerBloodOutput, 2);
AudioConnection          patchCord135(mixerBloodMerge13_16, 0, mixerBloodOutput, 3);
AudioConnection          patchCord136(delay1, 0, delayFilter, 0);
AudioConnection          patchCord137(mixerFinalOut, 0, i2s1, 0);
AudioConnection          patchCord138(mixerFinalOut, 0, i2s1, 1);
AudioConnection          patchCord139(mixerFinalOut, delay1);
AudioConnection          patchCord140(mixerBloodOutput, 0, mixerFinalOut, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=774.5000419616699,1130.5000190734863
// GUItool: end automatically generated code



// *************************************************************************************************************
// *************************************************************************************************************

int currentMode = 0;   // tracks operating mode - 0 = synth, 1 = drum machine, 2 = sampler, etc.

DebounceButton note0 = DebounceButton(BTN_PIN_0, DBTN_PULLUP_INTERNAL, 10, 8, 8);   // debounce time, hold time, retrigger time
DebounceButton note1 = DebounceButton(BTN_PIN_1, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton note2 = DebounceButton(BTN_PIN_2, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton note3 = DebounceButton(BTN_PIN_3, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton note4 = DebounceButton(BTN_PIN_4, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton note5 = DebounceButton(BTN_PIN_5, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton note6 = DebounceButton(BTN_PIN_6, DBTN_PULLUP_INTERNAL, 10, 8, 8);
DebounceButton note7 = DebounceButton(BTN_PIN_7, DBTN_PULLUP_INTERNAL, 10, 8, 8);

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
float potValues[21];
float potValuesPrevious[21];

int potDirectPins[5] = {OCTAVE_PIN,ENVELOPE_ATTACK_PIN,ENVELOPE_DECAY_PIN,ENVELOPE_SUSTAIN_PIN,ENVELOPE_RELEASE_PIN};

// LEDS
int redLevel;
int greenLevel;
int blueLevel;
int redLevelArray[7] = {   182, 255, 0,   248, 0,   240,  255};
int greenLevelArray[7] = { 246, 0,   133, 159, 230, 0,    0};
int blueLevelArray[7] = {  41,  129, 252, 0,   255, 180, 40};

// Switches
int envelopeFilter;
boolean bassBoostState;
boolean bassBoostStatePrevious;

// Peak Values
float tempPulseWidth;
float tempPeak;
float tempRMS;

// Volumes
float mainVolume;
int tempLineOutLevel;

// Synth
float vcoOneLevel;
float vcoTwoLevel;
int vcoOneOct = 1;
int vcoTwoOct = 1;
float deTune = 1;
int octArray[6] = {1,1,2,4,8,16};
int waveShapeOneIndex;
int waveShapeTwoIndex;
int lfoWaveShapeIndex;
int octOneIndex;
int octTwoIndex;
bool voiceBPulse;
float tempDetuneMod;
float deTuneLfo;

// WaveShapes
short waveShapes[4] = {
                        WAVEFORM_SINE,
                        WAVEFORM_SAWTOOTH,
                        WAVEFORM_SQUARE,
                        WAVEFORM_PULSE,
                      };
                      
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
int current_CrushBits = 16;    // this defaults to passthrough.
int current_SampleRate = 44100;     // this defaults to passthrough.

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
  pinMode(BASS_BOOST_PIN, INPUT_PULLUP);

  // Init Mixer
  mixerVoiceMerge1_4.gain(0, .25);
  mixerVoiceMerge1_4.gain(1, .25);
  mixerVoiceMerge1_4.gain(2, .25);
  mixerVoiceMerge1_4.gain(3, .25);
  mixerVoiceMerge5_8.gain(0, .25);
  mixerVoiceMerge5_8.gain(1, .25);
  mixerVoiceMerge5_8.gain(2, .25);
  mixerVoiceMerge5_8.gain(3, .25);

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
  mixerFinalOut.gain(3,0);
  lfo.begin(1,3,WAVEFORM_SINE);

  mixerFinalOut.gain(0,.5);
  lfoenvelope.amplitude(1);
  voiceBPulse = false;

  bitcrusherFX.bits(current_CrushBits); 
  bitcrusherFX.sampleRate(current_SampleRate); 

  playChime(2);

  sgtl5000_1.audioPostProcessorEnable();    // for Bass boost post effect

  bassBoostState = !digitalRead(BASS_BOOST_PIN);
  bassBoostStatePrevious = !bassBoostState;
  
}






void loop() {

  setVolumes();
  DebounceButton::updateAll();
 
  envelopeFilter = digitalRead(ENVELOPE_SWITCH_PIN);

  if (analogRead(MODE_TOGGLE_PIN) < 200) {
    DEBUG_PRINTS("\nToggle Mode Button Pressed.");
    if (currentMode == 0) currentMode = 1;
    else if (currentMode == 1) currentMode = 0;
    delay(250);  // !! temporary debounce method
  }
  
  bassBoostState = !digitalRead(BASS_BOOST_PIN);
  if (bassBoostState != bassBoostStatePrevious) {
    if (bassBoostState) {
      sgtl5000_1.enhanceBassEnable();
      DEBUG_PRINTS("\nBass boost on >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
      bassBoostStatePrevious = bassBoostState;
    }
    else {
      sgtl5000_1.enhanceBassDisable();
      DEBUG_PRINTS("\nBass boost off <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
      bassBoostStatePrevious = bassBoostState;
    }
  }

  readPots();
      
  if (currentMode == 0) {
    // Operate Synth mode
    defineNotes();
    peakProcessing_SynthMode();
  }
  else if (currentMode == 1) {
    // Operate Drum machine mode
  }

//  DEBUG_PRINT("\n\t DIAGNOSTICS - CPU: ", AudioProcessorUsageMax());
//  DEBUG_PRINT("Memory: ", AudioMemoryUsageMax());
  AudioProcessorUsageMaxReset();

  firstRunRead = false;
}
