#include "Tile.h"

Tile::Tile(Game* game, const Vector& position):
Sprite(game, "./assets/images/tiles.png", position, Vector(48, 48)){
}

Tile::~Tile() {
}
