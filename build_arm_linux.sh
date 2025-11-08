#!/bin/bash
echo -e "\033[0;32mHow many CPU cores do you want to be used in compiling process? (Default is 1. Press enter for default.)\033[0m"
read -e CPU_CORES
if [ -z "$CPU_CORES" ]
then
	CPU_CORES=1
fi

# Upgrade the system and install required dependencies
	sudo apt update
	sudo apt install git zip unzip build-essential libtool bsdmainutils autotools-dev autoconf pkg-config automake python3 libqt5svg5-dev libxdmcp-dev -y

# Clone code from official Github repository
	#rm -rf Skyrcoin
	#git clone https://github.com/SkynetResearchProject/Skyrcoin.git

# Entering directory
	cd Skyrcoin

# Compile dependencies
	cd depends
	make -j$(echo $CPU_CORES) HOST=arm-linux-gnueabihf
	cd ..

# Compile
	./autogen.sh
	#./configure --prefix=$PWD/depends/arm-linux-gnueabihf --enable-glibc-back-compat --enable-reduce-exports LDFLAGS=-static-libstdc++ --disable-shared --disable-debug --disable-tests #--disable-wallet
        ./configure --prefix=$PWD/depends/aarch64-linux-gnu --enable-glibc-back-compat --enable-reduce-exports LDFLAGS=-static-libstdc++  --disable-debug --disable-tests

        #set make -j1 if 'if you get an error: "arm-linux-gnueabihf-g++: fatal error: Killed signal terminated program cc1pluscompilation terminated'
        make -j$(echo $CPU_CORES) HOST=arm-linux-gnueabihf
	cd ..

# Create zip file of binaries
	cp Skyrcoin/src/skyrcoind Skyrcoin/src/skyrcoin-cli Skyrcoin/src/skyrcoin-tx Skyrcoin/src/qt/skyrcoin-qt .
	zip SKYR-$(git describe --abbrev=0 --tags | sed s/v//)-ARM-Linux.zip skyrcoind skyrcoin-cli skyrcoin-tx skyrcoin-qt
	rm -f skyrcoind skyrcoin-cli skyrcoin-tx skyrcoin-qt
