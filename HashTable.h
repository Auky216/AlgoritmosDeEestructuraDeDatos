#include "iostream"
#include "ForwardList.h"

using namespace std;

const int MAX_COL = 3;


template<typename TK, typename TV>
struct Pair{
    TK key;
    TV value;

    Pair(){}

    Pair(TK _key,TV _value){
        this->key = _key;
        this->value = _value;
    }
};

template<typename TK, typename TV>
class HashTable{
private:
    ForwardList<Pair<TK,TV>>* array;
    int capacity;
    int count;
    hash<TK> fhash;

public:

    HashTable(int capacity){
        this->capacity = capacity;
        this->array = new ForwardList<Pair<TK,TV>>[capacity];
        this->count = 0;
    }

    ~HashTable(){
        delete[] array;
    }

    void set(TK key,TV value){
        size_t hash_code = fhash(key);
        int index = hash_code % capacity;

        if(array[index].size() == MAX_COL){
            rehashing();
            index = hash_code % capacity;
        }

        array[index].push_front(Pair<TK,TV>(key,value));
        count++;
    }

    TV get(TK key){
        size_t hash_code = fhash(key);
        int index = hash_code % capacity;

        for(auto iter = array[index].begin(); iter != array[index].end(); ++iter){
            if((*iter).key == key){

                return (*iter).value;
            }
        }

        throw"Key not found";
    }

    void display(){
        for(int i = 0;i<capacity;i++){
            cout<<i<<"-> ";
            for(auto iter = array[i].begin(); iter != array[i].end();++iter){
                cout<<(*iter).key<<":"<<(*iter).value<<"  ";
            }
            cout<<endl;
        }
    }


private:

    void rehashing(){
        ForwardList<Pair<TK,TV>>* newArray = new ForwardList<Pair<TK,TV>>[capacity*2];

        size_t hashCode;
        int index;

        for(int i = 0;i<capacity;i++){
            for(auto iter = array[i].begin(); iter != array[i].end() ; ++iter){

                hashCode = fhash((*iter).key);
                index = hashCode % ( capacity * 2);

                newArray[index].push_front(*iter);

            }
        }

        capacity = capacity*2;
        array = newArray;
    }
};