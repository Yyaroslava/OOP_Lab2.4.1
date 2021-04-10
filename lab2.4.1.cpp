// lab2.4.1.cpp
#include <iostream>
#include "Matrix.h"
#define K 3
#define N 2

using namespace std;

int main() {
	Matrix::MatrixColumn c;
	cout << "c: " << c << endl;
	cout << "c[0]: "<< c[0] << endl;
	c[1] = 3.14;
	cout << "c: " << c << endl;
	cout << "c[1]: "<< c[1] << endl;
	
	Matrix::MatrixColumn v(new double[K] {1,3.14,0});
	cout << "v: " << v << endl;
	cout << "v[2]: " << v[2] << endl;

	cout << "c == v : " << (c == v) << endl;
	
	Matrix::MatrixColumn d;
	d = v;
	cout << "d: " << d << endl;

	Matrix::MatrixColumn e;
	e = d - c;
	cout << "e = d - c " << endl;
	cout << "e: " << e << endl;

	cout << "Norm(v): " << Norm(v) << endl;
		
	Matrix A;
	cout << "A: " << A << endl;
	A[0][0] = 7;
	A[1][1] = 3;
	A[0][2] = 1;
	cout << "A: " << A << endl;

	Matrix B;
	B = A;
	cout << "B: " << B << endl;

	A == B;
	cout << "A == B: " << (A==B) << endl;

	B[0][1] = 4;
	cout << "B: " << B << endl;

	Matrix C;
	C = A - B;
	cout << "C = A - B: " << endl;
	cout << "C: " << C << endl;

	cout << "Norm(A): " << Norm(A) << endl;
	cout << "Norm(C): " << Norm(C) << endl;

	Matrix::MatrixColumn k;
	cout << "Input matrix column " << endl;
	cin >> k;
	cout << "k: " << k << endl;

	Matrix M;
	cout << "Input matrix " << endl;
	cin >> M;
	cout << "Matrix M: " << M << endl;

	return 0;
}
