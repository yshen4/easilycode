/*
 * g++ -g longestsequence.cpp -std=c++11
 * unorderd_map requires c++11
 * */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int longestsequence(int *data, int n) {
    unordered_map<int, bool> used;
    for(int i=0; i < n; ++i) used[data[i]] = false;

    int longest = 0;
    for(int i=0; i < n; ++i) {
        if (used[data[i]]) continue;
        
        int length = 1;
        //check the sequence length
        for(int c = data[i] + 1; used.find(c) != used.end(); ++c) {
            used[c] = true;
            ++length;
        }
            
        for(int c = data[i] - 1; used.find(c) != used.end(); --c) {
            used[c] = true;
            ++length;
        }

        if (length > longest) longest = length;
    }

    return longest;
}

int main(void) {
    int data[] = {100, 1, 200, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0, 2, 3, -400, 4};
    cout<<longestsequence(data, sizeof(data)/sizeof(int))<<endl;
}
