#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::string, std::vector, std::map, std::ifstream;

class kanas {
   public:
    kanas(const map<string, vector<string>> &m) : japs(m){};
    std::pair<string, string> getRndJap();
    static void playJap(string au);

   private:
    map<string, vector<string>> japs;
};
