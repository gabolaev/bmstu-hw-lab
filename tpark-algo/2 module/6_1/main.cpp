#include <iostream>
#include <vector>
#include <array>
#include <fstream>

#define ALPHABET_SIZE 1000

void countingSort(std::vector<std::string> &words, int from, int to, int letterIndex,
                  std::array<int, ALPHABET_SIZE + 1> &counters) {

    for (auto i = from; i < to; ++i)
        ++counters[words[i][letterIndex]];

    int forLast = 0, tmp;
    for (auto i = 0; i < ALPHABET_SIZE; ++i) {
        tmp = counters[i];
        counters[i] = forLast;
        forLast += tmp;
    }
    counters[ALPHABET_SIZE] = forLast;

    std::vector<std::string> temp(static_cast<unsigned long>(to - from));

    for (auto i = from; i < to; ++i)
        temp[counters[words[i][letterIndex]]++] = words[i];

    for (auto i = from; i < to; ++i)
        words[i] = temp[i - from];

}

void MSDSort(std::vector<std::string> &words, int from, int howMuch, int letterIndex) {
    if (howMuch <= 1) return;

    std::array<int, ALPHABET_SIZE + 1> counters{};

    countingSort(words, from, from + howMuch, letterIndex, counters);

    for (int i = 0; i < ALPHABET_SIZE; ++i)
        MSDSort(words, from + counters[i], counters[i + 1] - counters[i], letterIndex + 1);
}

int main() {

    std::fstream fs;
    fs.open("../all_passes.txt", std::fstream::in);
    std::vector<std::string> words;
    std::string input;
    while(fs >> input)
        words.push_back(input);

    MSDSort(words, 0, static_cast<int>(words.size()), 0);
    for (auto &word : words)
        std::cout << word << std::endl;
    fs.close();
    return 0;
}
