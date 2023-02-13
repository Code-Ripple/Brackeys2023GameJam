#include "raylib.h"


constexpr auto SCREEN_WIDTH = 1920;
constexpr auto SCREEN_HEIGHT = 1080;

int textureX;
int textureY;
Texture2D texture2D;

int speed = 10;


void SetupFile(int& texture_x, int& texture_y, Texture2D& texture)
{
    texture = LoadTexture(ASSETS_PATH"phoenixPrototype.png");

    texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
    texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
}

void Update()
{

}

void Input()
{
    if(IsKeyDown(KEY_W) && textureY >= 0)
    {
        textureY -= speed;
    }

    if(IsKeyDown(KEY_S) && textureY <= (1080-texture2D.height))
    {
        textureY += speed;

    }
}


int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brackeys2023Game");
    SetTargetFPS(60);


    SetupFile(textureX, textureY, texture2D);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKGRAY);


        DrawTexture(texture2D, textureX, textureY, WHITE);
        Input();


        EndDrawing();
    }

    UnloadTexture(texture2D);

    CloseWindow();
    return 0;
}
