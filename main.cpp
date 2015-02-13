#include <iostream>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <time.h>

#include <unistd.h>
#include <time.h>

#include "Glaw/glaw.hpp"

using namespace std;

#define MULTISAMPLING true

void getTime(int &hour, int &minute, int &second);

int main()
{
	/* Variables */

    int i;
    float vitesseRotation = 2;

	bool run = true; // The main loop runs as long as it is true
	SDL_Surface *window; // Opened window
	
	Input input; // Contains all booleans of the SDL events
	memset(&input, 0, sizeof(input)); // Set all the events to false

    int heures, minutes, secondes;
    getTime(heures, minutes, secondes);
    cout << heures << ":" << minutes << ":" << secondes << endl;

    Vector center(50, 50);

    /* Objets */

    Color   white(255, 255, 255, 255),
            lightGray(230, 230, 230, 230),
            gray(200, 200, 200, 200),
            black(0, 0, 0, 0);

    Object cercle(Vector(10, 10), Vector(80, 80));

    float rayon = 50;
    int nbTriangles = 120;
    Vector pos(50, 50);

    for (i = 0; i < nbTriangles; ++i)
    {
        cercle.create(
            Triangle(
                pos,
                Vector(
                    cos(((360 / (float)nbTriangles) * M_PI / 180.0) * i) * rayon,
                    sin(((360 / (float)nbTriangles) * M_PI / 180.0) * i) * rayon
                ) + pos,
                Vector(
                    cos(((360 / (float)nbTriangles) * M_PI / 180.0) * (i + 1)) * rayon,
                    sin(((360 / (float)nbTriangles) * M_PI / 180.0) * (i + 1)) * rayon
                ) + pos,
                lightGray
            )
        );
    }

    rayon = 48;

    for (i = 0; i < nbTriangles; ++i)
    {
        cercle.create(
            Triangle(
                pos,
                Vector(
                    cos(((360 / (float)nbTriangles) * M_PI / 180.0) * i) * rayon,
                    sin(((360 / (float)nbTriangles) * M_PI / 180.0) * i) * rayon
                ) + pos,
                Vector(
                    cos(((360 / (float)nbTriangles) * M_PI / 180.0) * (i + 1)) * rayon,
                    sin(((360 / (float)nbTriangles) * M_PI / 180.0) * (i + 1)) * rayon
                ) + pos,
                black
            )
        );
    }

    Object cercleMilieu(Vector(48, 48), Vector(4, 4));

    rayon = 50;
    nbTriangles = 30;

    for (i = 0; i < nbTriangles; ++i)
    {
        cercleMilieu.create(
            Triangle(
                pos,
                Vector(
                    cos(((360 / (float)nbTriangles) * M_PI / 180.0) * i) * rayon,
                    sin(((360 / (float)nbTriangles) * M_PI / 180.0) * i) * rayon
                ) + pos,
                Vector(
                    cos(((360 / (float)nbTriangles) * M_PI / 180.0) * (i + 1)) * rayon,
                    sin(((360 / (float)nbTriangles) * M_PI / 180.0) * (i + 1)) * rayon
                ) + pos,
                lightGray
            )
        );
    }

    // Heures

    Object aiguilleHeures(Vector(25, 25), center);

    aiguilleHeures.create(
        Triangle(
            center,
            Vector(50, 10),
            Vector(45, 10),
            lightGray
        )
    );

    aiguilleHeures.create(
        Triangle(
            Vector(50, 10),
            Vector(45, 10),
            Vector(50, 0),
            lightGray
        )
    );

    aiguilleHeures.create(
        Triangle(
            center,
            Vector(50, 10),
            Vector(55, 10),
            gray
        )
    );

    aiguilleHeures.create(
        Triangle(
            Vector(50, 10),
            Vector(55, 10),
            Vector(50, 0),
            gray
        )
    );

    // Minutes

    Object aiguilleMinutes(Vector(15, 15), Vector(70, 70));

    aiguilleMinutes.create(
        Triangle(
            center,
            Vector(50, 10),
            Vector(46, 10),
            lightGray
        )
    );

    aiguilleMinutes.create(
        Triangle(
            Vector(50, 10),
            Vector(46, 10),
            Vector(50, 3),
            lightGray
        )
    );

    aiguilleMinutes.create(
        Triangle(
            center,
            Vector(50, 10),
            Vector(54, 10),
            gray
        )
    );

    aiguilleMinutes.create(
        Triangle(
            Vector(50, 10),
            Vector(54, 10),
            Vector(50, 3),
            gray
        )
    );

    // Secondes

    Object trotteuse(Vector(15, 15), Vector(70, 70));

    trotteuse.create(
        Triangle(
            Vector(50.2, 0),
            Vector(50.2, 50),
            Vector(49.9, 50),
            Color(200, 0, 0, 255)
        )
    );

    trotteuse.create(
        Triangle(
            Vector(50.2, 0),
            Vector(49.8, 0),
            Vector(49.8, 50),
            Color(200, 0, 0, 255)
        )
    );

    // Marques

    Object marquesHeures(Vector(14, 14), Vector(72, 72));
    
    Triangle marqueTri1(
        Vector(0, 49.8),
        Vector(5, 49.8),
        Vector(5, 50.2),
        lightGray
    );
    Triangle marqueTri2(
        Vector(0, 49.8),
        Vector(0, 50.2),
        Vector(5, 50.2),
        lightGray
    );

    for (i = 0; i < 12; ++i)
    {
        marquesHeures.create(marqueTri1);
        marquesHeures.create(marqueTri2);

        marqueTri1.rotate(center, 360 / 12);
        marqueTri2.rotate(center, 360 / 12);
    }

    Object marquesMinutes(Vector(14, 14), Vector(72, 72));

    Triangle marqueTri3(
        Vector(0, 49.9),
        Vector(2, 49.9),
        Vector(2, 50.1),
        lightGray
    );
    Triangle marqueTri4(
        Vector(0, 49.9),
        Vector(0, 50.1),
        Vector(2, 50.1),
        lightGray
    );

    for (i = 0; i < 60; ++i)
    {
        marquesMinutes.create(marqueTri3);
        marquesMinutes.create(marqueTri4);

        marqueTri3.rotate(center, 360 / 60);
        marqueTri4.rotate(center, 360 / 60);
    }

	/* Initialisation */

	SDL_Init(SDL_INIT_VIDEO);

    // Enabling OpenGL multisampling
    if (MULTISAMPLING)
    {
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);
        glEnable(GL_MULTISAMPLE);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST );
        glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST );
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POLYGON_SMOOTH);
    }

    window = SDL_SetVideoMode(700, 700, 32, SDL_OPENGL);

    /* Main loop */

    while (run)
    {
        getTime(heures, minutes, secondes);

        updateEvents(&input);
        if (input.key[SDLK_ESCAPE] || input.quit)
            run = false;

        glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);

            cercle.draw();

            marquesMinutes.draw();
            marquesHeures.draw();

            trotteuse.resetPos();
            trotteuse.rotate(center, (360 / 60) * secondes);
            trotteuse.draw();

            aiguilleMinutes.resetPos();
            aiguilleMinutes.rotate(center, (360 / 60) * (((float)minutes + ((float)secondes / 60))));
            aiguilleMinutes.draw();

            aiguilleHeures.resetPos();
            aiguilleHeures.rotate(center, (360 / 12) * (((float)(heures % 12) + ((float)minutes / 60))));
            aiguilleHeures.draw();

            cercleMilieu.draw();

		glEnd();
        glFlush();
    	SDL_GL_SwapBuffers();

        usleep(1000);
    }

    /* Quit */

    SDL_Quit();

    return 0;
}

void getTime(int &hour, int &minute, int &second)
{
    time_t t = time(NULL);
    struct tm lt = {0};

    localtime_r(&t, &lt);

    second = time(NULL) %60;
    int nbMinutes = time(NULL) / 60;
    minute = nbMinutes % 60;
    int nbHeures = nbMinutes / 60 + lt.tm_gmtoff / 3600;
    hour = nbHeures % 24;
}
