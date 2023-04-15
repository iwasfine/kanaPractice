#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::string, std::vector, std::map, std::ifstream;

class BuildMap {
   public:
    BuildMap(const string &filePath) : file(filePath), reverse(false){};
    BuildMap(const string &filePath, bool r) : file(filePath), reverse(r){};
    map<string, vector<string>> build();

   private:
    string file;
    bool reverse;
};
