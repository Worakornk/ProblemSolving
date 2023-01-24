#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, R, x, y;

vector<vector<int>> graph;
vector<pair<int, int>> nodes;

vector<int> visit;
queue<int> q;

int distance(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int shortestPath() {
    int count = 0, endpoint = graph.size() - 1;

    q.push(0);
    visit[0] = 1;
    while (!q.empty()) {
        int deq = q.front();
        q.pop();

        for (int i = 0; i < graph[deq].size(); i++) {
            if (graph[deq][i] == endpoint) return visit[deq];
            if (visit[graph[deq][i]]) continue;
            q.push(graph[deq][i]);
            visit[graph[deq][i]] = visit[deq] + 1;
        }
    }
    return -1;
}

int main() {
    cin >> N >> R;
    graph.resize(N + 2);
    visit.resize(N + 2);

    nodes.push_back({0, 0});
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        nodes.push_back({x, y});
    }
    nodes.push_back({100, 100});

    for (int i = 0; i < N + 2; i++) {
        for (int j = i + 1; j < N + 2; j++) {
            if (i == j) continue;
            if (distance(nodes[i].first, nodes[i].second, nodes[j].first, nodes[j].second) <= R * R) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    cout << shortestPath();
    return 0;
}
