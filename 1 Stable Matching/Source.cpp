#include <iostream>
using namespace std;
int main()
{
    int preset;
    cin >> preset;
    int** rankMan = new int*[preset];
    int** rankWoman = new int*[preset];
    int* match = new int[preset];
    int* proposed = new int[preset];
    bool isDone = 0;
    for (int i = 0; i < preset; i++) {
        rankMan[i] = new int[preset];
        for (int j = 0; j < preset; j++) {
            cin >> rankMan[i][j];
        }
        match[i] = -1;
        proposed[i] = -1;
    }
    for (int i = 0; i < preset; i++) {
        rankWoman[i] = new int[preset];
        for (int j = 0; j < preset; j++) {
            cin >> rankWoman[i][j];
        }
    }
    while (isDone == 0) {
        isDone = 1;
        for (int theMan = 0; theMan < preset; theMan++) {
            if (match[theMan] == -1) {
                int dateWith = -1;
                isDone = 0;
                proposed[theMan]++;
                for (int j = 0; j < preset; j++) {
                    if (match[j] == rankMan[theMan][proposed[theMan]] - 1) {
                        dateWith = j;
                    }
                }
                if (dateWith != -1) {
                    int ranka, rankb;
                    for (int j = 0; j < preset; j++) {
                        if (rankWoman[rankMan[theMan][proposed[theMan]] - 1][j] - 1 == theMan) {
                            ranka = j;
                        }
                        if (rankWoman[rankMan[theMan][proposed[theMan]] - 1][j] - 1 == dateWith) {
                            rankb = j;
                        }
                    }
                    if (ranka < rankb) {
                        match[theMan] = rankMan[theMan][proposed[theMan]] - 1;
                        match[dateWith] = -1;
                    }
                }
                else {
                    match[theMan] = rankMan[theMan][proposed[theMan]] - 1;
                }
            }
        }
    }
    for (int i = 0; i < preset; i++) {
        cout << match[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}