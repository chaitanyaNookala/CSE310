#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int hash_function(string text) {
    const int P = 12345701;
    int h1 = 0;
    int len = text.length();
 
    for (int i = 0; i < len; i++) {
        int c = text[i];
        if (c < 0) c += 256;
        h1 = (h1 * 53 + c + 1) % P;        // single left-to-right pass
    }
 
    int h = (h1 + len * 4813) % P;
    h = h ^ (h >> 9);
    h = (h % P) * 11 % P;
    h = (h ^ (h << 3)) % P;
    h = h ^ (h >> 6);
 
    return h;
}