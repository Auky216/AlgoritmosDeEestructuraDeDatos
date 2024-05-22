#include "iostream"
#include "list"

using namespace std;

int MAX_COL = 3;

struct Pair{
    int key;
    int value;

    Pair(int k,int v){
        this->key;
        this->value;
    }
};

class FrequencyTracker {
private:
    list<Pair>* array;
    int capacity;
    int size;

public :
    FrequencyTracker (){
        this->array = nullptr;
    }
    void add ( int number ){
        size_t getHashCode = hashCode(number);
        int index = getHashCode % capacity;

        if(array[index].size() == MAX_COL) {
            rehashing();
            int index = getHashCode % capacity;
        }
        bool find = false;
        for(auto i = array[index].begin() ; i != array[index].end();++i ){
            if((*i).key == number){
                (*i).value++;
                find = true;
                break;
            }
        }

        if(!find){
            array[index].push_front({number,1});
        }
    }
    void deleteOne (int number ){

    }
    bool hasFrequency ( int frequency );

private:

    size_t hashCode(int key){
        hash<int> fhash;
        return fhash(key);
    }

    void rehashing(){

    }
};

int main(){

}

// falta implementar hash