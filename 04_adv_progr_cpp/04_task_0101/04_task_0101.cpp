#include <iostream>
#include <fstream>
#include <clocale>
#include <locale.h>
#include <windows.h>
using namespace std; 

//---------------------------------------------------------
struct point {
	int m_x, m_y;

	point(int x, int y) {
		m_x = x;
		m_y = y;
	}
};

//---------------------------------------------------------
void print_point(point& point_object) {
	cout << "x:" << point_object.m_x << ", y:"
  << point_object.m_y << endl;
}

int main(int argc, char** argv)
{
	int i;

	for (i = 0; i < 5; i++) {
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	
	return 0;
}
