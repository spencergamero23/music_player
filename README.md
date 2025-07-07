# Overview

Thought it would be fun to work with C++. It's the first language I started with so I have a pretty basic knowledge in the language. So I decided to make a program that plays a music file. It was pretty fun in the end and I definitely plan on continuing to improve it!

I've made a program where you input a file path into the program and it receives it. Afterwards it will open the folder and iterate throuhg the directory to save 10 wav file paths into a vector. Afterwards it'll play the audio that you input and while giving you the option to skip or quit the program. If you skip it'll just play the next audio file in a loop.

My purpose for writing this software was just to explore and improve my understanding of a different language. I write a lot in Python and C# so I figured it'd be a guid exercise to work on a project in C++


[Software Demo Video](https://youtu.be/t-HBRLE5Mnk)

# Development Environment

Tools I used were just VS code as well as some libraries.

This has been completely written in C++ as well as using:
- iostream: Used for input/output stream such as cin,cout, and getline.
- sys\stat.h: Used for file status functions. Like checking yoru directory
- dirent.h: Reads contents fo directories
- Windows.h: required for (PlaySound)
- vector: for using vectors.
- filesystem: File system utility
- mmsystem.h: Provides the (PlaySound) function

# Useful Websites


- [How to Play Music in C++ (Simple)](https://www.youtube.com/watch?v=CrPHVvgENq0&ab_channel=MaxO%27Didily)
- [C++ Functions](https://www.w3schools.com/cpp/cpp_functions.asp)
- [How to list all files and folders from a directory, like a File Explorer with C/C++](https://www.youtube.com/watch?v=k_bqxnqud70&ab_channel=EasyProgramming)

# Future Work


- Being able to change the volume of the music
- Being able to read not mp3 files
- Improving the UI