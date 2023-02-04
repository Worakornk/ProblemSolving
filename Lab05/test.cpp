// CPP implementation of above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to return number of boxes
int numBoxes(int A[], int n, int K)
{
    // Sort the boxes in ascending order
    sort(A, A + n);
 
    // Try to fit smallest box with
    // current heaviest box (from right
    // side)
    int i = 0, j = n - 1;
    int ans = 0;
    while (i <= j) {
        ans++;
        if (A[i] + A[j] <= K)
            i++;
        j--;
    }
 
    return ans;
}
 
// Driver program
int main()
{
    int A[] = { 3, 2, 2, 1 }, K = 3;
    int n = sizeof(A) / sizeof(A[0]);
    cout << sizeof(A) << endl;
    cout << sizeof(A[0]) << endl;
    cout << n << endl;
    cout << numBoxes(A, n, K);
    return 0;
}
 
// This code is written by Sanjit_Prasad
