#ifndef ITEM_H
#define ITEM_H

#include<string>
class Item
{
    int dado;
    int key;
public:
    Item();
    int getDado() const;
    void setDado(int value);
    int getKey() const;
    void setKey(int value);

    std::string desmontarObj() const;
    void montarObj(std::string &str);
};

#endif // ITEM_H
