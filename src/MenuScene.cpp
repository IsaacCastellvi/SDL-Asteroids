#include "MenuScene.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "game.h"

void MenuScene::Update(float delta) {
    if (IM.GetKey(SDLK_RETURN, DOWN) || IM.GetKey(SDLK_KP_ENTER, DOWN)) {
        SCENES.TransitionScene(SceneIndex::GAME_SCENE);
    }
}
void MenuScene::Start(){

    titleFont = TTF_OpenFont("assets/CreatoDisplay-Regular.otf", 72);
    subFont   = TTF_OpenFont("assets/CreatoDisplay-Regular.otf", 24);

    if (!titleFont || !subFont)
        SDL_Log("Font error: %s", TTF_GetError());
}

//use claude to debug most of it 
void MenuScene::RenderText(const char* text, TTF_Font* font, SDL_Color color, int y) {
    if (!font) return;

    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(GAME.GetRenderer(), surface);
    if (!texture) { SDL_FreeSurface(surface); return; }

    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    SDL_Rect dst = { (GAME.GetWidth() - w) / 2, y, w, h };

    SDL_RenderCopy(GAME.GetRenderer(), texture, nullptr, &dst);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void MenuScene::Render() {
    SDL_Color white  = { 255, 255, 255, 255 };
    SDL_Color yellow = { 255, 220,   0, 255 };

    RenderText("ASTEROIDS", titleFont, yellow, 350);
    RenderText("Press ENTER to play", subFont,  white,  460);
}

void MenuScene::Clear() {
    if (titleFont) TTF_CloseFont(titleFont);
    if (subFont)   TTF_CloseFont(subFont);
    titleFont = nullptr;
    subFont   = nullptr;
}