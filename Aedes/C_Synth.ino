


void processPotsSynth(int pot) {
  switch (pot) {
    case 0:
      // VCO 1 Octave
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        octOneIndex = (potValues[pot] / 204) + 1;
        if (octOneIndex < 6) {
          vcoOneOct = octArray[octOneIndex];
        }
      }
      break;
    case 1:
      // VCO 1 Shape
      if (checkValueChange(pot, VCO_SHAPE_THRESHHOLD) == true) {
        waveShapeOneIndex = potValues[pot] / 255;
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
      break;
    case 2:
      //VCO 1 Mix
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        vcoOneLevel = (potValues[pot]) / 1023;
        vcoTwoLevel = 1 - (potValues[pot]) / 1023;
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
      break;
    case 3:
      // VCO 2 Octave
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        octTwoIndex = (potValues[pot] / 204) + 1;
        if (octTwoIndex < 6) {
          vcoTwoOct = octArray[octTwoIndex];
        }
      }
      break;
    case 4:
      // VCO 2 Shape
      if (checkValueChange(pot, VCO_SHAPE_THRESHHOLD) == true) {
        waveShapeTwoIndex = potValues[pot] / 255;
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
      break;
    case 5:
      // VCO 2 Detune
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        deTune = potValues[pot];
        deTune = mapfloat(deTune, 0, 1023, .875, 1.125);
      }
      break;
    case 6:
      // PulseWith / Mod
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        tempPulseWidth = 1 - (potValues[pot] / 1023);
        tempDetuneMod = potValues[pot] / 2046;
      }
      break;
    case 7:
      // LFO Frequency
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        lfo.frequency(potValues[pot] / 50);
      }
      break;
    case 8:
      // LFO Shape
      if (checkValueChange(pot, LFO_SHAPE_THRESHHOLD) == true) {
        lfoWaveShapeIndex = potValues[pot] / 204.6;
        if (lfoWaveShapeIndex < 5) {
          lfo.begin(lfoWaveShapes[lfoWaveShapeIndex]);
          DEBUG_PRINT("\nLFO Wave Shape: ", lfoWaveShapeIndex);
        }
      }
      break;
    case 9:
      // LFO Noise
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        voice1n.amplitude(potValues[pot] / 3096);
        voice2n.amplitude(potValues[pot] / 3096);
        voice3n.amplitude(potValues[pot] / 3096);
        voice4n.amplitude(potValues[pot] / 3096);
        voice5n.amplitude(potValues[pot] / 3096);
        voice6n.amplitude(potValues[pot] / 3096);
        voice7n.amplitude(potValues[pot] / 3096);
        voice8n.amplitude(potValues[pot] / 3096);
      }
      break;
    case 10:
      // Delay Time
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        delay1.delay(0, potValues[pot] / 2.4);
      }
      break;
    case 11:
      // Delay Feedback
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        mainOutMixer.gain(3, potValues[pot] / 1023);
      }
      break;
    case 12:
      // Filter Cutoff
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        voice1filter.frequency(potValues[pot] * 10);
        voice2filter.frequency(potValues[pot] * 10);
        voice3filter.frequency(potValues[pot] * 10);
        voice4filter.frequency(potValues[pot] * 10);
        voice5filter.frequency(potValues[pot] * 10);
        voice6filter.frequency(potValues[pot] * 10);
        voice7filter.frequency(potValues[pot] * 10);
        voice8filter.frequency(potValues[pot] * 10);
      }
      break;
    case 13:
      // Filter Resonance
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        voice1filter.resonance((potValues[pot] / 204) + .9);
        voice2filter.resonance((potValues[pot] / 204) + .9);
        voice3filter.resonance((potValues[pot] / 204) + .9);
        voice4filter.resonance((potValues[pot] / 204) + .9);
        voice5filter.resonance((potValues[pot] / 204) + .9);
        voice6filter.resonance((potValues[pot] / 204) + .9);
        voice7filter.resonance((potValues[pot] / 204) + .9);
        voice8filter.resonance((potValues[pot] / 204) + .9);
      }
      break;
    case 14:
      // Filter LFO Mix
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        voice1filtermodmixer.gain(1, potValues[pot] / 1023);
        voice2filtermodmixer.gain(1, potValues[pot] / 1023);
        voice3filtermodmixer.gain(1, potValues[pot] / 1023);
        voice4filtermodmixer.gain(1, potValues[pot] / 1023);
        voice5filtermodmixer.gain(1, potValues[pot] / 1023);
        voice6filtermodmixer.gain(1, potValues[pot] / 1023);
        voice7filtermodmixer.gain(1, potValues[pot] / 1023);
        voice8filtermodmixer.gain(1, potValues[pot] / 1023);
      }
      break;
    case 15:
      // Filter Filter Mix
      if (checkValueChange(pot, STD_THRESHHOLD) == true) {
        voice1filtermodmixer.gain(0, potValues[pot] / 1023);
        voice2filtermodmixer.gain(0, potValues[pot] / 1023);
        voice3filtermodmixer.gain(0, potValues[pot] / 1023);
        voice4filtermodmixer.gain(0, potValues[pot] / 1023);
        voice5filtermodmixer.gain(0, potValues[pot] / 1023);
        voice6filtermodmixer.gain(0, potValues[pot] / 1023);
        voice7filtermodmixer.gain(0, potValues[pot] / 1023);
        voice8filtermodmixer.gain(0, potValues[pot] / 1023);
      }
      break;

// End Muxer pot values and start direct pot values

    case 16:    
      // Key    
      if (checkValueChange(pot, KEY_THRESHOLD) == true) {
        colorIndex = potValues[pot] / 146;
        if (colorIndex < 7) {
          keyIndex = colorIndex;
          redLevel = redLevelArray[colorIndex];
          blueLevel = blueLevelArray[colorIndex];
          greenLevel = greenLevelArray[colorIndex];
        }
      }
      break;
    case 17:
      // Envelope Controls - Attack
      if (checkValueChange(pot, ENVELOPE_THRESHHOLD) == true) {

        if (firstRunRead) {
          attackTimeFilter = potValues[pot] * 2;
          attackTime = potValues[pot] * 2;
        }
        if (envelopeFilter == HIGH) {
          current_CrushBits = map(potValues[pot], 0, 1023, 16, 2);
          bitcrusher1.bits(current_CrushBits);
          // attackTimeFilter = potValues[pot] * 2;
        } else {
          attackTime = potValues[pot] * 2;
        }

      }
      break;
    case 18:
      // Envelope Controls - Decay
      if (checkValueChange(pot, ENVELOPE_THRESHHOLD) == true) {

        if (firstRunRead) {
          decayTimeFilter = potValues[pot];
          decayTime = potValues[pot];
        }
        if (envelopeFilter == HIGH) {
          current_SampleRate = map(potValues[pot], 0, 1023, 44100, 345);
          bitcrusher1.sampleRate(current_SampleRate);
          // decayTimeFilter = potValues[pot];
        } else {
          decayTime = potValues[pot];
        }
      }
      break;
    case 19:
      // Envelope Controls - Sustain
      if (checkValueChange(pot, ENVELOPE_THRESHHOLD) == true) {

        if (firstRunRead) {
          sustainLevelFilter = potValues[pot];
          sustainLevelFilter = mapfloat(sustainLevelFilter, 0, 1023, -1, 1);
          sustainLevel = potValues[pot] / 1023;
        }
        if (envelopeFilter == HIGH) {
          sustainLevelFilter = potValues[pot];
          sustainLevelFilter = mapfloat(sustainLevelFilter, 0, 1023, -1, 1);
        } else {
          sustainLevel = potValues[pot] / 1023;
        }
      }
      break;
    case 20:
      // Envelope Controls - Release
      if (checkValueChange(pot, ENVELOPE_THRESHHOLD) == true) {

        if (firstRunRead) {
          releaseTimeFilter = potValues[pot] * 2;
          releaseTime = potValues[pot] * 2;
        }
        if (envelopeFilter == HIGH) {
          releaseTimeFilter = potValues[pot] * 2;
        } else {
          releaseTime = potValues[pot] * 2;
        }

      }
      break;
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

  // Commented out for LED tests to secondary Teensy
  analogWrite(LED_BLUE_PIN, blueLevel * tempPeak);
  // analogWrite(LED_GREEN_PIN, greenLevel * tempPeak);
  // analogWrite(LED_RED_PIN, redLevel * tempPeak);

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


void onPressSynth(int key) {
  DEBUG_PRINT("\nButton ", key);
  DEBUG_PRINTS(" Pressed");
  switch (key) {
    case 0:
      voice1env.amplitude(1, attackTime);
      voice1filterenv.amplitude(1, attackTimeFilter);
      break;
    case 1:
      voice2env.amplitude(1, attackTime);
      voice2filterenv.amplitude(1, attackTimeFilter);
      break;
    case 2:
      voice3env.amplitude(1, attackTime);
      voice3filterenv.amplitude(1, attackTimeFilter);
      break;
    case 3:
      voice4env.amplitude(1, attackTime);
      voice4filterenv.amplitude(1, attackTimeFilter);
      break;
    case 4:
      voice5env.amplitude(1, attackTime);
      voice5filterenv.amplitude(1, attackTimeFilter);
      break;
    case 5:
      voice6env.amplitude(1, attackTime);
      voice6filterenv.amplitude(1, attackTimeFilter);
      break;
    case 6:
      voice7env.amplitude(1, attackTime);
      voice7filterenv.amplitude(1, attackTimeFilter);
      break;
    case 7:
      voice8env.amplitude(1, attackTime);
      voice8filterenv.amplitude(1, attackTimeFilter);
      break;
  }
  noteTrigFlag[key] = true;
  attackWait[key] = millis();
}

void onHoldSynth(int key) {
  DEBUG_PRINT("\nButton ", key);
  DEBUG_PRINTS(" Held.");
  if (millis() - attackWait[key] > attackTime && noteTrigFlag[key]) {
    switch (key) {
      case 0:
        voice1env.amplitude(sustainLevel, decayTime);
        break;
      case 1:
        voice2env.amplitude(sustainLevel, decayTime);
        break;
      case 2:
        voice3env.amplitude(sustainLevel, decayTime);
        break;
      case 3:
        voice4env.amplitude(sustainLevel, decayTime);
        break;
      case 4:
        voice5env.amplitude(sustainLevel, decayTime);
        break;
      case 5:
        voice6env.amplitude(sustainLevel, decayTime);
        break;
      case 6:
        voice7env.amplitude(sustainLevel, decayTime);
        break;
      case 7:
        voice8env.amplitude(sustainLevel, decayTime);
        break;
    }
  }

  if (millis() - attackWait[key] > attackTimeFilter && noteTrigFlag[key]) {
    switch (key) {
      case 0:
        voice1filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
        break;
      case 1:
        voice2filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
        break;
      case 2:
        voice3filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
        break;
      case 3:
        voice4filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
        break;
      case 4:
        voice5filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
        break;
      case 5:
        voice6filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
        break;
      case 6:
        voice7filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
        break;
      case 7:
        voice8filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
        break;
    }
  }
}

void onReleaseSynth(int key) {
  DEBUG_PRINT("\nButton ", key);
  DEBUG_PRINTS(" Released.");
  switch (key) {
    case 0:
      noteTrigFlag[key] = false;
      voice1env.amplitude(0, releaseTime);
      voice1filterenv.amplitude(-1, releaseTimeFilter);
      break;
    case 1:
      noteTrigFlag[key] = false;
      voice2env.amplitude(0, releaseTime);
      voice2filterenv.amplitude(-1, releaseTimeFilter);
      break;
    case 2:
      noteTrigFlag[key] = false;
      voice3env.amplitude(0, releaseTime);
      voice3filterenv.amplitude(-1, releaseTimeFilter);
      break;
    case 3:
      noteTrigFlag[key] = false;
      voice4env.amplitude(0, releaseTime);
      voice4filterenv.amplitude(-1, releaseTimeFilter);
      break;
    case 4:
      noteTrigFlag[key] = false;
      voice5env.amplitude(0, releaseTime);
      voice5filterenv.amplitude(-1, releaseTimeFilter);
      break;
    case 5:
      noteTrigFlag[key] = false;
      voice6env.amplitude(0, releaseTime);
      voice6filterenv.amplitude(-1, releaseTimeFilter);
      break;
    case 6:
      noteTrigFlag[key] = false;
      voice7env.amplitude(0, releaseTime);
      voice7filterenv.amplitude(-1, releaseTimeFilter);
      break;
    case 7:
      noteTrigFlag[key] = false;
      voice8env.amplitude(0, releaseTime);
      voice8filterenv.amplitude(-1, releaseTimeFilter);
      break;
  }
}

