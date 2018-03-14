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
  // !! need to add back in bitcrusher? 
}

