#include "makarovaaa.h"

/*void systemout(double **A, double *b, int N) //вывод уравнений
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << A[i][j] << "*x" << j;
      if (j < N - 1)
        cout << " + ";
    }
    cout << " = " << b[i] << endl;
  }
  return;
}*/

double * gauss(double **A, double *b, int N)
{
  double *x, max;
  int k, index;
  const double eps = 0.00001;
  x = new double[N];
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
  return x;
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
  //systemout(A, b, N);
  x = gauss(A, b, N);

}



/**
 * Метод прогонки
 */
void makarovaaa::lab3()
{

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
