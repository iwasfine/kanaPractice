#include "kanas.h"

#include <random>

#include "common.h"

/**
 * get a random kana from japs map
 * @return return kana and pronouce in pair
 */
std::pair<string, string> kanas::getRndJap() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rndAudio(0, japs.size() - 1);
    auto it = japs.begin();
    std::advance(it, rndAudio(rng));
    std::uniform_int_distribution<std::mt19937::result_type> rndChar(0, (it->second).size() - 1);
    return {it->first, it->second[rndChar(rng)]};
}

/**
 * play the audio of the kana
 * @param the roman character of the kana
 */
void kanas::playJap(string au) {
    string name;
    name = PROJECTPATH + "audio/" + au + ".mp3";
    string command = "mpg123 " + name + " > /dev/null 2>&1";
    std::system(command.c_str());
}
