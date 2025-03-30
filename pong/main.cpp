#include "include/raylib.h"

int player_score = 0;
int cpu_score = 0;

Color Green = GetColor(0x63b31dff);
Color DarkGreen = GetColor(0x202040ff);
Color LightGreen = GetColor(0xa3a324ff);
Color Yellow = GetColor(0xe03c32ff);

class Ball {
public:
  float x, y;
  int speed_x, speed_y;
  int radius;

  void Draw() { DrawCircle(x, y, radius, Yellow); }

  void Update() {
    x += speed_x;
    y += speed_y;
    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
      speed_y *= -1;
    }
    if (x + radius >= GetScreenWidth()) { // CPU wins
      cpu_score++;
      ResetBall();
    }
    if (x - radius <= 0) { // Player wins
      player_score++;
      ResetBall();
    }
  }

  void ResetBall() {
    x = int(GetScreenWidth() / 2);
    y = int(GetScreenHeight() / 2);
    int speed_choices[2] = {-1, 1};
    speed_x *= speed_choices[GetRandomValue(0, 1)];
    speed_y *= speed_choices[GetRandomValue(0, 1)];
  }
};

class Paddle {
protected:
  void LimitMovement() {
    if (y <= 0) {
      y = 0;
    }
    if (y + height >= GetScreenHeight()) {
      y = GetScreenHeight() - height;
    }
  }

public:
  float x, y;
  float width, height;
  int speed;
  void Draw() {
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
  }
  void Update() {
    if (IsKeyDown(KEY_UP)) {
      y = y - speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
      y = y + speed;
    }

    LimitMovement();
  }
};

class CpuPaddle : public Paddle {
public:
  void Update(int ball_y) {
    if (y + height / 2 > ball_y) {
      y = y - speed;
    }
    if (y + height / 2 <= ball_y) {
      y = y + speed;
    }
    LimitMovement();
  }
};

Ball ball;
Paddle player;
CpuPaddle cpu;

int main(void) {
  const int screen_width = 1280;
  const int screen_height = 800;

  InitWindow(screen_width, screen_height, "Pong");
  SetTargetFPS(60);

  ball.radius = 20;
  ball.x = float(screen_width) / 2;
  ball.y = float(screen_height) / 2;
  ball.speed_x = 7;
  ball.speed_y = 7;

  player.width = 25;
  player.height = 120 * 4;
  player.x = screen_width - player.width - 10;
  player.y = float(screen_height) / 2 - player.height / 2;
  player.speed = 9;

  cpu.height = 20;
  cpu.width = 25;
  cpu.x = 10;
  cpu.y = float(screen_height) / 2 - cpu.height / 2;
  cpu.speed = 6;

  while (!WindowShouldClose()) {
    BeginDrawing();

    // UPDATE
    ball.Update();
    player.Update();
    cpu.Update(ball.y);

    // Check collisions
    if (ball.speed_x > 0 &&
        CheckCollisionCircleRec(
            Vector2{ball.x, ball.y}, ball.radius,
            Rectangle{player.x, player.y, player.width, player.height})) {
      ball.speed_x *= -1;
    }

    if (ball.speed_x < 0 &&
        CheckCollisionCircleRec(
            Vector2{ball.x, ball.y}, ball.radius,
            Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})) {
      ball.speed_x *= -1;
    }

    // DRAWING
    ClearBackground(DarkGreen);

    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

    ball.Draw();
    player.Draw();
    cpu.Draw();

    DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80,
             WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
