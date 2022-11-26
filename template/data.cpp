//functions are declared in pch.h, so if you change inputs make sure to either
//update pch.h or create the prototype within main (or make a header yourself)
#include "pch.h"


//parse function
void parse(void* data, std::vector<std::string>* input){
    using namespace std;

    //cast the void* to the type you want to use
    for(int i = 0; i < input->size(); i++){
        //do something with the input and save it to the data
    }
    
    return;
}


//read function
int read(void* data){
    std::ifstream fajl("input.txt", std::fstream::in);
    if (!fajl){
        fmt::print("Error opening input.txt: {}\n", strerror(errno));
        return 1;
    }

    std::vector<std::string> input;
    int line = 0;
    while(getline(fajl, input[line]))
        line++;

    fajl.close();

    parse(data, &input);
    return 0;
}


//write function
int write(std::string output){
    std::ofstream fajl("output.txt", std::fstream::out | std::fstream::trunc);
    if (!fajl){
        fmt::print("Error opening output.txt: {}\n", strerror(errno));
        return 1;
    }

    fajl << output;
    fajl.close();
    return 0;
}