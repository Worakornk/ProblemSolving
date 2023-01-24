#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    string s;
    int check = 0; // 0 = natural, 1 = front, 2 = back
    list<char> answer;
    
    while (getline(cin, s))
    {
        list<char>::iterator iter = answer.begin();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[')
            {
                check = 1;
                iter = answer.begin();
            }
            else if (s[i] == ']')
            {
                check = 2;
            }
            else
            {
                if (check == 0)
                {
                    answer.push_back(s[i]);
                }
                if (check == 1)
                {
                    answer.insert(iter, s[i]);
                }
                if (check == 2)
                {
                    answer.push_back(s[i]);
                }
            }
        }
        for (auto x : answer)
        {
            cout << x;
        }
        check = 0;
        cout << endl;
        answer.clear();
    }
    return 0;
}