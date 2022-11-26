#include "pch.h"

using namespace std;

void part1(void* data){
    //cast the pointer and do sth with the data
}

void part2(void* data){
    //cast the pointer and do sth with the data
}

int main(){
    int data; //replace the "int" with the datatype you want to store data in
    //check if the process was succesful
    if(read((void*) &data) == 1){
        cin.get();
        return 0;
    }
    
    part1((void*) data);
    part2((void*) data);
    
    return 0;
}