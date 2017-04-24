#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#define dst(p1, p2) ((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second))
#define shorter(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
typedef pair<float, float> point;
bool compX(const point &p1, const point &p2) { return p1.first < p2.first; }
bool compY(const point &p1, const point &p2) { return p1.second < p2.second; }
vector<point> px, py;
float closest(int left, int right, const vector<int> &indexY) {
    if (left == right) { return 3E38F; }
    if (left + 1 == right) { return dst(px[left], px[right]); }
    if (left + 2 == right) {
        float temp = shorter(dst(px[left], px[left + 1]), dst(px[left + 1], px[right]));
        return shorter(temp, dst(px[left], px[right]));
    }
    const int mid = (left + right) / 2;
    const float xl = px[left].first, xr = px[right].first, xm = px[mid].first;
    vector<int> pyl, pyr, bar;
    int index = 0;
    for (int i = 0; i < indexY.size(); ++i) {
        index = py[indexY[i]].first;
        if (index >= xl && index <= xm) { pyl.push_back(indexY[i]); }
        if (index > xm && index <= xr) { pyr.push_back(indexY[i]); }
    }
    float minL = closest(left, mid, pyl);
    float minR = closest(mid + 1, right, pyr);
    float minLR = shorter(minL, minR);
    for (int i = 0; i < indexY.size(); ++i) {
        if (py[indexY[i]].first <= xm + minLR && py[indexY[i]].first >= xm - minLR) { bar.push_back(indexY[i]); }
    }
    for (int i = 0; i < bar.size(); ++i) {
        for (int j = i + 1; j < bar.size() && j < i + 12; ++j) {
            if (dst(py[bar[i]], py[bar[j]]) < minLR) { minLR = dst(py[bar[i]], py[bar[j]]); }
        }
    }
    return minLR;
}
int main()
{
    int num;
    float x, y;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%f %f", &x, &y);
        px.push_back(point(x, y));
        py.push_back(point(x, y));
    }
    sort(px.begin(), px.end(), compX);
    sort(py.begin(), py.end(), compY);
    vector<int> indexY(num);
    for (int i = 0; i < num; ++i) { indexY[i] = i; }
    float min = closest(0, num - 1, indexY);
    printf("%.2f\n", min);
    return 0;
}