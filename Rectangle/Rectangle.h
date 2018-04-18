#pragma once
#include<iostream>

using namespace std;
class Rectangle 
{private:
	double sideA, sideB;
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
	Rectangle() = default;
	//parameter cons
	Rectangle(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd);
	Rectangle(double xCenter, double yCenter, double sideA, double sideB);
	//accessors
	double getXA() { return a.getX(); }
	double getYA() { return a.getY(); }
	double getXB() { return a.getX(); }
	double getYB() { return a.getY(); }
	double getXC() { return a.getX(); }
	double getYC() { return a.getY(); }
	double getXD() { return a.getX(); }
	double getYD() { return a.getY(); }
	double getSideA() { return sideA; }
	double getSideB() { return sideB; }
	//methods
	void move(char direction, double value);
	void coordinates(double xCenter, double yCenter, double sideA, double sideB);
	void resize(double x, double y);
};

