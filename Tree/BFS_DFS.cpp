#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void BFS(int start, vector<vector<int>>& adj, vector<bool>& visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << (char)(node + 'A') << " ";

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

void DFS(int start, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[start] = true;
    cout << (char)(start + 'A') << " ";

    for (int neighbor : adj[start])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor, adj, visited);
        }
    }
}

int main()
{
    // Assume graph has 7 nodes: A-G → 0-6
    int n = 7;
    vector<vector<int>> adj(n);

    // Undirected graph (based on your diagram)
    adj[0] = {1, 2};       // A → W, P
    adj[1] = {0, 4};       // W → A, U
    adj[2] = {0, 3};       // P → A, R
    adj[3] = {2, 5, 6};    // R → P, O, L
    adj[4] = {1};          // U → W
    adj[5] = {3};          // O → R
    adj[6] = {3};          // L → R

    vector<bool> visited(n, false);
    BFS(0, adj, visited); // Start from node A (0)

    fill(visited.begin(), visited.end(), false); // reset visited

    cout << "DFS Traversal: ";
    DFS(0, adj, visited); // Start from node A (0)
    cout << endl;

    return 0;
}

