#ifndef HASHENTRY_H
#define HASHENTRY_H

template<class T>
class HashEntry 
{
private:
    int key;
    T value;
public:
    HashEntry(int &key, T &value) 
    {
        this->key = key;
        this->value = value;
    }
    int getKey() { return this->key;}
    int getValue() {  return this->value;}
};
#endif //!HASHENTRY_H