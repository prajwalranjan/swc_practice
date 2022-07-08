#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> pace;

void backtrack(int H, int D, int &res, int mask, int tm) {
    if(H<0) return;

    if(D==0) {
        res = min(res, mask);
        return;
    }

    for(int i=0; i<5; i++) {
        if((mask & (1 << i)) == (1 << i)) {
            mask ^= (1 << i);

            int curr_h = H;
            int curr_d = D;
            int curr_t = tm;

            while(1) {
                if(curr_h >= 0) backtrack(curr_h, curr_d, res, mask, curr_t);

                else break;

                curr_h -= pace[i].second;
                curr_d += 1;
                curr_t +- pace[i].first;
            }
        }
    }
}

void solve() {
    int H, D;
    cin >> H >> D;

    pace.clear();

    for(int i=0; i<5; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        int second = a*60 + b;

        pace.push_back({second, c});
    }

    int mask = 31; //11111

    int res = 0;
    
    backtrack(H, D, res, mask, 0);

    cout << res / 60 << " " << res % 60 << endl;
}

int main() {
    int T;
    cin >> T;

    for(int t=1; t<=T; t++) {
        cout << "#" << t << " ";
        solve();
    }

    return 0;
}