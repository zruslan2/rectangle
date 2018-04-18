#include"Rectangle.h"

Rectangle::Rectangle(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd)
{
	a.setXY(xa, ya);
	b.setXY(xb, yb);
	c.setXY(xc, yc);
	d.setXY(xd, yd);
}

Rectangle::Rectangle(double xCenter, double yCenter, double sideA, double sideB)
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

void Rectangle::move(char direction, double value)
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

void Rectangle::coordinates(double xCenter, double yCenter, double sideA, double sideB)
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

void Rectangle::resize(double x, double y)
{
	sideA += x;
	sideB += y;
	coordinates(center.getX(), center.getY(), sideA, sideB);
}