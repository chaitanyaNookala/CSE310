#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

struct Node {
    string key;
    Node* next;
};

int hash_function(string text);