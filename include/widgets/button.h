#ifndef BUTTON_H
#define BUTTON_H

#include <stdbool.h>
#include <raylib.h>

#define BUTTON_BG ((struct Color) {0x50, 0x50, 0x50, 0xFF})
#define BUTTON_HOVER_BG ((struct Color) {0x60, 0x60, 0x60, 0xFF})

typedef void (*onClickEvent)(void *);

struct Button {
        int x, y;
        int w, h;
        int fontSize;
        char *label;
        struct Color color;
        struct Color textColor;
        onClickEvent onClick;
        void *data;
};

void Button_draw(struct Button button);
void Button_update(struct Button *button);
bool Button_isMouseHover(struct Button button);
bool Button_isClicked(struct Button button);

#endif // BUTTON_H
