#include "pch.h"

//parse function
template <typename T>
void parse(T data, std::vector<std::string>* input){
    using namespace std;

    for(int i = 0; i < input->size(); i++){
        //do something with the input and save it to the data
        //don't forget that input is a pointer
    }
    
    return;
}


//read function
template<typename T>
int read(T data){
    std::ifstream fajl("input.txt");
    if (!fajl){
        fmt::print("Error opening input.txt: {}\n", strerror(errno));
        return 1;
    }

    std::vector<std::string> input;
    std::string trsh;
    while(getline(fajl, trsh)){
        //here you can also do some work on the input strings
        input.emplace_back(trsh);
    }

    fajl.close();

    parse(data, &input);
    return 0;
}


//write function
template<typename T>
int write(T data){
    std::ofstream fajl("output.txt", std::fstream::trunc);
    if (!fajl){
        fmt::print("Error opening output.txt: {}\n", strerror(errno));
        return 1;
    }

    //insert the way you want the data to be outputed

    fajl.close();
    return 0;
}