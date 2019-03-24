#include<iostream>

using namespace std;
#define MAX 9999
// graph implementation using adj matrix
class Graph
{
    private:
        int V;
        int E;
        bool isDirected;
        int **adjMat;
    public:
        Graph(int v, int e=0, bool d=false)
        {
            V = v;
            E = e;
            isDirected = d;
            *adjMat = new int[V];
            for(int i=0; i<V; i++)
                adjMat[i] = new int[V];
            for(int i=0; i<V; i++)
            {
                for(int j=0; j<V; j++)
                    adjMat[i][j] = MAX;
            }
        }
        bool addEdge(int src, int dst, int w=1)
        {
            E++;
            adjMat[src][dst] = w;
            if(!isDirected)
                adjMat[dst][src] = w;
        }
        void printAdjMat()
        {
            cout<<"The graph represented as adj matrix : "<<endl;
            for(int i=0; i<V; i++)
            {
                for(int j=0; j<V; j++)
                {
                    if(adjMat[i][j]==MAX)
                        cout<<"x"<<" ";
                    else
                        cout<<adjMat[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void floydWarshall()
        {
            int table[V][V];
            // initialize same as adj matrix
            for(int i=0; i<V; i++)
            {
                for(int j=0; j<V; j++)
                {
                    table[i][j] = adjMat[i][j];
                }
            }
            // pick an intermediate vertex
            for(int k=0; k<V; k++)
            {
                // pick a source vertex
                for(int i=0; i<V; i++)
                {
                    // pick a destination vertex
                    for(int j=0; j<V; j++)
                    {
                        // if we can get to destination using intermediate vertex and that is shortest
                        if(table[i][k] + table[k][j] < table[i][j])
                            table[i][j] = table[i][k] + table[k][j];
                    }
                }
            }
            // print the solution matrix
            cout<<"the solution matrix is : "<<endl;
            for(int i=0; i<V; i++)
            {
                for(int j=0; j<V; j++)
                {
                    if(table[i][j]==MAX)
                        cout<<"x"<<" ";
                    else
                        cout<<table[i][j]<<" ";
                }
                cout<<endl;
            }

        }
};

int main()
{
    Graph g(5, 0, true);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, 3);
    g.printAdjMat();
    g.floydWarshall();
    return 0;
}