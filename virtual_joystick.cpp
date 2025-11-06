#include "virtual_joystick.h"

VirtualJoystick::VirtualJoystick(TFT_eSPI* screen, TFT_eSprite* sprite, XPT2046_Bitbang* touchscreen)
    : screen(screen), sprite(sprite), touchscreen(touchscreen)
{
    // Layout dos botões
    buttons[0] = {40, 25 , 30, 30, "^"};
    buttons[1] = {40, 55 , 30, 30, "v"};
    buttons[2] = {10, 40 , 30, 30, "<"};
    buttons[3] = {70, 40 , 30, 30, ">"};
    buttons[4] = {120, 40 , 50, 30, "SELECT"};
    buttons[5] = {190, 40 , 50, 30, "START"};
    buttons[6] = {270, 25 , 30, 30, "A"};
    buttons[7] = {270, 55 , 30, 30, "B"};
}

void VirtualJoystick::begin() {
  touchscreen->begin();

  sprite->createSprite(screen->width(), 95);

  sprite->fillSprite(TFT_TRANSPARENT);
  
  for (int i = 0; i < BUTTON_COUNT; i++) {
      TouchButton &b = buttons[i];
      sprite->drawRect(b.x, b.y, b.w, b.h, TFT_WHITE);
      sprite->setTextColor(TFT_WHITE);
      sprite->drawCentreString(b.label, b.x + b.w / 2, b.y + (b.h / 2) - 6, 2);
  }
}

void VirtualJoystick::drawButtons() {
    sprite->pushSprite(0, screen->height() - 95,TFT_TRANSPARENT);
}

const char* VirtualJoystick::getButton() {
    TouchPoint touch = touchscreen->getTouch();

    if (touch.zRaw != 0) {
        for (int i = 0; i < BUTTON_COUNT; i++) {
            TouchButton &b = buttons[i];
            if (touch.x > b.x && touch.x < b.x + b.w &&
                touch.y > (screen->height() - 95) + b.y &&
                touch.y < (screen->height() - 95) + b.y + b.h)
            {
                return b.label;
            }
        }
    }

    return "";
}
