#include "Score.h"

#include <fstream>
#include <iostream>
#include <vector>

int Score::getLast100() {
    int count = 0, res = 0;
    // for (auto x : scores) std::cout << x;
    for (auto it = scores.rbegin(); count < 10 && it != scores.rend(); ++count, ++it) {
        res += *it;
        // std::cout << *it;
    }
    return res;
}

std::vector<int> Score::getHistory() {
    std::vector<int> res;
    std::string fileName = "/home/iwasfine/repos/kanaPractice/scores";
    if (!fileExists(fileName)) return res;
    // std::cout << "exists";
    std::ifstream f(fileName);
    int s;
    while (f >> s) {
        // std::cout << "push";
        res.push_back(s);
    }
    return res;
}
