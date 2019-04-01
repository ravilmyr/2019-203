#include "malovava.h"

/**
 * Введение в дисциплину
 */
void malovava::lab1()
{
cout<<"Hello world!!!"<<endl;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void malovava::lab2()
{
double Q = 0;
int max;
    for (int i = 0; i < N - 1; i++)
    {   max = i;
		for (int j = i + 1; j < N; j++)
		{
			if(abs(A[j][i]) > abs(A[max][i]))
			{  max = j;
			}
		}
            std::swap(A[max], A[i]);
		    std::swap(b[max], b[i]);

        for (int j = i + 1; j < N; j++)
        {
            Q = A[j][i] / A[i][i];
            for (int k = i; k < N; k++)
            {
                A[j][k] -= Q * A[i][k];
            }
            b[j] -= Q * b[i];
        }
    }

    for(int i = 0; i < N; i++)
	{
        x[i] = b[i];
	}

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < N; j++)
		{
			x[i] -= A[i][j] * x[j];
		}

     x[i] /= A[i][i];
	}

}



/**
 * Метод прогонки
 */
void malovava::lab3()
{

	double* P = new double[N]; // "альфа"
    double* Q = new double[N]; // "бетта"

    for (int i = 0; i < N; i++)
    {
        P[i] = 0;
        Q[i] = 0;
    }

    P[0] = -A[0][1] / A[0][0];
    Q[0] = b[0] / A[0][0];

    for(int i = 1; i < N; i++)
    {
        P[i] = A[i][i + 1] / (-A[i][i - 1] * P[i - 1] - A[i][i]);
        Q[i] = (-b[i] + A[i][i - 1] * Q[i - 1]) / (-A[i][i - 1] * P[i - 1] - A[i][i]);
    }

    x[N - 1] = Q[N - 1];

    for(int i = N - 2; i >= 0; i--)
	{
        x[i] = P[i] * x[i + 1] + Q[i];
	}

	delete[] P;
	delete[] Q;
}



/**
 * Метод простых итераций
 */
void malovava::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void malovava::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void malovava::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void malovava::lab7()
{

}


void malovava::lab8()
{

}


void malovava::lab9()
{

}


std::string malovava::get_name()
{
  return "Malova V.A.";
}
