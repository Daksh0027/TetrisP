#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>
#include <fstream> // I/O

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    // Draw Window
    InitWindow(550, 650, "raylib Tetris");
    //Style
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    // Read High Score
    int highScore = 0;
    std::ifstream infile("highscore.txt");
    if (infile.is_open()) {
        infile >> highScore;
        infile.close();
    }

    bool isMuted = false; // mute button
    Rectangle muteBtn = {320, 410, 170, 40};

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();

        // button logic
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse = GetMousePosition();
            if (CheckCollisionPointRec(mouse, muteBtn)) {
                isMuted = !isMuted;
                SetMusicVolume(game.music, isMuted ? 0.0f : 1.0f);
            }
        }

        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground({0, 0, 0, 255});
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, teal);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, teal);

        // Sound Button
        DrawRectangleRounded(muteBtn, 0.3, 6, DARKGRAY);
        const char* muteText = isMuted ? "Unmute" : "Mute";
        Vector2 muteTextSize = MeasureTextEx(font, muteText, 28, 2);
        DrawTextEx(font, muteText, 
            {muteBtn.x + (muteBtn.width - muteTextSize.x) / 2, muteBtn.y + (muteBtn.height - muteTextSize.y) / 2}, 
            28, 2, WHITE);

        // High Score Display
        char highScoreText[32];
        sprintf(highScoreText, "High Score: %d", highScore);
        Vector2 hsTextSize = MeasureTextEx(font, highScoreText, 28, 2);
        DrawTextEx(font, highScoreText, 
            {muteBtn.x + (muteBtn.width - hsTextSize.x) / 2 + 30, muteBtn.y + muteBtn.height + 10}, 
            28, 2, YELLOW);

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}