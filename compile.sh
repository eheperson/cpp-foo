apt-get install cowsay
cowsay "hello motherfucker"


# -----------------------------------
#       CONFIGURE
# -----------------------------------
echo ""
echo " Configure Begin"
echo ""

# cmake -G "MinGW Makefiles" -DUSE_EXAMPLELIB=ON -S . -B ./build
cmake -DUSE_EXAMPLELIB=ON -S . -B ./build

echo ""
echo " Configure End"
echo ""

# -----------------------------------
#       BUILD
# -----------------------------------
buildDIR="./build"
if [ ! -d "$DIR" ]; then
  mkdir ${DIR}
fi

echo ""
echo " Build Begin"
echo ""

cd build
cmake --build .
# or 
# mingw32-make
cd ..

echo ""
echo " Build End"
echo ""

# -----------------------------------
#       RUN
# -----------------------------------
echo ""
echo " Run Begin"
echo ""

cd build
# ./cppFoo "Mr. Anderson"
./cppFoo
cd ..

echo ""
echo " Run End"
echo ""

# -----------------------------------
#       INSTALL
# -----------------------------------
echo ""
echo " Install Begin"
echo ""

appdDIR="./app"
if [ ! -d "$DIR" ]; then
  mkdir ${DIR}
fi
cmake --install . --prefix="./app/"

echo ""
echo " Install End"
echo ""

# # -----------------------------------
# #       TEST
# # -----------------------------------
# cd build
# ctest -C Debug -VV
# cd ..

# # -----------------------------------
# #       PACK
# # -----------------------------------
# To build a binary distribution, from the binary directory run:
#     cpack
#
# To specify the generator, use the -G option. 
#
# For multi-config builds, use -C to specify the configuration. For example:
#     cpack -G ZIP -C Debug
#
# To create a source distribution you would type:
#     cpack --config CPackSourceConfig.cmake
#
# Alternatively, run make package or right click the Package target and Build Project from an IDE.
#
# Run the installer found in the binary directory. 
# Then run the installed executable and verify that it works.
echo ""
echo " Pack Begin"
echo ""

cd build
cpack -G ZIP -C Debug
cd ..

echo ""
echo " Pack End"
echo ""