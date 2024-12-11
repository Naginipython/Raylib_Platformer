#include "main.h"
#include "game.h"
#include "sprites.h"

int main(int argc, char* argv[]) {
  // InitWindow(WORLD_WIDTH*ZOOM, WORLD_HEIGHT*ZOOM, "Celeste Clone");
  InitWindow(150, 150, "Celeste Clone");
  SetTargetFPS(60);
  Color bgColor = {119, 33, 111, 255};
  GameState gameState;

  // camera
  Camera2D camera = { 0 };
  camera.target = { 0, 0 };
  camera.offset = { 0, 0 };
  camera.rotation = 0.0f;
  // camera.zoom = (float)ZOOM;
  camera.zoom = 3.0f;
  
  while (!WindowShouldClose()) {
    gameState.update();
    BeginDrawing();
    ClearBackground(bgColor);

    // BeginMode2D(camera);
      // gameState.draw();
      // DrawText("Celeste Clone", 10, 10, 20, DARKGRAY);
      // for (int i = 0; i < WORLD_WIDTH/TILESIZE -1; i++) {
      //   unsigned char temp = 255-i*5;
      //   DrawRectangle(i*TILESIZE, 0*TILESIZE, TILESIZE, TILESIZE, {temp, 255, 255, 255});
      // }
      // DrawRectangle(5*TILESIZE, 10*TILESIZE, TILESIZE, TILESIZE, {255, 255, 255, 255});

      // DrawCircle(gameState.player.pos.x, gameState.player.pos.y, gameState.player.size, RED);
    // EndMode2D();

    // temp
    // BeginMode2D(camera);
    // int i = 0;
    //   for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //       DrawRectangle(i*10, j*10, 10, 10, {255, 255, 255, 255});
    //     }
    //   }
    // EndMode2D();
    unsigned char step = 255/9;
    int addStep = 0;
    for (int i = 0; i < 150; i = i+50) {
      for (int j = 0; j < 150; j = j+50) {
        unsigned char temp = step*addStep;
        DrawRectangle(j, i, 50, 50, {temp, temp, temp, 255});
        addStep++;
      }
    }

    EndDrawing();
  }
  
  return 0;
}