#include "kiselevis.h"

/**
 * Введение в дисциплину
 */
void kiselevis::lab1()
{
	cout << "Hello, world!" << endl;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void kiselevis::lab2()
{
double epsilon = 1.e-10;
	int *BeforeSwaped = new int[N];
	for (int i = 0; i < N; i++)
	{
		BeforeSwaped[i] = i;
	}
	for (int i = 0; i < N; i++)
	{
		int MaxIndex = i;
		for (int j = i+1; j < N; j++)
		{
			if (abs(A[j][i]) > abs(A[MaxIndex][i]))
			{
				MaxIndex = j;
			}
		}
		if (MaxIndex != i)
		{
			swap(A[MaxIndex], A[i]);
			swap(b[MaxIndex], b[i]);
			swap(BeforeSwaped[MaxIndex], BeforeSwaped[i]);
		}
		if (abs(A[i][i]) < epsilon)
		{
			cout << "NULL" << endl;
			return;
		}
		b[i] /= A[i][i];
		for (int j = N - 1; j >= i; j--)
		{
			A[i][j] /= A[i][i];
		}
		
		for (int j = 0; j < N; j++)
		{
			if (j != i)
			{
				b[j] -= A[j][i] * b[i];
				for (int k = N-1; k >= i; k--)
				{
					A[j][k] -= A[j][i] * A[i][k];
				}
				
			}

		}
	}
	for (int i = 0; i < N; i++) {
		x[i] = b[i];
	}
	for (int i = 0; i < N; i++) {
		if (BeforeSwaped[i] != i) {
			swap(A[BeforeSwaped[i]], A[i]);
			swap(b[BeforeSwaped[i]], b[i]);
		}
	}
	
	delete[] BeforeSwaped;
}



/**
 * Метод прогонки
 */
void kiselevis::lab3()
{

}



/**
 * Метод простых итераций
 */
void kiselevis::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void kiselevis::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void kiselevis::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void kiselevis::lab7()
{

}


void kiselevis::lab8()
{

}


void kiselevis::lab9()
{

}


std::string kiselevis::get_name()
{
  return "Kiselev Ilya Sergeevich";
}
