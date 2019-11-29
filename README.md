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

### Sample output of the Program
```
❯ ./sample_generator 
Sinus samples:
    0,   571,  1143,  1714,  2285,  2855,  3425,  3993,  4560,  5126,  5690,  6252,  6812,  7371,  7927, 
 8480,  9032,  9580, 10125, 10668, 11207, 11743, 12275, 12803, 13327, 13848, 14364, 14876, 15383, 15886, 
16383, 16876, 17364, 17846, 18323, 18794, 19260, 19720, 20173, 20621, 21062, 21497, 21926, 22347, 22762, 
23170, 23571, 23964, 24351, 24730, 25101, 25465, 25821, 26169, 26509, 26841, 27165, 27481, 27788, 28087, 
28377, 28659, 28932, 29196, 29451, 29697, 29935, 30163, 30381, 30591, 30791, 30982, 31164, 31336, 31498, 
31651, 31794, 31928, 32051, 32165, 32270, 32364, 32449, 32523, 32588, 32643, 32688, 32723, 32748, 32763, 
32767, 32763, 32748, 32723, 32688, 32643, 32588, 32523, 32449, 32364, 32270, 32165, 32051, 31928, 31794, 
31651, 31498, 31336, 31164, 30982, 30791, 30591, 30381, 30163, 29935, 29697, 29451, 29196, 28932, 28659, 
28377, 28087, 27788, 27481, 27165, 26841, 26509, 26169, 25821, 25465, 25101, 24730, 24351, 23964, 23571, 
23170, 22762, 22347, 21926, 21497, 21062, 20621, 20173, 19720, 19260, 18794, 18323, 17846, 17364, 16876, 
16383, 15886, 15383, 14876, 14364, 13848, 13327, 12803, 12275, 11743, 11207, 10668, 10125,  9580,  9032, 
 8480,  7927,  7371,  6812,  6252,  5690,  5126,  4560,  3993,  3425,  2855,  2285,  1714,  1143,   571, 
    0,  -571, -1143, -1714, -2285, -2855, -3425, -3993, -4560, -5126, -5690, -6252, -6812, -7371, -7927, 
-8480, -9032, -9580, -10125, -10668, -11207, -11743, -12275, -12803, -13327, -13848, -14364, -14876, -15383, -15886, 
-16384, -16876, -17364, -17846, -18323, -18794, -19260, -19720, -20173, -20621, -21062, -21497, -21926, -22347, -22762, 
-23170, -23571, -23964, -24351, -24730, -25101, -25465, -25821, -26169, -26509, -26841, -27165, -27481, -27788, -28087, 
-28377, -28659, -28932, -29196, -29451, -29697, -29935, -30163, -30381, -30591, -30791, -30982, -31164, -31336, -31498, 
-31651, -31794, -31928, -32051, -32165, -32270, -32364, -32449, -32523, -32588, -32643, -32688, -32723, -32748, -32763, 
-32768, -32763, -32748, -32723, -32688, -32643, -32588, -32523, -32449, -32364, -32270, -32165, -32051, -31928, -31794, 
-31651, -31498, -31336, -31164, -30982, -30791, -30591, -30381, -30163, -29935, -29697, -29451, -29196, -28932, -28659, 
-28377, -28087, -27788, -27481, -27165, -26841, -26509, -26169, -25821, -25465, -25101, -24730, -24351, -23964, -23571, 
-23170, -22762, -22347, -21926, -21497, -21062, -20621, -20173, -19720, -19260, -18794, -18323, -17846, -17364, -16876, 
-16384, -15886, -15383, -14876, -14364, -13848, -13327, -12803, -12275, -11743, -11207, -10668, -10125, -9580, -9032, 
-8480, -7927, -7371, -6812, -6252, -5690, -5126, -4560, -3993, -3425, -2855, -2285, -1714, -1143,  -571, 
```

### Windows instructions
no idea. I think you need to import this project somehow and load the CMakeLists.txt into your IDE. If you know more than me, please dont hesitate and tell me :+1:

# Feedback
If you happen to find a bug or anything that you think is off with this program, feel free to open an issue/pullrequest.
