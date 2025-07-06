#include <iostream>
#include <sys\stat.h>
#include <dirent.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


using namespace std;

void chooseSong(const string& filePath)
{
    // Play the music file
    string songName;
    cin>> songName;
    filePath = f"filepath/{songName}.mp3"; // Assuming the file is in the same directory
    PlaySound(filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}
void pauseSong()
{
    // Pause the music
    PlaySound(0,0,0);
}
void showFolderContents(string folderName)
{
     struct dirent *d;
     struct stat dst;

     DIR *dr;
     string path = ".\\";
     dr = opendir(path.c_str());
     if (dr == NULL) {
         for (d = readdir(dr); d!= NULL; d= readdir(dr)) {
            string type = d -> d_name;
            type = path + type;
            if(stat(type.c_str(), &dst)==0)
            {
               if (dst.st_mode & S_IFDIR){
                    type = "is a Folder";
               }
               else if  (dst.st_mode & S_IFREG){
                    type = "is a File";
               }
            }
            cout << d ->d_name <<endl <<type<<endl;

         }
     }
     else{
          cout<<"ERROR"<<endl;
     }
     getch();
}
int main()
{
     cout << "Welcome to the Music Player!" << endl;
     cout << "This is a simple music player application." << endl;
     cout << "You can play, pause, and stop music tracks." << endl;
     string folderName;
     cout << "Enter folder path to choose from: ";
     cin >> folderName;

     // Here we would normally read the folder path and list the music files.
     // For simplicity, we will just simulate this with a placeholder.

     // Here we will print out the music files. (try and limit it to 10 files)
     // for x in folder_path{
     //     cout << "{i}. {x}" << endl;
     // }
     cout << "Type 'play <track_number>' to play a specific track." << endl;

     // While track is being played have the options available:
     cout << "Type 'pause' to pause the current track." << endl;
     cout << "Type 'skip' to stop the current track." << endl;
     cout << "Type 'exit' to stop the current track." << endl;
     // End the program when they type 'exit or the file ends.


    return 0;
}
