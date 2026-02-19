const int flexPins[5] = {32, 33, 34, 35, 36};  // ESP32 analog pins
int thresholds[5] = {210, 270, 100, 700, 555};  // Customize per sensor

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 5; i++) {
    pinMode(flexPins[i], INPUT);
  }
}

void loop() {
  const unsigned long captureDuration = 5000; // 5 seconds
  const int sampleDelay = 20;                 // ms between samples
  const int maxSamples = captureDuration / sampleDelay;

  long sums[5] = {0};
  int samples = 0;

  unsigned long startTime = millis();
  while (millis() - startTime < captureDuration) {
    for (int i = 0; i < 5; i++) {
      sums[i] += analogRead(flexPins[i]);
    }
    samples++;
    delay(sampleDelay);
  }

  bool fingerUp[5];
  int fingerCount = 0;

  Serial.println("Averaged Results:");
  for (int i = 0; i < 5; i++) {
    int avg = sums[i] / samples;
    Serial.print("Flex "); Serial.print(i); Serial.print(" Avg: ");
    Serial.print(avg);

    if (avg < thresholds[i]) {
      fingerUp[i] = true;   // finger up
      fingerCount++;
      Serial.println(" → UP");
    } else {
      fingerUp[i] = false;  // finger bent
      Serial.println(" → BENT");
    }
  }

  // Show ASCII hand
  Serial.println("Hand State:");
  Serial.print("  ");
  for (int i = 0; i < 5; i++) {
    if (fingerUp[i]) Serial.print("| "); // up = vertical finger
    else Serial.print("- ");             // bent = dash
  }
  Serial.println();
  Serial.println("   \\     /");
  Serial.println("    \\___/");

  Serial.print("Fingers Up: ");
  Serial.println(fingerCount);
  Serial.println("---------------");

  delay(1000); // pause between capture cycles
}
