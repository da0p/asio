# asio
This repo contains experimental codes with asio networking library.

# How to use it
- Create a build directory
```
    mkdir build
```

- Install dependencies
```
    conan install conanfile.txt 
        --output-folder=build 
        --build=missing 
        -c tools.cmake.cmaketoolchain:generator=Ninja 
        -s build_type=Debug
```
- Run cmake
```
    cd build
    cmake -GNinja ..
```
- Build examples
```
    ninja
```