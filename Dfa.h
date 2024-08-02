#pragma once

#include <vector>
#include <string>
#include <algorithm>

class DFA {
public:
    DFA(const std::string& pattern);
    bool search(const std::string& text);

private:
    std::vector<std::vector<int>> transitionTable;
    std::string pattern;
};
