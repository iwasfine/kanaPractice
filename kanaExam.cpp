#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

#include "BuildMap.h"
#include "Score.h"
#include "common.h"
#include "kanas.h"

int exam(kanas japs, std::default_random_engine &rng);
void showAll(vector<std::pair<string, string>> showList);

int main(int argc, char *argv[]) {
    string f = PROJECTPATH + "mapping";
    BuildMap bm(f);
    auto s = bm.build();
    kanas japs(s);
    auto rng = std::default_random_engine{};
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::ofstream outfile(PROJECTPATH + "scores", std::ios::app);
    if (!outfile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }
    int score = 0;
    for (int i = 0; i < 10; ++i) {
        std::cout << "\033[34m" << i + 1 << "  "
                  << "\033[0m";
        score += exam(japs, rng);
    }
    outfile << score << " ";
    outfile.close();
    auto h = Score::getHistory();
    Score current(h);
    std::cout << "You got " << current.getLast100() << " right out of last 100." << std::endl;
    std::cout << "Do you want to see your progress?(y/n): ";
    std::string yn;
    if (std::cin >> yn && yn == "y") current.showProgress();
    return 0;
}

/**
 * one exam, show random 10 kanas and a pronouce, take a anwser, judge right or wrong
 *
 * @param kanas japs
 * @param rng: random genarator
 * @return int: score of this exam
 */
int exam(kanas japs, std::default_random_engine &rng) {
    vector<std::pair<string, string>> showList;
    for (int i = 0; i < 10; ++i) {
        auto p = japs.getRndJap();
        showList.push_back(p);
    }
    string result = showList[0].first;
    string rightAnwser = showList[0].second;
    std::shuffle(std::begin(showList), std::end(showList), rng);
    kanas::playJap(result);
    for (int i = 0; i < 10; ++i) {
        std::cout << i << "."
                  << "\033[33m" << showList[i].second << "  "
                  << "\033[0m";
    }
    std::cout << std::endl;
    int anwser;
    std::cout << "Which one is it? : ";
    if (std::cin >> anwser && anwser >= 0 && anwser < 10 && showList[anwser].first == result) {
        showAll(showList);
        std::cout << "\033[32m"
                  << ""
                  << "\033[0m" << std::endl
                  << std::endl;
        return 1;
    } else {
        showAll(showList);
        std::cout << "\033[31m"
                  << ""
                  << "\033[0m"
                  << " The right anwser is "
                  << "\033[32m" << rightAnwser << result << "\033[0m" << std::endl
                  << std::endl;
        std::cin.clear();  // clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 0;
    }
}

/**
 * output the candidates
 *
 * @param showList: vector of candidates
 */
void showAll(vector<std::pair<string, string>> showList) {
    for (auto p : showList) {
        std::cout << p.second << "\033[32m" << p.first << "  "
                  << "\033[0m";
    }
    std::cout << std::endl;
}
