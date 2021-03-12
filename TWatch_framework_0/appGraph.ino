#include "FS.h"
#include "SPIFFS.h"

//using namespace fs;

void appGraph() 
{
    int16_t x, y;
    char buf[128];

    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int hh, mm, yyear, mmonth, dday; // 
    int base_hh, base_mm, base_yyear, base_mmonth, base_dday; //

    base_yyear = 1970;
    base_mmonth = 1;
    base_dday = 1;
    base_hh = 0;
    base_mm = 0;

    ttgo->tft->setTextSize(1);
    ttgo->tft->setTextColor(TFT_YELLOW, TFT_BLACK);
    snprintf(buf, sizeof(buf), "Graph application");
    ttgo->tft->drawString(buf, 5, 5, 4);

    //*
    fs::File file = SPIFFS.open("/journal.txt");
    if(!file || file.isDirectory())
    {
        Serial.println("- failed to open file for reading");
        return;
    }

    Serial.println("- read from file:");
    while(file.available())
    {
        Serial.write(file.read());
        //delay(2000);
    }

    //*/
    

    while (!ttgo->getTouch(x, y)) {} // Wait for touch to exit
    
  
    while (ttgo->getTouch(x, y)) {}  // Wait for release to return to the clock
    
    ttgo->tft->fillScreen(TFT_BLACK); // Clear screen
}
