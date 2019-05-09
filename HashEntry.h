#ifndef HASHENTRY_H
#define HASHENTRY_H

class HashEntry 
{
private:
    int key;
    int value;
public:
    HashEntry(int &key, int &value) 
    {
        this->key = key;
        this->value = value;
    }
    int getKey() { return this->key;}
    int getValue() {  return this->value;}
};
#endif //!HASHENTRY_H