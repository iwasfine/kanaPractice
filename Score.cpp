#include "Score.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "common.h"

int Score::getLast100() {
    int count = 0, res = 0;
    for (auto it = scores.rbegin(); count < 10 && it != scores.rend(); ++count, ++it) {
        res += *it;
    }
    return res;
}

std::vector<int> Score::getHistory() {
    std::vector<int> res;
    std::string fileName = PROJECTPATH + "scores";
    if (!fileExists(fileName)) return res;
    std::ifstream f(fileName);
    int s;
    while (f >> s) {
        res.push_back(s);
    }
    return res;
}
