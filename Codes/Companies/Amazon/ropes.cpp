#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,temp;
    cin >> n;
    vector<int> input;
    priority_queue<int,vector<int>,greater<int>> hp;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        input.push_back(temp);
        hp.push(temp);
    }
    
    int res=0;
    while(!hp.empty())
    {
        int a = hp.top(),b;
        hp.pop();
        if(!hp.empty())
        {
            b = hp.top();
            hp.pop();
            res+=a+b;
            hp.push(a+b);
        }
    }
    cout << res;
}