class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int> > v;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(0);
            }
            v.push_back(temp);
            temp.clear();
        }
        int l=0,r=n-1,u=0,d=n-1,limit=pow(n,2),curr=1,i,j;
        
        while(curr<=limit)
        {
            j=l;
            while(j<=r)
            {
                v[u][j] = curr;
                curr++;
                j++;
            }
            u++;

            i=u;
            while(i<=d)
            {
                v[i][r] = curr;
                curr++;
                i++;
            }
            r--;

            j=r;
            while(j>=l)
            {
                v[d][j] = curr;
                curr++;
                j--;
            }
            d--;

            i=d;
            while(i>=u)
            {
                v[i][l] = curr;
                curr++;
                i--;
            }
            l++;
        }
        
        return v;
    }
};