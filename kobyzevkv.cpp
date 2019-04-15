#include "kobyzevkv.h"

/**
 * Введение в дисциплину
 */
void kobyzevkv::lab1()
{
    cout << "Hello, world!" << endl;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void kobyzevkv::lab2()
{
	double eps = 10e-10;
	for (int i = 0; i < N; i++) {

		int indOfMaxElemInColumn = i;
		for (int j = i + 1; j < N; j++)
			if (abs(A[j][i]) > abs(A[indOfMaxElemInColumn][i]))
				indOfMaxElemInColumn = j;

		if (A[indOfMaxElemInColumn][i] == 0) {
			cout << "System hasn't solution" << endl;
			break;
		}

		if (indOfMaxElemInColumn != i) {
			swap(A[indOfMaxElemInColumn],A[i]);
			swap(b[indOfMaxElemInColumn],b[i]);
		}
		
		for (int j = i + 1; j < N; j++) {
			double d = A[j][i] / A[i][i];
			for (int k = i; k < N; k++) {
				if (abs(A[j][k] - A[i][k] * d) < eps)
					A[j][k] = 0;
				else
					A[j][k] -= A[i][k] * d;
			}
			if (abs(b[j] - b[i] * d) < eps)
				b[j] = 0;
			else
				b[j] -= b[i] * d;
		}

		for (int j = i - 1; j >= 0; j--) {
			double d = A[j][i] / A[i][i];
			for (int k = i; k < N; k++) {
				if (abs(A[j][k] - A[i][k] * d) < eps)
					A[j][k] = 0;
				else
					A[j][k] -= A[i][k] * d;
			}
			if (abs(b[j] - b[i] * d) < eps)
				b[j] = 0;
			else
				b[j] -= b[i] * d;
		}
	}

	for (int i = 0; i < N; i++) {
		x[i] = b[i] / A[i][i];
	}
}



/**
 * Метод прогонки
 */
void kobyzevkv::lab3()
{
	double* alpha = new double[N - 1];
	double* gamma = new double[N];

	for (int i = 0; i < N; i++) {

		gamma[i] = A[i][i];
		if (i != 0) gamma[i] += A[i][i - 1] * alpha[i - 1];

		if (i != N - 1) alpha[i] = -A[i][i + 1] / gamma[i];

		x[i] = b[i] / gamma[i];
		if (i != 0) x[i] -= A[i][i - 1] * x[i - 1] / gamma[i];

	}
	
	for (int i = N - 2; i >= 0; i--)
		x[i] += alpha[i] * x[i + 1];

	delete[] alpha;
	delete[] gamma;
}



/**
 * Метод простых итераций
 */
void kobyzevkv::lab4()
{
	double eps = 1e-15;
	double tau = 1e-5;

	double* prevX = new double[N];
	
	while (true) {

		for (int i = 0; i < N; i++)
			prevX[i] = x[i];

		for (int i = 0; i < N; i++) {
			double sum = 0;
			for (int j = 0; j < N; j++) 
				sum += A[i][j] * prevX[j];
			x[i] = prevX[i] - tau * (sum - b[i]);
		}

		double maxErr = abs(x[0] - prevX[0]);
		for (int i = 1; i < N; i++)
			if (abs(x[i] - prevX[i]) > maxErr)
				maxErr = abs(x[i] - prevX[i]);

		if (maxErr < eps)
			break;

	}

	delete[] prevX;
}



/**
 * Метод Якоби или Зейделя
 */
void kobyzevkv::lab5()
{
	double eps = 1e-15;

	double* prevX = new double[N];

	while (true) {

		for (int i = 0; i < N; i++)
			prevX[i] = x[i];

		for (int i = 0; i < N; i++) {
			double sum = 0;
			for (int j = 0; j < i; j++)
				sum += A[i][j] * x[j];
			for (int j = i + 1; j < N; j++)
				sum += A[i][j] * prevX[j];
			x[i] = (b[i] - sum) / A[i][i];
		}

		double maxErr = abs(x[0] - prevX[0]);
		for (int i = 1; i < N; i++)
			if (abs(x[i] - prevX[i]) > maxErr)
				maxErr = abs(x[i] - prevX[i]);

		if (maxErr < eps)
			break;

	}

	delete[] prevX;
}



/**
 * Метод минимальных невязок
 */
void kobyzevkv::lab6()
{
	double eps = 1e-15;

	double* prevX = new double[N];
	double* r = new double[N];

	while (true) {

		for (int i = 0; i < N; i++)
			prevX[i] = x[i];

		for (int i = 0; i < N; i++) {
			r[i] = b[i];

			for (int j = 0; j < N; j++) {
				r[i] -= A[i][j] * x[j];
			}
		}

		double tau = 0;
		double denomTau = 0;

		for (int i = 0; i < N; i++) {
			double Ar = 0;

			for (int j = 0; j < N; j++) {
				Ar += A[i][j] * r[j];
			}

			tau += Ar * r[i];
			denomTau += Ar * Ar;
		}

		tau /= denomTau;

		for (int i = 0; i < N; i++) {
			x[i] = prevX[i] + tau * r[i];
		}

		double maxErr = abs(x[0] - prevX[0]);
		for (int i = 1; i < N; i++)
			if (abs(x[i] - prevX[i]) > maxErr)
				maxErr = abs(x[i] - prevX[i]);

		if (maxErr < eps)
			break;

	}

	delete[] prevX;
	delete[] r;
}



/**
 * Метод сопряженных градиентов
 */
void kobyzevkv::lab7()
{

}


void kobyzevkv::lab8()
{

}


void kobyzevkv::lab9()
{

}


std::string kobyzevkv::get_name()
{
  return "Kobyzev Kirill";
}
