#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<pair<int,int> > gph[],int edgeFrom,int edgeTo,int weight)
{
    gph[edgeFrom].push_back(make_pair(edgeTo,weight));
    gph[edgeTo].push_back(make_pair(edgeFrom,weight));
}

vector<int> djikstra(vector<pair<int,int> > gph[],int nodes,int start)
{
    vector<int> distance(nodes,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > hp;

    distance[start] = 0;
    hp.push(make_pair(0,start));

    while(!hp.empty())
    {
        pair<int,int> temp = hp.top();
        hp.pop();
        for(int i=0;i<gph[temp.second].size();i++)
        {
            int vertex = gph[temp.second][i].first;
            int weight = gph[temp.second][i].second;
            if(distance[vertex]>distance[temp.second]+weight)
            {
                distance[vertex]=distance[temp.second]+weight;
                hp.push(make_pair(distance[vertex],vertex));
            }
        }
    }
    return distance;
}

int main()
{
    int nodes,edges,edge_from,edge_to,weight,start;
    cout << "Enter the number of nodes: " << endl;
    cin >> nodes;
    vector<pair<int,int> > gph[nodes];
    cout << "Enter the number of edges: " << endl;
    cin >> edges;
    cout << "Enter the edges with weight below: " << endl;
    for(int i=0;i<edges;i++)
    {
        cin >> edge_from >> edge_to >> weight;
        addEdge(gph,edge_from,edge_to,weight);
    }
    cout << "Enter starting vertx: " << endl;
    cin >> start;
    vector<int> distance = djikstra(gph,nodes,start);
    cout << "Distance from all nodes are: " <<endl;
    for(int i=0;i<nodes;i++)
    {
        cout << i << " " << distance[i] << endl; 
    }
}