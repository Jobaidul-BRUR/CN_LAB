#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>

using namespace std;
#define sq(x) ((x)*(x))

void plot(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, WHITE);
	putpixel(xc+x, yc-y, WHITE);
	putpixel(xc-x, yc+y, WHITE);
	putpixel(xc-x, yc-y, WHITE);
	delay(1);
}

void mid_ellipse(int rx, int ry, int xc, int yc)
{
	double p1, p2;
	int x, y;
	x = 0;
	y = ry;

	plot(xc, yc, x, y);

	// Initial decision parameter of region 1
	p1 = sq(ry) - sq(rx)*ry + 0.25*sq(rx);

	// For region 1
	while (2*sq(ry)*x < 2*sq(rx)*y)
	{
        x++;

		if (p1 < 0)
		{
			p1 = p1 + 2*sq(ry)*x + sq(ry);
		}
		else
		{
			y--;
			p1 = p1 + 2*sq(ry)*x - 2*sq(rx)*y + sq(ry);
		}
		plot(xc, yc, x, y);
	}

	// Decision parameter of region 2
	p2 = sq(ry)*sq(x + 0.5) + sq(rx)*sq(y - 1) - sq(rx)*sq(ry);

	// Plotting points of region 2
	while (y >= 0)
	{
	    y--;
		if (p2 > 0)
		{
			p2 = p2 + sq(rx) - 2*sq(rx)*y;
		}
		else
		{
			x++;
			p2 = p2 + 2*sq(ry)*x - 2*sq(rx)*y + sq(rx);
		}
		plot(xc, yc, x, y);
	}
}

// Driver code
int main()
{
	int width = 800, height = 700;
	initwindow(width, height, "Ellipse drawing algorithm");

	line(0, height/2, width, height/2);
	line(width/2, 0, width/2, height);

	// To draw a ellips2*sq(rx)*ye of major and
	// minor radius 15, 10 centered at (50, 50)
	int xc = 0, yc = 0, rx = 150, ry = 100;
	mid_ellipse(rx, ry, width/2+xc, height/2-yc);
	while (1)
    {
        xc = 10+rand()%200;
        yc = 10+rand()%200;
        rx = 10+rand()%150;
        ry = 10+rand()%100;
        mid_ellipse(rx, ry, width/2+xc, height/2-yc);
    }

	while (1)
    {
        cout << "Input Ellipse center(xc, yc): ";
        cin >> xc >> yc;
        cout << "Input major radius: ";
        cin >> rx;
        cout << "Input minor radius: ";
        cin >> ry;
        mid_ellipse(rx, ry, width/2+xc, height/2-yc);
    }

	getch();
	return 0;
}
