#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define PANEL_RES_X 128
#define PANEL_RES_Y 64
#define PANEL_CHAIN 1

#define R1_PIN 25
#define G1_PIN 26
#define B1_PIN 27
#define R2_PIN 14
#define G2_PIN 12
#define B2_PIN 13
#define A_PIN  23
#define B_PIN  19
#define C_PIN  5
#define D_PIN  17
#define E_PIN  18
#define LAT_PIN 4
#define OE_PIN  15
#define CLK_PIN 16

MatrixPanel_I2S_DMA *dma_display = nullptr;

void setup() {
  Serial.begin(115200);

  HUB75_I2S_CFG mxconfig(
    PANEL_RES_X,
    PANEL_RES_Y,
    PANEL_CHAIN
  );

  mxconfig.gpio.r1 = R1_PIN;   mxconfig.gpio.g1 = G1_PIN;   mxconfig.gpio.b1 = B1_PIN;
  mxconfig.gpio.r2 = R2_PIN;   mxconfig.gpio.g2 = G2_PIN;   mxconfig.gpio.b2 = B2_PIN;
  mxconfig.gpio.a  = A_PIN;    mxconfig.gpio.b  = B_PIN;    mxconfig.gpio.c  = C_PIN;
  mxconfig.gpio.d  = D_PIN;    mxconfig.gpio.e  = E_PIN;
  mxconfig.gpio.lat = LAT_PIN; mxconfig.gpio.oe = OE_PIN;   mxconfig.gpio.clk = CLK_PIN;

  // FM6373D panel konfigurasyonu
  mxconfig.driver = HUB75_I2S_CFG::FM6126A;
  mxconfig.clkphase = false;
  mxconfig.i2sspeed = HUB75_I2S_CFG::HZ_10M;

  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();
  dma_display->setBrightness8(128);
  
  // Test ekrani
  dma_display->fillScreen(dma_display->color565(0, 0, 0));
  dma_display->drawRect(0, 0, dma_display->width(), dma_display->height(), dma_display->color565(0, 255, 0));
  dma_display->setCursor(15, 25);
  dma_display->setTextColor(dma_display->color565(255, 255, 255));
  dma_display->print("SISTEM AKTIF");
}

void loop() {
  delay(100);
}
