#include <bits/stdc++.h>
using namespace std;
int m, n;
bool isValid(int x, int y, vector<vector<char>> &map)
{
    if (x >= 0 && x < n && y >= 0 && y < m && map[x][y] == '.')
    {
        return true;
    }
    return false;
}

void DFS(int x, int y, vector<vector<char>> &map)
{

    map[x][y] = '#';
    if (isValid(x + 1, y, map))
    {
        DFS(x + 1, y, map);
    }
    if (isValid(x - 1, y, map))
    {
        DFS(x - 1, y, map);
    }
    if (isValid(x, y + 1, map))
    {
        DFS(x, y + 1, map);
    }
    if (isValid(x, y - 1, map))
    {
        DFS(x, y - 1, map);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<map[i][j];
    //     }
    //     cout<<"\n";
    // }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '.')
            {
                ans++;
                DFS(i, j, map);
            }
        }
    }

    cout << ans;

    return 0;
}

// always use "\n" for new line and not endl
