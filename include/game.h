#pragma once
#include <raylib.h>
#include <vector>

class Player {
 public:
  Vector2 pos;
  float size;
};

class GameState {
  std::vector<int> tiles;
  Texture2D tileset;

  void autotile();
 public:
  Player player;

  GameState();
  ~GameState();
  void update();
  void draw();
};