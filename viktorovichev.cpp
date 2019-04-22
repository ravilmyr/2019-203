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
double eps = 1e-15; //чтобы выйти из цикла
double t = 1e-5; //(приближенный парметр) достаточно малое число, ПРИ ПОИМОМЩИ КОТОРОГО МЫ ПОЛУЧАЕМ КАЖДЫЙ РАЗ ВСЁ БОЛЕЕ И БОЛЕЕ ТОЧНОЕ ЧИСЛО

for (int i = 0; i < N; i++) //берем первое приближенное значение и прогоняем его
    {
		x[i] = 0;
	}

	double x1;
	double *xr = new double[N];//рассчитываем новые значения x-ов
	int step = 0;

	do {
		step++;

		for (int i = 0; i < N; i++) //рассчитываем новое точное значение в цикле
        {
			xr[i] = x[i];
			for (int k = 0; k < N; k++)
				xr[i] -= t*A[i][k] * x[k];
			xr[i] += t * b[i];

		}

		x1 = 0;
		for (int i = 0; i < N; i++) { //рассчитываем норму (с её помощью ведем учет того, что значение достаточно близкое к необходимое)
			x1 += (xr[i]-x[i])*(xr[i]-x[i]);
		}

		for (int i = 0; i < N; i++)
        {
			x[i] = xr[i]; //осуществляем перепресвоение, новое становится старым и мы возобновляем цикл
		}
	}
	while (sqrt(x1)>eps); //как меньш8е, то выходим из цимкла
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
