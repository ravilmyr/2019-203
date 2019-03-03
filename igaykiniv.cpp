#include "igaykiniv.h"

/**
 * Введение в дисциплину
 */
void igaykiniv::lab1()
{
	cout << "It's done" << endl;
	system("pause");
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void igaykiniv::lab2()
{
    double* temp = b;
	for (int i = 0, j = 0; (i < N - 1) && (j < N - 1); i++, j++)
	{
		int cur = i;
		double max = A[j][j];
		for (int num = j; num < N; num++)
			if (abs(max) < abs(A[num][j])) max = A[num][j];

		while (A[i][j] != max)
			i++;

		if (cur != i)
		{
			swap(temp[cur], temp[i]);
			swap(A[cur], A[i]);
			i = cur;
		}

		double t = 1/A[i][j];
		temp[i] *= t;
		for (int cj = j; cj < N; cj++)
			A[i][cj] *= t;

		for (int ci = i + 1; ci < N; ci++)
		{
			temp[ci] += temp[i] * (-A[ci][j]);
			t = -A[ci][j];
			for (int cj = j; cj < N; cj++)
			{
				A[ci][cj] += A[i][cj] * t;
			}
		}
	}

	for (int i = N - 1, j = N - 1; (i > 0) && (j > 0); i--, j--)
	{
		int cur = i;
		temp[i] *= 1 / A[i][j];
		A[i][j] *= 1 / A[i][j];
		for (int ci = i - 1; ci >= 0; ci--)
		{
			temp[ci] += temp[i] * (-A[ci][j]);
			A[ci][j] = 0;
		}
	}

	x = temp;
}



/**
 * Метод прогонки
 */
void igaykiniv::lab3()
{
    double* alpha = new double[N - 1];
    double* gamma = new double[N];
    for (int i = 0; i < N; i++)
    {
        gamma[i] = A[i][i];
        if (i != 0) gamma[i] += A[i][i - 1] * alpha[i - 1];
        if (i != N - 1) alpha[i] = -A[i][i + 1] / gamma[i];
        x[i] = b[i] / gamma[i];
        if (i != 0) x[i] -= (A[i][i - 1] * x[i - 1]) / gamma[i];
    }

    for (int i = N - 2; i >= 0; i--)
        x[i] += alpha[i] * x[i + 1];
}



/**
 * Метод простых итераций
 */
void igaykiniv::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void igaykiniv::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void igaykiniv::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void igaykiniv::lab7()
{

}


void igaykiniv::lab8()
{

}


void igaykiniv::lab9()
{

}


std::string igaykiniv::get_name()
{
  return "Igaykin I. V.";
}
