#include "kemaykinais.h"

/**
 * Введение в дисциплину
 */
void kemaykinais::lab1()
{
    cout << "Hello world!";
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void kemaykinais::lab2()
{
    double eps=0.00001;
    int lead;
    double maxElem, keep;
    int change[N];
    for (int i=0; i<N; i++){
        lead=i;
        for (int j=i+1; j<N; j++){
            if (abs(A[j][i])>abs(A[lead][i])){
                lead=j;
            }
        }
        if (abs(A[lead][i])<eps){
            cout<<"Нет решений";
            break;
        }
        change[i]=lead;
        if (lead!=i){
            swap(A[i],A[lead]);
            swap(b[i],b[lead]);
        }
        maxElem=A[i][i];
        A[i][i]=1;
        for (int j=i+1; j<N; j++){
            A[i][j]/=maxElem;
        }
        b[i]/=maxElem;
        for (int j=i+1; j<N; j++){
            keep=A[j][i];
            A[j][i]=0;
            for (int k=i+1; k<N; k++){
                A[j][k]-=A[i][k]*keep;
            }
            b[j]-=b[i]*keep;
        }
    }
    for (int i=N-1; i>=0; i--){
        for (int j=i-1; j>=0; j--){
            keep=A[j][i];
            A[j][i]=0;
            for (int k=i-1; k>=0; k--){
                A[j][k]-=A[i][k]*keep;
            }
            b[j]-=b[i]*keep;
        }
    }
    for (int i=0; i<N; i++){
        x[i]=b[i];
    }
    for (int i=N-1; i>=0; i--){
        if (change[i]!=i){
            swap(A[change[i]], A[i]);
            swap(b[change[i]], b[i]);
        }
    }
}



/**
 * Метод прогонки
 */
void kemaykinais::lab3()
{

}



/**
 * Метод простых итераций
 */
void kemaykinais::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void kemaykinais::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void kemaykinais::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void kemaykinais::lab7()
{

}


void kemaykinais::lab8()
{

}


void kemaykinais::lab9()
{

}


std::string kemaykinais::get_name()
{
  return "Kemaykina Irina";
}
