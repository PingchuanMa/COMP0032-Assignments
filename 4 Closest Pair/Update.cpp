#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#define dst(p1, p2) ((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second))
using namespace std;
typedef pair<float, float> point;
bool compX(const point &p1, const point &p2) { return p1.first < p2.first; }
bool compY(const point &p1, const point &p2) { return p1.second < p2.second; }
vector<point> px;
float closest(int left, int right, const vector<point> &py) {
    if (left == right) { return 3E38F; }
    if (left + 1 == right) { return dst(px[left], px[right]); }
    if (left + 2 == right) {
        float temp = min(dst(px[left], px[left + 1]), dst(px[left + 1], px[right]));
        return min(temp, dst(px[left], px[right]));
    }
    const int mid = (left + right) / 2;
    const float xl = px[left].first, xr = px[right].first, xm = px[mid].first;
    vector<point> pyl, pyr, bar;
    for (int i = 0; i < py.size(); ++i) {
        if (py[i].first >= xl && py[i].first <= xm) { pyl.push_back(py[i]); }
        if (py[i].first > xm && py[i].first <= xr) { pyr.push_back(py[i]); }
    }
    float minL = closest(left, mid, pyl);
    float minR = closest(mid + 1, right, pyr);
    float minLR = min(minL, minR);
    const float delta = minLR;
    for (int i = 0; i < py.size(); ++i) {
        if (py[i].first <= xm + delta && py[i].first >= xm - delta) { bar.push_back(py[i]); }
    }
    for (int i = 0; i < bar.size(); ++i) {
        for (int j = i + 1; j < bar.size() && j < i + 12; ++j) {
            if (dst(bar[i], bar[j]) < minLR) { minLR = dst(bar[i], bar[j]); }
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
    }
    vector<point> py(px);
    sort(px.begin(), px.end(), compX);
    sort(py.begin(), py.end(), compY);
    float min = closest(0, num - 1, py);
    printf("%.2f\n", min);
    return 0;
}