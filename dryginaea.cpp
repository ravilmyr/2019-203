#include "dryginaea.h"
#define  eps 0.0001

/**
 * Введение в дисциплину
 */
void dryginaea::lab1()
{
	cout << "Hello world!" << endl;
}



/**
 * Метод Гаусса с выбором главного элемента
 */

void change(double** a, double* b, int* shift, int line1, int line2, int n)
{
	double temp;
	int temp1;

	for (int i = 0; i < n; i++)
	{
		temp = a[line1][i];
		a[line1][i] = a[line2][i];
		a[line2][i] = temp;
	}

	temp = b[line1];
	b[line1] = b[line2];
	b[line2] = temp;

	temp1 = shift[line1];
	shift[line1] = shift[line2];
	shift[line2] = temp1;
}

void dryginaea::lab2()
{
	double diagonal, temp;
	int max;
	int shift[N];

	for (int i = 0; i < N; i++)
	{
		shift[i] = i;
	}

	for (int i = 0; i < N; i++)
	{
		max = i;

		for (int l = i; l < N; l++)
		{
			if (abs(A[l][i]) > abs(A[max][i]))
			{
				max = l;
			}
		}

		if (fabs(A[max][i]) > eps)
		{
			change(A, b,shift,i, max, N);
		}

		diagonal = A[i][i];
		A[i][i] = 1;

		for (int j = i + 1; j < N; j++)
		{
			A[i][j] /= diagonal;
		}

		b[i] /= diagonal;

		for (int j = i + 1; j < N; j++)
		{
			temp = A[j][i];
			A[j][i] = 0;

			for (int k = i + 1; k < N; k++)
			{
				A[j][k] -= A[i][k] * temp;
			}

			b[j] -= b[i] * temp;
		}
	}

    for (int i = N - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			temp = A[j][i];

			for (int k = i; k >= 0; k--)
			{
				A[j][k] -= A[i][k] * temp;
			}

			b[j] -= b[i] * temp;
		}
	}

	for (int i = 0; i < N; i++)
	{
		x[shift[i]] = b[i];
	}
}




/**
 * Метод прогонки
 */
void dryginaea::lab3()
{

}



/**
 * Метод простых итераций
 */
void dryginaea::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void dryginaea::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void dryginaea::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void dryginaea::lab7()
{

}


void dryginaea::lab8()
{

}


void dryginaea::lab9()
{

}


std::string dryginaea::get_name()
{
  return "Drygina E.A.";
}
