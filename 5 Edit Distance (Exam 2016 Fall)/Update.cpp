#include <iostream>
#include <vector>
#include <string>
using namespace std;
int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) return a;
        else return c;
    }
    else {
        if (b < c) return b;
        else return c;
    }
}
int main() {
    string a, b;
    cin >> a >> b;
    vector<int> dist[2];
    dist[0].resize(a.length() + 1);
    dist[1].resize(a.length() + 1);
    int now = 0, other = 0;

    for (int i = 0; i <= a.length(); ++i) {
        dist[0][i] = i;
    }

    for (int i = 1; i <= b.length(); ++i) {
        now = i % 2;
        other = 1 - now;
        dist[now][0] = i;
        for (int j = 1; j <= a.length(); ++j) {
            dist[now][j] = min(dist[other][j - 1] + (b[i - 1] != a[j - 1]), dist[other][j] + 1, dist[now][j - 1] + 1);
        }
    }

    cout << dist[b.length() % 2][a.length()];

    return 0;
}