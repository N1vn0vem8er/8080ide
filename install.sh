mkdir -p build
cd build
qmake6 ../8080ide.pro PREFIX=/usr/bin
make
make install
