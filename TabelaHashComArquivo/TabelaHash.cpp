#include "TabelaHash.h"
#include <iostream>
namespace ED2 {

int TabelaHash::getDimensao() const
{
    return dimensao;
}

void TabelaHash::setDimensao(int value)
{
    dimensao = value;
    qtdItens = 0;
}

void TabelaHash::inserir(Item objI)
{
    try {
        if(qtdItens>=dimensao){
            throw std::string("\nTabela cheia");
        }
        std::ifstream arq;
        arq.open(arquivo.c_str());
        if(!arq.is_open()){
            throw std::string("\nErro arquivo não encontrado");
        }
        std::string linha;
        int i=0;
        int j=0;
        std::queue<Item> fila;
        getline(arq,linha);
        while(!arq.eof()){
            Item obj;
            obj.montarObj(linha);
            if (i>=objI.getKey()&&(obj.getKey()==-1)&&j!=-1){
                fila.push(objI);
                j=-1;
            }
            else{
                fila.push(obj);
            }
            i++;
            getline(arq,linha);
        }
        arq.close();

        std::ofstream arqS;
        arqS.open(arquivo.c_str());
        if(!arqS.is_open()){
            throw std::string("\nErro arquivo não encontrado");
        }

        while(!fila.empty()){
            Item obj = fila.front();
            if(j!=-1){//O valor informado não foi colocado em lugar nenhum
                if(obj.getKey()==-1){
                    j=-1;
                    arqS<<objI.desmontarObj().c_str();
                }
                else{
                    arqS<<obj.desmontarObj().c_str();
                }
            }
            else{
                arqS<<obj.desmontarObj().c_str();
            }
            fila.pop();
        }
        qtdItens++;
        arqS.close();
    } catch (std::string &erro) {
        throw erro;
    }
}

std::string TabelaHash::getArquivo() const
{
    return arquivo;
}

void TabelaHash::setArquivo(const std::string &value)
{
    arquivo = value;
}

TabelaHash::TabelaHash(std::string arquivo):
    arquivo(arquivo)
{
    inicializarTabela();
}

TabelaHash::TabelaHash():
    dimensao(0),
    qtdItens(0),
    arquivo("")
{

}

TabelaHash::TabelaHash(int dimensao, int qtdItens, std::string arquivo):
    dimensao(dimensao),
    qtdItens(qtdItens),
    arquivo(arquivo)
{
    try {
        inicializarTabela();
    } catch (std::string &erro) {
        throw erro;
    }
}

void TabelaHash::inicializarTabela()
{
    try {
        if(dimensao<=0){
            throw std::string ("\nErro, impossivel criar a tabela");
        }
        std::ofstream arq;
        arq.open(arquivo.c_str(), std::ios::out|std::ios::app);
        if(!arq.is_open()){
            throw std::string("\nErro arquivo não encontrado");
        }
        for(int i=0;i<dimensao;i++){
            arq<<"-1;-1\n";
        }
        arq.close();
    } catch (std::string &erro) {
        throw erro;
    }
}

}

//struct no
//{
//    int data;
//    int state; /* 0 para VAZIO, 1 para REMOVIDO e 2 para OCUPADO */
//};

//// Calcula a função de espalhamento
//int funcao(int k, int m, int i)
//{
//    return ((k+i)%m);
//}

//// Cria a tabela hash
//no_hash *Cria_Hash(int m)
//{
//    no_hash *temp;
//    int i;

//   if((temp = (no_hash*)malloc(m*sizeof(no_hash))) != NULL)
//   {
//        for(i = 0; i < m; i++)
//           temp[i].state = 0;
//        return temp;
//   }
//   else
//        exit(0);
//}

//// Insere um elemento k na tabela T de tamanho m
//void Insere_Hash(no_hash *T, int m, int k)
//{
//    int j, i = 0;

//    do
//    {
//        j = funcao(k, m, i);
//        if(T[j].state == 0 || T[j].state == 1)
//        {
//            T[j].data = k;
//            T[j].state = 2;
//            printf("\nElemento inserido com sucesso!");
//            return;
//        }
//        else
//            i++;
//    }while(i < m);
//    printf("\nTabela cheia!");
//}

//int Busca_Hash(no_hash *T, int m, int k, int i)
//{
//    int j;

//    if(i < m)
//    {
//        j = funcao(k, m, i);
//        if(T[j].state == 0)
//            return -1;
//        else
//            if(T[j].state == 1)
//                return Busca_Hash(T, m, k, i+1);
//            else
//                if(T[j].data == k)
//                    return j;
//                else
//                    return Busca_Hash(T, m, k, i+1);
//    }
//    return -1;
//}

//int Remove_Hash(no_hash *T, int m, int k)
//{
//    int i;

//    i = Busca_Hash(T, m, k, 0);

//    if(i == -1)
//        return -1;
//    else
//    {
//        T[i].state = 1;
//        return 1;
//    }
//}

//void main()
//{
//    int m, i, k;
//    char resp;
//    no_hash *T;

//    printf("\nEntre com o tamanho da tabela: ");
//    scanf("%d", &m);
//    T = Cria_Hash(m);

//    while(1)
//    {
//        printf("\nInserir (i) Buscar (b) Remover (r) Sair (s)\n");
//        resp = getche();
//        getch();

//        switch(resp)
//        {
//            case 'i':
//                printf("\nEntre com o numero a ser inserido na tabela: ");
//                scanf("%d", &k);
//                Insere_Hash(T, m, k);
//                break;
//            case 'b':
//                printf("\nEntre com o numero a ser buscado na tabela: ");
//                scanf("%d", &k);
//                i = Busca_Hash(T, m, k, 0);
//                if(i == -1)
//                    printf("\nNumero nao encontrado!");
//                else
//                    printf("\nNumero encontrado!");
//                break;
//            case 'r':
//                printf("\nEntre com o numero a ser removido da tabela: ");
//                scanf("%d", &k);
//                i = Remove_Hash(T, m, k);
//                if(i == -1)
//                    printf("\nNumero nao encontrado!");
//                else
//                    printf("\nNumero removido com sucesso!");
//                break;
//            case 's':
//                exit(0);
//                break;
//      }
//   }
//}
