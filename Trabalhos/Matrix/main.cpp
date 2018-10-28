#include <iostream>
#include <gtest/gtest>
#include "Matrix.cpp"
#include "Matrix.h"
#include "testes.h"

using namespace std

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    Matrix mat (2,2);
    preencherMatriz(mat);
    printarMatriz(mat);

    return RUN_ALL_TESTS();

    //Mudança na main para inclusao dos testes.
}
