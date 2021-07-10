#!/bin/bash
echo -e "\033[0;32mHow many CPU cores do you want to be used in compiling process? (Default is 1. Press enter for default.)\033[0m"
read -e CPU_CORES
if [ -z "$CPU_CORES" ]
then
    CPU_CORES=1
fi

# Clone code from official Github repository
    rm -rf skyrcoin
    git clone https://github.com/SkyrcoinTeam/skyrcoin

# Entering directory
    cd skyrcoin

# Compile dependencies
    cd depends
    mkdir SDKs
    cd SDKs
    wget https://github.com/phracker/MacOSX-SDKs/releases/download/10.15/MacOSX10.11.sdk.tar.xz
    tar -xf MacOSX10.11.sdk.tar.xz
    cd ..
    make -j$(echo $CPU_CORES) HOST=x86_64-apple-darwin14
    cd ..

# Compile
    ./autogen.sh
    ./configure --prefix=$(pwd)/depends/x86_64-apple-darwin14 --enable-cxx --enable-static --disable-shared --disable-debug --disable-tests --disable-bench --disable-online-rust
    make -j$(echo $CPU_CORES) HOST=x86_64-apple-darwin14
    make deploy
    cd ..

# Create zip file of binaries
    cp skyrcoin/src/skyrcoind skyrcoin/src/skyrcoin-cli skyrcoin/src/skyrcoin-tx skyrcoin/src/qt/skyrcoin-qt skyrcoin/skyrcoin-Core.dmg .
    zip SKYR-MacOS.zip skyrcoind skyrcoin-cli skyrcoin-tx skyrcoin-qt skyrcoin-Core.dmg
    rm -f skyrcoind skyrcoin-cli skyrcoin-tx skyrcoin-qt skyrcoin-Core.dmg
