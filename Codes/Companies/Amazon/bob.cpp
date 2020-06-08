#include<bits/stdc++.h>

using namespace std;

void fun(vector<vector<int> > maze,int i,int j,int x,int y,int r,int c,int count,int gold,int &res)
{
    if(i<0 || i>=r | j<0 || j>=c)
        return;
    if(maze[i][j]==1)
        return;
    if(maze[i][j]==2)
        gold--;
    if(i==x && j==y && gold==0)
        res = min(res,count);
    fun(maze,i+1,j,x,y,r,c,count+1,gold,res);
    fun(maze,i-1,j,x,y,r,c,count+1,gold,res);
    fun(maze,i,j+1,x,y,r,c,count+1,gold,res);   
    fun(maze,i,j-1,x,y,r,c,count+1,gold,res);
     
}

int minMoves(vector<vector<int> > maze,int x,int y)
{
    int res = INT_MAX;
    int r = maze.size();
    int c = maze[0].size();
    int gold=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(maze[i][j]==2)
                gold++;
        }
    }
    fun(maze,0,0,x,y,r,c,0,gold,res);
    if(res==INT_MAX)
        res=-1;
    return res;   
}

int main()
{
    int r,c,x,y;
    vector<vector<int> >v;
    cin >> r >> c;
    for(int i=0;i<r;i++)
    {
        vector<int> temp;
        for(int j=0;j<c;j++)
        {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        v.push_back(temp);
        temp.clear();
    }
    cin >> x >> y;
    cout << minMoves(v,x,y);
}