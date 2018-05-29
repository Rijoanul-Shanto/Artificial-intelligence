/*
    Name    :   Rijoanul Hasan
    ID      :   152-15-572
    Lab     :   01
    Task    :   DFS and Edge Classification
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

class DFS
{
    vector<vector<int> > V; // To Build the graph
    vector <int> mark; // To mark the visited node
    vector <char> color; // To color nodes, initially all nodes are W [W = White, B = Black, G = Gray]
    vector <int> discover; // To calculate the discover time
    vector <int> finish; // To calculate the finishing time
    int noOfNodes; // Number of nodes
    int time; // To calculate time

public:
    DFS(int noOfNodes);
    void connect(int u, int v);
    void __dfs(int source);
};

DFS::DFS(int noOfNodes)
{
    //Initializing
    this->noOfNodes = noOfNodes;
    time = 0;
    V.resize(noOfNodes);
    mark.resize(noOfNodes, 0);
    color.resize(noOfNodes, 'W');
    discover.resize(noOfNodes, 0);
    finish.resize(noOfNodes, 0);
}

void DFS::connect(int u, int v)
{
    V[u].push_back(v); // Building the graph list representation
}

void DFS::__dfs(int source)
{
    mark[source] = 1;
    time++;
    discover[source] = time;
    color[source] = 'G';

    FOR(0, V[source].size(), 1)
    {
        if(color[V[source][i]] == 'B')
        {
            if(discover[source] < discover[V[source][i]]) cout << source << " --> " << V[source][i] << " = Forward Edge" << endl;
            else cout << source << " --> " << V[source][i] << " = Cross Edge" << endl;
        }
        else if(color[V[source][i]] == 'G') cout << source << " --> " << V[source][i] << " = Back Edge" << endl;
        else cout << source << " --> " << V[source][i] << " = Tree Edge" << endl;
        if(!mark[V[source][i]])
        {
            mark[V[source][i]] = 1;
            //cout << "Start : " << source << ' ' << color[source] << ' ' << discover[source] << endl;
            __dfs(V[source][i]);
        }
    }
    color[source] = 'B';
    time++;
    finish[source] = time;

    //cout << source << ' ' << color[source] << ' ' << finish[source] << endl;
}

int main()
{
    IN;
    int node;
    while(cin >> node)
    {
        int source, temp;

        DFS dfs(node);

        for(int i = 0; i < node; i++)
        {
            for(int j = 0; j < node; j++)
            {
                cin >> temp;
                if(temp) dfs.connect(i, j);
            }
        }

        cin >> source;
        dfs.__dfs(source);
    }

    return 0;
}
/*
Input format:
8 -> number of nodes

//matrix representation of graph
0 0 0 0 1 0 0 1
0 0 1 1 0 1 0 0
0 1 0 0 0 0 1 0
0 1 0 0 0 0 0 1
1 0 0 0 0 1 0 0
0 1 0 0 1 0 0 0
0 0 1 0 0 0 0 1
1 0 0 1 0 0 1 0

3 -> Source
*/
