#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int T;
    cin >> T;

    for(int t=1; t<=T; t++) {
        int n, m, k;
        cin >> n >> m >> k;

        int ans = 0;

        unordered_map<string, int> mp;

        for(int i=0; i<n; i++) {
            string str = "";
            for(int j=0; j<m; j++) {
                int x;
                cin >> x;
                str += x + '0';
            }
            mp[str]++;
        }

        for(auto it: mp) {
            string str = it.first;
            int cnt = it.second;

            int zeros = 0;

            for(int i=0; i<str.size(); i++) {
                if(str[i] == '0') zeros++;
            }

            if(zeros > k) continue;
            else {
                if((k%2) && (zeros%2)) ans = max(ans, cnt); 
                else if(!(k%2) && !(zeros%2)) ans = max(ans, cnt);
            }
        }

        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}