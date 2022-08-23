#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

void plot(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, WHITE);
	putpixel(xc+y, yc+x, WHITE);
	putpixel(xc+x, yc-y, WHITE);
	putpixel(xc+y, yc-x, WHITE);
	putpixel(xc-x, yc+y, WHITE);
	putpixel(xc-y, yc+x, WHITE);
	putpixel(xc-x, yc-y, WHITE);
	putpixel(xc-y, yc-x, WHITE);
}
void plot2(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, BLACK);
	putpixel(xc+y, yc+x, BLACK);
	putpixel(xc+x, yc-y, BLACK);
	putpixel(xc+y, yc-x, BLACK);
	putpixel(xc-x, yc+y, BLACK);
	putpixel(xc-y, yc+x, BLACK);
	putpixel(xc-x, yc-y, BLACK);
	putpixel(xc-y, yc-x, BLACK);
}

void bres_circle(int xc, int yc, int r)
{
	int x = 0, y = r;
    plot2(xc, yc, x, y);

	int d = 3-2*r;
	while (y >= x)
	{

		x++;
		if (d <= 0) d = d+4*x+6;
		else
		{
			y--;
			d = d+4*(x-y)+10;
		}

		plot2(xc, yc, x, y);
		delay(20);
	}
}

void mid_circle(int xc, int yc, int r)
{
	int x = 0, y = r;

    plot(xc, yc, x, y);

	int pk = 1-r;
	while (y > x)
	{

        x++;
		if (pk <= 0) pk = pk+2*x+1; // Mid-point is inside or on the perimeter
		else // Mid-point is outside the perimeter
		{
		    y--;
			pk = pk+2*x-2*y+1;
		}
		plot(xc, yc, x, y);
		delay(1);
	}
}

int main()
{
	int xc = 100, yc = 150, r = 100;

	int width = 800, height = 700;
	initwindow(width, height, "circle drawing algorithm");
	//bres_circle(xc, yc, r);

	//setfillstyle(SOLID_FILL, BLACK);
	//floodfill(0, 0 , YELLOW);
	//mid_circle(xc, yc+r*2+2, r);
	//circle(xc, yc, r-10);
	//circle(xc, yc, r+10);

	line(0, height/2, width, height/2);
	line(width/2, 0, width/2, height);

	mid_circle(width/2+xc, height/2-yc, r);

	for (int i = 0; i < 10; i++)
    {
    }

	/*while (1)
    {
        setcolor(WHITE);
        for (int r = 0; r <= 200; r += 10)
        {
            mid_circle(xc, yc, r); delay(1);
        }
        setcolor(BLACK);
        for (int r = 200; r >= 0; r -= 10)
        {
            bres_circle(xc, yc, r); delay(1);
        }
    }*/


	getch();
	return 0;
}
