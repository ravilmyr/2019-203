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
   double* P = new double[N-1];
    double* Q = new double[N];

     P[0] = -A[0][1]/A[0][0];
     Q[0] = b[0]/A[0][0];

      for(int i=1;i<N-1;i++)
       {
         P[i] = -A[i][i+1]/(A[i][i]+A[i-1][i]*P[i-1]);
         Q[i] = (b[i] - A[i][i-1]*Q[i-1])/(A[i][i] + A[i][i-1]*P[i-1]);
       }
        Q[N-1] = (b[N-1] - A[N-1][N-2]*Q[N-2])/(A[N-1][N-1] + A[N-1][N-2]*P[N-2]);


       x[N-1] = Q[N-1];
        for(int i=N-2;i>=0;i--)
          {
            x[i] = P[i]*x[i+1]+Q[i];
          }


     delete [] P;
     delete [] Q;

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
