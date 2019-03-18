#include "murtazinrr.h"

/**
 * Введение в дисциплину
 */
void murtazinrr::lab1()
{
cout <<"Hello world" << endl;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void murtazinrr::lab2()
{
  двойной p;
	int maxn;

    для (int k= 0; k<n-1; k++)
    {
 maxn = k;
        for (int i=k+ 1; i)
			если (abs (a[i][k]) > > abs (a[maxn][k])) maxn = i; 
        std:: swap (a[maxn], A[k]); 
        std:: swap (b[maxn], b[k]);

        for (int i=k+ 1; i)
        {
 p = a[i][k] / a[k][k];
            for (int j=k; j)
 A[i] [j] - = p*A[k][j];
 b[i] - = p*b[k];
        }
    }

    for (int i = 0; i)
    {
 x [i]=b[i];
    }

    для (int i=N-1; i> = > 0 ; i--)
    {
        for (int j=i+ 1; j)
 x[i]-=a[i] [j]*x[j];
 x [i] / = a[i][i];
    }
}



/**
 * Метод прогонки
 */
void murtazinrr::lab3()
{

}



/**
 * Метод простых итераций
 */
void murtazinrr::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void murtazinrr::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void murtazinrr::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void murtazinrr::lab7()
{

}


void murtazinrr::lab8()
{

}


void murtazinrr::lab9()
{

}


std::string murtazinrr::get_name()
{
  return "Murtazin R.R.";
}
