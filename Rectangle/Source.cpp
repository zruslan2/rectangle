#include <fstream>
#include <locale>
#include <time.h>
#include "Rectangle.h"


int main()
{
	setlocale(LC_ALL, "");	
	srand(time(NULL));

	coordinate();
	int count,m,np,np1;
	MyRectangle *r;
	cout << "1 - Загрузить | 2 - Создать "; cin >> m;
	if (m == 1)
	{
		ifstream in;
		in.open("rec.txt");
		in >> count;
		r = new MyRectangle[count];
		int i = 0;
		if (!in)
		{
			cerr << "file open error" << endl;
		}
		else
		{
			for (int i = 0; i < count; i++)
			{
				in >> r[i].getColR() >> r[i].getColG() >> r[i].getColB()
					>> r[i].getSideA() >> r[i].getSideB()
					>> r[i].getCX() >> r[i].getCY();
				r[i].coordinates(r[i].getCX(), r[i].getCY(), r[i].getSideA(), r[i].getSideB());
				viewR(r[i]);
			}
		}				
	}
	else if (m == 2)
	{
		GotoXY(0, 0);
		cout << "                                                                             ";
		GotoXY(0, 0);
		cout << "Введите количество прямогольников которое надо создать "; cin >> count;
		r = new MyRectangle[count];
		double SideA, SideB, CenterX, CenterY;
		for (int i = 0; i < count; i++)
		{
			SideA = (2 + rand() % 10) * 10;
			SideB = (2 + rand() % 10) * 10;
			CenterX = 50 + (5 + rand() % 40) * 10;
			CenterY = 550 - ((5 + rand() % 40) * 10);
			r[i].coordinates(CenterX, CenterY, SideA, SideB);
			viewR(r[i]);
		}
	}	
	while (true)
	{
		GotoXY(0, 0);
		cout << "1 - Переместить | 2 - Изменить размер | 3 - Определить площадь и периметр" << endl << "4 - Проверить на равенство | 5 - Информация | 6 - копировать | 7 - выход "; cin >> m;
		if (m == 1)
		{			
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 1);
			cout << "                                                                             ";
			GotoXY(0, 0);
			cout << "Выберите номер прямогольника от 1 до " << count<<" "; cin >> np;			
			char dir;
			int c;
			GotoXY(0, 0);
			cout<<"                                                                             ";
			GotoXY(0, 0);
			cout << "Выберите плоскость X или Y "; cin >> dir;
			GotoXY(0, 0);
			cout<<"                                                                             ";
			GotoXY(0, 0);
			cout << "На сколько переместить "; cin >> c;
			if(dir=='X')
				r[np-1].move(dir, c * 10);	
			else
				r[np - 1].move(dir, -1*(c * 10));
			system("cls");
			coordinate();
			for (int i = 0; i < count; i++)
			{
				viewR(r[i]);
			}
		}
		else if (m == 2)
		{
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 1);
			cout << "                                                                             ";
			GotoXY(0, 0);
			cout << "Выберите номер прямогольника от 1 до " << count << " "; cin >> np;
			double x, y;
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 0);
			cout << "Выберите на сколько изменить по ширине "; cin >> x;
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 0);
			cout << "Выберите на сколько изменить по высоте "; cin >> y;
			r[np - 1].resize(x*10, y*10);
			system("cls");
			coordinate();
			for (int i = 0; i < count; i++)
			{
				viewR(r[i]);
			}
		}
		else if (m == 3)
		{
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 1);
			cout << "                                                                             ";
			GotoXY(0, 0);
			cout << "Выберите номер прямогольника от 1 до " << count << " "; cin >> np;
			double S, P;
			S = (r[np - 1].area())/10;
			P = (r[np - 1].perimeter())/10;
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 0);
			cout << "S = " << S << ", P = " << P<<" "; system("pause");
			system("cls");
			coordinate();
			for (int i = 0; i < count; i++)
			{
				viewR(r[i]);
			}
		}
		else if (m == 4)
		{
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 1);
			cout << "                                                                             ";
			GotoXY(0, 0);
			cout << "Выберите номер прямогольника от 1 до " << count << " "; cin >> np;
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 0);
			cout << "Выберите еще прямогольник от 1 до " << count << " "; cin >> np1;
			bool b;
			b=comparison(r[np - 1], r[np1 - 1]);
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 0);
			if (b == true) cout << "Прямоугольник " << np << " и прямоугольник " << np1 << " равны ";
			else cout << "Прямоугольник " << np << " и прямоугольник " << np1 << " не равны ";
			system("pause");
			system("cls");
			coordinate();
			for (int i = 0; i < count; i++)
			{
				viewR(r[i]);
			}
		}
		else if (m == 5)
		{
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 1);
			cout << "                                                                             ";
			GotoXY(0, 0);
			cout << "Выберите номер прямогольника от 1 до " << count << " "; cin >> np;
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 0);
			r[np - 1].infPrint();
			system("pause");
			system("cls");
			coordinate();
			for (int i = 0; i < count; i++)
			{
				viewR(r[i]);
			}
		}
		else if (m == 6)
		{
			MyRectangle *t;
			t = new MyRectangle[count+1];
			for (int i = 0; i < count; i++)
			{
				t[i] = r[i];
			}
			GotoXY(0, 0);
			cout << "                                                                             ";
			GotoXY(0, 1);
			cout << "                                                                             ";
			GotoXY(0, 0);
			cout << "Выберите номер прямогольника от 1 до " << count << " "; cin >> np;
			t[count] = r[np - 1];
			r = t;	
			count++;
			system("cls");
			coordinate();
			for (int i = 0; i < count; i++)
			{
				viewR(r[i]);
			}
		}
		else if (m == 7)
		{
			ofstream out;
			out.open("rec.txt", ios::out);
			out << count << endl;
			for (int i = 0; i < count; i++)
			{
				out << r[i].getColR() <<"\t"<< r[i].getColG() << "\t" << r[i].getColB() 
					<< "\t" << r[i].getSideA() << "\t" << r[i].getSideB() 
					<< "\t" <<r[i].getCX() << "\t" <<r[i].getCY()<< endl;
			}
			break;
		}
	}

	system("pause");
	return 0;
}

