#include <data.h>

struct Label mainMenuLabel[2] = {
        [0] = {
                .x = 0,
                .y = 0,
                .fontSize = 40,
                .label = "Cosmic Odyssey",
                .color = TEXT_COLOR,
        },
        [1] = {
                .x = 0,
                .y = 0,
                .fontSize = 30,
                .label = "The Thoughts Within",
                .color = TEXT_COLOR,
        },
};

struct Button mainMenuButton[3] = {
        [0] = {
                .x = 20,
                .y = 20,
                .w = 30,
                .h = 30,
                .fontSize = 35,
                .label = "x",
                .color = BUTTON_BG,
                .textColor = TEXT_COLOR,
        },
        [1] = {
                .x = 20,
                .y = 20,
                .w = 100,
                .h = 40,
                .fontSize = 30,
                .label = "Help",
                .color = BUTTON_BG,
                .textColor = TEXT_COLOR,
        },
        [2] = {
                .x = 20,
                .y = 20,
                .w = 120,
                .h = 40,
                .fontSize = 30,
                .label = "Start",
                .color = BUTTON_BG,
                .textColor = TEXT_COLOR,
        },
};

struct Button helpButton[1] = {
        [0] = {
                .x = 20,
                .y = 20,
                .w = 30,
                .h = 30,
                .fontSize = 35,
                .label = "<",
                .color = BUTTON_BG,
                .textColor = (struct Color) {
                        .r = 0xEF,
                        .g = 0xEF,
                        .b = 0xEF,
                        .a = 0xFF,
                },
        },
};
