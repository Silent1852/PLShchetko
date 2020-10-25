#include <iostream>

using namespace std;

class Matrix {
private:
	int Sx, Sy;
	double** XY;
public:

	void ArrayResize(int NewSize1, int NewSize2) {
		double** Array = new double* [NewSize1];
		for (int i = 0; i < NewSize1; i++)
			Array[i] = new double[NewSize2];

		for (int i = 0; (i < Sx) && (i < NewSize1); i++)
			for (int j = 0; (j < Sy) && (j < NewSize2); j++)
				Array[i][j] = XY[i][j];

		for (int i = 0; i < Sx; i++) delete[]XY[i];
		delete[]XY;

		Sx = NewSize1;
		Sy = NewSize2;

		XY = Array;
	}

	void setSize(int NewSize1, int NewSize2) {
		XY = new double* [NewSize1];
		for (int i = 0; i < NewSize1; i++)
			XY[i] = new double[NewSize2];

		Sx = NewSize1;
		Sy = NewSize2;
	}

	Matrix(int NSx = 0, int NSy = 0) {
		Sx = abs(NSx);
		Sy = abs(NSy);
		XY = NULL;
		if (Sx != 0 && Sy != 0) {
			XY = new double* [Sx];
			for (int i = 0; i < Sx; i++)
				XY[i] = new double[Sy];

			for (int i = 0; i < Sx; i++)
				for (int j = 0; j < Sy; j++)
					XY[i][j] = NULL;
		}
	}

	Matrix(const Matrix& matrix) : XY(matrix.XY), Sx(matrix.Sx), Sy(matrix.Sy) {}

	~Matrix() {
	}

	friend istream& operator>> (istream& is, Matrix& matrix) {
		for (int i = 0; i < matrix.Sx; i++)
			for (int j = 0; j < matrix.Sy; j++)
				is >> matrix.XY[i][j];
		return is;
	}

	friend ostream& operator<<(ostream& out, const Matrix& matrix) {
		if (matrix.Sx == 0 || matrix.Sy == 0) {
			out << "Пустой массив." << endl;
			return out;
		}
		else {
			for (int i = 0; i < matrix.Sx; i++) {
				out << endl;
				for (int j = 0; j < matrix.Sy; j++) {
					out.width(3);
					out << matrix.XY[i][j] << " | ";
				}
			}
			out << endl;
		}
		return out;
	}

	friend Matrix operator+(const Matrix& m1, const Matrix& m2) {
		Matrix matrix;
		if (m1.Sx != m2.Sx || m1.Sy != m2.Sy) {
			cout << "Ошибка, разные размеры матриц." << endl;
			exit(0);
		}
		else {
			matrix.ArrayResize(m1.Sx, m1.Sy);
			for (int i = 0; i < matrix.Sx; i++)
				for (int j = 0; j < matrix.Sy; j++)
					matrix.XY[i][j] = m1.XY[i][j] + m2.XY[i][j];
		}
		return matrix;
	}

	friend Matrix operator*(const Matrix& m1, int a) {
		Matrix matrix;
		matrix.ArrayResize(m1.Sx, m1.Sy);
		for (int i = 0; i < matrix.Sx; i++)
			for (int j = 0; j < matrix.Sy; j++)
				matrix.XY[i][j] = m1.XY[i][j] * a;

		return matrix;
	}

	friend Matrix operator*(const Matrix& m1, const Matrix& m2) {
		Matrix matrix;
		if ((m1.Sx != m2.Sy || m1.Sy != m2.Sx) && (m1.Sx != m2.Sx || m1.Sy != m2.Sy)) {
			cout << "Ошибка, разные размеры матриц." << endl;
			exit(0);
		}
		else {
			matrix.ArrayResize(m1.Sx, m1.Sy);
			for (int i = 0; i < matrix.Sx; i++)
				for (int j = 0; j < matrix.Sy; j++) {
					double sum = 0;
					for (int k = 0; k < matrix.Sy; k++)
						sum += m1.XY[i][k] * m2.XY[k][j];
					matrix.XY[i][j] = sum;
				}
		}

		return matrix;
	}

};
