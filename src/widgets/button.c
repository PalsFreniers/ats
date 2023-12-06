#include <widgets/button.h>

void Button_draw(struct Button button) {
        struct Rectangle r = (struct Rectangle) {
                .x = button.x,
                .y = button.y,
                .width = button.w,
                .height = button.h, 
        };
        DrawRectangleRounded(r, 50.0f, 100, button.color);
        struct Vector2 textSize = MeasureTextEx(GetFontDefault(), button.label, button.fontSize, 1.0f);
        struct Vector2 textPos = {
                .x = button.x + (button.w / 2) - (textSize.x / 2),
                .y = button.y + (button.h / 2) - (textSize.y / 2),
        };
        DrawText(button.label, textPos.x, textPos.y, button.fontSize, button.textColor);
}

bool Button_isMouseHover(struct Button button) {
        int mx = GetMouseX();
        int my = GetMouseY();
        return ((mx >= button.x && mx <= button.x + button.w) && (my >= button.y && my <= button.y + button.h));
}

bool Button_isClicked(struct Button button) {
        bool mc = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        return (mc && Button_isMouseHover(button));
}

void Button_update(struct Button *button) {
        if(Button_isMouseHover(*button)) button->color = BUTTON_HOVER_BG;
        else button->color = BUTTON_BG;
        if(Button_isClicked(*button)) button->onClick(button->data);
}
