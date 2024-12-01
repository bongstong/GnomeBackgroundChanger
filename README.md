# GnomeBackgroundChanger
Lightweight program that changes the desktop background of the Gnome Desktop Environment

# HOW TO RUN:
Since this program works for the Gnome DE, I assume that you use Linux.
First, copy the git repository by running:
```sh
git clone https://github.com/bongstong/GnomeBackgroundChanger
```
After that, you must add the absolute path of your picture's folder to the
`main.cpp` file, the place is showed in the file. On line 20, in between the `""`
I could have made the progrram work on input or to put the file in  separate file
but this works just fine, so what for?

Then you have to compile the program yourself:
```sh
g++ main.gcc -o main
```
And just run the file:
```sh
./main
```
