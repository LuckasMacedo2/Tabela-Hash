#ifndef TABELAHASH_H
#define TABELAHASH_H
#include <string>
#include <fstream>
#include <queue>
#include "Item.h"
//-1 indica que nenhum item foi adicionado ali
//-2 indica que houve exclusão do item que estava naquela posição
namespace ED2 {
class TabelaHash
{
private:
    int dimensao;
    int qtdItens;
    std::string arquivo;
public:
    TabelaHash(std::string arquivo);
    TabelaHash();
    TabelaHash(int dimensao,int qtdItens ,std::string arquivo);
    void inicializarTabela();
    int getDimensao() const;
    void setDimensao(int value);
    int gerarKey();
    void inserir(Item);

    std::string getArquivo() const;
    void setArquivo(const std::string &value);
};

}

#endif // TABELAHASH_H
