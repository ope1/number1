#pragma once
#include <iostream>
using namespace std;

class Matrix
{
	int** x;
	int n;
	int m;
	friend istream& operator >> (istream& in, Matrix& z);
	friend ostream& operator << (ostream& out, const Matrix& z);
public:
	Matrix(const int& n, const int& m);
	~Matrix();
	Matrix(Matrix& a);
	Matrix operator + (const Matrix& a) const;
	Matrix operator - (const Matrix& a) const;
	Matrix operator * (const Matrix& a) const; //Matrix multiple(Matrix& a);
	Matrix operator * (const int& n) const; //Matrix multiple_k(int& k);
};

