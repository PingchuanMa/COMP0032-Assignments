#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int preset;
    int temp;
    cin >> preset;
    vector<queue<int> > rankM(preset, queue<int>());
    vector<vector<int> > rankW(preset, vector<int>(preset));
    vector<int> ans(preset, -1);
    queue<int> men;
    for (int i = 0; i < preset; men.push(i++));
    for (int i = 0; i < preset; ++i) {
        for (int j = 0; j < preset; ++j) {
            cin >> temp;
            rankM[i].push(temp);
        }
    }
    for (int i = 0; i < preset; ++i) {
        for (int j = 0; i < preset; ++j) {
            cin >> temp;
            rankW[i][temp - 1] = j;
        }
    }
    while (men.empty() != true) {

    }
}