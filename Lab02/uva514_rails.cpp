// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;

    while (1)
    {
        cin >> n;

        // If n == 0, break the loop
        if (n == 0)
        {
            break;
        }

        // Initialize Arriving Sequence
        vector<int> arrive;
        for (int i = 1; i <= n; i++)
        {
            arrive.push_back(i);
        }

        // Checking if input Sequence is possible
        while (1)
        {
            vector<int> check;
            // Input Sequence
            int is_zero = 0;
            for (int i = 0; i < n; i++)
            {
                int temp;
                cin >> temp;
                if (temp == 0)
                {
                    cout << endl;
                    is_zero = 1;
                    break;
                }
                check.push_back(temp);
            }
            if (is_zero == 1)
            {
                break;
            }
            stack<int> checkcase;
            for (int i = n-1; i >= 0; i--)
            {
                checkcase.push(check[i]);
            }

            // Setting up Temp array
            vector<int> tmpArr = arrive;
            
            // Checking if input Sequence is possible
            stack<int> stack;
            int is_possible = 0;

            for (int i = 0; i < n; i++)
            {
                stack.push(tmpArr[i]);

                while (1)
                {
                    if (stack.size() == 0 || tmpArr.size() == 0)
                    {
                        break;
                    }
                    if (stack.top() == checkcase.top())
                    {
                        stack.pop();
                        checkcase.pop();
                    }
                    else if (stack.top() != checkcase.top())
                    {
                        break;
                    }
                }
            }

            if (stack.size() == 0)
            {
                is_possible = 1;
            }

            if (is_possible == 1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
        
            }

            // clearing left overs
            for (int i = 0; i < stack.size(); i++)
            {
                stack.pop();
            }
            for (int i = 0; i < checkcase.size(); i++)
            {
                checkcase.pop();
            }
            tmpArr.clear();
        }
        arrive.clear();
    }

    return 0;
}