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

}



/**
 * Метод Якоби или Зейделя
 */
void kobyzevkv::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void kobyzevkv::lab6()
{

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
