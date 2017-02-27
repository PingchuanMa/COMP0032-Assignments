#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int preset;
    int man, woman;
    cin >> preset;
    vector<queue<int> > rankM(preset, queue<int>());
    vector<vector<int> > rankW(preset, vector<int>(preset));
    vector<int> ansM(preset, -1), ansW(preset, -1);
    queue<int> men;
    for (int i = 0; i < preset; ++i) {
        men.push(i);
        for (int j = 0; j < preset; ++j) {
            cin >> woman;
            rankM[i].push(woman - 1);
        }
    }
    for (int i = 0; i < preset; ++i) {
        for (int j = 0; j < preset; ++j) {
            cin >> man;
            rankW[i][man - 1] = j;
        }
    }
    while (men.empty() != true) {
        man = men.front();
        men.pop();
        while (true) {
            woman = rankM[man].front();
            rankM[man].pop();
            if (ansW[woman] == -1) {
                ansW[woman] = man;
                ansM[man] = woman;
                break;
            }
            else if (rankW[woman][man] < rankW[woman][ansW[woman]]) {
                ansM[ansW[woman]] = -1;
                men.push(ansW[woman]);
                ansW[woman] = man;
                ansM[man] = woman;
                break;
            }
        }
    }
    for (int i = 0; i < preset; ++i) {
        cout << ansM[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}