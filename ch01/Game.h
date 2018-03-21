#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game
{
public:
    bool Initialize();

    void RunLoop();

    void Shutdown();

private:
    void ProcessInput();

    void UpdateGame();

    void GenerateOutput();

    bool IsRunning_{true};

    SDL_Renderer* Renderer_{nullptr};

    SDL_Window* Window_{nullptr};
};

#endif
