#include <PDM.h>

volatile int16_t sampleBuffer[256];
volatile int samplesRead;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!PDM.begin(1, 16000)) {
    Serial.println("Échec d'initialisation du micro PDM !");
    while (1);
  }

  PDM.setBufferSize(512);
  PDM.onReceive(onPDMdata);

  Serial.println("Micro PDM prêt !");
}

void loop() {
  if (samplesRead) {
    long sum = 0;
    for (int i = 0; i < samplesRead; i++) {
      sum += abs(sampleBuffer[i]);
    }
    float level = (float)sum / samplesRead;
    Serial.print("Niveau audio : ");
    Serial.println(level);
    samplesRead = 0;
  }
}

void onPDMdata() {
  samplesRead = PDM.read(sampleBuffer, sizeof(sampleBuffer) / sizeof(sampleBuffer[0]));
}
