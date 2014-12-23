#include <iostream>
#include "Matrix.h"
using namespace std;

int main(void)
{
	int n, m;
	int k;
	cout << "Size of matrix:" << endl;
	cin >> n >> m;
	Matrix p(n, m);
	cout << "Input first matrix:" << endl;
	cin >> p;
	cout << endl;
	Matrix p1(n, m);
	cout << "Input second matrix:" << endl;
	cin >> p1;
	cout << endl;
	cout << "Multiple of matrix:" << endl;
	cout << p*p1 << endl;
	cout << "Vichitanie:" << endl;
	cout << p-p1 << endl;
	cout << "Slozhenie:" << endl;
	cout << p+p1 << endl;
	cout << "Multiple na chislo:" << endl;
	cout << "Vvedite chislo:" << endl;
	cin >> k;
	cout << p*k << endl;
	system("pause");
	return 0;
}
