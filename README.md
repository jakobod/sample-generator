# sample-generator
A sample program that calculates samples for a sinus/sawtooth lookup-table.
This little program is aimed at students of Computer-Engineering.

Right now the program will first print the 360 samples of the sinus table, then the 360 samples of the sawtooth table. All Printed values are already converted to fixed-point format with 0 integer bits and 11 fractional bits.
If you'd like to change those values, you can simply change the constants in the `sample_generator.cpp`.

# How to build?
First you will need cmake and gcc/clang. Visual Studio or CLion on Windows will probably work too, but are untested.

### Linux/Mac Instructions

1. clone this repo with
```bash
git clone https://github.com/jakobod/sample_generator.git
```

2. step into the folder and build the program:
```bash
cd sample_generator
mkdir build
cd build
cmake ..
make
```
Or simply call the `build.sh` script. It does all that for you.

3. Run the program:
```
./sample_generator
```

### Windows instructions
no idea. I think you need to import this project somehow and load the CMakeLists.txt into your IDE. If you know more than me, please dont hesitate and tell me :+1:

# Feedback
If you happen to find a bug or anything that you think is off with this program, feel free to open an issue/pullrequest.
