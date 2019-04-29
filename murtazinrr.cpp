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
 */void  emurtazinrr :: lab2 ()
{
двойной р;
    int maxn;

    для ( int k = 0 ; k <N- 1 ; k ++)
    {
        maxn = k;
        для ( int i = k + 1 ; i <N; i ++)
            if ( abs (A [i] [k])> abs (A [maxn] [k])) maxn = i;
        std :: swap (A [maxn], A [k]);
        std :: swap (b [maxn], b [k]);

        для ( int i = k + 1 ; i <N; i ++)
        {
            p = A [i] [k] / A [k] [k];
            для ( int j = k; j <N; j ++)
                A [i] [j] - = p * A [k] [j];
            b [i] - = p * b [k];
        }
    }

    для ( int i = 0 ; i <N; i ++)
    {
        х [I] = Ь [I];
    }

    для ( int i = N- 1 ; i> = 0 ; i--)
    {
        для ( int j = i + 1 ; j <N; j ++)
            х [г] - = А [I] [J] * х [J];
        x [i] / = A [i] [i];
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
