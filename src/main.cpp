#include <SDL2/SDL.h>
#include <SDL_events.h>

#define WIDTH 1200
#define HEIGHT 600

static void quit(void);

static int running = 1;
static int state;


void quit()
{
    running = 0;
}

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Surface* surface = SDL_GetWindowSurface(window);
    SDL_Event event;

    while(running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit();
            }
            if (event.type == SDL_KEYDOWN)
            {
                SDL_Keycode key = event.key.keysym.sym;

                if (key == SDLK_q)
                {
                    running = 0;
                }
            }
        }

        SDL_UpdateWindowSurface(window);
        // WIPE SCREEN
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
        // in ms
        SDL_Delay(100);
    }
}
