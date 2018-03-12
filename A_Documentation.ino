/*

Teensy Audio Design Tool - https://www.pjrc.com/teensy/gui/index.html
Teensy Audio Hardware - https://www.pjrc.com/teensy/td_libs_Audio.html
Reference project - https://github.com/otem/teensypolysynth
Noise reference - http://openaudio.blogspot.com/2017/03/teensy-audio-board-self-noise.html





TO DO LIST
==================================
    Delay time exceeds memory limits? adjust memory allocation or limit range of delay time
    Create drum sounds for better testing
    Enable delay time and delay feedback pots in drum mode
    Change order of notes?
    Buttons not yet implemented:
      MODE_LED_PIN A14 (turn LED on when in drum mode - not working)
      OUTPUT_SELECT_PIN (switch to change audio output - not an option?)
      BASS_BOOST_PIN (button to change bass boost status)
        sgtl5000_1.enhanceBassEnable();
        sgtl5000_1.enhanceBassDisable();
    Investigate noise problem - only in line-out. Problem with amp ground?
    Make Green and Blue LEDs power less to match the output of the red?
    Replace power jack with the correct size, laser cut new side peice without the lineout option
    map volume pot so it is log and not linear
    map volume pot so it effects line out down to zero?
    Start implementing drum machine mode




WISHLIST ITEMS
==================================
    Microphone integration
    Recording phrases/loops in synth mode
    Recording patterns in drum mode






HARDWARE ASSIGNMENTS
==================================
  Teensy IO Pins
      0       Note Button 1
      1       Note Button 2
      2       Note Button 3
      3       (R)GB (pwm)
      4       R(G)B (pwm)
      5       RG(B) (pwm)
      6       Audio Board - Memory Chip
      7       Audio Board - SD Card, Memory Chip (SPI - shareable)
      8       Note Button 4
      9       Audio Board
      10      Audio Board - SD Card
      11      Audio Board  
      12      Audio Board - SD Card, Memory Chip(SPI - shareable)  
      13      Audio Board  
      14/A0   Audio Board - SD Card, Memory Chip (SPI - shareable)
      15/A1   Audio Board - Volume Pot
      16/A2   Note Button 5
      17/A3   Note Button 6
      18/A4   Audio Board (I2C - shareable)
      19/A5   Audio Board (I2C - shareable)
      20/A6   Note Button 7
      21/A7   Note Button 8
      22/A8   Audio Board
      23/A9   Audio Board
      24      Switch 3 - Multiplexor Output
      25      Switch 2 - Multiplexor Output
      26      Switch 1 - Multiplexor Output
      27      Switch 0 - Multiplexor Output
      28      Signal - Multiplexor Input
      29      (A18, Attack)
      30      (A19, Decay)
      31      (A20, Sustain)
      32      Envelope switch pin
      33      Bass boost button pin  (was LED for enevlope switch status)
      A10     Toggle Mode Pin (button 9)
      A11     Audio mode select switch
      A12     Pot - Release
      A13     Pot - Octave
      A14     DAC pin, should be Toggle Mode LED but is not working, Analog out only
      A15     (26, Mux 1)
      A16     (27, Mux 0)
      A17     (28, Mux Signal)
      A18     Pot - Attack
      A19     Pot - Decay
      A20     Pot - Sustain
      
      
  Multiplexor has 16 input channels
      0   VCO 1 Octave
      1   VCO 1 Shape
      2   VCO 1 and VCO 2 Mix
      3   VCO 2 Octave
      4   VCO 2 Shape
      5   VCO 2 Detune
      6   VCO Width/Mod
      7   LFO Frequency
      8   LFO Shape
      9   LFO Noise
      10  Delay Time
      11  Delay Feedback
      12  Filter Cutoff
      13  Filter Resonance
      14  Filter LFO Mix
      15  Filter Filter Mix




NOTE FREQUENCIES 
==================================
  Current Order
      C5        523.25
      F4        349.23
      D5        587.33
      G4        392.00
      E5        659.25
      A4        440.00
      F5        698.46
      A#4/Bb4   466.16

  Linear Order
      F4        349.23
      G4        392.00
      A4        440.00
      A#4/Bb4   466.16
      C5        523.25
      D5        587.33
      E5        659.25
      F5        698.46
      
















 */
