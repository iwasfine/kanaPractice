#include "BuildMap.h"

/**
 * build a map from the file.
 */
map<string, vector<string>> BuildMap::build() {
    ifstream f;
    map<string, vector<string>> ret;
    f.exceptions(ifstream::badbit);  // No need to check failbit
    try {
        f.open(file);
        string ch1, ch2;
        while ((f >> ch1) && (f >> ch2)) {
            if (reverse)
                ret[ch1].push_back(ch2);
            else
                ret[ch2].push_back(ch1);
        }
        // for line-oriented input use file.getline(s)
    } catch (const ifstream::failure& e) {
        std::cout << "Error on opening/reading file";
    }
    f.close();
    return ret;
}
