class Solution {
public:
    
    vector<int> parent;
    int find(int x)
    {
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int a,int b) {
        int parenta = find(a);
        int parentb = find(b);
        if(parenta!=parentb) {
            parent[parentb] = parenta;
        }
        return;
    }
    
    static bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
    {
        return a.second<b.second;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > dist;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                dist.push(make_pair(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),make_pair(i,j)));
            }
        }
        
        for(int i=0;i<points.size();i++)
        {
            parent.push_back(i);
        }
        int res = 0;
        int numEdges = 0;
        
        while(!dist.empty())
        {
            pair<int,pair<int,int>> temp = dist.top();
            int parenta = find(temp.second.first);
            int parentb = find(temp.second.second);
            if(parenta!=parentb) {
                res += temp.first;
                Union(temp.second.first,temp.second.second);
                numEdges++;
            }
            dist.pop();
            if(numEdges==points.size()-1) break;
        }
        return res;
    }
};
