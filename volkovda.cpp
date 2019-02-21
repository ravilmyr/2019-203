#include "volkovda.h"

constexpr double EPSILON = 1.e-10;



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
void volkovda::lab2()
{
	// Отслеживаем позиции вектора x
	int *p = new int[N];
	for (int i = 0; i < N; i++) {
		p[i] = i;
	}

	for (int k = 0; k < N; k++) {

		// Выбор ведущего элемента
		int d = k;
		for (int i = k + 1; i < N; i++) {
			if (std::abs(A[d][k]) < std::abs(A[i][k])) {
				d = i;
			}
		}

		// Меняем строки
		if (d != k) {
			for (int j = k; j < N; j++) {
				std::swap(A[d][j], A[k][j]);
			}
			std::swap(p[d], p[k]);
			std::swap(b[d], b[k]);
		}

		// Система не определена
		if (std::abs(A[k][k]) < EPSILON) {
			std::cout << "System of linear equations has no solution.\n";
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

	// Записываем результат в вектор x с учетом измененных позиций
	for (int i = 0; i < N; i++) {
		x[i] = b[p[i]];
	}

	delete[] p;
}



/**
 * Метод прогонки
 */
void volkovda::lab3()
{
	double *v = new double[N];
	double *w = new double[N];

	// Прямой ход
	v[0] = -A[0][1] / A[0][0];
	w[0] = b[0] / A[0][0];
	for (int i = 1; i < N; i++) {
		v[i] = -A[i][i + 1] / (A[i][i] + A[i][i - 1] * v[i - 1]);
		w[i] = (b[i] - A[i][i - 1] * w[i - 1]) / (A[i][i] + A[i][i - 1] * v[i - 1]);
	}

	// Обратный ход
	x[N - 1] = w[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		x[i] = v[i] * x[i + 1] + w[i];
	}

	delete[] v;
	delete[] w;
}



/**
 * Метод простых итераций
 */
void volkovda::lab4()
{
	// Вектор значений x на предыдущий итерации
	double *px = new double[N];
	for (int i = 0; i < N; i++) {
		px[i] = 0.0;
	}

	/*int iteration = 0;*/
	while (true) {
		/*iteration++;*/

		// Посчитаем значения неизвестных на текущей итерации
		for (int i = 0; i < N; i++) {
			x[i] = b[i];

			// Вычислим сумму по всем отличным от i-ой неизвестной
			for (int j = 0; j < N; j++) {
				if (i != j) {
					x[i] -= A[i][j] * px[j];
				}
			}

			// Делим на коэффициент при i-ой неизвестной
			x[i] /= A[i][i];
		}

		// Посчитаем максимальную по модулю погрешность
		// относительно педыдущей итерации
		double error = 0.0;
		for (int i = 0; i < N; i++) {
			if (std::abs(x[i] - px[i]) > error) {
				error = std::abs(x[i] - px[i]);
			}
		}

		// При достижении необходимой точности завершаем процесс
		if (error < EPSILON) {
			break;
		}

		// Текущее зачение итерации представим как предыдущее
		for (int i = 0; i < N; i++) {
			px[i] = x[i];
		}
	}

	/*std::cout << "Number of iterations : " << iteration << '\n';*/

	delete[] px;
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
