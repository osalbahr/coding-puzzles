## Creates a folder for $1 problem

# Create the folder from template
cp -r template $1

# Rename hello.c
mv $1/hello.c $1/$1.c

# Edit the Makefile accordingly
str="s/hello/$1/g"
sed -i -e $str $1/Makefile

# I have no clue why sed created this
rm $1/Makefile-e
