/*
    Task    : 05_qualitymap
    Author  : Worakorn K.
    School  : Kasetsart University
    Language: C++
    Created : 28 December 2022 [00:17]
    Algo    : DFS
    Status  : Completed
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, nGreat = 0, nGood = 0;
int di[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char land[50][50];
int marked[50][50];

int stateA = 0; //has mineral
int stateB = 0; //has forest
int area = 0;
int size = 0;

void dfs(int i, int j)
{
    marked[i][j] = 1;
    size++;
    if (land[i][j] == '*')
        stateA=1;
    if (land[i][j] == '$')
        stateB=1;
    for (int k = 0; k < 4; k++)
    {
        int ni = i + di[k][0], nj = j + di[k][1];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m)
            continue;
        if (marked[ni][nj])
            continue;
        if (land[ni][nj] == '#')
            continue;
        if (land[ni][nj] == '.' || land[ni][nj] == '*' || land[ni][nj] == '$')
            dfs(ni, nj);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> land[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((land[i][j] == '.' || land[i][j] == '*' || land[i][j] == '$' ) && marked[i][j] == 0)
            {
                dfs(i, j);
                if (stateA == 1 and stateB == 1){
                    nGreat+=size;
                }
                else if (stateA == 1 or stateB == 1){
                    nGood+=size;
                }
                stateA = 0;
                stateB = 0;
                size=0;
            }
        }
    }
    cout << nGreat << " " << nGood << endl;
    return 0;
}