#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>

using namespace std;
struct Matrix
{
    vector<vector<int>> matrix;
    Matrix() {}
    Matrix(int row, int col)
    {
        matrix = vector<vector<int>>(row, vector<int>(col, 0));
    }
};
void rectangle(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int cx, int cy)
{
    x0 = cx+x0, x1 = cx+x1, x2 = cx+x2, x3 = cx+x3;
    y0 = cy-y0, y1 = cy-y1, y2 = cy-y2, y3 = cy-y3;
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x0, y0);
}
Matrix multiply(Matrix a, Matrix b)
{
    assert(a.matrix.size() > 0 and a.matrix[0].size() == b.matrix.size()); // column of a == row of b
    int n = a.matrix.size();
    int m = b.matrix[0].size();
    int x = a.matrix[0].size();
    Matrix res(n, m);
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << a.matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b.matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res.matrix[i][j] = 0;
            for (int k = 0; k < x; k++)
            {
                res.matrix[i][j] += a.matrix[i][k]*b.matrix[k][j];
            }
            //cout << res.matrix[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << endl;



    return res;

}
int main()
{
	int width = 1400, height = 800;
	initwindow(width, height, "2D Shear");

	line(0, height/2, width, height/2);
	line(width/2, 0, width/2, height);

	int x0 = 10, y0 = 10, x1 = 100, y1 = 10, x2 = 100, y2 = 100, x3 = 10, y3 = 100;

	rectangle(x0, y0, x1, y1, x2, y2, x3, y3, width/2, height/2);

	Matrix points[4];
	points[0] = Matrix(3, 1);
	points[0].matrix[0][0] = x0;
	points[0].matrix[1][0] = y0;
	points[0].matrix[2][0] = 1;

	points[1] = Matrix(3, 1);
	points[1].matrix[0][0] = x1;
	points[1].matrix[1][0] = y1;
	points[1].matrix[2][0] = 1;

	points[2] = Matrix(3, 1);
	points[2].matrix[0][0] = x2;
	points[2].matrix[1][0] = y2;
	points[2].matrix[2][0] = 1;

	points[3] = Matrix(3, 1);
	points[3].matrix[0][0] = x3;
	points[3].matrix[1][0] = y3;
	points[3].matrix[2][0] = 1;

	int sx = 2, sy = 2;
	//cout << "Input sx: "; cin >> sx;
	//cout << "Input sy: "; cin >> sy;

	Matrix s(3, 3);
	s.matrix[0][0] = 1;
	s.matrix[1][1] = 1;
	s.matrix[2][2] = 1;
	s.matrix[0][1] = sx;
	s.matrix[1][0] = sy;

	points[0] = multiply(s, points[0]);
	points[1] = multiply(s, points[1]);
	points[2] = multiply(s, points[2]);
	points[3] = multiply(s, points[3]);

	setcolor(RED);
	rectangle(points[0].matrix[0][0], points[0].matrix[1][0],
             points[1].matrix[0][0], points[1].matrix[1][0],
             points[2].matrix[0][0], points[2].matrix[1][0],
             points[3].matrix[0][0], points[3].matrix[1][0], width/2, height/2);



	getch();
	closegraph();
	return 0;
}
