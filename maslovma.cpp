#include "maslovma.h"

/**
 * Введение в дисциплину
 */
void maslovma::lab1()
{
  cout << "Hello world!" << endl;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void maslovma::lab2()
{

  double temp;
    int maxInd;

      for(int i=0;i<N-1;i++)
        {
         maxInd = i;

          for(int k=i+1;k<N;k++)
           {
            if(abs(A[k][i]) > abs(A[maxInd][i]))
              {
                maxInd = k;
              }
           }

           if (maxInd != i)
            {
              for(int k=i;k<N;k++)
               {
                std::swap(A[i][k],A[maxInd][k]);
               }
               std::swap(b[i],b[maxInd]);
            }

         for(int j=i+1;j<N;j++)
          {
             temp = A[j][i]/A[i][i];

             b[j] -= temp*b[i];

              for(int q=i;q<N;q++)
                {
                  A[j][q] -= temp*A[i][q];
                }
           }
        }

        for(int i=N-1;i>=0;i--)
         {
            b[i]/=A[i][i];

             for(int j=i-1;j>=0;j--)
              {
                b[j] -= b[i]*A[j][i];
              }

         }
    for(int i=0;i<N;i++)
         x[i] = b[i];
}



/**
 * Метод прогонки
 */
void maslovma::lab3()
{

}



/**
 * Метод простых итераций
 */
void maslovma::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void maslovma::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void maslovma::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void maslovma::lab7()
{

}


void maslovma::lab8()
{

}


void maslovma::lab9()
{

}


std::string maslovma::get_name()
{
  return "MaslovMA";
}
