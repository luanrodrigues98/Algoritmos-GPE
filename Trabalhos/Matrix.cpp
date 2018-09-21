#include <iostream>

using namespace std;


class Matrix{
public:
    Matrix(int linha, int coluna){
        this->linha = linha;
        this->coluna = coluna;

        mat = new int*[linha];

        for(int i=0;i<linha;i++){
            mat[i] = new int [coluna];
        }
    }

    ~Matrix(){
        for(int i=0; i < linha; i++){
            delete[]mat[i];
        }
        delete[]mat;
        cout<<"Desalocado com sucesso!"<<endl;
    }

    int getLinha(){
        return linha;
    }

    int getColuna(){
        return coluna;
    }

    int *operator[](int l){
        return mat[l];
    }
private:
    int **mat;
    int linha;
    int coluna;

};

void preencherMatriz(Matrix &mat, int l, int c){
    for(int i=0; i < l; i++){
        for(int j=0; j < c; j++){
            mat[i][j] =0;
        }
    }
}

void printarMatriz(Matrix &mat, int l, int c){
    for(int i=0; i < l; i++){
        for(int j=0; j < c; j++){
            cout<<mat[i][j] << " ";
        }
        cout<<endl;
    }
}
int main()
{
    Matrix mat1(10,10);
    preencherMatriz(mat1, mat1.getLinha(), mat1.getColuna());
    printarMatriz(mat1, mat1.getLinha(), mat1.getColuna());
    cout<<endl;
    mat1[0][0]=1;
    mat1[0][1]=2;
    mat1[1][0]=3;
    mat1[1][1]=4;
    printarMatriz(mat1, mat1.getLinha(), mat1.getColuna());
    cout<<endl;
    Matrix mat2(5,5);

    preencherMatriz(mat2, mat2.getLinha(), mat2.getColuna());
    printarMatriz(mat2, mat2.getLinha(), mat2.getColuna());
}
