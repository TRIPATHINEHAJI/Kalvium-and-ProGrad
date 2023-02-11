#include <iostream>
#include <vector>

using namespace std;

vector<int> minCoins(vector<int> &coins, int change)
{
    int m = coins.size();
    vector<int> dp(change + 1, change + 1);
    vector<int> result(change + 1);

    dp[0] = 0;
    for (int i = 1; i <= change; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]];
                if (sub_res != change + 1 && sub_res + 1 < dp[i])
                {
                    dp[i] = sub_res + 1;
                    result[i] = j;
                }
            }
        }
    }

    vector<int> selectedCoins;
    int start = change;
    while (start != 0)
    {
        int j = result[start];
        selectedCoins.push_back(coins[j]);
        start -= coins[j];
    }

    return selectedCoins;
}

int main()
{
    int n;
    cout << "Enter Number of Coins\n";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter values of Coins\n";
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int change;
    cout << "Enter the value that you want to change\n";
    cin >> change;
    vector<int> selectedCoins = minCoins(coins, change);
    cout << "Coins used: ";
    for (int i = 0; i < selectedCoins.size(); i++)
    {
        cout << selectedCoins[i] << " ";
    }
    cout << endl;

    return 0;
}
