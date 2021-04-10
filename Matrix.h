//Matrix.h
#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Matrix {
private:
public:
	class MatrixColumn { 
	public:
		double* d;
		MatrixColumn();
		MatrixColumn(double* init);
		double& operator [] (int);
		Matrix::MatrixColumn& operator = (Matrix::MatrixColumn&);
		friend Matrix::MatrixColumn& operator - (Matrix::MatrixColumn&, Matrix::MatrixColumn&);
		friend bool operator == (Matrix::MatrixColumn&, Matrix::MatrixColumn&);
		friend ostream& operator << (ostream&, const Matrix::MatrixColumn&);
		friend istream& operator >> (istream&, const Matrix::MatrixColumn&);
		friend double Norm(Matrix::MatrixColumn&);
		~MatrixColumn();
	};
	MatrixColumn* c;
	Matrix();
	Matrix(MatrixColumn* init);
	Matrix::MatrixColumn& operator [] (int);
	Matrix& operator = (Matrix&);
	friend Matrix& operator - (Matrix&, Matrix&);
	friend bool operator == (Matrix&, Matrix&);
	friend ostream& operator << (ostream&, const Matrix&);
	friend istream& operator >> (istream&, const Matrix&);
	friend double Norm(Matrix&);
	~Matrix();
};

