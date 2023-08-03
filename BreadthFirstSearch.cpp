#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<int> adj[])
{

    int initial = 0; // lets traversal begins from node 0

    vector<bool> visited(V, false); // to decide which node visited and which node is not.

    visited[initial] = true; // yes 0 is starting , so visited

    queue<int> q; // to keep track of nodes to be visited

    q.push(initial);

    vector<int> ans;

    while (!q.empty()) // run till every items visited
    {

        int p = q.front();
        ans.push_back(p);
        q.pop();

        for (auto ad : adj[p])
        {
            if (!visited[ad])
            {
                visited[ad] = true;
                q.push(ad);
            }
        }
    }

    return ans;
}

int main()
{

    int node = 5;
    vector<int> adj[5];

    adj[0].push_back(2); // 0 is adjacent to 2
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[2].push_back(4);

    vector<int> ans = bfs(node, adj);

    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
    return 0;
}