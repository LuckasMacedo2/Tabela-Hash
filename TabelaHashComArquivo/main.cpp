#include <iostream>
#include "TabelaHash.h"
using namespace std;
#include "Item.h"
int main()
{
    try {
        short int opc;
        Item objI;
        ED2::TabelaHash obj;

        do{
            cout<<"\nInforme: \n[1]Para informar o tamanho da tabela \n[2]Para inserir \nOPCAO: ";
            cin>>opc;
            switch (opc) {
            case 1:
                int tam;
                cout<<"\nInforme o tamanho: ";
                cin>>tam;
                while(tam<=0){
                    cout<<"\nInforme um tamanho >0: ";
                    cin>>tam;
                }
                obj.setArquivo("TabelaHash.txt");
                obj.setDimensao(tam);
                obj.inicializarTabela();
                break;
            case 2:
                try {
                    int dado;
                    int key;
                    cout<<"\nInforme ";
                    cout<<"\nDado númerico: ";
                    cin>>dado;
                    cout<<"\nKey: ";
                    cin>>key;
                    objI.setDado(dado);
                    objI.setKey(key);
                    obj.inserir(objI);
                } catch (std::string &erro) {
                    cout<< erro;
                }
                break;
            }
        }while(opc!=0);
    } catch (std::string &erro) {
        cout<<erro;
    }
}
