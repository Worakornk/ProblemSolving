/*
    Task	: 01_box
    Author	: First
    School	: KU
    Language: C++
    Created	: 27 December 2022 [12:51]
    Algo	: Recursion
    Status	: Completed
*/

#include <bits/stdc++.h>
using namespace std;

// Setup Global Variables
int n, m;
int di[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
char M[50][50];
int maze[50][50];
bool pass = false;

void dfs(int x, int y)
{
    maze[x][y] = 1;
    if (x == n - 2) // reached bottom
    {
        pass = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        // cout <<  di[i][0] << " " << di[i][1] << endl;
        int ni = x + di[i][0], nj = y + di[i][1];
        if (ni < 0 || ni >= n - 1 || nj < 0 || nj >= m - 1)
            continue;
        if (maze[ni][nj])
            continue;
        if (M[ni][nj] == '.' && M[ni][nj + 1] == '.' && M[ni + 1][nj] == '.' && M[ni + 1][nj + 1] == '.')
            dfs(ni, nj);
    }
    maze[x][y] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
    for (int i = 0; i < m; i++)
        if (M[0][i]=='.' && M[0][i+1]=='.' && M[1][i]=='.' && M[1][i+1]=='.')
            dfs(0, i);
    if (pass)
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}

/*

case1:

7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
..........###.
####...######.
...#..##..###.

case2:

7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
........#####.
####...######.
...#..##..###.

*/