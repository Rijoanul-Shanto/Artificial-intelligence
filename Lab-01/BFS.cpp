/*
    Name    :   Rijoanul Hasan
    ID      :   152-15-572
    Lab     :   01
    Task    :   BFS
*/

#include <bits/stdc++.h>
#define endl '\n'
#define IN freopen("input.txt", "rt", stdin)
#define OUT freopen("output.ans", "wt", stdout)
#define PF printf
#define SF scanf
#define YES PF("YES\n")
#define Yes PF("Yes\n")
#define NO PF("NO\n")
#define No PF("No\n")
#define SF1(a) scanf("%d", &a)
#define SF2(a, b) scanf("%d %d", &a, &b)
#define SF3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define FOR(a, b, c) for(int i = a; i < b; i += c)
#define TC int t;scanf("%d", &t);while(t--)

using namespace std;

class Graph
{
    vector <int> mark; // To mark the visited vertex
    vector <int> level; // To keep the level of vertex from source
    queue <int> Q;
    vector<vector<int> > V; // To build the graph
    int n; // Number of vertex's

public:
    Graph(int n);
    void connect(int u, int v); // To connect edges between vertex's
    void BFS(int source);
};

Graph::Graph(int n)
{
    this->n = n;
    mark.resize(n, 0);
    level.resize(n, 0);
    V.resize(n);
}
void Graph::connect(int u, int v)
{
    V[u].push_back(v);
}
void Graph::BFS(int source)
{
    mark[source] = 1;
    Q.push(source);
    level[source] = 0;
    PF("Source = %d\n", source);

    while(!Q.empty())
    {
        int node = Q.front();

        for(int i = 0; i < V[node].size(); i++)
        {
            if(!mark[V[node][i]])
            {
                Q.push(V[node][i]);
                mark[V[node][i]] = 1;
                level[V[node][i]] = level[node] + 1;
            }
        }
        Q.pop();
    }

    // Printing the distance from source to all other nodes
    FOR(0, level.size(), 1) cout << "Vertex = " << i << ",\tDistance from source = " << level[i] << endl;
}

int main()
{
    IN;

    int n;
    while(cin >> n)
    {
        int source, temp;

        Graph g(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> temp;
                if(temp) g.connect(i, j);
            }
        }

        cin >> source;

        g.BFS(source);
    }


    return 0;
}

/*
Input format:

4 -> no of nodes (starting from node 0)

// matrix representation of the graph
0 0 1 1
0 0 1 1
1 1 0 1
1 1 1 0

0 -> source
*/
