#include <Adafruit_NeoPixel.h>

// Configuration
#define PIN 4
#define NUM_BLOCKS 8
#define PIXELS_PER_BLOCK 1
#define TOTAL_PIXELS (NUM_BLOCKS * PIXELS_PER_BLOCK)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(TOTAL_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();  // Initialize all pixels to 'off'
}

void loop() {
  // Run the gradient fade effect on each block independently
  // Arcobaleno ridotto e lento
  for (int block = 0; block < NUM_BLOCKS; block++) {
    showGradient(block, strip.Color(0, 255, 26), strip.Color(255, 0, 229), 3, 25);
    showGradient(block, strip.Color(255, 0, 229), strip.Color(0, 255, 26), 3, 25);
  }
/*
  // Run the soft pulsing effect on each block independently
  // Spegnimento e riaccensione lente
  // SI POTREBBE FARE SOLO SPEGNIMENTO...
  for (int block = 0; block < NUM_BLOCKS; block++) {
    pulseColor(block, strip.Color(0, 0, 255), 5, 100);
  }
*/
  // Run the color wipe effect on each block independently
  // Cambia colore secco
  for (int block = 0; block < NUM_BLOCKS; block++) {
    colorWipe(block, strip.Color(random(0, 255), random(0, 255),random(0, 255)), 1500);
  }

  delay(5000);
/*
  // Run the theater chase effect on each block independently
  // Lampeggia e poi spegne
  for (int block = 0; block < NUM_BLOCKS; block++) {
    theaterChase(block, strip.Color(127, 127, 127), 100);
  }
*/
  // Run the rainbow effect on each block independently
  // Arcobaleno più completo e veloce
  for (int block = 0; block < NUM_BLOCKS; block++) {
    rainbow(block, 20, 100);
  }
/*
  // Run the theater chase rainbow effect on each block independently
  for (int block = 0; block < NUM_BLOCKS; block++) {
    theaterChaseRainbow(block, 50, 10);
  }
*/
}

void setBlockColor(int block, uint32_t color) {
  for (int i = 0; i < PIXELS_PER_BLOCK; i++) {
    strip.setPixelColor(block * PIXELS_PER_BLOCK + i, color);
  }
}

void showGradient(int block, uint32_t startColor, uint32_t endColor, int duration, int steps) {
  for (int step = 0; step < steps; step++) {
    uint8_t r = ((startColor >> 16 & 0xFF) * (steps - step) + (endColor >> 16 & 0xFF) * step) / steps;
    uint8_t g = ((startColor >> 8 & 0xFF) * (steps - step) + (endColor >> 8 & 0xFF) * step) / steps;
    uint8_t b = ((startColor & 0xFF) * (steps - step) + (endColor & 0xFF) * step) / steps;
    setBlockColor(block, strip.Color(r, g, b));
    strip.show();
    delay(duration * 1000 / steps);
  }
}

void pulseColor(int block, uint32_t color, int duration, int steps) {
  for (int step = 0; step < steps; step++) {
    float brightness = (1 + sin(step * 2.0 * PI / steps)) / 2;
    uint8_t r = ((color >> 16 & 0xFF) * brightness);
    uint8_t g = ((color >> 8 & 0xFF) * brightness);
    uint8_t b = ((color & 0xFF) * brightness);
    setBlockColor(block, strip.Color(r, g, b));
    strip.show();
    delay(duration * 1000 / steps);
  }
}

void colorWipe(int block, uint32_t color, int wait) {
  setBlockColor(block, color);
  strip.show();
  delay(wait);
}

void theaterChase(int block, uint32_t color, int wait) {
  for (int a = 0; a < 10; a++) {  // Repeat 10 times
    setBlockColor(block, color);
    strip.show();
    delay(wait);
    setBlockColor(block, 0);  // Turn off all pixels in the block
    strip.show();
    delay(wait);
  }
}

void rainbow(int block, int wait, int duration) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    uint32_t color = strip.gamma32(strip.ColorHSV(firstPixelHue));
    setBlockColor(block, color);
    strip.show();
    delay(wait);
    if (--duration <= 0) break;
  }
}

void theaterChaseRainbow(int block, int wait, int cycles) {
  for (int j = 0; j < 256 * cycles; j++) {  // cycles of all colors in the wheel
    uint32_t color = strip.gamma32(strip.ColorHSV((j * 65536L / 256)));
    setBlockColor(block, color);
    strip.show();
    delay(wait);
    setBlockColor(block, 0);  // Turn off all pixels in the block
    strip.show();
    delay(wait);
  }
}
