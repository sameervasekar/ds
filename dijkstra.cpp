// 4) Write a Program to implement Dijkstra’s algorithm to find shortest distance
// between two nodes of a user defined graph. Use Adjacency Matrix to represent a graph.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int> &dist, vector<bool> &visited, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

vector<int> dijkstras(vector<vector<int>> &graph, int src, int n)
{
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;

    // Relax all vertices
    for (int i = 0; i < n - 1; i++)
    {
        int u = findMinVertex(dist, visited, n);
        if (u == -1)  // no more reachable vertices
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            // graph[u][v] > 0  => edge exists
            if (graph[u][v] > 0 && !visited[v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist;
}

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));

    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    cout << "(0 for no edge, positive weight for edge)\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    int src, dest;
    cout << "Enter source vertex (0 to " << n - 1 << "): ";
    cin >> src;
    cout << "Enter destination vertex (0 to " << n - 1 << "): ";
    cin >> dest;

    vector<int> dist = dijkstras(adj, src, n);

    if (dist[dest] == INT_MAX)
        cout << "No path from " << src << " to " << dest << endl;
    else
        cout << "Shortest distance from " << src << " to " << dest << " = " << dist[dest] << endl;

    return 0;
}
