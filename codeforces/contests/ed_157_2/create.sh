## Creates a folder for $1 problem

# Create the folder from template
cp -r template "$1"

# cd into it
cd "$1"

# Rename hello.c
mv hello.cpp "$1".cpp

# Edit the Makefile accordingly
str="s/hello/$1/g"
sed -i -e $str Makefile

# I have no clue why sed created this
rm Makefile-e

# Ignore exe
echo "$1" >> .gitignore
