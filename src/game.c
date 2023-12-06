#include <game.h>



void buttonReturnFunc(enum GameStates *state) {
        *state = STATE_MAIN_MENU;
}

void buttonCloseFunc(enum GameStates *state) {
        *state = STATE_CLOSE;
}

void buttonHelpFunc(enum GameStates *state) {
        *state = STATE_HELP;
}

void buttonStartFunc(enum GameStates *state) {
        *state = STATE_START;
}

void drawWIPScreen() {
        DrawText("WIP not implemented!", 0, 0, 20, RED);
}

void Game_init(struct Game *game) {
        helpButton[0].onClick = (onClickEvent)buttonReturnFunc;
        helpButton[0].data = &(game->state);

        mainMenuButton[0].onClick = (onClickEvent)buttonCloseFunc;
        mainMenuButton[0].data = &(game->state);

        mainMenuButton[1].x = game->width / 2 - (mainMenuButton[1].w / 2);
        mainMenuButton[1].y = game->height / 2 - (mainMenuButton[1].h / 2);
        mainMenuButton[1].onClick = (onClickEvent)buttonHelpFunc;
        mainMenuButton[1].data = &(game->state);

        mainMenuButton[2].x = game->width / 2 - (mainMenuButton[2].w / 2);
        mainMenuButton[2].y = game->height / 2 - (mainMenuButton[2].h / 2) - mainMenuButton[2].h - 10;
        mainMenuButton[2].onClick = (onClickEvent)buttonStartFunc;
        mainMenuButton[2].data = &(game->state);

        struct Vector2 textSize = MeasureTextEx(GetFontDefault(), mainMenuLabel[0].label, mainMenuLabel[0].fontSize, 1.0f);
        mainMenuLabel[0].x = game->width / 2 - (textSize.x / 2);
        mainMenuLabel[0].y = game->height / 2 - (textSize.y / 2) - (game->height / 2 - 30);

        struct Vector2 text2Size = MeasureTextEx(GetFontDefault(), mainMenuLabel[1].label, mainMenuLabel[1].fontSize, 1.0f);
        mainMenuLabel[1].x = game->width / 2 - (text2Size.x / 2);
        mainMenuLabel[1].y = game->height / 2 - (text2Size.y / 2) - (game->height / 2 - textSize.y - 30);
}

void Game_event(struct Game *game) {
        if(WindowShouldClose()) game->open = false;
}

void Game_update(struct Game *game) {
        switch(game->state) {
                case STATE_CLOSE:
                        game->open = false;
                        break;
                case STATE_MAIN_MENU:
                        Button_update(&(mainMenuButton[0]));
                        Button_update(&(mainMenuButton[1]));
                        Button_update(&(mainMenuButton[2]));
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
                case STATE_MAIN_MENU:
                        Label_draw(mainMenuLabel[0]);
                        Label_draw(mainMenuLabel[1]);
                        Button_draw(mainMenuButton[0]);
                        Button_draw(mainMenuButton[1]);
                        Button_draw(mainMenuButton[2]);
                        break;
                case STATE_HELP:
                        Button_draw(helpButton[0]);
                        break;
                case STATE_CLOSE:
                        break;
                default:
                        drawWIPScreen();
                        break;
        }
}
