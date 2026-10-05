#include <iostream>
#include <queue>
using namespace std;
void DFS(int graph[10][10], int visited[], int node, int n)
{
    visited[node] = 1;

    cout << node << " ";

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            DFS(graph, visited, i, n);
        }
    }
}
void BFS(int graph[10][10], int start, int n)
{
    int visited[10] = {0};

    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n;
    int graph[10][10];
    int visited[10] = {0};
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(graph, visited, start, n);

    cout << endl;

    cout << "BFS Traversal: ";
    BFS(graph, start, n);

    cout << endl;

    return 0;
}
