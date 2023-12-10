if [ $# -gt 0 ] 
then # compile and run the files in the given directory
    g++ -o main.o $1*.cpp
    ./main.o
else # compile and run the files in the last directory
    path=$(ls -1 ./ | tail -n 1)
    path=$path/$(ls -1 $path | tail -n 1)/
    echo "Compiling *.cpp files in \"$path\"..."
    echo "---------------------------------------------------"
    
    g++ -o main.o $path/*.cpp
    if [ $? -eq 0 ]
    then
        ./main.o
    fi
    
    echo "---------------------------------------------------"
fi