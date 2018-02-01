#include <iostream>

#define DEFAULT_TABLE_SIZE 4
#define PRIMARY_HASH_KEY 19
#define SECONDARY_HASH_KEY 23

// specify these values for the type of data you are using T
const std::string EMPTY = "EMP";
const std::string DELETED = "DEL";

enum hashType {
    PRIMARY,
    SECONDARY
};

class DoubleHashGenerator {
public:
    size_t operator()(std::string element, size_t elemSize, size_t tableSize, hashType stage) {
        size_t hash = 0;

        for (auto i = 0; i < elemSize; ++i) {
            hash = (1 + (hash * (stage == PRIMARY ? PRIMARY_HASH_KEY : SECONDARY_HASH_KEY) + element[i]) * 2) % tableSize;
        }

        return hash;
    }
};


template<class T, class HASH_GENERATOR>
class HashTable {
public:

    bool exists(T element, size_t elemSize);

    bool insert(T element, size_t elemSize);

    bool remove(T element, size_t elemSize);

private:

    T *elements;
    HASH_GENERATOR DoubleHashGenerator;

    void reHash();

    size_t capacity;
    size_t countOfElements;

public:

    HashTable(HASH_GENERATOR functor);

    ~HashTable();

};

template<class T, class HASH_GENERATOR>
HashTable<T, HASH_GENERATOR>::HashTable(HASH_GENERATOR functor) :
        capacity(DEFAULT_TABLE_SIZE),
        countOfElements(0),
        DoubleHashGenerator(functor) {
    elements = new T[capacity];
    for(int i = 0; i < capacity; ++i){
        elements[i] = EMPTY;
    }
}

template<class T, class HASH_GENERATOR>
HashTable<T, HASH_GENERATOR>::~HashTable() {
    delete[] elements;
}

template<class T, class HASH_GENERATOR>
bool HashTable<T, HASH_GENERATOR>::insert(T element, size_t elemSize) {
    if (countOfElements >= capacity*3/4) reHash();

    size_t primaryHash = DoubleHashGenerator(element, elemSize, capacity, hashType::PRIMARY);
    size_t secondaryHash = DoubleHashGenerator(element, elemSize, capacity, hashType::SECONDARY);

    size_t finalIndex;
    bool finded = false;

    for (size_t i = 0; i <= capacity; ++i) {
        size_t candidateHash = (primaryHash + secondaryHash * i) % capacity;

        if (elements[candidateHash] == element) {
            return false;
        }else if (elements[candidateHash] == EMPTY || elements[candidateHash] == DELETED){
            finded = true;
            finalIndex = candidateHash;
            if( elements[candidateHash] == EMPTY){
                break;
            }
        }
    }

    if (finded) {
        elements[finalIndex] = element;
        ++countOfElements;
    }

    return finded;
}

template<class T, class HASH_GENERATOR>
bool HashTable<T, HASH_GENERATOR>::remove(T element, size_t elemSize) {


    size_t primaryHash = DoubleHashGenerator(element, elemSize, capacity, hashType::PRIMARY);
    size_t secondaryHash = DoubleHashGenerator(element, elemSize, capacity, hashType::SECONDARY);

    for (size_t i = 0; i < capacity; ++i) {
        size_t candidateHash = (primaryHash + secondaryHash * i) % capacity;
        if (elements[candidateHash] == element){
            countOfElements --;
            elements[candidateHash] = DELETED;
            return true;
        }else if (elements[candidateHash] == EMPTY){
            return false;
        }
    }

    return false;
}

template<class T, class HASH_GENERATOR>
bool HashTable<T, HASH_GENERATOR>::exists(T element, size_t elemSize) {

    size_t primaryHash = DoubleHashGenerator(element, elemSize, capacity, hashType::PRIMARY);
    size_t secondaryHash = DoubleHashGenerator(element, elemSize, capacity, hashType::SECONDARY);

    for(size_t i = 0; i < capacity; ++i){
        size_t candidateHash = (primaryHash + secondaryHash * i) % capacity;
        if (elements[candidateHash] == element){
            return true;
        }else if (elements[candidateHash] == EMPTY){
            return false;
        }
    }

    return false;
}

template<class T, class HASH_GENERATOR>
void HashTable<T, HASH_GENERATOR>::reHash() {

    T* oldArray = elements;
    elements = new T[capacity *= 2];

    for(auto iter = 0; iter < capacity; ++iter)
        elements[iter] = EMPTY;

    for(size_t i = 0; i < capacity/2; ++i){
        if(oldArray[i] != EMPTY && oldArray[i] != DELETED){
            insert(oldArray[i], oldArray[i].size());
            --countOfElements;
        }
    }
    delete[] oldArray;
}


int main() {

    using namespace std;
    auto table = HashTable<string, DoubleHashGenerator>(DoubleHashGenerator());

    char command;
    string line;
    while((cin >> command) && cin.ignore() && getline(cin, line)){
        switch(command){
            case '+':
                cout << (table.insert(line, line.length()) ? "OK" : "FAIL") << flush;
                break;
            case '-':
                cout << (table.remove(line, line.length()) ? "OK" : "FAIL") << flush;
                break;
            case '?':
                cout << (table.exists(line, line.length()) ? "OK" : "FAIL") << flush;
                break;
        }
        cout << endl;
    }

    return 0;
}