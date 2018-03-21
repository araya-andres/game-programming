#include "Game.h"

#include <iostream>

bool Game::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Unable to initialize SDL: " << SDL_GetError();
        return false;
    }
    Window_ = SDL_CreateWindow(
            "Title",
            100, 100,
            1024, 768,
            0
            );
    if (!Window_) {
        std::cerr << "Failed to create window: " << SDL_GetError();
        return false;
    }
    Renderer_ = SDL_CreateRenderer(
            Window_,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
            );
    if (!Renderer_) {
        std::cerr << "Failed to create renderer: " << SDL_GetError();
        return false;
    }
    return true;
}

void Game::RunLoop() {
    while (IsRunning_) {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::Shutdown() {
    SDL_DestroyWindow(Window_);
    SDL_Quit();
}

void Game::ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                IsRunning_ = false;
                break;
        }
    }

    auto state = SDL_GetKeyboardState(nullptr);
    if (state[SDL_SCANCODE_ESCAPE]) {
        IsRunning_ = false;
    }
}

void Game::UpdateGame() {}

void Game::GenerateOutput() {}
