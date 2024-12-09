#include "main.h"
#include "game.h"
#include "sprites.h"

int main(int argc, char* argv[]) {
  InitWindow(WORLD_WIDTH*ZOOM, WORLD_HEIGHT*ZOOM, "Celeste Clone");
  SetTargetFPS(60);
  Color bgColor = {119, 33, 111, 255};
  GameState gameState;

  // camera
  Camera2D camera = { 0 };
  camera.target = { 0, 0 };
  camera.offset = { 0, 0 };
  camera.rotation = 0.0f;
  camera.zoom = (float)ZOOM;
  
  while (!WindowShouldClose()) {
    gameState.update();
    BeginDrawing();
    ClearBackground(bgColor);

    BeginMode2D(camera);
      gameState.draw();
      // DrawText("Celeste Clone", 10, 10, 20, DARKGRAY);
      // for (int i = 0; i < WORLD_WIDTH/TILESIZE -1; i++) {
      //   unsigned char temp = 255-i*5;
      //   DrawRectangle(i*TILESIZE, 0*TILESIZE, TILESIZE, TILESIZE, {temp, 255, 255, 255});
      // }
      // DrawRectangle(5*TILESIZE, 10*TILESIZE, TILESIZE, TILESIZE, {255, 255, 255, 255});

      // DrawCircle(gameState.player.pos.x, gameState.player.pos.y, gameState.player.size, RED);
    EndMode2D();
    EndDrawing();
  }
  
  return 0;
}