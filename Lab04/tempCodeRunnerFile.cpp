    Created	: 23 January 2023 [13:20]
    Algo	: Bipatite Graph
    Status	: 
*/
#include<bits/stdc++.h>
using namespace std;


bool isBipartite(vector<int> adj[], int src,int n, int m)
{
    queue<int> q;
    int color[n] = {0};
    color[src] = 1; // 0 = no color, 1 = red, 2 = blue , set 'starting point' to be 'Red'
    q.push(src);