#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>

using namespace std;
#define EPS 1e-10
#define ROUND(x) ((int)(x+0.5+EPS))
#define color WHITE


void DDA(int x0, int y0, int x1, int y1)
{
	int dx = x1-x0;
	int dy = y1-y0;

    if (abs(dx) >= abs(dy)) // Slope m is less than or equal to 1
    {
        int steps = abs(dx);
        int x = x0;
        double y = y0;

        putpixel(x, ROUND(y), color);

        for (int i = 0; i < steps; i++)
        {
            x < x1 ? x++ : x--;
            y += dy/(double)steps; // y += m

            putpixel(x, ROUND(y), color);
        }
    }
    else // Slope m is greater than 1
    {
        int steps = abs(dy);
        double x = x0;
        int y = y0;

        putpixel(ROUND(x), y, color);

        for (int i = 0; i < steps; i++)
        {
            y < y1 ? y++ : y--;
            x += dx/(double)steps; // x += 1/m

            putpixel(ROUND(x), y, color);
        }
    }
}
void bresenham(int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);

	bool swaped = 0;
	if (dx < dy)
    {
        swap(dx, dy); swap(x0, y0); swap(x1, y1); swaped = 1;
    }
	int x = x0;
	int y = y0;
	double pk = 2*dy-dx;
	cout << fixed << setprecision(6);
	for (int i = 0; i <= dx; i++)
	{
	    //cout << "(" <<  x << ", " << y << ")\n";
		if (swaped == 0) putpixel(x, y, RED);
		else putpixel(y, x, RED);
		x < x1 ? x++ : x--;
		if (pk < 0)
        {
            pk = pk+2*dy;
        }
        else
        {
            y < y1 ? y++ : y--;
            pk = pk+2*dy-2*dx;
        }
		delay(1);
	}
}
int main()
{
	//int gd = DETECT, gm = VGAMED;
	//initgraph (&gd, &gm, "");
	initwindow(800, 700, (const char *)"DDA Line Drawing Algorithm");
	int d; cin >> d;

	int x0, y0, x1, y1;

	//cout << "Input 1st point (x0, y0): ";
	//cin >> x0 >> y0;
	//cout << "Input 2nd point (x1, y1): ";
	//cin >> x1 >> y1;

	//DDA(x0, y0, x1, y1);
	//bresenham(x0, y0, x1, y1);
	//DDA(x1, y1, x0, y0);
	//bresenham(x1, y1, x0, y0);
	int w = 200, h = 200;
	int x = 400, y = 400;
	int inc = 1;
	for (int j = 0; j < h; j += inc)
    {
        DDA(x, y, x+w/2, y-h/2+j);
        delay(0.5);
    }
    for (int i = 0; i < w; i += inc)
    {
        DDA(x, y, x+w/2-i, y+h/2);
        delay(0.5);
    }
	for (int j = 0; j < h; j += inc)
    {
        DDA(x, y, x-w/2, y+h/2-j);
        delay(0.5);
    }
    for (int i = 0; i < w; i += inc)
    {
        DDA(x, y, x-w/2+i, y-h/2);
        delay(0.5);
    }

    inc = 20;

    for (int j = 0; j < h; j += inc)
    {
        bresenham(x, y, x+w/2, y-h/2+j);
        delay(0.5);
    }
    for (int i = 0; i < w; i += inc)
    {
        bresenham(x, y, x+w/2-i, y+h/2);
        delay(0.5);
    }
	for (int j = 0; j < h; j += inc)
    {
        bresenham(x, y, x-w/2, y+h/2-j);
        delay(0.5);
    }
    for (int i = 0; i < w; i += inc)
    {
        bresenham(x, y, x-w/2+i, y-h/2);
        delay(0.5);
    }

	//closegraph();
	getch();
	return 0;
}
