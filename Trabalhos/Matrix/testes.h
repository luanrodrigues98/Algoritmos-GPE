#include <gtest/gtest.h>

// Testes para verificar a funcionalidade dos overloads.

TEST(MATRIX, get_linhas){
     Matrix mat(2,2);
     ASSERT_EQ(2, mat.getLinhas());
}
TEST(MATRIX, get_colunas){
     Matrix mat(2,8);
     ASSERT_EQ(5, mat.getColunas());
}
TEST(MATRIX, operator_assigment){
     Matrix mat(2,2);
     Matrix mat2(2,2);
     for(int i = 0; i < 2; i++){
 	for(int j = 0; j < 2; j++){
	    mat[i][j] = 2;
            mat2[i][j] = 3;
        }
     }
     mat = mat2;
     ASSERT_EQ(3, mat[0][1]);
}
TEST(MATRIX, operator_brackets){
     Matrix mat (2,2);
     mat[0][1] = 54;
     ASSERT_EQ(54, mat[0][1]);
}

TEST(MATRIX, operator_plus){
     Matrix mat(2,2);
     Matrix mat2(2,2);
     Matrix mat_plus(2,2);

     for(int i = 0; i < 2; i++){
 	for(int j = 0; j < 2; j++){
	    mat[i][j] = 2;
            mat2[i][j] = 2;
        }
     }
     mat_plus(2,2); = mat + mat2;
     ASSERT_EQ(4, mat_plus[0][1]);
}

TEST(MATRIX, operator_less){
     Matrix mat(2,2);
     Matrix mat2(2,2);
     Matrix mat_less(2,2);

    for(int i = 0; i < 2; i++){
 	for(int j = 0; j < 2; j++){
	    mat[i][j] = 2;
            mat2[i][j] = 2;
        }
     }
     mat_less; = mat - mat2;
     ASSERT_EQ(0, mat_less[0][1]);
}


TEST(MATRIX, operator_multiplication){
     Matrix mat(2,2);
     Matrix mat2(2,2);
     Matrix mat_multiplication(2,2);
     for(int i = 0; i < 2; i++){
 	for(int j = 0; j < 2; j++){
	    mat[i][j] = 2;
            mat2[i][j] = 2;
        }
     }
     mat_multiplication = mat * mat2;
     ASSERT_EQ(8, mat_multiplication[0][1]);
}
