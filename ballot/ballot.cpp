#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void eliminate_one(int ballot[][30], int n, int a) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(ballot[i][j]==a) {
                ballot[i][j] = 0;
                break;
            }
        }
    }
}

void eliminate_multiple(int ballot[][30], int n, vector<int> &v) {
    for(int k=0; k<v.size(); k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(ballot[i][j]==v[k]) {
                    ballot[i][j] = 0;
                    break;
                }
            }
        }
    }
}

int main() {

    int T;
    cin >> T;

    for(int t=1; t<=T; t++) {

        int n, ans, majority;
        int ballot[30][30];

        cin >> n;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> ballot[i][j];
            }
        }

        majority = n/2;

        while(true) {
            // Count for first place
            unordered_map<int, int> count_f;
            
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(ballot[i][j]>0) {
                        count_f[ballot[i][j]]++;
                        break;
                    }
                }
            }

            int top1, max_count=0, top_count_1=0;

            for(auto it: count_f) {
                if(it.second > max_count) {
                    max_count = it.second;
                    top1 = it.first;
                    top_count_1 = it.second;
                }
            }

            if(max_count == 0) {
                ans = -1;
                break;
            }

            if(top_count_1 > majority) {
                ans = top_count_1;
                break;
            }

            // Count for last place
            unordered_map<int, int> count_last;

            for(int i=0; i<n; i++) {
                for(int j=n-1; j>=0; j--) {
                    if(ballot[i][j] > 0) {
                        count_last[ballot[i][j]]++;
                        break;
                    }
                }
            }

            int l_top, l_top_count, max_l_count=0;

            for(auto it: count_last) {
                if(it.second > max_l_count) {
                    max_l_count = it.second;
                    l_top = it.first;
                    l_top_count = it.second;
                }
            }

            vector<int> v;
            v.push_back(l_top);

            for(auto it: count_last) {
                if(it.first != l_top) {
                    int l_top_curr = it.first;
                    int l_top_count_curr = it.second;

                    if(l_top_count_curr == l_top_count) {
                        v.push_back(l_top_curr);
                    }
                }
            }

            // Elimination one at a time
            if(v.size()==1 || v.size()==2) {
                eliminate_one(ballot, n, v[0]);
            } else { // Eliminate multiple
                eliminate_multiple(ballot, n, v);
            }
        }

        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}