#include "game.h"
#include "main.h"
#include "sprites.h"
#include <math.h>

GameState::GameState() {
  player.pos = {(float)WORLD_WIDTH/2-4, (float)WORLD_HEIGHT/2-4};
  player.size = 8;
  tiles = std::vector<int>(WORLD_WIDTH*WORLD_HEIGHT, -1);
  tileset = LoadTexture("resources/TILESET.png");
}
GameState::~GameState() {
  UnloadTexture(tileset);
}

Vector2 screen_to_tile(float x, float y) {
  float x2 = std::floor(x/ZOOM/TILESIZE);
  float y2 = std::floor(y/ZOOM/TILESIZE);
  return {x2, y2};
}

void GameState::update() {
  if (IsKeyDown(KEY_W)) player.pos.y -= 1; 
  if (IsKeyDown(KEY_S)) player.pos.y += 1;
  if (IsKeyDown(KEY_A)) player.pos.x -= 1;
  if (IsKeyDown(KEY_D)) player.pos.x += 1;
  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePosition = GetMousePosition();
    println("Coords: (" << mousePosition.x << ", " << mousePosition.y << ")");
    Vector2 tile = screen_to_tile(mousePosition.x, mousePosition.y);
    println("Tile: (" << tile.x << ", " << tile.y << ")");
    tiles[tile.x + tile.y*WORLD_WIDTH] = 0;
    autotile();
  }
  if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
    Vector2 mousePosition = GetMousePosition();
    Vector2 tile = screen_to_tile(mousePosition.x, mousePosition.y);
    tiles[tile.x + tile.y*WORLD_WIDTH] = -1;
    autotile();
  }
}

void GameState::draw() {
  for (int i = 0; i < WORLD_WIDTH; i++) {
    for (int j = 0; j < WORLD_HEIGHT; j++) {
      if (tiles[i + j*WORLD_WIDTH] > -1) {
        int tileVal = SpriteID::TILE0 + tiles[i + j*WORLD_WIDTH];
        Sprite sprite = get_sprite((SpriteID)tileVal);
        DrawTextureRec(tileset, sprite.rect, {(float)i*TILESIZE, (float)j*TILESIZE}, WHITE);
      }
    }
  }
  DrawCircle(player.pos.x, player.pos.y, player.size, RED);
}

void GameState::autotile() {
  // https://code.tutsplus.com/how-to-use-tile-bitmasking-to-auto-tile-your-level-layouts--cms-25673t
  // Check top, left, right, and bottom, and decide on the tile based on those
  for (int y = 0; y < WORLD_HEIGHT/TILESIZE; y++) {
    for (int x = 0; x < WORLD_WIDTH/TILESIZE; x++) {
      if (tiles[x + y*WORLD_WIDTH] == -1) continue;
      int tileVal = 0;
      if (y != 0 && y != WORLD_HEIGHT/TILESIZE) {
        if (tiles[x + (y-1)*WORLD_WIDTH] > -1) {
          tileVal += 1; // TOP
        }
        if (tiles[x + (y+1)*WORLD_WIDTH] > -1) {
          tileVal += 8; // BOTTOM
        }
      }
      if (x != 0 && x != WORLD_WIDTH/TILESIZE) {
        if (tiles[(x-1) + y*WORLD_WIDTH] > -1) {
          tileVal += 2; // LEFT
        }
        if (tiles[(x+1) + y*WORLD_WIDTH] > -1) {
          tileVal += 4; // RIGHT
        }
      }
      tiles[x + y*WORLD_WIDTH] = tileVal;
    }
  }
}