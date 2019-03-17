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
