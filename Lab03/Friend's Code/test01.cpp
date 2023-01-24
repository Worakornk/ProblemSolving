#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[35][35] = {0};
string graph[31];
bool has_mineral = false, has_forest = false;
int tier2_cnt = 0, tier1_cnt = 0;

void dfs(int i, int j) {
  visited[i][j] = 1;
  if (graph[i][j] == '$')
    has_mineral = 1;
  if (graph[i][j] == '*')
    has_forest = 1;
  if (j + 1 <= m - 1 && graph[i][j + 1] != '#' && !visited[i][j + 1]) { // right
    dfs(i, j + 1);
  }
  if (j - 1 >= 0 && graph[i][j - 1] != '#' && !visited[i][j - 1]) { // left
    dfs(i, j - 1);
  }
  if (i - 1 >= 0 && graph[i - 1][j] != '#' && !visited[i - 1][j]) { // up
    dfs(i - 1, j);
  }
  if (i + 1 <= n - 1 && graph[i + 1][j] != '#' && !visited[i + 1][j]) { // down
    dfs(i + 1, j);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> graph[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (graph[i][j] != '#') {

        dfs(i, j);
        if (has_mineral && has_forest) {
          tier1_cnt++;
        } else if (has_mineral || has_forest) {
          tier2_cnt++;
        }

        has_mineral = false;
        has_forest = false;
        for (int x = 0; x < n; x++) {
          for (int y = 0; y < m; y++)
            visited[x][y] = 0;
        }
      }
    }
  }
  cout << tier1_cnt << " " << tier2_cnt << endl;
}