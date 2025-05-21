#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

#define WIDTH 80
#define HEIGHT 24
#define NUM_OF_CIRCLES 3
#define RED_COLOR "\033[31m"
#define BLUE_COLOR "\033[34m"
#define WHITE_COLOR "\033[37m"
#define RESET_COLOR "\033[0m"

struct Circle
{
    double x, y, r, v_x, v_y;
};

void temizle()
{
    cout << "\033[2J";
}

void imleci_basa_gotur()
{
    cout << "\033[H";
}

void animation(Circle circles[NUM_OF_CIRCLES], char *colors[])
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            bool filled = false;
            for (int i = 0; i < NUM_OF_CIRCLES && !filled; i++)
            {
                Circle circle = circles[i];
                int distance = sqrt(pow(x - circle.x, 2) + pow(y - circle.y, 2));
                if (distance < circle.r)
                {
                    filled = true;
                    cout << colors[i] << "#";
                    cout << RESET_COLOR;
                }
            }
            if (!filled)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    Sleep(50);
}

void hareket(Circle circles[NUM_OF_CIRCLES])
{
    for (int i = 0; i < NUM_OF_CIRCLES; i++)
    {
        Circle *circle = &circles[i];

        if (circle->x - circle->r <= 0)
        {
            circle->v_x = -circle->v_x;
            circle->x = circle->r;
        }
        if (circle->x + circle->r >= WIDTH)
        {
            circle->v_x = -circle->v_x;
            circle->x = WIDTH - circle->r;
        }
        if (circle->y - circle->r <= 0)
        {
            circle->v_y = -circle->v_y;
            circle->y = circle->r;
        }
        if (circle->y + circle->r >= HEIGHT)
        {
            circle->v_y = -circle->v_y;
            circle->y = HEIGHT - circle->r;
        }
        circle->x += circle->v_x;
        circle->y += circle->v_y;
    }
}

int main()
{
    Circle circle1 = {8, 5, 5, 0.7, 0.3};
    Circle circle2 = {20, 13, 7, -0.5, -0.2};
    Circle circle3 = {12, 8, 3, 0.3, -0.6};

    Circle circles[] = {circle1, circle2, circle3};

    temizle();

    char *colors[] = {RED_COLOR, BLUE_COLOR, WHITE_COLOR};

    while (true)
    {
        imleci_basa_gotur();
        animation(circles, colors);
        hareket(circles);
    }
}
