#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
    int x, y, cost, priority;
    bool operator>(const Node &o) const { return priority > o.priority; }
};

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int search(const vector<string> &grid, pair<int,int> start, pair<int,int> goal, bool useHeuristic, int &expanded) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start.first, start.second, 0, 0});
    expanded = 0;

    while (!pq.empty()) {
        auto [x, y, cost, prio] = pq.top(); pq.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        expanded++;
        if (x == goal.first && y == goal.second) return cost;

        for (auto [dx, dy] : vector<pair<int,int>>{{1,0},{-1,0},{0,1},{0,-1}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] != '#' && !visited[nx][ny]) {
                int newCost = cost + 1;
                int newPrio = newCost + (useHeuristic ? manhattan(nx, ny, goal.first, goal.second) : 0);
                pq.push({nx, ny, newCost, newPrio});
            }
        }
    }
    return -1; // No path found
}

int main() {
    ifstream in("input.txt");
    if (!in) {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    vector<string> grid;
    string line;
    while (getline(in, line)) {
        if (!line.empty())
            grid.push_back(line);
    }

    if (grid.empty()) {
        cerr << "Error: input.txt is empty!" << endl;
        return 1;
    }

    pair<int,int> S = {-1, -1}, G = {-1, -1};
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 'S') S = {i, j};
            if (grid[i][j] == 'G') G = {i, j};
        }
    }

    if (S.first == -1 || G.first == -1) {
        cerr << "Error: Start (S) or Goal (G) not found in input." << endl;
        return 1;
    }

    int expA, expU;
    int pathA = search(grid, S, G, true, expA);
    int pathU = search(grid, S, G, false, expU);

    cout << "A*  : path=" << pathA << " expanded=" << expA << endl;
    cout << "UCS : path=" << pathU << " expanded=" << expU << endl;
    cout << "Heuristic admissible ⇒ never overestimates; hence A* explores fewer nodes." << endl;

    return 0;
}
