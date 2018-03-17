void onPressDrum(int key) {
  DEBUG_PRINT("\nButton ", key);
  DEBUG_PRINTS(" Pressed.");
  switch (key) {
    case 0:
      playFlashRaw1.play(sampleNames[4]);
      break;
    case 1:
      playFlashRaw2.play(sampleNames[3]);
      break;
    case 2:
      playFlashRaw3.play(sampleNames[2]);
      break;
    case 3:
      playFlashRaw4.play(sampleNames[5]);
      break;
    case 4:
      playFlashRaw5.play(sampleNames[0]);
      break;
    case 5:
      playFlashRaw6.play(sampleNames[1]);
      break;
    case 6:
      playFlashRaw7.play(sampleNames[6]);
      break;
    case 7:
      playFlashRaw8.play(sampleNames[7]);
      break;
  }
}

void onHoldDrum(int key) {
  DEBUG_PRINT("\nButton ", key);
  DEBUG_PRINTS(" Held.");
}

void onReleaseDrum(int key) {
  DEBUG_PRINT("\nButton ", key);
  DEBUG_PRINTS(" Released.");
}

void processPotsDrums(int pot) {
  switch (pot) {
    case 0:
      // VCO 1 Octave
      break;
    case 1:
      // VCO 1 Shape
      break;
    case 2:
      //VCO 1 Mix
      break;
    case 3:
      // VCO 2 Octave
      break;
    case 4:
      // VCO 2 Shape
      break;
    case 5:
      // VCO 2 Detune
      break;
    case 6:
      // PulseWith / Mod
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      // LFO Noise
      break;
    case 10:
      // Delay Time
      if (checkValueChange(pot, 5) == true) {
        delay1.delay(0, potValues[pot] / 2.4);
      }
      break;
    case 11:
      // Delay Feedback
      if (checkValueChange(pot, 5) == true) {
        mainOutMixer.gain(3, potValues[pot] / 1023);
      }
      break;
    case 12:
      // Filter Cutoff
      break;
    case 13:
      // Filter Resonance
      break;
    case 14:
      // Filter LFO Mix
      break;
    case 15:
      // Filter Filter Mix
      break;
    case 16:    // End Muxer pot values and start direct pot values
      // Octave - key of notes    
      break;
    case 17:
      // Envelope Controls - Attack
      if (checkValueChange(pot, 1) == true) {
        current_CrushBits = map(potValues[pot], 0, 1023, 16, 2);
        bitcrusher1.bits(current_CrushBits);
      }
      break;
    case 18:
      // Envelope Controls - Decay
      if (checkValueChange(pot, 1) == true) {
          current_SampleRate = map(potValues[pot], 0, 1023, 44100, 345);
          bitcrusher1.sampleRate(current_SampleRate);
      }
      break;
    case 19:
      // Envelope Controls - Sustain
      break;
    case 20:
      // Envelope Controls - Release
      break;
  }
  potValuesPrevious[pot] = potValues[pot];
}
