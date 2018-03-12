

void processPotsMuxerValues_SynthMode() {
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
        octOneIndex = (potsMuxerValues[i] / 204) + 1;
        if (octOneIndex < 6) {
          vcoOneOct = octArray[octOneIndex];
        }
      }
      if (i == 1) {
        // VCO 1 Shape
        waveShapeOneIndex = potsMuxerValues[i] / 255;
        if (waveShapeOneIndex < 4) {
          voice1a.begin(waveShapes[waveShapeOneIndex]);
          voice2a.begin(waveShapes[waveShapeOneIndex]);
          voice3a.begin(waveShapes[waveShapeOneIndex]);
          voice4a.begin(waveShapes[waveShapeOneIndex]);
          voice5a.begin(waveShapes[waveShapeOneIndex]);
          voice6a.begin(waveShapes[waveShapeOneIndex]);
          voice7a.begin(waveShapes[waveShapeOneIndex]);
          voice8a.begin(waveShapes[waveShapeOneIndex]);
        }
      }
      if (i == 2) {
        //VCO 1 Mix
        vcoOneLevel = (potsMuxerValues[i]) / 1023;
        vcoTwoLevel = 1 - (potsMuxerValues[i]) / 1023;
        voice1mix.gain(1, vcoOneLevel);
        voice1mix.gain(0, vcoTwoLevel);
        voice2mix.gain(1, vcoOneLevel);
        voice2mix.gain(0, vcoTwoLevel);
        voice3mix.gain(1, vcoOneLevel);
        voice3mix.gain(0, vcoTwoLevel);
        voice4mix.gain(1, vcoOneLevel);
        voice4mix.gain(0, vcoTwoLevel);
        voice5mix.gain(1, vcoOneLevel);
        voice5mix.gain(0, vcoTwoLevel);
        voice6mix.gain(1, vcoOneLevel);
        voice6mix.gain(0, vcoTwoLevel);
        voice7mix.gain(1, vcoOneLevel);
        voice7mix.gain(0, vcoTwoLevel);
        voice8mix.gain(1, vcoOneLevel);
        voice8mix.gain(0, vcoTwoLevel);
      }
      // VCO 2
      if (i == 3) {
        // VCO 2 Octave
        octTwoIndex = (potsMuxerValues[i] / 204) + 1;
        if (octTwoIndex < 6) {
          vcoTwoOct = octArray[octTwoIndex];
        }
      }
      if (i == 4) {
        // VCO 2 Shape
        waveShapeTwoIndex = potsMuxerValues[i] / 255;
        if (waveShapeTwoIndex < 4) {
          if (waveShapeTwoIndex == 3) {
            voiceBPulse = true;
          } else {
            voiceBPulse = false;
          }
          voice1b.begin(waveShapes[waveShapeTwoIndex]);
          voice2b.begin(waveShapes[waveShapeTwoIndex]);
          voice3b.begin(waveShapes[waveShapeTwoIndex]);
          voice4b.begin(waveShapes[waveShapeTwoIndex]);
          voice5b.begin(waveShapes[waveShapeTwoIndex]);
          voice6b.begin(waveShapes[waveShapeTwoIndex]);
          voice7b.begin(waveShapes[waveShapeTwoIndex]);
          voice8b.begin(waveShapes[waveShapeTwoIndex]);
        }
      }
      if (i == 5) {
        // VCO 2 Detune
        deTune = potsMuxerValues[i];
        deTune = mapfloat(deTune, 0, 1023, .875, 1.125);
      }
      // PulseWith / Mod
      if (i == 6) {
        tempPulseWidth = 1 - (potsMuxerValues[i] / 1023);
        tempDetuneMod = potsMuxerValues[i] / 2046;
      }
      // LFO
      if (i == 7) {
        // LFO Frequency
        lfo.frequency(potsMuxerValues[i] / 50);
      }
      if (i == 8) {
        // LFO Shape
        lfoWaveShapeIndex = potsMuxerValues[i] / 204.6;
        if (lfoWaveShapeIndex < 5) {
          lfo.begin(lfoWaveShapes[lfoWaveShapeIndex]);
          DEBUG_PRINT("\nLFO Wave Shape: ", lfoWaveShapeIndex);
        }
      }
      if (i == 9) {
        // LFO Noise
        voice1n.amplitude(potsMuxerValues[i] / 3096);
        voice2n.amplitude(potsMuxerValues[i] / 3096);
        voice3n.amplitude(potsMuxerValues[i] / 3096);
        voice4n.amplitude(potsMuxerValues[i] / 3096);
        voice5n.amplitude(potsMuxerValues[i] / 3096);
        voice6n.amplitude(potsMuxerValues[i] / 3096);
        voice7n.amplitude(potsMuxerValues[i] / 3096);
        voice8n.amplitude(potsMuxerValues[i] / 3096);
      }
      // Delay
      if (i == 10) {
        // Delay Time
        delay1.delay(0, potsMuxerValues[i] / 2.4);
      }
      if (i == 11) {
        // Delay Feedback
        mainOutMixer.gain(3, potsMuxerValues[i] / 1023);
      }
      // Filter
      if (i == 12) {
        // Filter Cutoff
        voice1filter.frequency(potsMuxerValues[i] * 10);
        voice2filter.frequency(potsMuxerValues[i] * 10);
        voice3filter.frequency(potsMuxerValues[i] * 10);
        voice4filter.frequency(potsMuxerValues[i] * 10);
        voice5filter.frequency(potsMuxerValues[i] * 10);
        voice6filter.frequency(potsMuxerValues[i] * 10);
        voice7filter.frequency(potsMuxerValues[i] * 10);
        voice8filter.frequency(potsMuxerValues[i] * 10);
      }
      if (i == 13) {
        // Filter Resonance
        voice1filter.resonance((potsMuxerValues[i] / 204) + .9);
        voice2filter.resonance((potsMuxerValues[i] / 204) + .9);
        voice3filter.resonance((potsMuxerValues[i] / 204) + .9);
        voice4filter.resonance((potsMuxerValues[i] / 204) + .9);
        voice5filter.resonance((potsMuxerValues[i] / 204) + .9);
        voice6filter.resonance((potsMuxerValues[i] / 204) + .9);
        voice7filter.resonance((potsMuxerValues[i] / 204) + .9);
        voice8filter.resonance((potsMuxerValues[i] / 204) + .9);
      }
      if (i == 14) {
        // Filter LFO Mix
        voice1filtermodmixer.gain(1, potsMuxerValues[i] / 1023);
        voice2filtermodmixer.gain(1, potsMuxerValues[i] / 1023);
        voice3filtermodmixer.gain(1, potsMuxerValues[i] / 1023);
        voice4filtermodmixer.gain(1, potsMuxerValues[i] / 1023);
        voice5filtermodmixer.gain(1, potsMuxerValues[i] / 1023);
        voice6filtermodmixer.gain(1, potsMuxerValues[i] / 1023);
        voice7filtermodmixer.gain(1, potsMuxerValues[i] / 1023);
        voice8filtermodmixer.gain(1, potsMuxerValues[i] / 1023);
      }
      if (i == 15) {
        // Filter Filter Mix
        voice1filtermodmixer.gain(0, potsMuxerValues[i] / 1023);
        voice2filtermodmixer.gain(0, potsMuxerValues[i] / 1023);
        voice3filtermodmixer.gain(0, potsMuxerValues[i] / 1023);
        voice4filtermodmixer.gain(0, potsMuxerValues[i] / 1023);
        voice5filtermodmixer.gain(0, potsMuxerValues[i] / 1023);
        voice6filtermodmixer.gain(0, potsMuxerValues[i] / 1023);
        voice7filtermodmixer.gain(0, potsMuxerValues[i] / 1023);
        voice8filtermodmixer.gain(0, potsMuxerValues[i] / 1023);
      }
      potsMuxerValuesPrevious[i] = potsMuxerValues[i];
    }
  }
}

void processPotsDirectValues_SynthMode() {
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
        colorIndex = potsDirectValues[i] / 146;
        if (colorIndex < 7) {
          keyIndex = colorIndex;
          redLevel = redLevelArray[colorIndex];
          blueLevel = blueLevelArray[colorIndex];
          greenLevel = greenLevelArray[colorIndex];
        }
      }
      if (i == 1) {
        // Envelope Controls - Attack
        if (firstRunRead) {
          attackTimeFilter = potsDirectValues[i] * 2;
          attackTime = potsDirectValues[i] * 2;
        }
        if (envelopeFilter == HIGH) {
          attackTimeFilter = potsDirectValues[i] * 2;
        } else {
          attackTime = potsDirectValues[i] * 2;
        }
      }
      if (i == 2) {
        // Envelope Controls - Decay
        if (firstRunRead) {
          decayTimeFilter = potsDirectValues[i];
          decayTime = potsDirectValues[i];
        }
        if (envelopeFilter == HIGH) {
          decayTimeFilter = potsDirectValues[i];
        } else {
          decayTime = potsDirectValues[i];
        }
      }
      if (i == 3) {
        // Envelope Controls - Sustain
        if (firstRunRead) {
          sustainLevelFilter = potsDirectValues[i];
          sustainLevelFilter = mapfloat(sustainLevelFilter, 0, 1023, -1, 1);
          sustainLevel = potsDirectValues[i] / 1023;
        }
        if (envelopeFilter == HIGH) {
          sustainLevelFilter = potsDirectValues[i];
          sustainLevelFilter = mapfloat(sustainLevelFilter, 0, 1023, -1, 1);
        } else {
          sustainLevel = potsDirectValues[i] / 1023;
        }
      }
      if (i == 4) {
        // Envelope Controls - Release
        if (firstRunRead) {
          releaseTimeFilter = potsDirectValues[i] * 2;
          releaseTime = potsDirectValues[i] * 2;
        }
        if (envelopeFilter == HIGH) {
          releaseTimeFilter = potsDirectValues[i] * 2;
        } else {
          releaseTime = potsDirectValues[i] * 2;
        }
      }
      potsDirectValuesPrevious[i] = potsDirectValues[i];
    }
  }
}

void defineNotes() {
  for (int i = 0; i < 8; i++) {
    if (i == 0) {
      voice1a.frequency((noteFreq[keyIndex][i] / 4)*vcoOneOct);
      voice1b.frequency(((noteFreq[keyIndex][i] / 4 * vcoTwoOct) * deTune) * deTuneLfo);
    }
    if (i == 1) {
      voice2a.frequency((noteFreq[keyIndex][i] / 4)*vcoOneOct);
      voice2b.frequency(((noteFreq[keyIndex][i] / 4 * vcoTwoOct) * deTune) * deTuneLfo);
    }
    if (i == 2) {
      voice3a.frequency((noteFreq[keyIndex][i] / 4)*vcoOneOct);
      voice3b.frequency(((noteFreq[keyIndex][i] / 4 * vcoTwoOct) * deTune) * deTuneLfo);
    }
    if (i == 3) {
      voice4a.frequency((noteFreq[keyIndex][i] / 4)*vcoOneOct);
      voice4b.frequency(((noteFreq[keyIndex][i] / 4 * vcoTwoOct) * deTune) * deTuneLfo);
    }
    if (i == 4) {
      voice5a.frequency((noteFreq[keyIndex][i] / 4)*vcoOneOct);
      voice5b.frequency(((noteFreq[keyIndex][i] / 4 * vcoTwoOct) * deTune) * deTuneLfo);
    }
    if (i == 5) {
      voice6a.frequency((noteFreq[keyIndex][i] / 4)*vcoOneOct);
      voice6b.frequency(((noteFreq[keyIndex][i] / 4 * vcoTwoOct) * deTune) * deTuneLfo);
    }
    if (i == 6) {
      voice7a.frequency((noteFreq[keyIndex][i] / 4)*vcoOneOct);
      voice7b.frequency(((noteFreq[keyIndex][i] / 4 * vcoTwoOct) * deTune) * deTuneLfo);
    }
    if (i == 7) {
      voice8a.frequency((noteFreq[keyIndex][i] / 4)*vcoOneOct);
      voice8b.frequency(((noteFreq[keyIndex][i] / 4 * vcoTwoOct) * deTune) * deTuneLfo);
    }
  }
}

void peakProcessing_SynthMode() {
  // LFO Peak Processing
  if (peak1.available()) tempPeak = peak1.read();

  analogWrite(LED_BLUE_PIN, blueLevel * tempPeak);
  analogWrite(LED_GREEN_PIN, greenLevel * tempPeak);
  analogWrite(LED_RED_PIN, redLevel * tempPeak);

  voice1a.pulseWidth((tempPeak / 2) + tempPulseWidth);
  voice2a.pulseWidth((tempPeak / 2) + tempPulseWidth);
  voice3a.pulseWidth((tempPeak / 2) + tempPulseWidth);
  voice4a.pulseWidth((tempPeak / 2) + tempPulseWidth);
  voice5a.pulseWidth((tempPeak / 2) + tempPulseWidth);
  voice6a.pulseWidth((tempPeak / 2) + tempPulseWidth);
  voice7a.pulseWidth((tempPeak / 2) + tempPulseWidth);
  voice8a.pulseWidth((tempPeak / 2) + tempPulseWidth);

  if (voiceBPulse) {
    voice1b.pulseWidth((tempPeak / 2) + tempPulseWidth);
    voice2b.pulseWidth((tempPeak / 2) + tempPulseWidth);
    voice3b.pulseWidth((tempPeak / 2) + tempPulseWidth);
    voice4b.pulseWidth((tempPeak / 2) + tempPulseWidth);
    voice5b.pulseWidth((tempPeak / 2) + tempPulseWidth);
    voice6b.pulseWidth((tempPeak / 2) + tempPulseWidth);
    voice7b.pulseWidth((tempPeak / 2) + tempPulseWidth);
    voice8b.pulseWidth((tempPeak / 2) + tempPulseWidth);
  }
  else {
    deTuneLfo = ((tempPeak) * tempDetuneMod + 1);
    //    DEBUG_PRINT("\nLFO Detune: ", deTuneLfo);
  }
}
