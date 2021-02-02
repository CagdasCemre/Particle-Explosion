#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace fundamentals;

int main( int argc, char * argv[] )
{
    srand(time(NULL));

    Screen screen;

    if(screen.init() == false){
        cout << "Error initializing SDL." << endl;
    }

    Swarm swarm;

    const int dim = Screen::SCREEN_WIDTH/2;
    const int dimHeight = Screen::SCREEN_HEIGHT/2;
    while(true)
    {

        // update particles
        // Draw particles
        int elapsed = SDL_GetTicks();
        Uint8 red = (1 + cos(elapsed * 0.002)) * 128;
        Uint8 blue = (1 + sin(elapsed * 0.003)) * 128;
        Uint8 green = (1 + cos(elapsed * 0.001)) * 128;

        /*
        for(int y = 0 ; y < Screen::SCREEN_HEIGHT ; y++){
            for(int x = 0 ; x < Screen::SCREEN_WIDH ; x++){
             screen.setPixel(x, y, red, green, blue);
            }

        }
        */

        const Particle * const pParticles = swarm.getParticles();

        for(int i = 0 ; i < Swarm::NPARTICLES ; i++){
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * (dim);
            int y = particle.m_y  * dim + dimHeight;

            screen.setPixel(x, y, red, green, blue);
        }

        swarm.update(elapsed);
        screen.boxBlur();
        // Draw the screen
        screen.update();
        // Check for messages/events
        if(!screen.processEvents()){
            break;
        }

    }

    screen.close();
    return 0;
}
