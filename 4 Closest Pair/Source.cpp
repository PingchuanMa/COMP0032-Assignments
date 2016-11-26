#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<unsigned int, unsigned int> point;
typedef pair<point, point> points;
bool less_x(const point &p1, const point &p2) {
    return p1.first < p2.first;
}
bool less_y(const point &p1, const point &p2) {
    return p1.second < p2.second;
}
unsigned int sq_dist(const point& p1, const point& p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) *(p1.second - p2.second);
}
unsigned int sq_dist(const points& p) {
    return (p.first.first - p.second.first) * (p.first.first - p.second.first) + (p.first.second - p.second.second) *(p.first.second - p.second.second);
}
points closest_pair_rec(unsigned int px_l, unsigned int py_l, unsigned int range, const vector<point>& px, const vector<point>& py) {
    // p_r = p_l + range
    if (range == 1) {
        return points(px[px_l], px[px_l + 1]);
    }
    if (range == 2) {
        points min(px[px_l], px[px_l + 1]);
        if (sq_dist(min) > sq_dist(px[px_l + 1], px[px_l + 2])) {
            min = points(px[px_l + 1], px[px_l + 2]);
        }
        if (sq_dist(min) > sq_dist(px[px_l], px[px_l + 2])) {
            return points(px[px_l], px[px_l + 2]);
        }
        return min;
    }
    unsigned int middle_y = binary_search(py.begin() + py_l, py.begin() + py_l + range, px[px_l + range / 2].second);
    points left = closest_pair_rec(px_l, );
    
}
int main()
{
    unsigned int num_of_point = 0;
    unsigned int x, y;
    cin >> num_of_point;
    vector<point> px;
    for (int i = 0; i < num_of_point; ++i) {
        cin >> x >> y;
        px.push_back(point(x, y));
    }
    vector<point> py(px);
    sort(px.begin(), px.end(), less_x);
    sort(py.begin(), py.end(), less_y);
    points min = closest_pair_rec(0, 0, px.size() - 1, px, py);
    return 0;
}