#include <iostream>
using namespace std;

class Matrix {
	private:
		double v[3][3];
	public:
		Matrix(double ve[3][3], int);
		Matrix() {}
		double& operator()(int, int);
};

Matrix::Matrix(double ve[3][3], int r_size) {
	if (r_size != 3)
		cout << " Error!!";
	else
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				v[i][j] = ve[i][j];
}

double& Matrix::operator()(int i, int j) {
	return v[i][j];
}

int main() {
	double a[3][3];
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			cin >> a[i][j];

	Matrix M(a, 3);

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)  cout << M(i, j) <<" ";

		cout << endl;
	}
}

