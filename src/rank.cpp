#include "rank.h"

#include <fstream>
#include <map>
#include <string>

std::map<std::string, int> getRank() {
    std::ifstream fin;
    std::map<std::string, int> ranklist;
    fin.open("ranklist.txt");
    std::map<std::string, int> defaultmap;
    defaultmap["xxx1"] = 0;
    defaultmap["xxx2"] = 0;
    defaultmap["xxx3"] = 0;
    if (fin.fail()) {
        fin.close();
        return defaultmap;
    }
    std::string name;
    int score;
    while (!fin.eof()) {
        fin >> name >> score;
        ranklist[name] = score;
    }
    if (ranklist.empty()) {
        return defaultmap;
    }
    fin.close();
    return ranklist;

    /*void inputRank(){
        ofstream fout;
        fout.open("ranklist.txt");



    }*/
}
