/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Chaitanya Nookala and Jasreet Kaur 
Your team alias: late_sub:)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now
    Node** table = new Node*[k];
    for (int i = 0; i < k; i++) {
        table[i] = NULL;
    }
 
    for (int i = 0; i < n; i++) {
        int idx = hash_function(texts[i]) % k;
        Node* node = new Node;
        node->key = texts[i];
        node->next = NULL;
        if (table[idx] == NULL) {
            table[idx] = node;
        } else {
            Node* cur = table[idx];
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = node;
        }
    }
 
    
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    for (int i = 0; i < 5 && i < k; i++) {
        cout << "Slot " << i << ":";
        for (Node* cur = table[i]; cur != NULL; cur = cur->next) {
            cout << " " << cur->key;
        }
        cout << endl;
    }
 
 
    cout << "==== Printing the slot lengths ====" << endl;
    int* lengths = new int[k];
    for (int i = 0; i < k; i++) {
        lengths[i] = 0;
        for (Node* cur = table[i]; cur != NULL; cur = cur->next) {
            lengths[i]++;
        }
        cout << "Slot " << i << ": " << lengths[i] << endl;
    }
 
 
    cout << "==== Printing the standard deviation =====" << endl;
    double mean = (double)n / (double)k;
    double sum = 0.0;
    for (int i = 0; i < k; i++) {
        double diff = (double)lengths[i] - mean;
        sum += diff * diff;
    }
    cout << fixed << setprecision(4) << sqrt(sum / (double)k) << endl;
 
    // Free memory
    for (int i = 0; i < k; i++) {
        Node* cur = table[i];
        while (cur != NULL) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
    delete[] table;
    delete[] lengths;
 
    return 0;
}