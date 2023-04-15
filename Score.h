#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Score {
   public:
    Score(std::vector<int>& h) : scores(h){};
    int getLast100();
    static std::vector<int> getHistory();

   private:
    std::vector<int> scores;
    static bool fileExists(const std::string& filename) {
        // std::cout << filename;
        std::ifstream infile(filename);
        bool res = infile.good();
        // std::cout << res;
        infile.close();
        return res;
    }
};
