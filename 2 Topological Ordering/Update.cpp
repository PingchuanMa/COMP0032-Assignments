#include <iostream>
#include <vector>
using namespace std;

int main() {

    // declare variations
    int vertice, edge;
    int start, end;

    // set the number of vertice and edge
    cin >> vertice >> edge;

    // initialize the graph with all value := false
    vector<vector<bool> > graph(vertice, vector<bool>(vertice, false));
    vector<bool> isDeleted(vertice, false);
    vector<int> inDegree(vertice, 0);
    vector<int> outDegree(vertice, 0);
    vector<int> ans;
    ans.reserve(vertice);

    // build the edges for the graph
    for (size_t i = 0; i < edge; ++i) {
        cin >> start >> end;
        graph[start][end] = true;
        ++inDegree[end];
        ++outDegree[start];
    }
    
    // Assume the graph is DAG, search for topological ordering


    return 0;
}