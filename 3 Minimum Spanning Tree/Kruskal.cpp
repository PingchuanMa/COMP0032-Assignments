#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> head, tail, weight, index_rank;
vector<int> parent; // make a union-find set using arraylist
bool comparator(int a, int b) {
    return weight[a] < weight[b];
}
int find_parent(int child) {
    int previous = parent[child];
    while (previous != parent[previous]) {
        previous = parent[previous];
    }
    return previous;
}
int main()
{
    int vertex, edge;
    int sum_weight = 0;
    cin >> vertex >> edge;
    int head_in, tail_in, weight_in;
    for (int i = 0; i < edge; ++i) {
        cin >> head_in >> tail_in >> weight_in;
        head.push_back(head_in - 1);
        tail.push_back(tail_in - 1);
        weight.push_back(weight_in);
        index_rank.push_back(i);
    } // make the graph
    sort(index_rank.begin(), index_rank.end(), comparator); // sort the rank of index using their weights
    for (int i = 0; i < vertex; ++i) {
        parent.push_back(i); // set the parent node of every child to itself
    }
    for (int i = 0; i < edge; ++i) {
        int the_head = head[index_rank[i]];
        int the_tail = tail[index_rank[i]];
        int head_parent = find_parent(the_head);
        int tail_parent = find_parent(the_tail);
        if (head_parent != tail_parent) {
            parent[tail_parent] = head_parent; // join it!
            sum_weight += weight[index_rank[i]];
        }
    }
    cout << sum_weight << endl;
    return 0;
}