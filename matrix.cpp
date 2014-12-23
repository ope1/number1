#include "Matrix.h"

Matrix::Matrix(const int& a, const int& b)
{
	n = a;
	m = b;
    x = new int*[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = new int[m];
		for (int j = 0; j < m; j++)
			x[i][j] = 0;
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
		delete x[i];
	delete[] x;
}

Matrix::Matrix(Matrix& a)
{
	n = a.n;
	m = a.m;
	x = new int*[n];
	for (int i = 0; i < n; i++)
		x[i] = new int[m];
	Matrix (n,m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		  x[i][j] = a.x[i][j];
}

Matrix Matrix::operator + (const Matrix& a) const
{
	Matrix z(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			z.x[i][j] = x[i][j] + a.x[i][j];
	return z;
}

Matrix Matrix::operator - (const Matrix& a) const 
{
	Matrix z(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			z.x[i][j] = x[i][j] - a.x[i][j];
	return z;
}

Matrix Matrix::operator * (const Matrix& a) const
{
   if (n != m)
	return -1;
	Matrix z(n, a.m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int p = 0; p < m; p++)
				z.x[i][j] += x[i][p] * a.x[p][j];
	return z;
}

Matrix Matrix::operator * (const int& k) const
{
	Matrix z(n, m);
	for (int i = 0; i < n; i++)
 		for (int j = 0; j < m; j++)
			z.x[i][j] = x[i][j] * k;
	return z;
}

istream& operator >> (istream& in, Matrix& z)
{
	for (int i = 0; i < z.n; i++)
	{
		for (int j = 0; j < z.m; j++)
		{
			in >> z.x[i][j];
		}
	}
	 return in;
}

ostream& operator << (ostream& out, const Matrix& z)
{
	for (int i = 0; i < z.n; i++)
	{
		for (int j = 0; j < z.m; j++)
			out << z.x[i][j]<<" ";
		out << endl;
	}
	return out;
}
