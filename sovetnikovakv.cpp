#include "sovetnikovakv.h"

/**
 * Введение в дисциплину
 */
void sovetnikovakv::lab1()
{
	cout << "Hello World!" << endl;
}

//*****************************************************************

/**
 * Метод Гаусса с выбором главного элемента
 */

// Приближенное значение к 0
const double EPSILON = 1.e-12;

void sovetnikovakv::lab2()
{
	// Запоминаем позиции x при перестановке строк
	int *p = new int[N];
	for (int i = 0; i < N; i++) {
		p[i] = i;
	}

	// Прямой ход
	for (int k = 0; k < N; k++) {
		// Поиск ведущего элемента
		int s = k;
		for (int i = k + 1; i < N; i++) {
			if (std::abs(A[s][k]) < std::abs(A[i][k])) {
				s = i;
			}
		}

		// Меняем строки
		if (s != k) {
			std::swap(b[s], b[k]);
			std::swap(p[s], p[k]);
			for (int j = k; j < N; j++) {
				std::swap(A[s][j], A[k][j]);
			}
		}

		// Система не определена
		if (std::abs(A[k][k]) < EPSILON) {
			std::cout << "Система не определена." << std::endl;
			return;
		}

		// Нормируем k-ю строчку
		double tmp = A[k][k];

		b[k] /= tmp;
		for (int j = k; j < N; j++) {
			A[k][j] /= tmp;
		}

		// Приводим матрицу к верхне треугольному виду
		for (int i = k + 1; i < N; i++) {
			tmp = A[i][k];

			b[i] -= b[k] * tmp;
			for (int j = k; j < N; j++) {
				A[i][j] -= A[k][j] * tmp;
			}
		}
	}

	// Обратный ход
	for (int k = N - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			b[i] -= A[i][k] * b[k];
		}
	}

	// Записываем результат в вектор x
	for (int i = 0; i < N; i++) {
		x[i] = b[p[i]];
	}

	delete[] p;
}

//*****************************************************************

/**
 * Метод прогонки
 */
void sovetnikovakv::lab3()
{
	double *alph = new double[N];
	double *beta = new double[N];

	// Прямой ход
	alph[0] = -A[0][1] / A[0][0];
	beta[0] = b[0] / A[0][0];
	for (int i = 1; i < N; i++) {
		alph[i] = -A[i][i + 1] / (A[i][i - 1] * alph[i - 1] + A[i][i]);
		beta[i] = (b[i] - A[i][i - 1] * beta[i - 1]) / (A[i][i - 1] * alph[i - 1] + A[i][i]);
	}

	// Обратный ход
	x[N - 1] = beta[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		x[i] = alph[i] * x[i + 1] + beta[i];
	}

	delete[] alph;
	delete[] beta;
}



/**
 * Метод простых итераций
 */
void sovetnikovakv::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void sovetnikovakv::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void sovetnikovakv::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void sovetnikovakv::lab7()
{

}


void sovetnikovakv::lab8()
{

}


void sovetnikovakv::lab9()
{

}

std::string sovetnikovakv::get_name()
{
  return "sovetnikova Karina Vladislavovna";
}
