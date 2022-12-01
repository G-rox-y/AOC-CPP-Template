#! bin/sh

check_copy(){
    if [ -d "$1" ]; then
        echo "This directory already exists!"
    else
        cp -r "template" "$1"
    fi
}

#set the variable $last to the folder name
new=""
if [ $# -gt 0 ]; then
    new=$1
    check_copy $new
fi

while [ ! -d "$new" ]; do
    read -p "Insert a valid directory name: " new
    check_copy $new
done

#mark the new folder as lastused, so that running run.sh without args calls it
echo "$new" > last.txt

echo "Directory created!"
echo 
read -p "Press any key to exit..." sayonara