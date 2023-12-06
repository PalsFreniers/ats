#include <widgets/label.h>

void Label_draw(struct Label label) {
        DrawText(label.label, label.x, label.y, label.fontSize, label.color);
}
