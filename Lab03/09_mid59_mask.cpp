/*
    Task	: 09_mid59_mask
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 27 December 2022 [23:21]
    Algo	: Brute Force
    Status	: Completed
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int list_skillLevel[4];
    int list_pos[4];

    int j = 0;
    for (int i = 0; i < 4; i++)
    {
        int temp[N];
        for (int j = 0; j < N; j++)
        {
            int skillLevel;
            cin >> skillLevel;
            temp[j] = skillLevel;
        }
        list_skillLevel[i] = *max_element(temp, temp + N);
        auto itr = find(temp, temp + N, list_skillLevel[i]);
        list_pos[i] = distance(temp, itr) + 1 + i*N;
    }

    if (list_skillLevel[0]<list_skillLevel[1]){
        swap(list_skillLevel[0], list_skillLevel[1]);
        swap(list_pos[0], list_pos[1]);
    }
    if (list_skillLevel[2]<list_skillLevel[3]){
        swap(list_skillLevel[2], list_skillLevel[3]);
        swap(list_pos[2], list_pos[3]);
    }
    if (list_skillLevel[0]<list_skillLevel[2]){
        swap(list_skillLevel[0], list_skillLevel[2]);
        swap(list_pos[0], list_pos[2]);
        swap(list_skillLevel[1], list_skillLevel[2]);
        swap(list_pos[1], list_pos[2]);
    }
    else
    {
        swap(list_skillLevel[1], list_skillLevel[2]);
        swap(list_pos[1], list_pos[2]);
    }

    for (int i = 0; i < 4; i++)
    {
        cout << list_pos[i] << " ";
    }

    return 0;
}