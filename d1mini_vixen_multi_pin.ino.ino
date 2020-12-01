/*
* ESP8266_NeoPixel.ino - Simple sketch to listen for E1.31 data on an ESP8266
*                        and drive WS2811 LEDs using the NeoPixel Library
*
* == Requires Adafruit_NeoPixel - http://github.com/adafruit/Adafruit_NeoPixel                        
*
* Project: E131 - E.131 (sACN) library for Arduino
* Copyright (c) 2015 Shelby Merrick
* http://www.forkineye.com
*
*  This program is provided free for you to use in any way that you wish,
*  subject to the laws and regulations where you are using it.  Due diligence
*  is strongly suggested before using this code.  Please give credit where due.
*
*  The Author makes no warranty of any kind, express or implied, with regard
*  to this program or the documentation contained in this document.  The
*  Author shall not be liable in any event for incidental or consequential
*  damages in connection with, or arising out of, the furnishing, performance
*  or use of these programs.
*
*/

#include <ESP8266WiFi.h>
#include <E131.h>
#include <Adafruit_NeoPixel.h>

#define LOG_PORT        Serial  /* Serial port for console logging */
#define CONNECT_TIMEOUT 30000   /* 30 seconds */

#define NUM_PIXELS_A 162   /* Number of pixels */
#define UNIVERSE_A 1      /* Universe to listen for */
#define CHANNEL_START_A 1 /* Channel to start listening at */
#define DATA_PIN_A D4      /* Pixel output - GPIO2 / nodeMCU D4 */

#define NUM_PIXELS_B 168  /* Number of pixels */
#define UNIVERSE_B 2      /* Universe to listen for */
#define CHANNEL_START_B 1 /* Channel to start listening at */
#define DATA_PIN_B D3      /* Pixel output - GPIO1 / nodeMCU D3 */
/*
#define NUM_PIXELS_C 84  /* Number of pixels 
#define UNIVERSE_C 2      /* Universe to listen for 
#define CHANNEL_START_C 1 /* Channel to start listening at 
#define DATA_PIN_C D2      /* Pixel output - GPIO4 / nodeMCU D2 

#define NUM_PIXELS_D 84  /* Number of pixels 
#define UNIVERSE_D 2      /* Universe to listen for 
#define CHANNEL_START_D 252 /* Channel to start listening at 
#define DATA_PIN_D D1      /* Pixel output - GPIO5 / nodeMCU D1 */

const char ssid[] = "ledEsp";         /* Replace with your SSID */
const char passphrase[] = "30051995";   /* Replace with your WPA2 passphrase */

E131 e131;

Adafruit_NeoPixel pixels_a = Adafruit_NeoPixel(NUM_PIXELS_A, DATA_PIN_A, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel pixels_b = Adafruit_NeoPixel(NUM_PIXELS_B, DATA_PIN_B, NEO_RGB + NEO_KHZ800);
/*
Adafruit_NeoPixel pixels_c = Adafruit_NeoPixel(NUM_PIXELS_C, DATA_PIN_C, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel pixels_d = Adafruit_NeoPixel(NUM_PIXELS_D, DATA_PIN_D, NEO_RGB + NEO_KHZ800);*/

int initWifi() {
    /* Switch to station mode and disconnect just in case */
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(secureRandom(100,500));

    LOG_PORT.println("");
    LOG_PORT.print(F("Connecting to "));
    LOG_PORT.println(ssid);

    WiFi.begin(ssid, passphrase);

    uint32_t timeout = millis();
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        LOG_PORT.print(".");
        if (millis() - timeout > CONNECT_TIMEOUT) {
            LOG_PORT.println("");
            LOG_PORT.println(F("*** Failed to connect ***"));
            break;
        }
    }

    if (WiFi.status() == WL_CONNECTED) {
        LOG_PORT.println("");
        LOG_PORT.print(F("Connected with IP: "));
        LOG_PORT.println(WiFi.localIP());

        e131.begin(E131_MULTICAST, UNIVERSE_A, 2);
    }

    return WiFi.status();
}

void setup() {
    LOG_PORT.begin(115200);
    delay(10);


      
    /* Choose one to begin listening for E1.31 data */
    e131.begin(ssid, passphrase);                       /* via Unicast on the default port */
    //e131_a.beginMulticast(ssid, passphrase, UNIVERSE_A);  /* via Multicast for Universe 1 */
    initWifi();

    /* Initialize output */
    pixels_a.begin();
    pixels_a.show();
    pixels_b.begin();
    pixels_b.show();
    /*
    pixels_c.begin();
    pixels_c.show();
    pixels_d.begin();
    pixels_d.show();*/
}

void loop() {
    /* Parse a packet and update pixels */
    if(e131.parsePacket())
    {
        if (e131.universe == UNIVERSE_A) {
            for (int i = 0; i < NUM_PIXELS_A; i++) {
                int j = i * 3 + (CHANNEL_START_A - 1);
                pixels_a.setPixelColor(i, e131.data[j], e131.data[j+1], e131.data[j+2]);
            }
            pixels_a.show();
        }
        if (e131.universe == UNIVERSE_B) {
            for (int i = 0; i < NUM_PIXELS_B; i++) {
                int j = i * 3 + (CHANNEL_START_B - 1);
                pixels_b.setPixelColor(i, e131.data[j], e131.data[j+1], e131.data[j+2]);
            }
            pixels_b.show();
        }
        /*
         if (e131.universe == UNIVERSE_C) {
            for (int i = 0; i < NUM_PIXELS_C; i++) {
                int j = i * 3 + (CHANNEL_START_C - 1);
                pixels_c.setPixelColor(i, e131.data[j], e131.data[j+1], e131.data[j+2]);
            }
            pixels_c.show();
        }
         if (e131.universe == UNIVERSE_D) {
            for (int i = 0; i < NUM_PIXELS_D; i++) {
                int j = i * 3 + (CHANNEL_START_D - 1);
                pixels_d.setPixelColor(i, e131.data[j], e131.data[j+1], e131.data[j+2]);
            }
            pixels_d.show();
        }
       */ 
    }
}
