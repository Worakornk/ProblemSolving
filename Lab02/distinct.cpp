#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> Shop;
    vector<int> priceCombination;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Shop.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int temp = Shop[i];
        if (find(priceCombination.begin(), priceCombination.end(), temp) == priceCombination.end())
        {
            priceCombination.push_back(temp);
        }
        for (int j = i+1; j < n; j++)
        {
            temp += Shop[j];
            if (find(priceCombination.begin(), priceCombination.end(), temp) != priceCombination.end())
            {
                continue;
            }
            else
            {
                priceCombination.push_back(temp);
            }
        }
    }
    cout << priceCombination.size() << endl;
    return 0;
}
