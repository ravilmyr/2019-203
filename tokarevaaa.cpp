#include "tokarevaaa.h"

/**
 * Введение в дисциплину
 */
void tokarevaaa::lab1()
{
 cout << "Hello, World!";
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void tokarevaaa::lab2()
{
    double eps = 1.e-10;
	int *f = new int[N];
	for (int i = 0; i < N; i++) {
		f[i] = i;
	}

	for (int k = 0; k < N; k++) {
		int s = k;
		for (int i = k + 1; i < N; i++) {
			if (abs(A[s][k]) < abs(A[i][k])) {
				s = i;
			}
		}
		if (s != k) {
			swap(b[s], b[k]);
			swap(f[s], f[k]);
			for (int j = k; j < N; j++) {
				swap(A[s][j], A[k][j]);
			}
		}
		if (abs(A[k][k]) < eps) {
			cout << "Система не определена." << endl;
			return;
        }
		double t = A[k][k];
		b[k] /= t;
		for (int j = k; j < N; j++) {
			A[k][j] /= t;
		}
		for (int i = k + 1; i < N; i++) {
			t = A[i][k];

			b[i] -= b[k] * t;
			for (int j = k; j < N; j++) {
				A[i][j] -= A[k][j] * t;
			}
		}
	}
	// Обратный ход
	for (int k = N - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			b[i] -= A[i][k] * b[k];
		}
	}

	for (int i = 0; i < N; i++) {
		x[i] = b[f[i]];
	}

	delete[] f;

}



/**
 * Метод прогонки
 */
void tokarevaaa::lab3()
{
    double *alpha = new double[N];
	double *beta = new double[N];
	// Прямой ход
	alpha[0] = -A[0][1] / A[0][0];
	beta[0] = b[0] / A[0][0];
	for (int i = 1; i < N; i++) {
		alpha[i] = -A[i][i + 1] / (A[i][i] + A[i][i - 1] * alpha[i - 1]);
		beta[i] = (b[i] - A[i][i - 1] * beta[i - 1]) / (A[i][i] + A[i][i - 1] * alpha[i - 1]);
	}
	// Обратный ход
	x[N - 1] = beta[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		x[i] = alpha[i] * x[i + 1] + beta[i];
	}
	delete[] alpha;
	delete[] beta;
}



/**
 * Метод простых итераций
 */
void tokarevaaa::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void tokarevaaa::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void tokarevaaa::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void tokarevaaa::lab7()
{

}


void tokarevaaa::lab8()
{

}


void tokarevaaa::lab9()
{

}


std::string tokarevaaa::get_name()
{
  return "Tokareva Alina Aleksandrovna";
}
