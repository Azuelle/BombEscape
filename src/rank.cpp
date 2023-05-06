#include "rank.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}
vector<pair<string, int> > getRank() {
    std::ifstream fin;
    vector<pair<string, int> > ranklist, defaultlist;
    fin.open("ranklist.txt");
    defaultlist.push_back(make_pair("xxx1", 0));
    defaultlist.push_back(make_pair("xxx2", 0));
    defaultlist.push_back(make_pair("xxx3", 0));
    if (fin.fail()) {
        fin.close();
        return defaultlist;
    }
    std::string name;
    int score;
    while (!fin.eof()) {
        fin >> name >> score;
        ranklist.push_back(make_pair(name, score));
    }
    if (ranklist.empty()) {
        return defaultlist;
    }
    sort(ranklist.begin(), ranklist.end(), cmp);

    fin.close();
    return ranklist;
}

/*int main() {
    vector<pair<string, int> > rank = getRank();
    vector<pair<string, int> >::iterator itr;
    for (itr = rank.begin(); itr != rank.end(); itr++) {
        cout << (*itr).first << " " << (*itr).second << endl;
    }
    return 0;
}*/
