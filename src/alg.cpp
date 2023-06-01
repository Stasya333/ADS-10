// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

static const int fact[13] = {
    1, 1, 2, 6, 24, 120, 720, 5040, //
    40320, 362880, 3628800, 39916800, 479001600,
};

std::vector<char> getPerm(const Tree& tree, int n) {
    // напишите реализацию
    if (tree.getSize() == 0 || n > fact[tree.getSize()])
        return {};

    if (tree.getSymb() == '*')
        n--;

    std::vector<char> result;
    int temp = fact[tree.getSize() - 1];

    result.push_back(tree[n / temp].getSymb());
    std::vector<char> a = getPerm(tree[n / temp], n % temp);
    result.insert(result.end(), a.begin(), a.end());

    return result;
}
