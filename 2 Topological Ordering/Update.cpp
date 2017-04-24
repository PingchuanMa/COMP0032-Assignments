#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

	// Declare variations
	int vertice, edges;
	int start, end;

	// Set the number of vertice and edge
	cin >> vertice >> edges;

	// Initialize the graph with all value := false
	vector<vector<bool> > graph(vertice, vector<bool>(vertice, false));
	set<int> verticeSet;
	vector<int> inDegree(vertice, 0);
	vector<int> outDegree(vertice, 0);
	bool isDAG = true;
	vector<int> answer;
	answer.reserve(vertice);
	for (size_t i = 0; i < vertice; ++i) {
		verticeSet.insert(i);
	}

	// Build the edges for the graph
	for (size_t i = 0; i < edges; ++i) {
		cin >> start >> end;
		graph[start - 1][end - 1] = true;
		++inDegree[end - 1];
		++outDegree[start - 1];
	}
	
	// Assume that the graph is DAG, search for topological ordering
	while (!verticeSet.empty() && isDAG) {
		isDAG = false;
		for (set<int>::iterator iteOut = verticeSet.begin(); iteOut != verticeSet.end(); ++iteOut) {
			if (inDegree[*iteOut] == 0) {
				isDAG = true;
				for (set<int>::iterator iteIn = verticeSet.begin(); iteIn != verticeSet.end(); ++iteIn) {
					if (graph[*iteOut][*iteIn]) {
						graph[*iteOut][*iteIn] = false;
						--inDegree[*iteIn];
						--outDegree[*iteOut];
					}
				}
				answer.push_back(*iteOut);
				verticeSet.erase(iteOut);
				break;
			}
		}
	}

	// Output a cycle if the graph is not DAG
	if (!isDAG) {
		answer.clear();
		bool hasOnlyCycle = false;
		vector<bool> detector(vertice, false);
		while (!hasOnlyCycle) {
			hasOnlyCycle = true;
			for (set<int>::iterator iteIn = verticeSet.begin(); iteIn != verticeSet.end(); ++iteIn) {
				if (outDegree[*iteIn] == 0) {
					hasOnlyCycle = false;
					for (set<int>::iterator iteOut = verticeSet.begin(); iteOut != verticeSet.end(); ++iteOut) {
						if (graph[*iteOut][*iteIn]) {
							graph[*iteOut][*iteIn] = false;
							--outDegree[*iteOut];
							--inDegree[*iteIn];
						}
					}
					verticeSet.erase(iteIn);
					break;
				}
			}
		}
		int now = *verticeSet.begin();
		detector[now] = true;
		while (true) {
			for (set<int>::iterator ite = verticeSet.begin(); ite != verticeSet.end(); ++ite) {
				if (graph[now][*ite]) {
					now = *ite;
					break;
				}
			}
			if (detector[now] == true) { break; }
			else { detector[now] = true; }
		}
		answer.push_back(now);
		while (true) {
			for (set<int>::iterator ite = verticeSet.begin(); ite != verticeSet.end(); ++ite) {
				if (graph[now][*ite]) {
					now = *ite;
					break;
				}
			}
			answer.push_back(now);
			if (now == answer[0]) { break; }
		}
	}
	cout << (isDAG ? "YES" : "NO") << endl;
	for (size_t i = 0; i < answer.size(); ++i) {
		cout << answer[i] + 1;
		if (i != answer.size() - 1) { cout << ','; }
	}
	cout << endl;
	return 0;
}