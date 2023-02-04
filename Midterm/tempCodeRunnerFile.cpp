/*
    Task	: mid65_fakeheight
    Author	: First
    School	: KU
    Language: C++
    Created	: 30 January 2023 [14:13]
    Algo	: Idk
    Status	:
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N;
    cin >> N;
    long long int students[N];
    for (int i = 0; i < N; i++)
    {
        cin >> students[i];
    }


    // Find if we can readjust the height to get lowest difference height
    long long int sum = 0;
    if (N < 4)
    {   
        sum = accumulate(students + 1, students + N + 1, sum);
        cout << sum << endl;
        return 0;
    }

    int maxDiff_mode[3];
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            long long int diff = abs(students[i] - students[i + 1]);
            if (diff > maxDiff_mode[0])
            {
                maxDiff_mode[0] = diff;
                maxDiff_mode[1] = i;
                maxDiff_mode[2] = 1;
            }
        }
        else if (i == N - 1)
        {
            long long int diff = abs(students[i] - students[i - 1]);
            if (diff > maxDiff_mode[0])
            {
                maxDiff_mode[0] = diff;
                maxDiff_mode[1] = i;
                maxDiff_mode[2] = 3;
            }
        }
        else
        {
            long long int diff = abs(students[i] - students[i + 1]) + abs(students[i] - students[i - 1]);
            if (diff > maxDiff_mode[0])
            {
                maxDiff_mode[0] = diff;
                maxDiff_mode[1] = i;
                maxDiff_mode[2] = 2;
            }
        }
    }

    if (maxDiff_mode[2] == 1)
    {
        for (int i = 0; i < N; i++)
        {
            long long int diff = abs(students[i] - students[1]);
            if (diff > maxDiff_mode[0])
            {
                maxDiff_mode[0] = diff;
                maxDiff_mode[1] = i;
                maxDiff_mode[2] = 1;
            }
        }

    }
    

    cout << maxDiff_mode[0] << " " << maxDiff_mode[1] << " " << maxDiff_mode[2] << endl;


    int newpos;
    
    if (maxDiff_mode[2] == 1)
    {
        for(int i = 1; i < N; i++)
        {
            if (i == 0 or i == 1)
            {
                continue;
            }
            long long int diff = abs(students[i] - students[1]);
            if (diff < maxDiff_mode[0])
            {
                maxDiff_mode[0] = diff;
                newpos = i;
            }
        }
    }
    if (maxDiff_mode[2] == 3)
    {
        for(int i = 0; i < N-1; i++)
        {
            if (i == N-1 or i == N-2)
            {
                continue;
            }
            long long int diff = abs(students[i] - students[N-2]);
            if (diff < maxDiff_mode[0])
            {
                maxDiff_mode[0] = diff;
                newpos = i;
            }
        }
    }
    if (maxDiff_mode[2] == 2)
    {
        for(int i = 1; i < N-1; i++)
        {
            if (i == 0 or i == 1 or i == N-1 or i == N-2)
            {
                continue;
            }
            long long int diff = abs(students[i] - students[i+1]) + abs(students[i] - students[i-1]);
            if (diff > maxDiff_mode[0])
            {
                maxDiff_mode[0] = diff;
                newpos = i;
            }
        }
    }

    students[maxDiff_mode[1]] = students[newpos];
    long long int sumall = 0;
    for (int i = 0; i < N-2; i++)
    {
        sumall += abs(students[i] - students[i+1]);
    }

    cout << sumall << endl;


    return 0;

    // // locate interesting position in array
    // int pos = 0;
    // long long int maxDiff = 0;
    // for (int i = 1; i <= N-1; i++)
    // {
    //     long long int diff = abs(students[i] - students[i + 1]) + abs(students[i] - students[i - 1]);
    //     if ( diff > maxDiff )
    //     {
    //         maxDiff = diff;
    //         pos = i-1;
    //     }
    // }

    // // cout << pos << endl;

    // long long int replace = 10000000;
    // int pos2;
    // for (int i = 0; i < N; i++)
    // {
    //     if (i-1<0 or i+1>N-1)
    //     {
    //         continue;
    //     }
    //     if (i == pos - 1 or i == pos + 1 or i == pos)
    //     {
    //         continue;
    //     }
        
    //     if (abs(students[i] - students[pos+1]) + abs(students[i] - students[pos-1])  < replace)
    //     {
    //         replace = abs(students[i] - students[pos+1]) + abs(students[i] - students[pos-1]);
    //         pos2 = i;
    //     }
    // }

    // // cout << pos2 << endl;

    // students[pos] = students[pos2];
    // for (int i = 1; i < N; i++)
    // {
    //     sum += abs(students[i] - students[i - 1]);
    // }
    // cout << sum << endl;
    // return 0;
}

