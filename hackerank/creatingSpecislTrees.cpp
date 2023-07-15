#include <bits/stdc++.h>
using namespace std;


int dfs(int u, int pathSum, vector<vector<pair<int, int>>> &graph, vector<int> &arr, vector<int> &pathDistance,vector<int> &vis)
{
    if (u == 1)
    {
       pathDistance.push_back(pathSum);
       return 1;
    }
      
    vis[u ] = 1;
    pathDistance.push_back(pathSum);
    int ans = 0;
    for (auto &[v, w] : graph[u])
    {
        if(vis[v]==0)
            ans |= dfs(v, pathSum + w, graph, arr, pathDistance,vis);
    }
    
    if(!ans)
      pathDistance.pop_back();

    return ans;
}

int getMinLeavesToRemove(int tree_nodes, vector<int> tree_from, vector<int> tree_to, vector<int> tree_weight, vector<int> arr)
{
    int ans = 0;

    vector<vector<pair<int,int>>> graph(tree_nodes + 1,vector<pair<int,int>>());
    for (int i = 0; i < tree_from.size(); i++)
    {
        graph[tree_from[i]].push_back({tree_to[i], tree_weight[i]});
        graph[tree_to[i]].push_back({tree_from[i], tree_weight[i]});
    }

    vector<int> pathDistance;
    vector<int> vis(tree_nodes+1,0);
    
    dfs(1, 0, graph, arr, pathDistance,vis);
    return ans;
}

int main()
{
    int tree_nodes;
    
    cin>> tree_nodes;

    vector<int> arr;
    vector<int> tree_from;
    vector<int> tree_to;
    vector<int> tree_weight;

    for (int i = 0; i < tree_nodes; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < tree_nodes - 1; i++)
    {
        int temp;
        cin >> temp;
        tree_from.push_back(temp);
    }
    for (int i = 0; i < tree_nodes - 1; i++)
    {
        int temp;
        cin >> temp;
        tree_to.push_back(temp);
    }

    for (int i = 0; i < tree_nodes - 1; i++)
    {
        int temp;
        cin >> temp;
        tree_weight.push_back(temp);
    }

    int min_leaves = getMinLeavesToRemove(tree_nodes, tree_from, tree_to, tree_weight, arr);

    cout << min_leaves << endl;

    return 0;
}