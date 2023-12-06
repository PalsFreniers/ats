#include <game.h>

struct Game game = {
                .width = 600,
                .height = 400,
                .title = "Cosmic Odyssey: The Thought Within",
                .fps = 60,

                .open = true,
                .state = STATE_MAIN_MENU,
                .bgColor = (struct Color) {
                        .r = 0x30,
                        .g = 0x30,
                        .b = 0x30,
                        .a = 0xFF,
                },
                .settings = (struct Settings) {
                        .fullscreen = false,
                },
};

int main() {
        InitWindow(game.width, game.height, game.title);
        SetTargetFPS(game.fps);
        Game_init(&game);
        while(game.open) {
                Game_event(&game);
                Game_update(&game);
                BeginDrawing();
                Game_draw(game);
                EndDrawing();
        }
        CloseWindow();
        return 0;
}
