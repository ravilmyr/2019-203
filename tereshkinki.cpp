#include "tereshkinki.h"

/**
 * Введение в дисциплину
 */
void tereshkinki::lab1()
{
cout<<"Hello World!!";
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void tereshkinki::lab2()
{
 double p;
	int maxn;

    for (int k=0; k<N-1; k++)
    {
        maxn = k;
        for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[maxn][k])) maxn = i; ///Выбор главного элемента
        std::swap(A[maxn], A[k]); ///Меняем строки местами
        std::swap(b[maxn], b[k]);

        for (int i=k+1; i<N; i++)
        {
            p = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= p*A[k][j];
            b[i] -= p*b[k];
        }
    }

    for(int i = 0; i<N; i++)
    {
        x[i]=b[i];
    }

    for (int i=N-1; i>=0; i--)
    {
        for (int j=i+1;j<N;j++)
            x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}



/**
 * Метод прогонки
 */
void tereshkinki::lab3()
{

}



/**
 * Метод простых итераций
 */
void tereshkinki::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void tereshkinki::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void tereshkinki::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void tereshkinki::lab7()
{

}


void tereshkinki::lab8()
{

}


void tereshkinki::lab9()
{

}


std::string tereshkinki::get_name()
{
  return "Tereshkin Kirill Igorevich";
}
