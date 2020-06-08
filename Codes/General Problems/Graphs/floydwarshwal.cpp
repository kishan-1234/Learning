#include<bits/stdc++.h>

using namespace std;

void print(vector<vector<int> > gphmatrix,int nodes)
{
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            cout << gphmatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addEdge(vector<pair<int,int> > gph[],int edgeFrom,int edgeTo,int weight)
{
    gph[edgeFrom].push_back(make_pair(edgeTo,weight));
}

void floydwarshwal(vector<pair<int,int> > gph[],int nodes)
{
    vector<vector<int> > gphmatrix;
    for(int i=0;i<nodes;i++)
    {
        vector<int> temp;
        for(int j=0;j<nodes;j++)
        {
            if(i==j)
                temp.push_back(0);
            else
                temp.push_back(INT_MAX);
        }
        gphmatrix.push_back(temp);
        temp.clear();
    }

    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<gph[i].size();j++)
        {
            int vertex = gph[i][j].first;
            int weight = gph[i][j].second;
            gphmatrix[i][vertex] = weight;
        }
    }

    for(int k=0;k<nodes;k++)
    {
        for(int i=0;i<nodes;i++)
        {
            for(int j=0;j<nodes;j++)
            {
                if(gphmatrix[i][k]!=INT_MAX && gphmatrix[k][j]!=INT_MAX && gphmatrix[i][j]>gphmatrix[i][k]+gphmatrix[k][j])
                    gphmatrix[i][j] = gphmatrix[i][k]+gphmatrix[k][j];
            }
        }
    }

    print(gphmatrix,nodes);
}

int main()
{
    int nodes,edges,edgeFrom,edgeTo,weight;
    cout << "Enter the number of nodes: " << endl;
    cin >> nodes;
    vector<pair<int,int> > gph[nodes];
    cout << "Enter the number of edges: " << endl;
    cin >> edges;
    cout << "Enter the edges along with their weights" << endl;
    for(int i=0;i<edges;i++)
    {
        cin >> edgeFrom >> edgeTo >> weight;
        addEdge(gph,edgeFrom,edgeTo,weight);
    }
    floydwarshwal(gph,nodes);
}