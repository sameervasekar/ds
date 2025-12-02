/ 2) Write a Program to accept a graph from a user and represent it with Adjacency
// List and perform BFS and DFS traversals on it.
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
void BFS(int start, int v, vector<vector<int>> &adj)
{
    vector<bool> visited(v, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        cout << node << " ";
        for (int neighbour : adj[node])
        {

            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
void DFS(int start, vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V, false);
    stack<int> st;
    st.push(start);

    cout << "DFS Traversal : ";
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        while (!visited[node])
        {
            cout << node << " ";
            visited[node] = true;
        }
        for (int i = adj[node].size() - 1; i >= 0; i--)
        {
            int neighbor = adj[node][i];
            if (!visited[neighbor])
                st.push(neighbor);
        }
    }
}
int main()
{

    // adj[0] = {1, 2, 3};
    // adj[1] = {0, 2};
    // adj[2] = {0, 1, 3, 4};
    // adj[3] = {0, 2, 4};
    // adj[4] = {2, 3, 5, 6};
    // adj[5] = {4};
    // adj[6] = {4};

    int vertices, edges;
    cout << "Enter number of vertices : ";
    cin >> vertices;

    cout << "Enter number of edges : ";
    cin >> edges;

    vector<vector<int>> adj(vertices);
    cout << "Enter edges between U and V : ";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter start Node : ";
    cin >> start;

    cout << endl;
    BFS(start, vertices, adj);
    cout << endl;
    DFS(start, adj, vertices);
    return 0;
}
