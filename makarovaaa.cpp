#include "makarovaaa.h"

double * gauss(double **A, double *b, int N)
{
  double *x, max;
  int k, index;
  const double eps = 0.00001;
  x = new double[N]; double change[N]; int L;
  k = 0;
  while (k < N)
  {
    max = abs(A[k][k]);
    index = k;
    for (int i = k + 1; i < N; i++)
    {
      if (abs(A[i][k]) > max)
      {
        max = abs(A[i][k]);
        index = i;
      }
    }

    if (max < eps)
    {
      cout << "Решение получить невозможно из-за нулевого столбца ";
      cout << index << " матрицы A" << endl;
      return 0;
    }
    for (int i = 0; i < N; i++)
    {
    change[i]=index;
    if(index!=i) {swap(A[i],A[index]);
                  swap(b[i],b[index]); }

    for (int j = 0; j < N; j++)
    {
      double temp = A[k][j];

      A[k][j] = A[index][j];
      A[index][j] = temp;
    }
    double temp = b[k];
    b[k] = b[index];
    b[index] = temp;

    for (int i = k; i < N; i++)
    {
      double temp = A[i][k];
      if (abs(temp) < eps) continue;
      for (int j = 0; j < N; j++)
        A[i][j] = A[i][j] / temp;
      b[i] = b[i] / temp;
      if (i == k)  continue;
      for (int j = 0; j < N; j++)
        A[i][j] = A[i][j] - A[k][j];
      b[i] = b[i] - b[k];
    }
    k++;
  }
  for (k = N - 1; k >= 0; k--)
  {
    x[k] = b[k];
    for (int i = 0; i < k; i++)
      b[i] = b[i] - A[i][k] * x[k];
  }
   for (int i = N-1; i >= 0; i--) { if (index!=i) {L = change[i];
                                              swap(A[L], A[i]);
                                              swap(b[L], b[i]); } }
  return x;
}
}

/**
 * Введение в дисциплину
 */
void makarovaaa::lab1()
{
cout<<"Hello, World!"<<endl;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void makarovaaa::lab2()
{
  system("chcp 1251");
  system("cls");
  x = gauss(A, b, N);

}



/**
 * Метод прогонки
 */
void makarovaaa::lab3()
{
//Это частный случай для метода Гаусса, используется, когда матрица трёхдиагональная
double *up, *mid, *low;  
up = new double[N]; 
mid = new double[N]; 
low = new double[N]; 
double k; 

low[0] = 0; 
up[N-1] = 0; 

for (int i = 0; i < N; i++)//Заполняем "диагональные" массивы 
{ 
	if (i - 1 >= 0 && i - 1 < N) 
	up[i] = A[i-1][i];  
	mid[i] = A[i][i];  
	if (i + 1 >= 0 && i + 1 < N) 
	low[i] = A[i+1][i];  
} 
//Прямая прогонка 
for (int i = 1; i < N; i++) //Вычисляем коэффициенты прогонки 
{ 
	k = low[i]/mid[i-1]; 
	mid[i] = mid[i] - k*up[i-1]; 
	b[i] = b[i] - k*b[i-1]; 
} 

//Обратная прогонка 
x[N-1] = b[N-1]/mid[N-1];

for (int i = N - 2; i >= 0; i--) 
	x[i]=(b[i]-up[i]*x[i+1])/mid[i]; 

delete[] up;
delete[] mid; 
delete[] low; 
}



/**
 * Метод простых итераций
 */
void makarovaaa::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void makarovaaa::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void makarovaaa::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void makarovaaa::lab7()
{

}


void makarovaaa::lab8()
{

}


void makarovaaa::lab9()
{

}


std::string makarovaaa::get_name()
{
  return "Makarova Anna Alekseevna";
}
