#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

// Function to print a path
void printPath(const string& method, const vector<string>& path) {
    cout << method << ": ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1) cout << " → ";
    }
    cout << "   (length " << path.size() - 1 << ")" << endl;
}

// BFS using queue
vector<string> bfs(unordered_map<string, vector<string>>& graph, string start, string goal) {
    queue<vector<string>> q;
    unordered_set<string> visited;
    q.push({start});
    visited.insert(start);

    while (!q.empty()) {
        vector<string> path = q.front();
        q.pop();
        string node = path.back();
        if (node == goal) return path;

        for (string& neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                vector<string> newPath = path;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
    }
    return {};
}

// DFS using stack
vector<string> dfs(unordered_map<string, vector<string>>& graph, string start, string goal) {
    stack<vector<string>> st;
    unordered_set<string> visited;
    st.push({start});

    while (!st.empty()) {
        vector<string> path = st.top();
        st.pop();
        string node = path.back();
        if (node == goal) return path;
        if (visited.find(node) != visited.end()) continue;
        visited.insert(node);

        for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
            if (visited.find(*it) == visited.end()) {
                vector<string> newPath = path;
                newPath.push_back(*it);
                st.push(newPath);
            }
        }
    }
    return {};
}

int main() {
    unordered_map<string, vector<string>> graph;
    graph["S"] = {"A", "B"};
    graph["A"] = {"C"};
    graph["B"] = {"D"};
    graph["C"] = {"G"};
    graph["D"] = {"E"};
    graph["E"] = {"F"};
    graph["F"] = {"G"};
    graph["G"] = {};

    string start = "S";
    string goal = "G";

    vector<string> bfsPath = bfs(graph, start, goal);
    vector<string> dfsPath = dfs(graph, start, goal);

    printPath("BFS", bfsPath);
    printPath("DFS", dfsPath);

    cout << "\nResult: BFS is optimal because it found the shallowest goal first." << endl;

    return 0;
}
