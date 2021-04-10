//Matrix.cpp
#include "Matrix.h"
#define K 3
#define N 2

using namespace std;

Matrix::MatrixColumn::MatrixColumn() {
	d = new double[K];
	for (int i = 0; i < K; i++) {
		*(d + i) = 0;
	}
}

Matrix::MatrixColumn::MatrixColumn(double* init) {
	d = new double[K];
	for (int i = 0; i < K; i++) {
		*(d + i) = *(init + i);
	}
}

double& Matrix::MatrixColumn::operator[] (int i) { return d[i]; }

bool operator == (Matrix::MatrixColumn& A, Matrix::MatrixColumn& B) {
	for (int i = 0; i < K; i++) {
		if (A[i] != B[i]) return false; 
	}
	return true;
}

ostream& operator << (ostream& out, const Matrix::MatrixColumn& A) {
	out << "[ ";
	for (int i = 0; i < K; i++) {
		out << A.d[i] << " ";
	}
	out << "]";
	return out;
}

istream& operator >> (istream& in, const Matrix::MatrixColumn& A) {
	for (int i = 0; i < K; i++) {
		in >> A.d[i];
	}
	return in;
}

Matrix::MatrixColumn& Matrix::MatrixColumn::operator = (Matrix::MatrixColumn& A) {
	for (int i = 0; i < K; i++) {
		*(d + i) = A[i]; 
	}
	return *this;
}

Matrix::MatrixColumn& operator - (Matrix::MatrixColumn& A, Matrix::MatrixColumn& B) {
	Matrix::MatrixColumn* result = NULL;
	result = new Matrix::MatrixColumn;
	for (int i = 0; i < K; i++)
		(*result)[i] = A[i] - B[i];
	return *result;
}

double Norm(Matrix::MatrixColumn& A) {
	double result = 0;
	for (int i = 0; i < K; i++)
		result += A[i] * A[i];
	return result;
}

Matrix::MatrixColumn::~MatrixColumn() {
	delete[] d;
}
/////////////////////////////////////////////////////

Matrix::Matrix() {
	c = new Matrix::MatrixColumn[N];
	for (int i = 0; i < N; i++) {
		*(c + i) = *(new Matrix::MatrixColumn);
	}
}

Matrix::Matrix(Matrix::MatrixColumn* init) {
	c = new Matrix::MatrixColumn[N];
	for (int i = 0; i < N; i++) {
		*(c + i) = *(init + i);
	}
}

Matrix::MatrixColumn& Matrix::operator[] (int i) { return c[i]; }

bool operator == (Matrix& A, Matrix& B) {
	for (int i = 0; i < N; i++) {
		if(!(A[i] == B[i])) return false;
	}
	return true;
}

ostream& operator << (ostream& out, const Matrix& A) {
	out << "[ ";
	for (int i = 0; i < N; i++) {
		out << A.c[i] << " ";
	}
	out << "]";
	return out;
}

istream& operator >> (istream& in, const Matrix& A) {
	for (int i = 0; i < N; i++) {
		cout << "Input matrix column number " << i << ":" << endl;
		in >> A.c[i];
	}
	return in;
}


Matrix& Matrix::operator = (Matrix& A) {
	for (int i = 0; i < N; i++) {
		*(c + i) = A[i];
	}
	return *this;
}

Matrix& operator - (Matrix& A, Matrix& B) {
	Matrix* result = NULL;
	result = new Matrix;
	for (int i = 0; i < N; i++)
		(*result)[i] = A[i] - B[i];
	return *result;
}

double Norm(Matrix& A) {
	double result = 0;
	for (int i = 0; i < N; i++)
		result += Norm(A[i]);
	return sqrt(result);
}

Matrix::~Matrix() {
	delete[] c;
}
