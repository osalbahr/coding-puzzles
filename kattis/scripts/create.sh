## Creates a folder for $1 problem

# Create the folder from template
cp -r template $1

# Rename hello.cpp
mv $1/hello.cpp $1/$1.cpp

# Edit the Makefile accordingly
str="s/hello/$1/g"
sed -i -e $str $1/Makefile

# I have no clue why sed created this
rm $1/Makefile-e

# ignore executables
echo $1 > $1/.gitignore
