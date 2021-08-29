int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> prevdist(n,INT_MAX);
        prevdist[src] = 0;
        vector<int> dist = prevdist;
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<flights.size();j++)
            {
                int source = flights[j][0];
                int dest = flights[j][1];
                int weight = flights[j][2];
                if(prevdist[source]!=INT_MAX && dist[dest]>prevdist[source]+weight) {
                    dist[dest]=prevdist[source]+weight;
                }
            }
            prevdist = dist;
        }
        return dist[dst] == INT_MAX ? -1:dist[dst];
    }
