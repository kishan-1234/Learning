#include<bits/stdc++.h>

using namespace std;

int calculate(vector<vector<int> > input,int n,int m)
{
    int res=INT_MIN;
    queue<pair<pair<int,int>,int> > q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(input[i][j]==1)
                q.push(make_pair(make_pair(i,j),0));
        }
    }
    while(!q.empty())
    {
        pair<pair<int,int>,int> temp = q.front();
        cout << temp.first.first << " " << temp.first.second << " " << temp.second << endl;
        if(temp.second>res)
            res = temp.second;
        q.pop();
        if(temp.first.first-1>=0 && temp.first.first-1<n && temp.first.second>=0 && temp.first.second<m && input[temp.first.first-1][temp.first.second]==0)
        {
            input[temp.first.first-1][temp.first.second] = 1;
            q.push(make_pair(make_pair(temp.first.first-1,temp.first.second),temp.second+1));
        }
        if(temp.first.first+1>=0 && temp.first.first+1<n && temp.first.second>=0 && temp.first.second<m && input[temp.first.first+1][temp.first.second]==0)
        {
            input[temp.first.first+1][temp.first.second] = 1;
            q.push(make_pair(make_pair(temp.first.first+1,temp.first.second),temp.second+1));
        }
        if(temp.first.first>=0 && temp.first.first<n && temp.first.second-1>=0 && temp.first.second-1<m && input[temp.first.first][temp.first.second-1]==0)
        {
            input[temp.first.first][temp.first.second-1] = 1;
            q.push(make_pair(make_pair(temp.first.first,temp.first.second-1),temp.second+1));
        }
        if(temp.first.first>=0 && temp.first.first<n && temp.first.second+1>=0 && temp.first.second+1<m && input[temp.first.first][temp.first.second+1]==0)
        {
            input[temp.first.first][temp.first.second+1] = 1;
            q.push(make_pair(make_pair(temp.first.first,temp.first.second+1),temp.second+1));
        }
    }
    return res;
}

int main()
{
    int n,m,t;
    cin >> n >>m;
    vector<vector<int> > input;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<m;j++)
        {
            cin >> t;
            temp.push_back(t);
        }
        input.push_back(temp);
        temp.clear();
    }
    cout << calculate(input,n,m);
}