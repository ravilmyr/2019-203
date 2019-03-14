#include "igaykiniv.h"

/**
 * Введение в дисциплину
 */
void igaykiniv::lab1()
{
	cout << "It's done" << endl;
	system("pause");
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void igaykiniv::lab2()
{
    double* temp = b;
	for (int i = 0, j = 0; (i < N - 1) && (j < N - 1); i++, j++)
	{
		int cur = i;
		double max = A[j][j];
		for (int num = j; num < N; num++)
			if (abs(max) < abs(A[num][j])) max = A[num][j];

		while (A[i][j] != max)
			i++;

		if (cur != i)
		{
			swap(temp[cur], temp[i]);
			swap(A[cur], A[i]);
			i = cur;
		}

		double t = 1/A[i][j];
		temp[i] *= t;
		for (int cj = j; cj < N; cj++)
			A[i][cj] *= t;

		for (int ci = i + 1; ci < N; ci++)
		{
			temp[ci] += temp[i] * (-A[ci][j]);
			t = -A[ci][j];
			for (int cj = j; cj < N; cj++)
			{
				A[ci][cj] += A[i][cj] * t;
			}
		}
	}

	for (int i = N - 1, j = N - 1; (i > 0) && (j > 0); i--, j--)
	{
		int cur = i;
		temp[i] *= 1 / A[i][j];
		A[i][j] *= 1 / A[i][j];
		for (int ci = i - 1; ci >= 0; ci--)
		{
			temp[ci] += temp[i] * (-A[ci][j]);
			A[ci][j] = 0;
		}
	}

	x = temp;
}



/**
 * Метод прогонки
 */
void igaykiniv::lab3()
{
    double* alpha = new double[N - 1];
    double* gamma = new double[N];
    for (int i = 0; i < N; i++)
    {
        gamma[i] = A[i][i];
        if (i != 0) gamma[i] += A[i][i - 1] * alpha[i - 1];
        if (i != N - 1) alpha[i] = -A[i][i + 1] / gamma[i];
        x[i] = b[i] / gamma[i];
        if (i != 0) x[i] -= (A[i][i - 1] * x[i - 1]) / gamma[i];
    }

    for (int i = N - 2; i >= 0; i--)
        x[i] += alpha[i] * x[i + 1];

    delete[] alpha;
    delete[] gamma;
}



/**
 * Метод простых итераций
 */
void igaykiniv::lab4()
{
    double *new_x = new double[N], tau = 0.001, eps = 0.0000001;
    for (int i = 0; i < N; i++)
        x[i] = 0;

    do
    {
        for (int i = 0; i < N; i++)
        {
            double temp = 0;
            for (int j = 0; j < N; j++)
                temp += A[i][j] * x[j];

            new_x[i] = x[i] + tau * (b[i] - temp);
        }

        double maxdif = 0;
        for (int i = 0; i < N; i++)
        {
            if (fabs(x[i] - new_x[i]) > maxdif) maxdif = fabs(x[i] - new_x[i]);
            x[i] = new_x[i];
        }

        if (maxdif < eps) break;
    }while(true);

    delete[] new_x;
}



/**
 * Метод Якоби или Зейделя
 */
void igaykiniv::lab5()
{
    double *new_x = new double[N], eps = 0.0000001;
    bool condition;
    for (int i = 0; i < N; i++)
        x[i] = 1;

    do
    {
        condition = false;
        for (int i = 0; i < N; i++)
        {
            new_x[i] = b[i];
            for (int j = 0; j < N; j++)
            {
                if (i == j) continue;
                new_x[i] -= A[i][j]*x[j];
            }

            new_x[i] /= A[i][i];
            if (!condition) condition = (fabs(new_x[i] - x[i]) > eps);
            x[i] = new_x[i];
        }

    }while(condition);

    delete[] new_x;
}



/**
 * Метод минимальных невязок
 */
void igaykiniv::lab6()
{
    double *new_x = new double[N], *r = b, eps = 0.0000001;
    for (int i = 0; i < N; i++)
    {
        x[i] = 0;
        for (int j = 0; j < N; j++)
            r[i] -= A[i][j] * x[j];
    }

    do
    {
        double tau, P = 0, Q = 0, t;
        for (int i = 0; i < N; i++)
        {
            t = 0;
            for (int j = 0; j < N; j++)
                t += A[i][j] * r[j];


            P += r[i] * t;
            Q += t * t;
        }

        tau = P / Q;
        for (int i = 0; i < N; i++)
        {
            double temp = 0;
            for (int j = 0; j < N; j++)
                temp += A[i][j] * x[j];

            new_x[i] = x[i] + tau * (b[i] - temp);
        }

        for (int i = 0; i < N; i++)
        {
            double temp = 0;
            for (int j = 0; j < N; j++)
                temp += A[i][j] * x[j];

            new_x[i] = x[i] + tau * (b[i] - temp);
        }

        for (int i = 0; i < N; i++)
        {
            double temp = 0;
            for (int j = 0; j < N; j++)
                temp += A[i][j] * new_x[j];

            r[i] = b[i] - temp;
        }

        double maxdif = 0;
        for (int i = 0; i < N; i++)
        {
            if (fabs(x[i] - new_x[i]) > maxdif) maxdif = fabs(x[i] - new_x[i]);
            x[i] = new_x[i];
        }

        if (maxdif < eps) break;
    }while(true);

    delete[] new_x;
    delete[] r;
}



/**
 * Метод сопряженных градиентов
 */
void igaykiniv::lab7()
{

}


void igaykiniv::lab8()
{

}


void igaykiniv::lab9()
{

}


std::string igaykiniv::get_name()
{
  return "Igaykin I. V.";
}
