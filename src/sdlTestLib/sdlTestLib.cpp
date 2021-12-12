#include<sdlTestLib/sdlTestLib.h>


void speak(){
    cout<<"ello motherfucker"<<endl;
};

void stay(){
   cout<<"Press any key to continue";
   getchar();
}

// void glfwTest(){
//     if (!glfwInit()){
//         cout<<"GLFW initialization is sucked"<<endl;
//     }else{
//         cout<<"GLFW initialization is not sucked"<<endl;
//     }
// }


void sdlTest(){
    SDL_Window *window;                   // Declare a pointer

    //Initialize all the systems of SDL
    // SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    //Create a window with a title, "Getting Started", in the centre
    //(or undefined x and y positions), with dimensions of 800 px width
    //and 600 px height and force it to be shown on screen
    window = SDL_CreateWindow(
        "Getting Started",          // window title
        SDL_WINDOWPOS_UNDEFINED,    // initial x position
        SDL_WINDOWPOS_UNDEFINED,    // initial y position
        800,                        // width, in pixels
        600,                        // height, in pixels
        SDL_WINDOW_SHOWN            // flags
        );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
    }

    //Create a renderer for the window created above, with the first display driver present
    //and with no additional settings
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    //Set the draw color of renderer to green
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    //Clear the renderer with the draw color
    SDL_RenderClear(renderer);

    //Update the renderer which will show the renderer cleared by the draw color which is green
    SDL_RenderPresent(renderer);

    // //Pause for 3 seconds (or 3000 milliseconds)
    // SDL_Delay(3000);

    bool isquit = false;
    SDL_Event event;
    while (!isquit) {
        if (SDL_PollEvent( & event)) {
            if (event.type == SDL_QUIT) {
                isquit = true;
            }
        }
    }
    
    //Destroy the renderer created above
    SDL_DestroyRenderer(renderer);

    //Destroy the window created above
    SDL_DestroyWindow(window);

    //Close all the systems of SDL initialized at the top
    SDL_Quit();

}




