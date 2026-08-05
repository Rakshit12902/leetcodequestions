class Solution {
public:
    // Standard DFS
void dfs(vector<int> adj[],
         int node,
         vector<int>& vis) {

    vis[node] = 1;

    for (int child : adj[node]) {

        if (!vis[child]) {

            dfs(adj,
                child,
                vis);
        }
    }
}

vector<int> remainingMethods(
    int n,
    int k,
    vector<vector<int>>& invocations) {

    // Build graph
    vector<int> adj[n];

    for (auto &edge : invocations) {

        adj[edge[0]].push_back(
            edge[1]
        );
    }

    // Find all suspicious methods
    vector<int> vis(n, 0);

    dfs(adj,
        k,
        vis);

    bool externalInvocation = false;

    // Check whether any external node
    // invokes a suspicious node
    for (int i = 0; i < n; i++) {

        if (!vis[i]) {

            for (int child : adj[i]) {

                if (vis[child]) {

                    externalInvocation = true;
                    break;
                }
            }
        }

        if (externalInvocation)
            break;
    }

    vector<int> ans;

    // If removal is unsafe,
    // keep all methods
    if (externalInvocation) {

        for (int i = 0; i < n; i++)
            ans.push_back(i);

        return ans;
    }

    // Otherwise,
    // keep only non-suspicious methods
    for (int i = 0; i < n; i++) {

        if (!vis[i])
            ans.push_back(i);
    }

    return ans;
}
};