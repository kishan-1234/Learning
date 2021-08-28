class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > dist;
       
        for(int j=1;j<points.size();j++)
        {
            dist.push(make_pair(abs(points[0][0]-points[j][0])+abs(points[0][1]-points[j][1]),make_pair(0,j)));
        }
        
        int res = 0;
        int visitedCount = 0;
        vector<bool> visited(points.size(),false);
        visited[0] = true;
        while(!dist.empty())
        {
            pair<int,pair<int,int>> temp = dist.top();
            if(!visited[temp.second.second])
            {
                visited[temp.second.second] = true;
                res += temp.first;  
                visitedCount++;
                for(int j=0;j<points.size();j++)
                {
                    dist.push(make_pair(abs(points[temp.second.second][0]-points[j][0])+abs(points[temp.second.second][1]-points[j][1]),make_pair(temp.second.second,j)));   
                }
            }
            dist.pop();
            if(visitedCount==points.size()) break;
        }
        return res;
    }
};
