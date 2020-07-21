#!/bin/bash

echo $1

if [[ $1 = gg ]]
then
    echo "not rebuilding"
    cp ./build/compile_commands.json ./compile_commands.json 
    cmake --build build
    ./build/main
fi

if [[ $1 = s ]]
then
    echo "running: camke --build build and Scene"
    cmake --build build
    cp ./build/compile_commands.json ./compile_commands.json 
    cp ./build/libludo_engine.so ./ludo_cpp/bin/x11/libludo_engine.so
    cd /home/babayaga/Godot/Projects/ludo_cpp/ludo_cpp/
    /home/babayaga/Godot/Godot -d scenes/BoardDisplay.tscn 
fi
if [[ $1 = "" ]]
then
    echo "running: camke --build build and copy"
    cmake --build build
    cp ./build/compile_commands.json ./compile_commands.json 
    cp ./build/libludo_engine.so ./ludo_cpp/bin/x11/libludo_engine.so

fi

if [[ $1  = f  || $2 = f ]]
then
    echo "rebuilding"
    rm -r build
    cmake -S./ -B build -DCMAKE_BUILD_TYPE=Debug -G "Ninja" 

    cmake --build build
    cp ./build/libludo_engine.so ./ludo_cpp/bin/x11/libludo_engine.so
    #cp ./build/compile_commands.json ./compile_commands.json 


fi

if [[ $1 = git ]]
then
    ./run.sh clean
    git add .
    git commit -m "test"
    git push origin master
fi

if [[ $1 = copy ]]
then
    sudo ../copy.sh
fi

if [[ $1 = clean ]]
then
    rm -r build
    rm -r \#*
    rm -r *~
    rm -r .*~
    cd src
    rm -r \#*
    rm -r *~
    rm -r .*~
    cd ..
    cd includes
    rm -r \#*
    rm -r *~
    rm -r .*~
    cd ..
    cd ludo_cpp
    cd bin
    rm -r .mono
    cd x11
    rm -r *
    cd ..
    cd ..    
fi

