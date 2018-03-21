#include "Game.h"

int main() {
    Game g;
    auto success = g.Initialize();
    if (success) {
        g.RunLoop();
    }
    g.Shutdown();
}
