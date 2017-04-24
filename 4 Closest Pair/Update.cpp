#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define dst(p1, p2) ((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second))
using namespace std;
typedef pair<float, float> point;
typedef pair<point, point> match;
bool compX(const point &p1, const point &p2) { return p1.first < p2.first; }
float closest(int left, int right, const vector<point> &points) {
    if (left == right) { return 3E38F; }
    if (left + 1 == right) { return dst(points[left], points[right]); }
}
int main()
{
    int num = 0;
    float x, y;
    cin >> num;
    vector<point> points;
    for (int i = 0; i < num; ++i) {
        cin >> x >> y;
        points.push_back(point(x, y));
    }
    sort(points.begin(), points.end(), compX);
    float min = closest(0, points.size() - 1, points);
}