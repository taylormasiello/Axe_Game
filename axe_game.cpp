#include "raylib.h"

int main() 
{
    //window dimensions
    int width{1400};
    int height{800};

    //raylib, creates a popUp text window; InitWindow(int width, int height, title); (of window in pixels)
    InitWindow(width, height, "Axe_Game");

    //circle coordinates & radius
    int circle_x{700};
    int circle_y{400};
    int cirlce_rad{125};

    SetTargetFPS(60); //sets target val for num times window will update per sec; from raylib

    while (!WindowShouldClose()) //WindowShouldClose() returns true if X window button clicked or ESC key presed; false otherwise
    {
        //SetUp
        BeginDrawing();
        //ClearsCanvas to prevent DoubleBuffer Flickering
        ClearBackground(PURPLE);

        //Game Logic begins

        //DrawCircle(int centerX, int centerY, int radius, COLOR); raylib window top left is (0,0)
        DrawCircle(circle_x, circle_y, cirlce_rad, GREEN); //drawn to center of window

        //IsKeyDown & input macros from raylib
        if (IsKeyDown(KEY_D) && circle_x < 1400)
        {
            circle_x+=50;
        }

        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x-=50;
        }

        if (IsKeyDown(KEY_W) && circle_y > 0) //y axis in raylib window inverted
        {
            circle_y-=50;
        }

        if (IsKeyDown(KEY_S) && circle_y < 800)
        {
            circle_y+=50;
        }

        //Game Logic ends

        //TearDown
        EndDrawing();
    }
}



/*
Double Buffering: Image constantly updated many times per second (really just a bunch of still images updating rapidly)
each time raylib shows 1 image, is constructing next image behind the scenes, pixel by pixel
raylib shows current image while it's constructing next one, to avoiding showing construction of image 1 pixel at a time
*image under construction behind the scense is called a "frame buffer"
once new image is ready, raylib switches the old w/ the new, then starts creating next frame buffer behind the scenes
if background is not cleared, raylib will switch between it's default (WHITE) canvas, and its empty frame buffer (which is BLACK)
switching between these 2 causes rapid flashing many times per second, which can lead to seizures  
if ClearBackground() is called each time image is updated, this causes the canvas to be "washed" with the color passed in 
*/