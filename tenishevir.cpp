#include "tenishevir.h"

/**
 * Введение в дисциплину
 */
void tenishevir::lab1()
{
  cout << "Hello world!" << endl;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void tenishevir::lab2()
{
    double p;
	int maxn;

    for (int k=0; k<N-1; k++){
        maxn = k;
        for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[maxn][k])) maxn = i; ///Выбор главного элемента
        std::swap(A[maxn], A[k]); ///Меняем строки местами
        std::swap(b[maxn], b[k]);

        for (int i=k+1; i<N; i++){
            p = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= p*A[k][j];
            b[i] -= p*b[k];
        }
    }

    for(int i = 0; i<N; i++){
        x[i]=b[i];
    }

    for (int i=N-1; i>=0; i--){
        for (int j=i+1;j<N;j++)
            x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}



/**
 * Метод прогонки
 */
void tenishevir::lab3()
{

}



/**
 * Метод простых итераций
 */
void tenishevir::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void tenishevir::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void tenishevir::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void tenishevir::lab7()
{

}


void tenishevir::lab8()
{

}


void tenishevir::lab9()
{

}


std::string tenishevir::get_name()
{
  return "Tenishev Ilya";
}
