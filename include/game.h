#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <raylib.h>
#include <widgets.h>
#include <data.h>

struct Settings {
        bool fullscreen;
};

enum GameStates {
        STATE_CLOSE = 0,
        STATE_MAIN_MENU,
        STATE_SETTINGS,
        STATE_HELP,
        STATE_START,
};

struct Game {
        // default window settings
        int width;
        int height;
        int fps;
        char *title;

        //game specific settings
        bool open;
        Color bgColor;
        enum GameStates state;
        struct Settings settings;
};

void Game_init(struct Game *game);
void Game_event(struct Game *game);
void Game_update(struct Game *game);
void Game_draw(struct Game game);

#endif // GAME_H
