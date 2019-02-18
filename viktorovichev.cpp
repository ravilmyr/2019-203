#include "viktorovichev.h"

/**
 * Введение в дисциплину
 */
void viktorovichev::lab1()
{
cout<<"Hello world!";
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void viktorovichev::lab2()
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
void viktorovichev::lab3()
{

}



/**
 * Метод простых итераций
 */
void viktorovichev::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void viktorovichev::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void viktorovichev::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void viktorovichev::lab7()
{

}


void viktorovichev::lab8()
{

}


void viktorovichev::lab9()
{

}


std::string viktorovichev::get_name()
{
  return "Viktorovichev E.V";
}
