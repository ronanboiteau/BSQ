# BSQ

{EPITECH.} first year project.

C program that finds the biggest square in a map using a homemade algorithm.

## Requirements

 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)

## Compilation

Navigate to the root of the repository from your Terminal and run `make` to build the `bsq` executable file.

## How to use BSQ?

Pass a map file to the program as an argument when running BSQ:
```
./bsq map.txt
```
BSQ finds the biggest square and ouputs the result.

## Map format

 - You can find a sample in the file `map.txt`.
 - The first line is the number of lines in the map.
 - The map is only made of `.` (empty) and `o` (obstacles) symbols.
 - The map is always a rectangle.
 - All lines are the same size.

## Map generator

You can generate BSQ maps using the Perl script `gen_map.pl`:

```
perl gen_map.pl [COLS] [LINES] [DENSITY]
```

## Options

 - `-v`: verbose mode
 - `-c`: enable colorized output
