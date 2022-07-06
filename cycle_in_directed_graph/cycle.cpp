// print nodes of any cyclic digraph

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<int, vector<int>> v;
int visited[100], par[100];

int dfs(vector<int> &vis1, int node) {
    visited[node] = 1;
    vis1[node] = 1;

    for(auto& i: v[node]) {
        if(!visited[i]) {
            par[i] = node;
            int x = dfs(vis1, i);
            if(x) return x;
        }

        if(vis1[i]) {
            par[i] = node;
            return i;
        }
    }

    vis1[node] = 0;
    return 0;
}

int main() {

    int T;
    cin >> T;

    for(int t=1; t<=T; t++) {

        v.clear();
        cin >> n >> m;

        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;

            v[a].push_back(b);
        }

        for(int i=1; i<=n; i++) {
            visited[i] = 0;
            parent[i] = 0;
        }

        int x;

        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                vector<int> vis1(n);
                x = dfs(vis1, i);
                if(x) break;
            }
        }

        if(x) {
            vector<int> ans;
            ans.push_back(x);

            int i = par[x];

            while(i != x) {
                ans.push_back(i);
                i = par[i];
            }

            sort(ans.begin(), ans.end());

            for(auto&j: ans) {
                cout << j << " ";
            }
            cout << endl;
        } else {
            cout << 0 << endl;
        }

        cout << "#" << t << " " << endl;
    }

    return 0;
}