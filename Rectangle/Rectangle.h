#pragma once
#include <Windows.h>
#include<iostream>

using namespace std;
class MyRectangle 
{private:
	double sideA, sideB;
	int colR, colG, colB;
	class Point
	{
	private:
		double x;
		double y;
	public:
		Point() = default;
		Point(double x, double y) :x(x), y(y) {}

		double &getX() { return x; }
		double &getY() { return y; }

		void setXY(double x, double y)
		{
			this->x = x;
			this->y = y;
		}
	}a, b, c, d, center;
public:
	//default cons
	MyRectangle() = default;
	//parameter cons
	/*Rectangle(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd);*/
	MyRectangle(double xCenter, double yCenter, double sideA, double sideB);
	//accessors
	double getXA() { return a.getX(); }
	double getYA() { return a.getY(); }
	double getXB() { return b.getX(); }
	double getYB() { return b.getY(); }
	double getXC() { return c.getX(); }
	double getYC() { return c.getY(); }
	double getXD() { return d.getX(); }
	double getYD() { return d.getY(); }
	double &getSideA() { return sideA; }
	double &getSideB() { return sideB; }	
	double &getCX() { return center.getX(); }
	double &getCY() { return center.getY(); }
	int &getColR() { return colR; }
	int &getColG() { return colG; }
	int &getColB() { return colB; }
	//methods
	void move(char direction, double value);
	void coordinates(double xCenter, double yCenter, double sideA, double sideB);
	void resize(double x, double y);
	double area();
	double perimeter();	
	void infPrint();		
};

bool comparison(MyRectangle r1, MyRectangle r2);
MyRectangle copyR(MyRectangle r);
void viewR(MyRectangle r);
void coordinate();
void GotoXY(int X, int Y);
