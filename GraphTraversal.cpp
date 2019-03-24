#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

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
        bool BFS(int s)
        {
            queue<int> q;
            bool visited[V] = {false};
            q.push(s);
            int cur;
            cout<<"Visiting the graph using BFS : ";
            while(!q.empty())
            {
                cur = q.front();
                q.pop();
                visited[cur] = true;
                cout<<cur<<" ";
                for(int i=0; i<V; i++)
                {
                    if(adjMat[cur][i] && !visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
            cout<<endl;
        }
        bool DFS(int s)
        {
            stack<int> st;
            bool visited[V] = {false};
            st.push(s);
            int cur;
            cout<<"Visiting the graph using DFS : ";
            while(!st.empty())
            {
                cur = st.top();
                st.pop();
                visited[cur] = true;
                cout<<cur<<" ";
                for(int i=0; i<V; i++)
                {
                    if(adjMat[cur][i] && !visited[i])
                    {
                        st.push(i);
                        visited[i] = true;
                    }
                }
            }
            cout<<endl;
        }
        bool DFSRecur(int s)
        {
            bool visited[V] = {false};
            cout<<"Visiting the graph using DFS Recursive : ";
            DFSRecurUtil(s, visited);
        }
        bool DFSRecurUtil(int s, bool visited[])
        {
            visited[s] = true;
            cout<<s<<" ";
            for(int i=0; i<V; i++)
            {
                if(adjMat[s][i] && !visited[i])
                    DFSRecurUtil(i, visited);
            }
            return true;
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
    g.BFS(0);
    g.DFS(0);
    g.DFSRecur(0);
    return 0;
}