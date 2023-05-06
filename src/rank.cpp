#include "rank.h"

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

// Create a default ranklist.txt
inline void createDefaultRanklist() {
    ofstream fout("ranklist.txt");
    for (auto i : defaultRank) fout << i.first << " " << i.second << endl;
    fout.close();
}

// To get rank from ranklist.txt
// return a vector pair containing the username and score.
vector<pair<string, int>> getRank() {
    std::ifstream fin;
    vector<pair<string, int>> ranklist;
    fin.open("ranklist.txt");
    if (fin.fail()) {
        log("Failed to load ranklist, creating default list");
        createDefaultRanklist();
        fin.close();
        return ranklist;
    }
    string name;
    int score;
    while (!fin.eof()) {
        fin >> name >> score;
        ranklist.push_back(make_pair(name, score));
    }
    ranklist.pop_back();
    fin.close();

    sort(ranklist.begin(), ranklist.end(), cmp);

    return ranklist;
}

// Add the current record to the ranklist
void addRank(long long score) {
    string username = (getlogin() ? getlogin() : "AnonymousWizard");
    ofstream fout("ranklist.txt", ios::app);
    fout << username << " " << score << endl;
}
