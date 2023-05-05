#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

map<string,int> config(){
  ifstream fin;
  fin.open("config.txt");
  if (fin.fail()){
    cout << "Cannot open configuration file from ./src" << endl;
  }

  map<string,int> configMap;
  string key_name;
  int key_int;
  while (!fin.eof()){
    fin >> key_name >> key_int;
    configMap[key_name] = key_int;
  }

  fin.close();
  return configMap;
}
