# Advent of code c++ template
This is the c++ template system for writing [advent of code](https://adventofcode.com) tasks <b>faster</b> and with more convenience.

##### <b>Features:</b>
-   Customizable template
-   No configuration necessary
-   shared submodules (you can add as many libraries as you want, as long as CMake supports them)
-   Automatization scripts

<br>

### Requirements
-   [CMake](https://cmake.org/) version 3.16 or above
-   C++ compiler (the configuration is set to c++17 in the CMakeLists.txt in template, however, you can change that)
-   A way to run a shell script, if you don't have it, the simplest way is to get it is alongside with [git](https://git-scm.com/), just make sure to select the option for installing "git bash"

<br>

### How to use
1.  Clone the repository, make sure to do a recursive clone since it contains submodules `git clone --recurse-submodules "https://github.com/G-rox-y/AOC-CPP-Template"`
2.  Check out what is written in the template folder and modify it to your needs, since the default template setup is just how I use it
3.  When you want to solve a new task, run `create.sh` with an additional argument that specifies the name of the new folder (ex: `.\create.sh Day1`)
4.  The new folder will be created with 5 files, `input.txt` where you are supposed to paste the input from the website, `main.cpp` where you put your code, `data.cpp` where you have premade function templates for reading the input, parsing it, and writing it to `output.txt`, and `CMakeLists.txt` which the scripts use to build your program
5.  When you are done writing the code save it and run `run.sh` script, it will compile your program and run it. If the command doesn't work, make sure to insert the folder name as an argument to the script (ex: `.\run.sh Day1`)

##### Things to note:
-   The CMake script creates precompiled headers to speed up the compilation times, the precompiled header `pch.h` is inside the include folder
-   In the default template main.cpp includes data.cpp *directly*, they are separate files only for better readability
-   `run.sh` knows what file to run thanks to `last.txt` because that file saves what was the last folder that `create.sh` or `run.sh` were using
-   You should run the scripts from their root folders since they arent made to be run from other locations
-   The binaries will be built in the `build` folder that will be created inside the project folder, they access `input.txt` and `output.txt` because the shell scripts run them inside those folders
