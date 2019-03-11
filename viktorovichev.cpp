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

}



/**
 * Метод прогонки
 */
void viktorovichev::lab3()
{
double *P = new double [N]; ///Коэффициенты "альфа"
	double *Q = new double [N]; ///Коэффициенты "бетта"

	P[0] = -A[0][1]/A[0][0];
	Q[0] = b[0]/A[0][0];

	for(int i=1; i<N; i++) ///Определяем прогоночные коэффициенты
	{
		P[i] = A[i][i+1]/(-A[i][i] - A[i][i-1]*P[i-1]);
		Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i] - A[i][i-1]*P[i-1]);
	}

	x[N-1] = Q[N-1];
	for(int i=N-2; i>=0; i--) ///Определяем решение
		x[i] = P[i]*x[i+1] + Q[i];

	delete [] P;
	delete [] Q;
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
