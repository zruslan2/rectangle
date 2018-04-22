#include"Rectangle.h"

//Rectangle::Rectangle(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd)
//{
//	a.setXY(xa, ya);
//	b.setXY(xb, yb);
//	c.setXY(xc, yc);
//	d.setXY(xd, yd);
//}

MyRectangle::MyRectangle(double xCenter, double yCenter, double sideA, double sideB)
{
	a.getX() = xCenter - (sideA / 2);
	a.getY() = yCenter - (sideB / 2);
	b.getX() = xCenter - (sideA / 2);
	b.getY() = yCenter + (sideB / 2);
	c.getX() = xCenter + (sideA / 2);
	c.getY() = yCenter + (sideB / 2);
	d.getX() = xCenter + (sideA / 2);
	d.getY() = yCenter - (sideB / 2);
}

void MyRectangle::move(char direction, double value)
{
	if (direction == 'x' || direction == 'X')
	{
		a.getX() += value;
		b.getX() += value;
		c.getX() += value;
		d.getX() += value;
	}
	else if (direction == 'y' || direction == 'Y')
	{
		a.getY() += value;
		b.getY() += value;
		c.getY() += value;
		d.getY() += value;
	}
	else
		cerr << "wrong direction" << endl;	
}

void MyRectangle::coordinates(double xCenter, double yCenter, double sideA, double sideB)
{
	a.getX() = xCenter - (sideA / 2);
	a.getY() = yCenter - (sideB / 2);
	b.getX() = xCenter - (sideA / 2);
	b.getY() = yCenter + (sideB / 2);
	c.getX() = xCenter + (sideA / 2);
	c.getY() = yCenter + (sideB / 2);
	d.getX() = xCenter + (sideA / 2);
	d.getY() = yCenter - (sideB / 2);
	getSideA() = sideA;
	getSideB() = sideB;
	center.getX() = xCenter;
	center.getY() = yCenter;
	getColR()= 10 + rand() % 245;
	getColG()= 10 + rand() % 245;
	getColB()= 10 + rand() % 245;
}

void MyRectangle::resize(double x, double y)
{
	getSideA() += x;
	getSideB() += y;	
	coordinates(center.getX(), center.getY(), sideA, sideB);
}

double MyRectangle::area()
{
	double ar;
	ar = getSideA()*getSideB();
	return ar;
}

double MyRectangle::perimeter()
{
	double p;
	p= (getSideA()+getSideB())*2;
	return p;
}

bool comparison(MyRectangle r1, MyRectangle r2)
{
	if (r1.perimeter() == r2.perimeter()&&r1.area() == r2.area()) return true;	
	else return false;
}

void MyRectangle::infPrint()
{
	cout << "Ширина прямоугольника: " << getSideA() << endl;
	cout << "Высота прямоугольника: " << getSideB() << endl;
	cout << "Площадь прямоугольника: " << area() << endl;
	cout << "Периметр прямоугольника: " << perimeter() << endl;
	cout << "Координаты уголов(x,y): "
		<< "Угол1 - " << a.getX() << "," << a.getY() << ";"
		<< "Угол2 - " << b.getX() << "," << b.getY() << ";"
		<< "Угол3 - " << c.getX() << "," << c.getY() << ";"
		<< "Угол4 - " << d.getX() << "," << d.getY() << ";"
		<< endl;
}

MyRectangle copyR(MyRectangle r)
{
	MyRectangle rec;
	rec = r;
	return rec;
}

void viewR(MyRectangle r)
{
	int R, G, B;
	R = r.getColR();
	G = r.getColG();
	B = r.getColB();
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 1, RGB(R, G, B));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, r.getXA(), r.getYA(), NULL);
	LineTo(hDC, r.getXB(), r.getYB());
	MoveToEx(hDC, r.getXB(), r.getYB(), NULL);
	LineTo(hDC, r.getXC(), r.getYC());
	MoveToEx(hDC, r.getXC(), r.getYC(), NULL);
	LineTo(hDC, r.getXD(), r.getYD());
	MoveToEx(hDC, r.getXD(), r.getYD(), NULL);
	LineTo(hDC, r.getXA(), r.getYA());
}

void coordinate()
{
	//x0=50,y0=550
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 50, 50, NULL);
	LineTo(hDC, 50, 600);
	MoveToEx(hDC, 50, 50, NULL);
	LineTo(hDC, 45, 55);
	MoveToEx(hDC, 50, 50, NULL);
	LineTo(hDC, 55, 55);
	MoveToEx(hDC, 20, 550, NULL);
	LineTo(hDC, 600, 550);
	MoveToEx(hDC, 600, 550, NULL);
	LineTo(hDC, 595, 545);
	MoveToEx(hDC, 600, 550, NULL);
	LineTo(hDC, 595, 555);
	int x1= 47, y=540, x2= 53;
	for (int i = 0; i < 49; i++)
	{
		MoveToEx(hDC, x1, y, NULL);
		LineTo(hDC, x2, y);
		y = y - 10;
	}
	int x = 60, y1 = 547, y2 = 553;
	for (int i = 0; i < 54; i++)
	{
		MoveToEx(hDC, x, y1, NULL);
		LineTo(hDC, x, y2);
		x = x + 10;
	}	
}

void GotoXY(int X, int Y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hConsole, coord);
}