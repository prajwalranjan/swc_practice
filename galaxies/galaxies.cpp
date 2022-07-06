#include <iostream>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int matx[100], maty[100];
bool visited[100];
vector<vector<int>> groups;

bool valid(int i, int j, int r) {
    int dx = matx[i] - matx[j];
    int dy = maty[i] - maty[j];

    int d = dx*dx + dy*dy;

    if(d <= r*r) return true;

    return false;
}

void dfs(int i, int n, int r, int id) {
    visited[i] = true;

    groups[id].push_back(i);

    for(int nbr=0; nbr<n; nbr++) {
        if(!visited[nbr] && valid(i, nbr, r)) {
            dfs(nbr, n, r, id);
        }
    }
}

int main() {

    freopen("sample_input.txt", "r", stdin);

    int T;
    cin >> T;

    for(int test_case=1; test_case<=T; test_case++) {
        int n;
        cin >> n;

        int r;
        cin >> r;

        for(int i=0; i<n; i++) {
            cin >> matx[i] >> maty[i];
            visited[i] = false;
        }

        groups = vector<vector<int>> (n);

        int id = 0;

        for(int i=0; i<n; i++) {
            if(!visited[i]) dfs(i, n, r, id++);
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            if(groups[i].size() >=  2) ans++;
        }

        cout << "#" << test_case << " " << ans << endl;
    }

    return 0;
}