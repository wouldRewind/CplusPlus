
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
		// цикл в цикле
	for (double y = 1.0; y >= -1.0; y -= 0.1) {
		// область определения игрика
		for (double x = 0.0; x <= 13.0; x += 0.1) { // область определения икса
			if (y >= sin(x) - 0.05 && y <= sin(x) + 0.05) {
				cout << 1;
			}
			else if (x == 0) cout << "|";
			else if (-0.0005 < y && y < 0.0005) cout << "_";
			else {
				cout << " ";
			}
		}
		// перевод строки
		cout << endl;
	}
	return 0;
}