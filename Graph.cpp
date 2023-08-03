#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> v, int sv)
{
    int n = v.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int cv = q.front();
        q.pop();
        cout << cv << endl;
        for (int i = 0; i < n; i++)
        {
            if (v[cv][i] && !visited[i])
            {

                q.push(i);
                visited[i] = true;
            }
        }
    }
}
void print(vector<vector<int>> v, int sv, vector<bool> &visited)
{

    cout << sv << endl;
    visited[sv] = true;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (v[sv][i] == 1 && !visited[i])
            print(v, i, visited);
    }
}

void DFS(vector<vector<int>> v)
{
    int n = v.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
            print(v, i, visited);
    }
}

int main()
{

    int v, e;
    cin >> v >> e;
    vector<vector<int>> matrix(v, vector<int>(v, 0));

    for (int i = 1; i <= e; i++)
    {

        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }
    vector<bool> visited(v, false);
    DFS(matrix);

    return 0;
}
