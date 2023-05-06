// config.cpp

#include "config.h"

using namespace std;

inline void createDefaultConfigFile() {
    ofstream fout("config.txt");
    for (auto i : defaultConfig) fout << i.first << " " << i.second << endl;
    fout.close();
}

map<string, int> getConfig() {
    ifstream fin;
    fin.open("config.txt");

    if (fin.fail()) {
        log("Failed to load config file, creating new file");
        fin.close();
        createDefaultConfigFile();
        return defaultConfig;
    }

    vector<string> key_list;
    map<string, int> config_map;
    string key_name;
    int key_int;

    // Get config from file
    while (!fin.eof()) {
        fin >> key_name >> key_int;
        config_map[key_name] = key_int;
        key_list.push_back(key_name);
    }
    fin.close();

    // Check whether config.txt contains all the settings
    // Otherwise return the default config
    bool found = false;
    for (auto const& req_key : necessaryKeys) {
        found = false;
        for (auto const& k : key_list)
            if (k == req_key) {
                found = true;
                break;
            }
        if (!found) {
            log("Failed to find key \"" + req_key +
                "\", resetting config file");
            break;
        }
    }
    if (!found) {
        createDefaultConfigFile();
        return defaultConfig;
    } else
        return config_map;
}
