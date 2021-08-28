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
        
        vector<pair<pair<int,int>,int>> dist;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                dist.push_back(make_pair(make_pair(i,j),abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])));
            }
        }
        sort(dist.begin(),dist.end(),cmp);
        
        for(int i=0;i<points.size();i++)
        {
            parent.push_back(i);
        }
        int res = 0;
        int numEdges = 0;
        
        for(int i=0;i<dist.size();i++)
        {
            int parenta = find(dist[i].first.first);
            int parentb = find(dist[i].first.second);
            if(parenta!=parentb) {
                res += dist[i].second;
                Union(dist[i].first.first,dist[i].first.second);
                numEdges++;
            }
            if(numEdges==points.size()-1) break;
        }
        return res;
    }
};
