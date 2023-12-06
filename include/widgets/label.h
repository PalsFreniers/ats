#ifndef LABEL_H
#define LABEL_H

#include <raylib.h>

#define TEXT_COLOR ((struct Color) {0xEF, 0xEF, 0xEF, 0xFF})

struct Label {
        int x, y;
        int fontSize;
        char *label;
        struct Color color;
};

void Label_draw(struct Label label);

#endif // LABEL_H
