
#include <iostream>
#include <sys\stat.h>
#include <dirent.h>
#include <Windows.h>
#include <vector>
#include <filesystem>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


using namespace std;
namespace fs = std::filesystem;

void chooseSong(string& filePath,const string& folderName)
{
     // Play the music file
     string songName;
    cout << "Which song would you like to play?" << endl;
    cout << "Enter the name of the song (without extension): ";
    getline(cin, songName);
     
    string chosenFile = folderName + "/" + songName + ".wav"; 
    filePath = chosenFile;

    if (!fs::exists(chosenFile)) {
        cout << "ERROR: The file does not exist." << endl;
        filePath = "";
        return;
    }

    PlaySound(filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}

int findSongIndex(const vector<string>& playlist, const string& songName)
{
    for (size_t i = 0; i < playlist.size(); ++i) {
        if (playlist[i] == songName) {
            return i;
        }
    }
    return -1; // Not found
}

bool endsWithWav(const string& fileName){
     if (fileName.length() < 4) return false;
     string ext = fileName.substr(fileName.length() - 4);
     for(auto& c: ext) c = tolower(c);
     return ext == ".wav";
}

vector<string>getFirst10WavFiles(const string& folderName)
{
     struct dirent *d;
     struct stat dst;
     vector <string> files;
     int fileCount = 0;

     DIR *dr = opendir(folderName.c_str());
     if (dr != NULL) {
          while((d=readdir(dr)) !=NULL && fileCount < 10){
               string fileName = d->d_name;
               string fullPath = folderName + "/" + fileName;

               // We check if it's a folder
               if (stat(fullPath.c_str(), &dst) == 0 && S_ISREG(dst.st_mode)&& endsWithWav(fileName) && fileName !="." && fileName!= "..")
               {
                    files.push_back(fullPath);
                    fileCount++;
               }
          }
          closedir(dr);
     }else{
          cout << "ERROR: Could not open "<< folderName << endl;
     }
     return files;
}
int main()
{
     string folderName = "";
     string filePath = "";

     cout << "----------------------------------------" << endl;
     cout << "Welcome to the Music Player!" << endl;
     cout << "This is a simple music player application." << endl;
     cout << "You can play, pause, and stop music tracks." << endl;
     cout << "Enter folder path to choose from: ";

     cin >> folderName;
     cin.ignore();

     vector<string> playlist = getFirst10WavFiles(folderName);
     if(playlist.empty()){
          cout << "No WAV files found!" << endl;
          return 1;
     }

     string currentFile;
     int currentIndex = 0;

     chooseSong(currentFile,folderName);

     if(currentFile.empty() || !fs::exists(currentFile)){
          currentFile = playlist[0];
          PlaySound(currentFile.c_str(), NULL, SND_FILENAME | SND_ASYNC);
     }
     
     currentIndex = findSongIndex(playlist, currentFile);
     if(currentIndex == -1) currentIndex = 0;

     cout << "Now playing: " << currentFile << endl;

     char command;
     while(true){
          cout << "Enter 'n' to skip to next song, 'q' to quit: ";
          cin >> command;
          cin.ignore(); 

          if (command =='q'){
               PlaySound(NULL, NULL, 0); // Stop the sound
               break;
          } else if (command == 'n') {
               PlaySound(NULL, NULL, 0); // Stop the current sound
               currentIndex = (currentIndex + 1)% playlist.size();
               currentFile = playlist[currentIndex];
               PlaySound(currentFile.c_str(),NULL, SND_FILENAME | SND_ASYNC);
               cout << "Now playing: " << currentFile << endl;
          }
     }
    return 0;
}
