#include<bits/stdc++.h>

using namespace std;

void AP(int u,vector<int> gph[], bool visited[], int disc[],int low[], int parent[], bool ap[]) 
{ 
    static int time = 0; 
  
    int children = 0; 
  
    visited[u] = true; 
  
    disc[u] = low[u] = ++time; 
  
    for (int i = 0; i != gph[u].size(); ++i) 
    { 
        int v = gph[u][i];    
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            AP(v, gph, visited, disc, low, parent, ap); 
  
            low[u]  = min(low[u], low[v]); 
  
            if (parent[u] == -1 && children > 1) 
               ap[u] = true; 
  
            if (parent[u] != -1 && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
  
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 


bool* articulation(vector<pair<int,int> > edges,int v,int e)
{
    vector<int> gph[v];
    for(int i=0;i<edges.size();i++)
    {
        gph[edges[i].first].push_back(edges[i].second);
        gph[edges[i].second].push_back(edges[i].first);
    }

    bool *visited = new bool[v]; 
    int *disc = new int[v]; 
    int *low = new int[v]; 
    int *parent = new int[v]; 
    bool *ap = new bool[v]; 
  
    for (int i = 0; i < v; i++) 
    { 
        parent[i] = -1; 
        visited[i] = false; 
        ap[i] = false; 
    } 
  
    for (int i = 0; i < v; i++) 
        if (visited[i] == false) 
            AP(i, gph, visited, disc, low, parent, ap); 

    return ap;
}

int main()
{
    int v,e,p1,p2;
    cin >> v >> e;
    vector<pair<int,int> > edges;
    for(int i=0;i<e;i++)
    {
        cin >> p1 >> p2;
        edges.push_back(make_pair(p1,p2));
    }
    vector<int> res;
    bool *ap = articulation(edges,v,e);
    for(int i=0;i<v;i++)
    {
        if(ap[i])
            res.push_back(i);
    }
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << " ";
    }
}