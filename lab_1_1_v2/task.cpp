// lab_1_1_v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"

int** GetCreatedMatrix(int size)
{
    int** matrix{ new int* [size] {} };
    for (int i{}; i < size; i++)
    {
        matrix[i] = new int[size] {};
    }
    return matrix;
}

void DestroyMatrix(int** matrix, int size)
{
    for (int i{}; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void CopyVector(const std::vector<int>& in, std::vector<int>& out)
{
    for (int i = 0; i < in.size(); i++)
    {
        out[i] = in[i];
    }
}

int main()
{
    int matrixSize = 5;

    // расстояние между местами назначения
    int** matrixC = GetCreatedMatrix(matrixSize);

    // объёмы ресурсов, перемещаемых между объектами
    int** matrixQ = GetCreatedMatrix(matrixSize);

    // текущий вариант
    std::vector<int> queueP;

    // вариант с минимумом затрат
    std::vector<int> queuePmin;

    for (int i = 0; i < matrixSize; i++)
    {
        queueP.push_back(i + 1);
        queuePmin.push_back(i + 1);
    }

    //CopyVector(queueP, queuePmin);


    for (int i = 0; i < queuePmin.size(); i++)
    {
        std::cout << queuePmin[i] << "\t";
    }
    std::cout << '\n';

    /*
    // затраты текущего варианта и варианта с минимумом затрат
    int r, rMin;

    // вывод данных
    for (int i{}; i < matrixSize; i++)
    {
        // выводим данные столбцов i-й строки
        for (int j{}; j < matrixSize; j++)
        {
            std::cout << matrixC[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    */

    DestroyMatrix(matrixQ, matrixSize);
    DestroyMatrix(matrixC, matrixSize);

    return 0;
}
