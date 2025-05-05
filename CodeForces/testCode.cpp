#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "++X" or s == "X++")
            answer++;
        else
            answer--;
    }
    cout << answer;
}