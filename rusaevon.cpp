#include "rusaevon.h"

/**
 * Введение в дисциплину
 */
void rusaevon::lab1()
{
cout<<"Hello world!";
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void rusaevon::lab2()
{
 double p;
	int maxn;

    for (int k=0; k<N-1; k++)
    {
        maxn = k;
        for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[maxn][k])) maxn = i; 
        std::swap(A[maxn], A[k]); 
        std::swap(b[maxn], b[k]);

        for (int i=k+1; i<N; i++)
        {
            p = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= p*A[k][j];
            b[i] -= p*b[k];
        }
}



/**
 * Метод прогонки
 */
void rusaevon::lab3()
{

}



/**
 * Метод простых итераций
 */
void rusaevon::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void rusaevon::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void rusaevon::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void rusaevon::lab7()
{

}


void rusaevon::lab8()
{

}


void rusaevon::lab9()
{

}


std::string rusaevon::get_name()
{
  return "Ruzaev O.N.";
}
