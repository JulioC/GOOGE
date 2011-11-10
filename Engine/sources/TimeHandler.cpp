#include "TimeHandler.h"

TimeHandler::TimeHandler():
_lastTick(0),
_elapsed(0),
_frameCount(0),
_fps(0) {
    _lastTick = SDL_GetTicks();
}

TimeHandler::~TimeHandler() {
}

void TimeHandler::update() {
    int now = SDL_GetTicks();
    _elapsed = _lastTick - now;
    _lastTick = now;
}

int TimeHandler::fps() const {
    return _fps;
}

int TimeHandler::elapsed() const {
    return _elapsed;
}







