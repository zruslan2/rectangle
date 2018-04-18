#include "Rectangle.h"
#include <fstream>

int main()
{
	ifstream in;
	ofstream out;
	out.open("write.txt", ios::out);
	in.open("read.txt");
	Rectangle *p;
	p = new Rectangle[5];
	double xa, ya, xb, yb, xc, yc, xd, yd;
	double xCenter, yCenter,sideA,sideB;
	int i = 0;
	if (!in)
	{
		cerr << "file open error" << endl;
	}
	else
	{
		/*while (!in.eof())
		{*/
			/*in >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;*/

		Rectangle r;
			r.coordinates(xCenter, yCenter, sideA, sideB);
			p[0] = r;
			
		/*}*/
	}
	for (int k = 0;k < i;k++)
	{
		/*p[k].move('x', 5);*/
		p[0].resize(2, 10);
		out << p[0].getXA() << "\t" << p[0].getYA() << "\t" 
			<< p[0].getXB() << "\t" << p[0].getYB() << "\t" 
			<< p[0].getXC() << "\t" << p[0].getYC() << "\t" 
			<< p[0].getXD() << "\t" << p[0].getYD() << "\t" << endl;
	}

	

	/*Point p(1.5, 10.5);
	cout << p.getX() << "\t" << p.getY() << endl;
	out << p.getX() << "\t" << p.getY() << endl;
	out.close();*/

	system("pause");
	return 0;
}