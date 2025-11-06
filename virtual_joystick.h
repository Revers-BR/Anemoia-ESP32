#ifndef VIRTUAL_JOYSTICK_H
#define VIRTUAL_JOYSTICK_H

#include <TFT_eSPI.h>
#include <XPT2046_Bitbang.h>

class VirtualJoystick {
public:
    struct TouchButton {
        int x, y, w, h;
        const char* label;
    };

    VirtualJoystick(TFT_eSPI* screen, TFT_eSprite* sprite, XPT2046_Bitbang* touchscreen);

    void begin();                // Inicializa e desenha os botões
    void drawButtons();          // Desenha os botões na tela
    const char* getButton();     // Retorna o label do botão tocado (ou "" se nenhum)

private:
    TFT_eSPI* screen;
    TFT_eSprite* sprite;
    XPT2046_Bitbang* touchscreen;

    static constexpr int BUTTON_COUNT = 8;
    TouchButton buttons[BUTTON_COUNT];
};

#endif
