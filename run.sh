#! bin/sh

#set the variable $last to the folder name
last=$(cat last.txt)
if [ $# -gt 0 ]; then
    last=$1
fi

#check if folder exists
if [ ! -d "$last" ]; then
    echo "folder \"$last\" not found"
    echo
    read -p "Press any key to exit..." byee
    exit 0
fi
#mark that this is the last program that has been run
echo "$last" > last.txt


#build (cmake is smart, so if its built alr, nothing will change)
cmake -S "./$last/" -B "./$last/build" -G "MinGW Makefiles"

#and now build
cd "./$last/build" ; 
mingw32-make ; 
echo ; read -p "Press any key to run the program..." waitin ;
echo ; echo ;

#run!
cd .. ;
echo "Program output:" ;
echo ;
".\\build\\$last.exe" ;

#and say goodbye
echo ; echo ;
read -p "Press any key to exit..." adios
