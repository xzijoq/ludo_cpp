#!/bin/bash

echo $1
#scan_build use to scan
if [[ $1 = gg ]]
then
    echo "not rebuilding"
    cp ./build/compile_commands.json ./compile_commands.json 
    cmake --build build
    ./build/main
fi

if [[ $1 = s ]]
then
    echo "running: camke --build build and runnning Scene: $2"
    cmake --build build
    cp ./build/compile_commands.json ./compile_commands.json 
    cp ./build/libludo_engine.so ./ludo_cpp/bin/libludo_engine.so
    cd /home/babayaga/Godot/Projects/ludo_cpp/ludo_cpp/
    if [[ $2 = "" ]]
    then
    	/home/babayaga/Godot/Godot -d scenes/BoardDisplay.tscn 
	
    else
       
	    /home/babayaga/Godot/Godot -d scenes/$2.tscn

    fi
    
fi
if [[ $1 = "" ]]
then
    echo "running: camke --build build and copy"
    cmake --build build
    cp ./build/compile_commands.json ./compile_commands.json 
    cp ./build/libludo_engine.so ./ludo_cpp/bin/libludo_engine.so

fi

if [[ $1  = f  || $2 = f ]]
then
    echo "rebuilding"
    rm -r build
    cmake -S./ -B build -DCMAKE_BUILD_TYPE=Debug -G "Ninja" 

    cmake --build build
    cp ./build/libludo_engine.so ./ludo_cpp/bin/libludo_engine.so
    cp ./build/compile_commands.json ./compile_commands.json 


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


CleanEmacsTemp(){
    rm -r \#*
    rm -r *~
    rm -r .*~
}
if [[ $1 = clean ]]
then
    rm -r build
    CleanEmacsTemp
    cd src
    CleanEmacsTemp
    cd ..
    cd includes
    CleanEmacsTemp
    cd ..
    cd ludo_cpp
    cd bin
    rm -r libludo_engine.so
    rm -r .mono
    cd ..
    cd ..
fi



