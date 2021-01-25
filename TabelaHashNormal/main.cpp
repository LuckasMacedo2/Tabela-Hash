#include <iostream>
using namespace std;
/*Metodo da divisão*/
int hk(int k,  int m){
    return (k%m);
}

/*Metodo da multiplicação*/
int hk1 (int k, int m){
    int kA = k*0.05;
    return (m*(kA%1));
}

/*Sondagem linear*/
int h(int k, int i, int m){
    return ((hk(k,m)+i)%m);
}


/*Sondagem quadratica*/
int h1(int k, int i, int m){
    int c1 = 1;
    int c2 = 2;
    return ((h(k,i,m)+c1*i+c2*i*i)%m);
}

/*Hash Duplo*/
int h2(int k, int i, int m){
    return (hk(k,m)+i*(1+(k%(m-1))));
}

bool inserir (int k, int A[], int dim){
    int i = 0;
    int j = h(k,i,dim);
    while (i<dim){
        if(A[j]==-1 || A[j]==-2){
            A[j]=k;
            return true;
        }
        else{
            i++;
            j=h(k,i,dim);
        }

    }
    return false;
}

int pesquisar (int k, int A[], int dim){
    int i = 0;
    int j = h(k,i,dim);
    while(i<dim && A[j]!=-1){
        if(A[j]==k){
            return j;
        }
        else{
            i++;
            j=h(k,i,dim);
        }
    }
    return -1;
}

bool excluir (int k, int A[], int dim){
    int i=0;
    int j=h(k,i,dim);

    while(i<dim&&A[j]!=-1){
        if(A[j]==k){
            A[j]=-2;
            return true;
        }
        else{
            i++;
            j=h(k,i,dim);
        }
    }
    return false;
}

void imprimir(int A[],int tam){
    for(int i=0;i<tam;i++){
        cout<<"\n"<<A[i];
    }
    cout<<"\n\n";
}

void inicializa(int A[],int tam){
    for (int i = 0; i<tam; i++){
        A[i]=-1;
    }
}

int main()
{
    int *A;
    int dim = 8;

    A = new int[dim];
    inicializa(A, dim);
    inserir(8,A,dim);
    inserir(9,A,dim);
    inserir(1,A,dim);
    inserir(31,A,dim);
    inserir(10,A,dim);
    inserir(19,A,dim);
    inserir(11,A,dim);
    inserir(311,A,dim);
    imprimir(A,dim);

    cout<<"\nPesquisas";
    cout<<"\n"<<pesquisar(32,A,dim);
    cout<<"\n"<<pesquisar(1,A,dim)<<"\n\n";

    cout<<"Exclusões\n";
    excluir(8,A,dim);
    imprimir(A,dim);
    excluir(19,A,dim);
    imprimir(A,dim);
    excluir(31,A,dim);
    imprimir(A,dim);
    inserir(31,A,dim);
    imprimir(A,dim);

    delete A;


}
