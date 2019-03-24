#include<iostream>
#include<vector>

using namespace std;
// implementation of graph edges
class Edge
{
    private:
        int source;
        int destination;
        int weight;
    public:
        Edge(int src, int dst, int w)
        {
            source = src;
            destination = dst;
            weight = w;
        }
        ~Edge()
        {

        }
        int getSource()
        {
            return source;
        }
        int getDestination()
        {
            return destination;
        }
        int getWeight()
        {
            return weight;
        }
};
// implementation of graph using adj list
class Graph
{
    private:
        int V;
        int E;
        vector<Edge> adjList;
    public:
        Graph(int v, int e=0)
        {
            V = v;
            E = e;
        }
        bool addEdge(int src, int dst, int w=1)
        {
            E++;
            adjList.push_back(Edge(src, dst, w));
        }
        void bellmanFord(int s)
        {
            int dist[V];
            // step 1 : initialization
            for(int i=0; i<V; i++)
                dist[i] = INT32_MAX;
            dist[s] = 0;
            // step 2 : relaxation
            for(int i=1; i<V; i++)
            {
                for(int j=0; j<E; j++)
                {
                    if(dist[adjList[j].getSource()] != INT32_MAX && dist[adjList[j].getSource()] + adjList[j].getWeight() < dist[adjList[j].getDestination()])
                        dist[adjList[j].getDestination()] = dist[adjList[j].getSource()] + adjList[j].getWeight();
                }
            }
            // step 3 : find any negetive edge cycle
            for(int i=0; i<E; i++)
            {
                if(dist[adjList[i].getSource()] != INT32_MAX && dist[adjList[i].getSource()] + adjList[i].getWeight() < dist[adjList[i].getDestination()])
                    cout<<"graph contains negetive edge cycle"<<endl;
            }

            // print the dist array
            for(int i=0; i<V; i++)
                cout<<dist[i]<<" ";
            cout<<endl;
        }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);
    g.bellmanFord(0);
    return 0;
}