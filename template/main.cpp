#include "pch.h"
#include "data.cpp"


int main(){
    using namespace std;
    ios::sync_with_stdio(false); //c and c++ streams dont need to be sync
    cin.tie(0); //untie cin from cout

    int data; //replace the "int" with the datatype you want to store data in

    //check if the process was succesful
    if(read(data) == 1)
        return 0;
    
    // insert code here
    
    return 0;
}