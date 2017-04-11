#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge {
    int end, power;
    edge(int x, int y) : end(x), power(y) {}
    friend bool operator< (const edge& e1, const edge& e2) { return e1.power > e2.power; }
};
int main() {
    int edges, vertice;
    int start, end, power;  // the parameters for a edge
    int sum = 0;    // the sum of selected edges
    cin >> vertice >> edges;
    priority_queue<edge> candidates; // the edges waiting to be selected
    vector<bool> selected(vertice, false);   // the selected edges
    vector<edge> *graph = new vector<edge>[vertice];    // define the graph
    for (int i = 0; i < edges; ++i) {   // initialize the graph
        cin >> start >> end >> power;
        graph[start - 1].push_back(edge(end - 1, power));
        graph[end - 1].push_back(edge(start - 1, power));
    }
    selected[0] = true;
    for (int i = 0, now = 0; i < vertice - 1; ++i) {
        for (int j = 0; j < graph[now].size(); ++j) {
            if (!selected[graph[now][j].end]) {
                candidates.push(graph[now][j]); // add edges into the priority queue
            }
        }
        while (selected[candidates.top().end]) {
            candidates.pop();   // delete the cycle-making edges
        }
        now = candidates.top().end; // decide next vertex
        selected[now] = true;   // mark the map
        sum += candidates.top().power;
        candidates.pop();
    }
    cout << sum << endl;
    return 0;
}