#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Score {
   public:
    Score(std::vector<int>& h) : scores(h){};
    int getLast100();
    static std::vector<int> getHistory();
    void showProgress();

   private:
    std::vector<int> scores;

    /**
     * check the file of scores exist or not
     *
     * @param filename
     * @return the result
     */
    static bool fileExists(const std::string& filename) {
        std::ifstream infile(filename);
        bool res = infile.good();
        infile.close();
        return res;
    }
};
