#include <bits/stdc++.h>
using namespace std;

void dfs_helper(int node, vector<int> adj[], vector<bool> &visited, vector<int> &result)

{
    visited[node] = true;

    result.push_back(node);

    for (auto adje : adj[node])
    {
        if (!visited[adje])
            dfs_helper(adje, adj, visited, result);
    }
}

vector<int> dfs(int V, vector<int> adj[])
{

    vector<bool> visited(V, false);

    vector<int> result;

    dfs_helper(0, adj, visited, result);

    return result;
}

int main()
{

    int node = 5;
    vector<int> adj[5];

    adj[0].push_back(2); // 0 is adjacent to 2
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[2].push_back(4);

    vector<int> ans = dfs(node, adj);

    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}