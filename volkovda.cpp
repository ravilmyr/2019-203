#include "volkovda.h"
#define EPSILON 1e-10

/**
 * Введение в дисциплину
 */
void volkovda::lab1()
{
	std::cout << "Hello, World!!!\n";
}


/**
 * Метод Гаусса с выбором главного элемента
 */

// Меняет местами строки СЛАУ
void row_swap(double **A, double *b, int N, int i, int j)
{
	double tmp;

	tmp = b[i];
	b[i] = b[j];
	b[j] = tmp;

	for (int k = 0; k < N; k++)
	{
		tmp = A[i][k];
		A[i][k] = A[j][k];
		A[j][k] = tmp;
	}
}

void volkovda::lab2()
{
	for (int k = 0; k < N; k++) {

		// Выбор ведущего элемента
		int d = k;
		for (int i = k + 1; i < N; i++) {
			if (abs(A[d][k]) < abs(A[i][k])) {
				d = i;
			}
		}

		// Меняем строки
		if (d != k) {
			row_swap(A, b, N, d, k);
		}

		// Система не определена
		if (A[k][k] < EPSILON) {
			std::cout << "System of linear equations has no solution.";
			return;
		}

		// Нормируем строку k
		b[k] /= A[k][k];
		for (int j = N - 1; j >= k; j--) {
			A[k][j] /= A[k][k];
		}

		// Приводим матрицу к диагональному виду на позиции k
		for (int i = 0; i < N; i++) {
			if (i != k) {
				b[i] -= A[i][k] * b[k];
				for (int j = N - 1; j >= k; j--) {
					A[i][j] -= A[i][k] * A[k][j];
				}
			}
		}
	}

	// Записываем результат в вектор x
	for (int i = 0; i < N; i++) {
		x[i] = b[i];
	}
}



/**
 * Метод прогонки
 */
void volkovda::lab3()
{

}



/**
 * Метод простых итераций
 */
void volkovda::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void volkovda::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void volkovda::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void volkovda::lab7()
{

}


void volkovda::lab8()
{

}


void volkovda::lab9()
{

}


std::string volkovda::get_name()
{
  return "Volkov Dmitry Alekseevich";
}
