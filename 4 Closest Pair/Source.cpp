#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef pair<int, int> point;
typedef pair<point, point> points;
bool less_x(const point &p1, const point &p2) {
    return p1.first < p2.first;
}
int sq_dist(const point& p1, const point& p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) *(p1.second - p2.second);
}
int sq_dist(const points& p) {
    return (p.first.first - p.second.first) * (p.first.first - p.second.first) + (p.first.second - p.second.second) *(p.first.second - p.second.second);
}
int closest_pair_rec(int left, int right, const vector<point>& px) {
    if (left == right) {
        return 2147483647;
    }
    if (left + 1 == right) {
        return sq_dist(px[left], px[right]);
    }
    if (left + 2 == right) {
        int min = sq_dist(px[left], px[left + 1]);
        if (min > sq_dist(px[left + 1], px[right])) {
            min = sq_dist(px[left + 1], px[right]);
        }
        if (min > sq_dist(px[left], px[right])) {
            return sq_dist(px[left], px[right]);
        }
        return min;
    }
    const int mid = (left + right) / 2;
    int l_min = closest_pair_rec(left, mid, px);
    int r_min = closest_pair_rec(mid + 1, right, px);
    const int delta = (int)sqrt(min(l_min, r_min)) + 1;
    int lr_min = min(l_min, r_min);
    for (int i = mid; i >= left && px[mid].first - px[i].first <= delta; --i) {
        for (int j = mid + 1; j <= right && px[j].first - px[mid].first <= delta; ++j) {
            if (px[i].second - px[j].second <= delta && px[i].second - px[j].second >= -delta) {
                int temp = sq_dist(px[i], px[j]);
                if (temp < lr_min) {
                    lr_min = temp;
                }
            }
        }
    }
    return lr_min;
}
int main()
{
    int num_of_point = 0;
    int x, y;
    cin >> num_of_point;
    vector<point> px;
    for (int i = 0; i < num_of_point; ++i) {
        cin >> x >> y;
        px.push_back(point(x, y));
    }
    sort(px.begin(), px.end(), less_x);
    int min = closest_pair_rec(0, px.size() - 1, px);
    cout << min;
    return 0;
}