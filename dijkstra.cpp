#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
// graph implementation using adj matrix
class Graph
{
    private:
        int V;
        int E;
        bool isDirected;
        int** adjMat;
    public:
        Graph(int v, bool b=false)
        {
            V = v;
            E = 0;
            isDirected = b;
            adjMat = new int*[V];
            for(int i=0; i<V; i++)
                adjMat[i] = new int[V];
        }
        bool addEdge(int src, int dst)
        {
            E++;
            adjMat[src][dst] = 1;
            if(!isDirected)
                adjMat[dst][src] = 1;
            return true;
        }
        bool printGraph()
        {
            for(int i=0; i<V; i++)
            {
                cout<<"vertex "<<i<<" is connected to : ";
                for(int j=0; j<V; j++)
                {
                    if(adjMat[i][j])
                        cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        ~Graph()
        {
            for(int i=0; i<V; i++)
                delete adjMat[i];
            delete adjMat;
        }
        void Dijkstra(int source)
        {
            // shortest path set, includes shortest reachable vertices one by one
            // dist knows the best possible distance to reach any vertex
            int spSet[V];
            int dist[V];
            // let's initialize the shortest path set and dist
            for(int i=0; i<V; i++)
            {
                spSet[i] = false;
                dist[i] = INT32_MAX;
            }
            // set the source distance to 0, so that it will be picked up first
            dist[source] = 0;
            int minDist;
            int minIndex; 
            for(int count = 0; count < V; count++)
            {
                minDist = INT32_MAX;
                for(int i=0; i<V; i++)
                {
                    if(!spSet[i] && minDist > dist[i])
                    {
                        minDist = dist[i];
                        minIndex = i;
                    }
                }
                spSet[minIndex] = true;

                for(int v = 0; v < V; v++)
                {
                    if(!spSet[v] && adjMat[minIndex][v] && dist[minIndex]+adjMat[minIndex][v] < dist[v])
                        dist[v] = dist[minIndex] + adjMat[minIndex][v];
                }
            }

            cout<<"Shortest path distance from vertex : "<<source<<endl;
            for(int i=0; i<V; i++)
            {
                cout<<dist[i]<<" ";
            }
            cout<<endl;
        }
};

int main()
{
    Graph g(4, true);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    g.Dijkstra(3);
    return 0;
}