#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>  
#include <windows.h>
#include <unordered_set>
#include <filesystem>
#include <cctype> 


using namespace std;
namespace fs=filesystem;

class Node {
public:
   
    string name; 
    vector<string> children;
    vector<string>subchildren;
    vector<string> leaf;
    string rootPath;
    
    void addroot(string name, string path) {
       string dirPath = path + "\\" + name;
       rootPath = dirPath + "\\";
        if (!fs::exists(dirPath)) {
            fs::create_directories(dirPath);
        }
    }

   void addChild(string childName) {
        children.push_back(childName);
        string fullPath = rootPath + childName;
        if (!fs::exists(fullPath)) {
            fs::create_directories(fullPath);
        }

    }
   
   
    void addleaf(string childName,int level) {
        string yol;
        string fullPath;
            if (level == 0) {
                
                subchildren.push_back(childName);
                
                yol = rootPath + children[level] + "\\";
                 fullPath = yol + childName;
                if (!fs::exists(fullPath)) {
                    fs::create_directories(fullPath);
                }
            }
            else if(level==1){

                subchildren.push_back(childName);
                 fullPath = rootPath + children[level] + "\\" + childName;
                if (!fs::exists(fullPath)) {
                    fs::create_directories(fullPath);
                }
            }
            else if (level == 2) {
                subchildren.push_back(childName);
                fullPath = rootPath + children[level] + "\\" + childName;
                if (!fs::exists(fullPath)) {
                    fs::create_directories(fullPath);
                }
            }
        }

    void intoAddleaf(string childName, int level,int sublevel) {
        string yol;
        string fullPath;
        if (level == 0) {

            leaf.push_back(childName);

            yol = rootPath + children[level] + "\\" + subchildren[sublevel] + "\\";
            fullPath = yol + childName;
            if (!fs::exists(fullPath)) {
                fs::create_directories(fullPath);
            }
        }
        else if (level == 1) {

            leaf.push_back(childName);
            fullPath = rootPath + children[level] + "\\" + subchildren[sublevel] + "\\"+ childName;
            if (!fs::exists(fullPath)) {
                fs::create_directories(fullPath);
                
            }
        }
        else if (level == 2) {
            leaf.push_back(childName);
            fullPath = rootPath + children[level] + "\\" + subchildren[sublevel] + "\\" + childName;
            if (!fs::exists(fullPath)) {
                fs::create_directories(fullPath);
            }
        }
    }

    void removeIntoLeaf(string childName, int level, int sublevel,int choosen) {
        string yol;
        string fullPath;
        if (choosen == 0) {
            if (level == 0) {


                yol = rootPath + children[level] + "\\" + subchildren[sublevel] + "\\";
                fullPath = yol + childName;
                if (fs::exists(fullPath)) {
                    fs::remove_all(fullPath);
                    cout << fullPath << " silindi" << endl;
                }
            }
            else if (level == 1) {


                fullPath = rootPath + children[level] + "\\" + subchildren[sublevel] + "\\" + childName;
                if (fs::exists(fullPath)) {
                    fs::remove_all(fullPath);
                    cout << fullPath << " silindi" << endl;

                }
            }
            else if (level == 2) {

                fullPath = rootPath + children[level] + "\\" + subchildren[sublevel] + "\\" + childName;
                if (fs::exists(fullPath)) {
                    fs::remove_all(fullPath);
                    cout << fullPath << " silindi" << endl;
                }
            }
        }
        else {
            if (level == 0) {


                yol = rootPath + children[level] + "\\" + subchildren[sublevel] + "\\";
                fullPath = yol + childName;
                if (!fs::exists(fullPath)) {

                    cout << fullPath << " dosya yok" << endl;
                }
                if (fs::exists(fullPath)) {
                    cout << fullPath << "dosya var" << endl;
                }
            }
            else if (level == 1) {


                fullPath = rootPath + children[level] + "\\" + subchildren[sublevel] + "\\" + childName;
                if (!fs::exists(fullPath)) {

                    cout << fullPath << " dosya yok" << endl;
                }
                if (fs::exists(fullPath)) {
                    cout << fullPath << "dosya var" << endl;
                }
            }
            else if (level == 2) {

                fullPath = rootPath + children[level] + "\\" + subchildren[sublevel] + "\\" + childName;
                if (!fs::exists(fullPath)) {

                    cout << fullPath << " dosya yok" << endl;
                }
                if (fs::exists(fullPath)) {
                    cout << fullPath << "dosya var" << endl;
                }
            }

        }
    }

    void removeChild(string childName, int level, int choosen) {
        string yol;
        string fullPath;
        if (choosen == 0) {
            if (level == 0) {


                yol = rootPath + children[level] + "\\";
                fullPath = yol + childName;

                if (fs::exists(fullPath)) {
                    fs::remove_all(fullPath);
                    cout << fullPath << " silindi" << endl;
                }
            }
            else if (level == 1) {


                fullPath = rootPath + children[level] + "\\" + childName;
                if (fs::exists(fullPath)) {
                    fs::remove_all(fullPath);
                    cout << fullPath << " silindi" << endl;

                }
            }
            else if (level == 2) {

                fullPath = rootPath + children[level] + "\\" + childName;
                if (fs::exists(fullPath)) {
                    fs::remove_all(fullPath);
                    cout << fullPath << " silindi" << endl;
                }
            }
        }
        else {
           
            if (level == 0) {


                yol = rootPath + children[level] + "\\";
                fullPath = yol + childName;
                if (!fs::exists(fullPath)) {

                    cout << fullPath << " dosya yok" << endl;
                }
                else if (fs::exists(fullPath)) {
                    
                    cout << fullPath << " dosya var" << endl;
                }
            }
            else if (level == 1) {


                fullPath = rootPath + children[level] + "\\" + childName;
                if (!fs::exists(fullPath)) {

                    cout << fullPath << " dosya yok" << endl;
                }
                else if (fs::exists(fullPath)) {

                    cout << fullPath << " dosya var" << endl;
                }
            }
            else if (level == 2) {

                fullPath = rootPath + children[level] + "\\" + childName;
                if (!fs::exists(fullPath)) {

                    cout << fullPath << " dosya yok" << endl;
                }
                else if (fs::exists(fullPath)) {

                    cout << fullPath << " dosya var" << endl;
                }
            }

        }
    }

    void removeParent(string childName,int choosen) {
        string fullPath = rootPath + childName;
        if (choosen == 0) {
            if (fs::exists(fullPath)) {
                fs::remove_all(fullPath);
                cout << fullPath << " silindi" << endl;
            }
        }
        else {
            if (!fs::exists(fullPath)) {
                
                cout << fullPath << " dosya yok" << endl;
            }
            else if (fs::exists(fullPath)) {
                cout<< fullPath << " dosya var" << endl;
            }
        }

    }

    
    
};



int main() {

    string path = "C:\\Users\\ASUS\\source\\repos\\Lab Uygulaması\\Lab Uygulaması\\";
    Node node;
   
    node.addroot("MediaRoot", path);
    node.addChild("Videos");
    node.addChild("Music");
    node.addChild("Photos");
    node.addleaf("Pop", 1);//0
    node.addleaf("jazz", 1);//1 
    node.addleaf("Documentries", 0);//2
    node.addleaf("Movies", 0);//3
    node.addleaf("Vacations", 2);//4
    node.addleaf("Events", 2);//5
   node.intoAddleaf("track.mp3", 1, 0);
   node.intoAddleaf("track1.mp3", 1, 0);
   node.intoAddleaf("track2.mp3", 1, 1);
   node.intoAddleaf("track3.mp3", 1, 1);
   node.intoAddleaf("photos1.jpg", 2, 4);
   node.intoAddleaf("photos2.jpg", 2, 4);
   node.intoAddleaf("photos3.jpg", 2, 5);
   node.intoAddleaf("photos4.jpg", 2, 5);
   node.intoAddleaf("movies1.mp4", 0, 2);
   node.intoAddleaf("movies2.mp4", 0, 2);
   node.intoAddleaf("movies3.mp4", 0, 3);
   node.intoAddleaf("movies4.mp4", 0, 3);

   
  node.removeIntoLeaf("movies4.mp4", 0, 3,1);
   node.removeChild("Pop", 1,0);
   node.removeParent("Videos",1);
    

    return 0;
}