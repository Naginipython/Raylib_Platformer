#pragma once
#include <raylib.h>
#include "main.h"

enum SpriteID {
  PLAYER,
  TILE0, // No open edges
  TILE1, // Open top edge
  TILE2, // Open left edge
  TILE3, // Open top left edge
  TILE4, // Open right edge
  TILE5, // Open top right edge
  TILE6, // Open left right edge
  TILE7, // Open top left right edge
  TILE8, // Open bottom edge
  TILE9, // Open top bottom edge
  TILE10, // Open left bottom edge
  TILE11, // Open top left bottom edge
  TILE12, // Open right bottom edge
  TILE13, // Open top right bottom edge
  TILE14, // Open left right bottom edge
  TILE15, // Open top left right bottom edge
  TILE
};

class Sprite {
 public:
  Vector2 tilesetOffset;
  Vector2 tilesetSize;
  Vector2 position;
  Rectangle rect;
};

inline Sprite get_sprite(SpriteID id) {
  Sprite sprite{};
  if (id >= TILE0 && id <= TILE15) {
    sprite.tilesetOffset = {
      (float)(48+((id-1)%4*8)), 
      (float)((id-1)/4*8)
    };
    sprite.tilesetSize = {8, 8};
    sprite.rect = {sprite.tilesetOffset.x, sprite.tilesetOffset.y, 8, 8};
  }

  return sprite;
}