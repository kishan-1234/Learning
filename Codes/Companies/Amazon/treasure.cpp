#include<bits/stdc++.h>

using namespace std;

void findtreasure(vector<vector<char> >& v,vector<vector<int> >& value,int i,int j,int r,int c,int count,int &res)
{
    if(i<0 || i>=r || j<0 || j>=c)
        return;
    if(v[i][j]=='D')
        return;
    if(count>value[i][j])
        return;
    value[i][j] = count;
    if(v[i][j]=='X')
        res = min(res,count);
    findtreasure(v,value,i,j+1,r,c,count+1,res);
    findtreasure(v,value,i+1,j,r,c,count+1,res);
    findtreasure(v,value,i,j-1,r,c,count+1,res);
    findtreasure(v,value,i-1,j,r,c,count+1,res);
}
    
int main()
{
    int r,c;
    cin >> r >> c;
    vector<vector<char> > v;
    vector<vector<int> > value;
    char t;
    int res=INT_MAX;
    for(int i=0;i<r;i++)
    {
        vector<char> temp;
        vector<int> vtemp;
        for(int j=0;j<c;j++)
        {
            cin >> t;
            temp.push_back(t);
            vtemp.push_back(INT_MAX);
        }
        v.push_back(temp);
        value.push_back(vtemp);
        temp.clear();
        vtemp.clear();
    }
    findtreasure(v,value,0,0,r,c,0,res);
    cout << res;
}