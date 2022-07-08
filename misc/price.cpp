#include <iostream>
#include <unordered_set>

using namespace std;

int k, karr[10], n, price[15], m[15], grid[15][15], vis[15], ans, store[15];

void dfs(int start, int cnt) {
    int sum = 0;
    unordered_set<int> s;

    for(int f=0; f<cnt; f++) {
        int index = store[f];
        sum += price[index];
        for(int r=0; r<m[index]; r++) {
            for(int q=0; q<k; q++) {
                if(karr[q] == grid[index][r]) {
                    s.insert(karr[q]);
                }
            }
        }
    }

    if(sum>ans) return;

    if(s.size() == k) {
        ans = min(ans, sum);
        return;
    }

    for(int i=start; i<n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            store[cnt] = 1;
            dfs(i+1, cnt+1);
            vis[i] = 0;
        }
    }
}

int main() {
    int T;
    cin >> T;

    for(int t=1; t<=T; t++) {

        cin >> k;

        for(int i=0; i<k; i++) {
            cin >> karr[i];
        }

        cin >> n;

        for(int p=0; p<n; p++) {
            cin >> price[p] >> m[p];
            for(int j=0; j<m[p]; j++) {
                cin >> grid[p][j];
            }
        }

        ans = INT_MAX;

        dfs(0, 0);

        if(ans != INT_MAX) {
            cout << "#" << t << " " << ans << endl;
        } else {
            cout << "#" << t << " " << -1 << endl;
        }
    }

    return 0;
}