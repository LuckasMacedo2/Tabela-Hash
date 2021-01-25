#include "Item.h"

int Item::getDado() const
{
    return dado;
}

void Item::setDado(int value)
{
    dado = value;
}

int Item::getKey() const
{
    return key;
}


void Item::setKey(int value)
{
    key = value;
}

std::string Item::desmontarObj() const
{
    std::string saida("");
    saida = std::to_string(key)+';';
    saida += std::to_string(dado);
    saida +='\n';
    return saida;
}

void Item::montarObj(std::string &str)
{
    std::string aux[2];
    aux[0]="";
    aux[1]="";
    for(int i = 0, j=0; i<str.length();i++){
        if(str[i]==';'){
            j++;
            i++;
        }
        aux[j]+=str[i];
    }
    this->key=std::stoi(aux[0].c_str());
    this->dado=std::stoi(aux[1].c_str());
}

Item::Item()
{

}
