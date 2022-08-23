#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>

using namespace std;
struct Line
{
    int x0, y0, x1, y1;
    Line(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}
};
void flood_fill4(int x, int y, int fill_color, int old_color)
{
    if(getpixel(x, y) == old_color)
    {
        //delay(1);
        putpixel(x, y, fill_color);
        flood_fill4(x+1, y, fill_color, old_color);
        flood_fill4(x, y+1, fill_color, old_color);
        flood_fill4(x-1, y, fill_color, old_color);
        flood_fill4(x, y-1, fill_color, old_color);
    }
}
void flood_fill8(int x, int y, int fill_color,int old_color)
{
    if(getpixel(x, y) == old_color)
    {
        //if (rand()%10 == 0) delay(1);
        putpixel(x, y, fill_color);
        flood_fill8(x+1, y, fill_color, old_color);
        flood_fill8(x, y+1, fill_color, old_color);
        flood_fill8(x-1, y, fill_color, old_color);
        flood_fill8(x, y-1, fill_color, old_color);

        flood_fill8(x+1, y+1, fill_color, old_color);
        flood_fill8(x-1, y-1, fill_color, old_color);
        flood_fill8(x-1, y+1, fill_color, old_color);
        flood_fill8(x+1, y-1, fill_color, old_color);
    }
}
int main()
{
	int width = 800, height = 700;
	initwindow(width, height, "Boundary Fill algorithm");

	line(0, height/2, width, height/2);
	line(width/2, 0, width/2, height);

	vector<Line> lines;
	lines.push_back(Line(10, 10, 201, 10));
	lines.push_back(Line(10, 100, 200, 100));
	lines.push_back(Line(10, 10, 10, 100));
	lines.push_back(Line(201, 10, 201, 99));

	lines.push_back(Line(201, 99, 300, 99));
	lines.push_back(Line(300, 99, 300, 201));
	lines.push_back(Line(200, 200, 300, 200));
	lines.push_back(Line(200, 100, 200, 200));

	for (Line l : lines)
    {
        line(width/2+l.x0, height/2-l.y0, width/2+l.x1, height/2-l.y1);
    }

    //delay(1000);
    //flood_fill4(width/2+50, height/2-50, WHITE, BLACK);

    int x, y;
    cout << ": ";
    cin >> x >> y;
    flood_fill4(width/2+x, height/2-y, WHITE, BLACK);




	getch();
	closegraph();
	return 0;
}
