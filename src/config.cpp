// config.cpp

#include "config.h"
using namespace std;

map<string, int> config() {
    ifstream fin;
    fin.open("config.txt");
    map<string, int> finalmap;
    finalmap["up"] = 259;
    finalmap["down"] = 258;
    finalmap["left"] = 260;
    finalmap["right"] = 261;
    finalmap["place"] = 32;
    finalmap["enter"] = 10;
    finalmap["backspace"] = 263;
    finalmap["none"] = -1;
    vector<string> listshould;
    listshould.insert(listshould.end(), {"up", "down", "left", "right", "place",
                                         "enter", "backplace", "none"});

    if (fin.fail()) {
        fin.close();
        ofstream fout;
        fout.open("config.txt");
        fout << "up 259" << endl;
        fout << "down 258" << endl;
        fout << "left 260" << endl;
        fout << "right 261" << endl;
        fout << "place 32" << endl;
        fout << "enter 10" << endl;
        fout << "backspace 263" << endl;
        fout << "none -1" << endl;
        fout.close();
        return finalmap;
    }
    // check whether config.txt contains all the settings
    // otherwise return the default map
    vector<string> keylist;
    map<string, int> configMap;
    string key_name;
    int key_int;
    while (!fin.eof()) {
        fin >> key_name >> key_int;
        configMap[key_name] = key_int;
    }
    for (auto const& imap : configMap) keylist.push_back(imap.first);
    for (auto const& imap : configMap) {
        if (find(listshould.begin(), listshould.end(), imap) !=
            listshould.end()) {
            fin.close();
            ofstream fout;
            fout.open("config.txt");
            fout << "up 259" << endl;
            fout << "down 258" << endl;
            fout << "left 260" << endl;
            fout << "right 261" << endl;
            fout << "place 32" << endl;
            fout << "enter 10" << endl;
            fout << "backspace 263" << endl;
            fout << "none -1" << endl;
            fout.close();
            return finalmap;
        }

        fin.close();
        return configMap;
    }
}
