#include "Score.h"

#include <deque>
#include <fstream>
#include <iostream>
#include <vector>

#include "common.h"

/**
 * get the last 100 total score
 * @return the total score
 */
int Score::getLast100() {
    int count = 0, res = 0;
    for (auto it = scores.rbegin(); count < 10 && it != scores.rend(); ++count, ++it) {
        res += *it;
    }
    return res;
}

/**
 * put score history to a vector and return it
 */
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

/**
 * show score history in graph
 */
void Score::showProgress() {
    int total = 0;
    std::deque<int> que;
    for (int x : scores) {
        total += x;
        que.push_back(x);
        if (que.size() == 11) {
            total -= que.front();
            que.pop_front();
        }
        for (int i = 0; i < 99; ++i) {
            if (i <= total)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << "*" << std::endl;
    }
    std::cout << "                   *                   *                   *                   *                   *"
              << std::endl;
    std::cout << "                  20                  40                  60                  80                 100";
}
