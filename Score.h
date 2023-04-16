#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Score {
   public:
    Score(std::vector<int>& h) : scores(h){};
    int getLast100();
    static std::vector<int> getHistory();
    void showProgress();

   private:
    std::vector<int> scores;
    static bool fileExists(const std::string& filename) {
        std::ifstream infile(filename);
        bool res = infile.good();
        infile.close();
        return res;
    }
};
