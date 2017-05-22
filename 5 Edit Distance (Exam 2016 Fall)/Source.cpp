#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    // initial the distance matrix
    vector<vector<int> > dist(a.length() + 1);
    for (int i = 0; i <= a.length(); ++i) {
        dist[i].resize(b.length() + 1, 0);
        dist[i][0] = i;
    }
    for (int i = 0; i <= b.length(); ++i) {
        dist[0][i] = i;
    }

    // compute the distance for dist[i][j]
    for (int i = 1; i <= a.length(); ++i) {
        for (int j = 1; j <= b.length(); ++j) {
            dist[i][j] = (dist[i - 1][j] < dist[i][j - 1] ? dist[i - 1][j] : dist[i][j - 1]) + 1;
            if (a[i - 1] == b[j - 1]) {
                dist[i][j] = (dist[i][j] < dist[i - 1][j - 1] ? dist[i][j] : dist[i - 1][j - 1]);
            }
            else {
                dist[i][j] = (dist[i][j] < (dist[i - 1][j - 1] + 1) ? dist[i][j] : (dist[i - 1][j - 1] + 1));
            }
        }
    }

    // output the answer
    cout << dist[a.length()][b.length()] << endl;
    return 0;
}