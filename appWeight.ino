// save current weight

void appWeight() 
{
    int16_t x, y;
    
    float weigth = appSetNumber();

    char buf[128];

    ttgo->tft->setTextSize(1);

    ttgo->tft->setTextColor(TFT_YELLOW, TFT_BLACK);
    snprintf(buf, sizeof(buf), "weight = %5.1f", weigth);
    ttgo->tft->drawString(buf, 5, 5, 4);

    preferences.begin("twatch", false);
    preferences.putUInt("weight", (uint32_t)(weigth*10));
    preferences.end();

    while (!ttgo->getTouch(x, y)) {} // Wait for touch to exit
    
  
    while (ttgo->getTouch(x, y)) {}  // Wait for release to return to the clock
    
    ttgo->tft->fillScreen(TFT_BLACK); // Clear screen
}
