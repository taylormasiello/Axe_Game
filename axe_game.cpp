#include "raylib.h"

int main() 
{
    int width{1400};
    int height{800};

    //raylib, creates a popUp text window; InitWindow(int width, int height, title); (of window in pixels)
    InitWindow(width, height, "Taylor's Window");

    while (!WindowShouldClose()) //WindowShouldClose() returns true if X window button clicked or ESC key presed; false otherwise
    {
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

        //SetUp
        BeginDrawing();
        //ClearsCanvas to prevent DoubleBuffer Flickering
        ClearBackground(RED);
        //TearDown
        EndDrawing();
        
    }
}