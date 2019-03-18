#include "shmelevaov.h"
const double eps = 1.e-15;
/**
 * Введение в дисциплину
 */
void shmelevaov::lab1()
{
	cout << "Hello World!";
}


/**
 * Метод Гаусса с выбором главного элемента
 */

 void change_lines (double **A, double *b, int first_line, int second_line, int N, int *help)
{
    for (int i = first_line; i < N; i++)
    {
        swap(A[first_line][i], A[second_line][i]);
    }

    swap(b[first_line], b[second_line]);

    swap(help[second_line], help[first_line]);
}

void shmelevaov::lab2()
{
    int *help = new int[N];
	for (int i = 0; i < N; i++)
    {
		help[i] = i;
    }

    for (int i = 0; i < N; i++)
    {
        int maximum = i;
        for (int j = i; j < N; j++)
        {
            if (fabs(A[j][i]) > fabs(A[maximum][i]))
            {
                maximum = j;
            }
        }

        if (fabs(A[maximum][i]) > eps)
        {
           change_lines(A, b, i, maximum, N, help);
        }

        double diagonal = A[i][i];

        A[i][i] = 1;

        for (int j = i + 1; j < N; j++)
        {
            A[i][j] /= diagonal;
        }

        b[i] /= diagonal;

        for (int j = i + 1; j < N; j++)
        {
            double temp = A[j][i];
            A[j][i] = 0;
            for(int k = i + 1; k < N; k++)
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
			double temp = A[j][i];			
			A[j][i] -= A[i][i] * temp;
			b[j] -= b[i] * temp;
		}
	}

    for (int i = 0; i < N; i++)
    {
		x[help[i]] = b[i];
	}
}



/**
 * Метод прогонки
 */
void shmelevaov::lab3()
{
	double alpha[N - 1], beta[N];
    alpha[0]= - A[0][1] / A[0][0];
    beta[0]= b[0] / A[0][0];
	
    for (int i = 1; i < N; i++)
	{
		double y = A[i][i] + A[i][i - 1] * alpha[i - 1];
        alpha[i] = - A[i][i + 1] / y;
        beta[i] = (b[i] - A[i][i - 1] * beta[i - 1]) / y;
    }

    x[N - 1] = beta[N - 1];
    for (int i = N - 2; i >= 0; i--)
	{
        x[i] = alpha[i] * x[i + 1] + beta[i];
    }
}



/**
 * Метод простых итераций
 */
void shmelevaov::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void shmelevaov::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void shmelevaov::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void shmelevaov::lab7()
{

}


void shmelevaov::lab8()
{

}


void shmelevaov::lab9()
{

}


std::string shmelevaov::get_name()
{
  return "Shmeleva O. V.";
}
