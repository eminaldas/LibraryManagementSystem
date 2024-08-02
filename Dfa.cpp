#include "Dfa.h"

DFA::DFA(const std::string& pattern) : pattern(pattern) {
    int m = pattern.length();
    int numOfChars = 128;// ASCII karakter sayýsý

  
    transitionTable.resize(m + 1, std::vector<int>(numOfChars, 0));

    // Geçiþleri doldur
    for (int state = 0; state <= m; ++state) {
        for (int charIndex = 0; charIndex < numOfChars; ++charIndex) {
            int nextState = std::min(m, state + 1);
            while (nextState > 0 && pattern[nextState - 1] != charIndex) {
                nextState = transitionTable[nextState - 1][charIndex];
            }
            transitionTable[state][charIndex] = nextState;
        }
    }
}

bool DFA::search(const std::string& text) {
    int n = text.length();
    int m = pattern.length();
    int currentState = 0;

    for (int i = 0; i < n; ++i) {
        currentState = transitionTable[currentState][std::tolower(text[i])];

        if (currentState == m) {
            // Desen bulundu
            return true;
        }
    }

    // Desen bulunamadý
    return false;
}
