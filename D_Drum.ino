void processPotsMuxerValues_DrumMode() {
  // Read potentiometers via muxer
  for (int i = 0; i < 16; i ++) {

    // Reverse the readings (pots installed inverted)
    potsMuxerValues[i] = (1023-readMuxer(i));

    if (i == 1 || i == 4) {  // Threshold for VCO shapes
      changeThresh = 250;
    } else if (i == 8)       // Threshold for LFO shape
      changeThresh = 200;
    else {
      changeThresh = 5;     // Threshold for all others
    }

    if (abs(potsMuxerValues[i] - potsMuxerValuesPrevious[i]) > changeThresh || firstRunRead) {
      // VCO 1
      if (i == 0) {
        // VCO 1 Octave
      }
      if (i == 1) {
        // VCO 1 Shape
      }
      if (i == 2) {
        //VCO 1 Mix
      }
      // VCO 2
      if (i == 3) {
        // VCO 2 Octave
      }
      if (i == 4) {
        // VCO 2 Shape
      }
      if (i == 5) {
        // PulseWith / Mod
      }
      if (i == 6) {
        // LFO
      }
      if (i == 7) {
        // LFO Frequency
      }
      if (i == 8) {
        // LFO Shape
      }
      if (i == 9) {
        // LFO Noise
      }
      if (i == 10) {
        // Delay Time
        delay1.delay(0, potsMuxerValues[i] / 2.4);
      }
      if (i == 11) {
        // Delay Feedback
        mainOutMixer.gain(3, potsMuxerValues[i] / 1023);
      }
      if (i == 12) {
        // Filter Cutoff
      }
      if (i == 13) {
        // Filter Resonance
      }
      if (i == 14) {
        // Filter LFO Mix
      }
      if (i == 15) {
        // Filter Filter Mix
      }
      potsMuxerValuesPrevious[i] = potsMuxerValues[i];
    }
  }
}


void processPotsDirectValues_DrumMode() {
  for (int i = 0; i < 5; i++) {

    // Reverse the readings (pots installed inverted)
    potsDirectValues[i] = (1023-getSmooth(potsDirectPins[i]));

    if (i == 0) {
      extraChangeThresh = 144;  // Threshold for Octave (key) changes
    } else {
      extraChangeThresh = 1;  // Threshold for everything else
    }
    if (abs(potsDirectValues[i] - potsDirectValuesPrevious[i]) > extraChangeThresh || firstRunRead) {
      if (i == 0) {
        // Octave - key of notes
        }
      if (i == 1) {
        // Envelope Controls - Attack
        current_CrushBits = map(potsDirectValues[i], 0, 1023, 16, 2);
        bitcrusher1.bits(current_CrushBits);
      }
      if (i == 2) {
        // Envelope Controls - Decay
        current_SampleRate = map(potsDirectValues[i], 0, 1023, 44100, 345);
        bitcrusher1.sampleRate(current_SampleRate);
      }
      if (i == 3) {
        // Envelope Controls - Sustain
      }
      if (i == 4) {
        // Envelope Controls - Release
      }
      potsDirectValuesPrevious[i] = potsDirectValues[i];
    }
  }
}

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

