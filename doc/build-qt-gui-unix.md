# Build depends

# Copy addition libs to depends lib folder 

cd ~/Skyrcoin
sudo cp depends/addlibs/*.a depends/x86_64-pc-linux-gnu/lib/

# Entering directory
	cd ~/Skyrcoin

# Compile (under not root)
	sudo sh ./autogen.sh



Save changes.
        sudo sh ./configure --enable-glibc-back-compat --prefix=$(pwd)/depends/x86_64-pc-linux-gnu LDFLAGS="-static-libstdc++" --enable-cxx --enable-static --disable-shared --disable-debug --disable-tests --disable-bench --with-pic CPPFLAGS="-static -fPIC -O3 --param ggc-min-expand=1 --param ggc-min-heapsize=32768" CXXFLAGS="-static -fPIC -O3 --param ggc-min-expand=1 --param ggc-min-heapsize=32768" CFLAGS="-static "

        sudo make -j$(echo $CPU_CORES) HOST=x86_64-pc-linux-gnu

        #where (echo $CPU_CORES)= CPU core number
Exsample:
        sudo make -j4 HOST=x86_64-pc-linux-gnu



# Note

libraries were downloaded from dib-files:

https://packages.ubuntu.com/focal/amd64/libx11-xcb-dev/download
https://packages.ubuntu.com/focal/amd64/libxcb1-dev/download
https://packages.ubuntu.com/focal/amd64/libxdmcp-dev/download

https://packages.debian.org/ru/buster/amd64/libx11-dev/download

