// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print_stack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void clear(stack<int> &s)
{
    while (!s.empty())
    {
        s.pop();
    }
}

int main()
{
    int n, n2, pos = 0, br, br2 = 0, c = 0;
    stack<int> g1;
    stack<int> g2;
    stack<int> car;
    string status;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        while (1)
        {
            int t;
            bool aok_mai = false;
            for (int i = 0; i < n; i++)
            {
                cin >> n2;
                if (n2 == 0)
                {
                    cout<<endl;
                    aok_mai = true;
                    break;
                }
                g1.push(n2);
            }
            // cout << "g1 : ";
            // print_stack(g1);
            if (aok_mai)
            {
                break;
            }
            br = g1.size();
            pos = n;
            while (1)
            {
                br2 += 1;
                if (!g1.empty())
                {
                    t = g1.top();
                    car.push(t);
                    g1.pop();
                }

                // cout << "top: ";
                // cout << car.top() << endl;
                while (!car.empty()&&car.top() == pos)
                {
                    
                    // cout << "car : ";
                    // print_stack(car);
                    g2.push(car.top());
                    car.pop();
                    pos -= 1;
                }
                if (g2.size() == br)
                {
                    cout << "Yes" << endl;
                    clear(g1);
                    clear(g2);
                    clear(car);
                    br = 0;
                    br2 = 0;
                    break;
                }
                if (br2 == br * 2)
                {
                    cout << "No" << endl;
                    clear(g1);
                    clear(g2);
                    clear(car);
                    br = 0;
                    br2 = 0;
                    break;
                }
                c += 1;
                // cout << "pos: " << pos << endl;
                // cout << "g2 : ";
                // print_stack(g2);
            }
        }
    }
}