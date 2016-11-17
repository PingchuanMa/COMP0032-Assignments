#include <iostream>
#include <vector>
using namespace std;

// judge if the matrix is empty
bool isEmpty(int* numInput, int* numOutput, int vertice) {
    for (int i = 0; i < vertice; i++) {
        if (numInput[i] > 0 || numOutput[i] > 0) {
            return false;
        }
    }
    return true;
}

// search the index number with the value "finding" in loop
int find(const vector<int>& loop, int finding) {
    for (int i = 0; i < (int)loop.size() - 1; ++i) {
        if (loop[i] == finding) {
            return i;
        }
    }
    return -1;
}

// swap the "index"th nubmer and the number which is "i" in topo
void swap(int* topo, int index, int i) {
    int temp;
    int iIndex = 0;
    while (1) {
        if (topo[iIndex] == i) {
            break;
        }
        iIndex++;
    }
    temp = topo[index];
    topo[index] = i;
    topo[iIndex] = temp;
}

// delete a vertice
void deleteV(int* numInput, int* numOutput, bool** matrix, int vertice, int index) {
    numInput[index] = 0;
    numOutput[index] = 0;
    for (int i = 0; i < vertice; i++) {
        if (matrix[index][i]) {
            matrix[index][i] = false;
            numInput[i]--;
        }
        if (matrix[i][index]) {
            matrix[i][index] = false;
            numOutput[i]--;
        }
    }
}

int main()
{
    int vertice, edge;
    int start, end;
    cin >> vertice >> edge;
    bool** matrix = new bool*[vertice];
    int* topo = new int[vertice];
    vector<int> loop;
    int* numInput = new int[vertice];
    int* numOutput = new int[vertice];
    int index = 0;
    bool isDAG = true;

    //	initialize
    for (int i = 0; i < vertice; i++) {
        matrix[i] = new bool[vertice];
        numInput[i] = 0;
        numOutput[i] = 0;
        topo[i] = i;
        for (int j = 0; j < vertice; j++) {
            matrix[i][j] = false;
        }
    }

    // input
    for (int i = 0; i < edge; i++) {
        cin >> start >> end;
        matrix[start - 1][end - 1] = true;
        numOutput[start - 1]++;
        numInput[end - 1]++;
    }

    while (!isEmpty(numInput, numOutput, vertice) && isDAG) {
        isDAG = false;
        for (int i = 0; i < vertice; i++) {
            if (numInput[i] == 0 && numOutput[i] != 0) {
                deleteV(numInput, numOutput, matrix, vertice, i);
                swap(topo, index++, i);
                isDAG = true;
                break;
            }
        }
    }
    if (isDAG) {
        cout << "YES" << endl;
        for (int i = 0; i < vertice; i++) {
            cout << topo[i] + 1;
            if (i != vertice - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }
    else {
        while (1) {
            bool isPureLoop = true;
            for (int i = 0; i < vertice; ++i) {
                if (numInput[i] > 0 && numOutput[i] == 0) {
                    deleteV(numInput, numOutput, matrix, vertice, i);
                    isPureLoop = false;
                    break;
                }
            }
            if (isPureLoop) {
                break;
            }
        }
        int next = -1;
        int loopStart = 0;
        for (int j = 0; j < vertice; j++) {
            if (numOutput[j] != 0) {
                for (int k = 0; k < vertice; k++) {
                    if (matrix[j][k]) {
                        next = k;
                        loop.push_back(next);
                        break;
                    }
                }
                break;
            }
        }
        while ((loopStart = find(loop, next)) == -1) {
            for (int i = 0; i < vertice; ++i) {
                if (matrix[next][i]) {
                    next = i;
                    loop.push_back(next);
                    break;
                }
            }
        }
        cout << "NO" << endl;
        for (int i = loopStart; i < (int)loop.size(); ++i) {
            cout << loop[i] + 1;
            if (i != (int)loop.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }
    return 0;
}