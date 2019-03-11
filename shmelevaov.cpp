#include "shmelevaov.h"

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

 void change_lines (double **A, double *x, int first_line, int second_line, int N)
{
    for (int i = first_line; i < N; i++)
    {
        double temp = A[first_line][i];
        A[first_line][i] = A[second_line][i];
        A[second_line][i] = temp;
    }

    double temp = x[second_line];
    x[second_line] = x[first_line];
    x[first_line] = temp;
}

void shmelevaov::lab2()
{
    double eps = 0.00000001;

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
           change_lines(A, b, i, maximum, N);
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

    x = b;
}



/**
 * Метод прогонки
 */
void shmelevaov::lab3()
{

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
