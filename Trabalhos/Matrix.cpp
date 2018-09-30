#include <iostream>

using namespace std;


class Matrix{
protected:
    void allocate(int ***matrix, int linha, int coluna){
      int **mat;
      mat = new int*[linha];
      for(unsigned i=0;i<linha;i++){
        mat[i]=new int[coluna];
      }
      cout<<"Alocado"<<endl;
      *matrix=mat;
    }

    void deallocate(int **matrix){
      for(unsigned i=0;i<linha;i++){
        delete[] matrix[i];
      }
      delete[] matrix;
      cout<<"Desalocado com sucesso!"<<endl;
    }
public:
    Matrix(int linha, int coluna){ // construtor normal
        this->linha = linha;
        this->coluna = coluna;

        allocate(&matrix, linha, coluna);
    }

    ~Matrix(){ //destrutor

        deallocate(matrix);
    }

    Matrix(Matrix& objeto_a_copiar){ // construtor por cópia
        cout<<"Construtor por cópia"<<endl;
        this->linha = objeto_a_copiar.getLinha();
        this->coluna = objeto_a_copiar.getColuna();

        allocate(&matrix, linha, coluna);
         for(unsigned i=0; i< linha; i++){
            for(unsigned j=0; j< coluna; j++){
               matrix[i][j] = objeto_a_copiar[i][j];
            }
        }


    }


    int getLinha(){
        return linha;
    }

    int getColuna(){
        return coluna;
    }

    int *operator[](int l){
        return matrix[l];
    }

    Matrix& operator = (Matrix &objeto_a_copiar){ // operador assignment
        cout<<"Operador assignmet"<<endl;
        int l = objeto_a_copiar.getLinha();
        int c = objeto_a_copiar.getColuna();

        deallocate(matrix);
        allocate(&matrix, l, c);


        for(unsigned i=0; i< l; i++){
            for(unsigned j=0; j< c; j++){
               matrix[i][j] = objeto_a_copiar[i][j];
            }
        }
        this->linha = l;
        this->coluna = c;
        return *this;
    }

private:
    int **matrix;
    int linha;
    int coluna;

};

    void preencherMatriz(Matrix &mat){
        int l = mat.getLinha();
        int c = mat.getColuna();
        for(int i=0; i < l; i++){
            for(int j=0; j < c; j++){
                mat[i][j] =1;
            }
        }
    }


    void printarMatriz(Matrix &mat){
        int l = mat.getLinha();
        int c = mat.getColuna();
        for(int i=0; i < l; i++){
            for(int j=0; j < c; j++){
                cout<<mat[i][j] << " ";
            }
            cout<<endl;
        }
    }
int main()
{
    int linha;
    int coluna;
    cout<<"Entre com o número de linhas e colunas da matriz 1"<<endl;
    cin>>linha;
    cin>>coluna;
    cout<<endl;

    Matrix mat1(linha,coluna);
    preencherMatriz(mat1);
    printarMatriz(mat1);
    cout<<endl;
    mat1[0][0]=1;
    mat1[0][1]=2;
    mat1[1][0]=3;
    mat1[1][1]=4;

    printarMatriz(mat1);

    cout<<endl;

    cout<<"Entre com o número de linhas e colunas da matriz 2"<<endl;
    cin>>linha;
    cin>>coluna;
    cout<<endl;
    Matrix mat2(linha, coluna);
    mat2=mat1;
    printarMatriz(mat2);
    cout<<endl;

    Matrix mat3(mat2);
    printarMatriz(mat3);
    cout<<endl;


}
