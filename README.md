# RPP-M (Rec-Play-Pause Micro)
 Template repository for cross-platform cpp development based on CMake build system Resources

> **NOTE :** This repository is tested only on MacOS and debian based Linux Distributions. Will be updated for Windows in the future.

### Who is this repository for?
* If project based on CMakeLists build system.
* If project contains only few source files like `main.cpp`, `mylib.cpp` etc.
* If you need a C++ development laboratuary to test simple codes does not requires any 3Rd dependencies.

### Requirements:
* Cmake
* Make (optional)
* Git
* GNU Compiler Collection (gcc, g++ etc.)

## Preparing Development Environment
```
# clone the repo
git clone git@github.com:eheperson/rpp-m.git

# change access rights of bake.sh file
chmod +x bake.sh
```

Generate the build files using CMake for Release configuration:
```bash
# Windows
cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX=out/app -S . -B out/build

# Unix/Linux
cmake -DCMAKE_INSTALL_PREFIX=out/app -S . -B out/build

```

Build the project (Release configuration will be used by default)
```bash
cmake  --build .//out//build -j 12 -v
```

Install the project (Release configuration will be used by default)
```bash
cmake --install .//out//build  --verbose
```


Package the project
```bash
cpack .\out\build  -c Debug --verbose
```