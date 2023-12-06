#include <game.h>
#include <macros.h>

struct Button {
        int x, y;
        int w, h;
        char *label;
        struct Color color;
        void (*onClick)(struct );
};

struct Color buttonBg = (struct Color) {
        .r = 0x50,
        .g = 0x50,
        .b = 0x50,
        .a = 0xFF,
};

struct Color buttonHoverBg = (struct Color) {
        .r = 0xF0,
        .g = 0xF0,
        .b = 0xF0,
        .a = 0xFF,
};

struct Button helpButton[1] = {
        [0] = (struct Button) {
                .x = 20,
                .y = 20,
                .w = 50,
                .h = 50,
                .label = "X",
                .color = (struct Color) {
                        .r = 0x50,
                        .g = 0x50,
                        .b = 0x50,
                        .a = 0xFF,
                },
        },
};

void Button_draw(struct Button button) {
        struct Rectangle r = (struct Rectangle) {
                .x = button.x,
                        .y = button.y,
                        .width = button.w,
                        .height = button.h, 
        };
        DrawRectangleRec(r, button.color);
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
        if(Button_isMouseHover(*button)) button->color = buttonHoverBg;
        else button->color = buttonBg;
        if(Button_isClicked(*button)) button->onClick();
}

void drawWIPScreen() {
        DrawText("WIP not implemented!", 0, 0, 20, RED);
}

void Game_event(struct Game *game) {
        if(IsKeyDown(KEY_ESCAPE)) game->open = false;
}

void Game_update(struct Game *game) {
        switch(game->state) {
                case STATE_CLOSE:
                        game->open = false;
                        break;
                case STATE_HELP:
                        Button_update(&(helpButton[0]));
                        break;
                default:
                        break;
        }
}

void Game_draw(struct Game game) {
        ClearBackground(game.bgColor);
        switch(game.state) {
                default:
                        drawWIPScreen();
                        break;
        }
}
