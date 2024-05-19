// lab_1_1_v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "task.h"

constexpr int MaxLength = 30;
constexpr int MaxVolume = 15;

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

void GenerateMatrixC(int** matrix, int size)
{
    for (auto i = 0; i < size; i++)
    {
        for (auto j = i + 1; j < size; j++)
        {
            matrix[i][j] = 1 + rand() % MaxLength;
        }
    }
}

void GenerateMatrixQ(int** matrix, int size)
{
    for (auto i = 0; i < size; i++)
    {
        for (auto j = i + 1; j < size; j++)
        {
            matrix[i][j] = 1 + rand() % MaxVolume;
            matrix[j][i] = 1 + rand() % MaxVolume;
        }
    }
}

void PrintMatrix(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

bool CalculateVariant(int** matrixC, int** matrixQ, const std::vector<int>& in, std::vector<int>& min, int& rMin)
{
    int r = 0;
    for (auto i = 0; i < in.size(); i++)
    {
        for (auto j = i + 1; j < in.size(); j++)
        {
            r += matrixC[i][j] * (matrixQ[in[i] - 1][in[j] - 1] + matrixQ[in[j] -1][in[i] - 1]);
        }
    }
    //std::cout << r << '\n';
    if (r < rMin || rMin == -1)
    {
        CopyVector(in, min);
        rMin = r;
        return true;
    }
    return false;
}

int main()
{
    boost::timer::auto_cpu_timer t;
    std::srand(std::time(nullptr));

    int matrixSize = 11;

    // расстояние между местами назначения
    int** matrixC = GetCreatedMatrix(matrixSize);

    // объёмы ресурсов, перемещаемых между объектами
    int** matrixQ = GetCreatedMatrix(matrixSize);

    // инициализация матрицы расстояний
    //matrixC[0][1] = 1;
    //matrixC[0][2] = 2;
    //matrixC[1][2] = 3;
    GenerateMatrixC(matrixC, matrixSize);
    std::cout << "matrix C:\n";
    PrintMatrix(matrixC, matrixSize);
    std::cout << '\n';

    // инициализация матрицы перемещения ресурсов
    /*matrixQ[0][1] = 6;
    matrixQ[0][2] = 8;
    matrixQ[1][2] = 7;
    matrixQ[1][0] = 3;
    matrixQ[2][0] = 5;
    matrixQ[2][1] = 4;*/
    GenerateMatrixQ(matrixQ, matrixSize);
    std::cout << "matrix Q:\n";
    PrintMatrix(matrixQ, matrixSize);
    std::cout << '\n';

    // текущий вариант
    std::vector<int> queueP;

    // вариант с минимумом затрат
    std::vector<int> queuePmin;

    for (int i = 0; i < matrixSize; i++)
    {
        queueP.push_back(i + 1);
        queuePmin.push_back(i + 1);
    }

    // затраты варианта с минимумом затрат
    int rMin = -1;

    do
    {
//        copy(queueP.begin(), queueP.end(), std::ostream_iterator<size_t>(std::cout, " "));
        if (CalculateVariant(matrixC, matrixQ, queueP, queuePmin, rMin))
        {
        //CalculateVariant(matrixC, matrixQ, queueP, queuePmin, rMin);
            std::cout << "R = " << rMin << "; vector: ";
            copy(queueP.begin(), queueP.end(), std::ostream_iterator<size_t>(std::cout, " "));
            std::cout << std::endl;
        }
        
    } while (std::next_permutation(queueP.begin(), queueP.end()));

    for (int i = 0; i < queuePmin.size(); i++)
    {
        std::cout << queuePmin[i] << "\t";
    }
    std::cout << '\n';

    DestroyMatrix(matrixQ, matrixSize);
    DestroyMatrix(matrixC, matrixSize);

    return 0;
}
