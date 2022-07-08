#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
#define MOD 1000000007;
ll INF = 1e18;

void solve() {
    ll D, H;
    cin >> D >> H;

    vector<pair<int, int>> v(5);

    for(int i=0; i<5; i++) {
        ll m, s, p;
        cin >> m >> s >> p;
        v[i] = {m*60 + s, p};
    }

    ll res=INT_MAX, energy=0, time=0;

    for(ll a=0; a<=D; a++) {
        energy = a*v[0].second;
        time = a*v[0].first;

        if(energy <= H && a == D) res = min(res, time);

        if(energy > H) break;

        for(ll b=0; a+b<=D; b++) {
            energy = a*v[0].second + b*v[1].second;
            time = a*v[0].first + b*v[1].first;

            if(energy <= H && a+b == D) res = min(res, time);

            if(energy > H) break;

            for(ll c=0; a+b+c<=D; c++) {
                energy = a*v[0].second + b*v[1].second + c*v[2].second;
                time = a*v[0].first + b*v[1].first + c*v[2].first;

                if(energy <= H && a+b+c == D) res = min(res, time);

                if(energy > H) break;

                for(ll d=0; a+b+c+d<=D; d++) {
                    energy = a*v[0].second + b*v[1].second + c*v[2].second + d*v[3].second;
                    time = a*v[0].first + b*v[1].first + c*v[2].first + d*v[3].first;

                    if(energy <= H && a+b+c+d == D) res = min(res, time);

                    if(energy > H) break;

                    for(ll e=0; a+b+c+d+e<=D; e++) {
                        energy = a*v[0].second + b*v[1].second + c*v[2].second + d*v[3].second + e*v[4].second;
                        time = a*v[0].first + b*v[1].first + c*v[2].first + d*v[3].first + e*v[4].first;

                        if(energy <= H && a+b+c+d+e == D) res = min(res, time);

                        // if(energy > H) break;
                    }
                }
            }
        }
    }
}

int main() {
    return 0;
}