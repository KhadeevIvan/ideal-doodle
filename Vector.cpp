#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using std::ifstream;
using std::string;
using std::getline;
using std::cin;
using std::cout;

struct subvector{
    int* arr;
    int size;
    int capacity;
};

bool init(subvector *qv){
    (qv) -> arr = (int*)malloc(sizeof(int));
    (qv) -> size = 0;
    (qv) -> capacity = sizeof(int);
}

bool push_back(subvector *qv, int d){
    if((4*((qv) -> size) + sizeof(d)) <= (qv) -> capacity){
        ((qv) -> arr)[((qv) -> size)] = d;
        (qv) -> size = (qv) -> size + 1;
    }
    else{
        int* pointer = (qv) -> arr;
        (qv) -> arr = (int*)realloc(pointer, 2 * ((qv) -> capacity));
        (qv) -> capacity = ((qv) -> capacity) * 2;
        (qv) -> size = (qv) -> size + 1;
    }
}
//capacity должна быть равна sizeof(int)*2^n
int pop_back(subvector *qv){
    int num = ((qv) -> arr)[((qv) -> size) - 1];
    (qv) -> size = ((qv) -> size) - 1;
    return num;
}

bool resize(subvector *qv, int new_capacity){
    int* pointer = (qv) -> arr;
    (qv) -> arr = (int*)realloc(pointer, new_capacity);
    (qv) -> capacity = new_capacity;
}

void shrink_to_fit(subvector *qv){
    int power = log2((qv) -> size) + 1;
    (qv) -> capacity = pow(2, power) * sizeof(int);
    int* pointer = (qv) -> arr;
    (qv) -> arr = (int*)realloc(pointer, (qv) -> capacity);
}

void clear(subvector *qv){
    (qv) -> size = 0;
}

void destructor(subvector *qv){
    int* pointer = (qv) -> arr;
    (qv) -> arr = (int*)realloc(pointer, 0);
    (qv) -> capacity = 0;
    (qv) -> size = 0;
}

bool init_from_file(subvector *qv, char *filename){
    string line;
    ifstream in(filename);
    if(in.is_open()){
        getline(in, line);

    }

}





