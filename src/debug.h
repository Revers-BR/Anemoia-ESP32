#ifndef DEBUG_H
#define DEBUG_H

#include "../config.h"
#include <Arduino.h>

#ifdef DEBUG
  #define LOG(msg)        Serial.println(msg)
  #define LOGF(fmt, ...)  Serial.printf(fmt, __VA_ARGS__)
#else
  #define LOG(msg)
  #define LOGF(fmt, ...)
#endif

#endif