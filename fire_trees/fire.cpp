#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[10][10], aa[10][10]; // "aa" is a copy of "a"
int treex[10], treey[10], firex[10], firey[10];
int tree_count, fire_count;

void fire(int x, int y) {
    if(x<0 || y<0 || x>=n || y>=n) return;

    if(aa[x][y] != 1) return;

    aa[x][y] = 0;

    fire(x+1, y);
    fire(x-1, y);
    fire(x, y+1);
    fire(x, y-1);
}

int burn() {
    int count = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            aa[i][j] = a[i][j];
        }
    }

    for(int i=0; i<fire_count; i++) {
        fire(firex[i], firey[i]+1);
        fire(firex[i], firey[i]-1);
        fire(firex[i]+1, firey[i]);
        fire(firex[i]-1, firey[i]);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(a[i][j] == 1) {
                 count++;
            }
        }
    }

    return count;
}

int main() {

    int T;
    cin >> T;

    for(int t=1; t<=T; t++) {

        cin >> n >> m;

        tree_count = 0;
        fire_count = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> a[i][j];
                if(a[i][j]==1) {
                    treex[tree_count] = i;
                    treey[tree_count] = j;
                    tree_count++;
                } else if(a[i][j]==2) {
                    firex[fire_count] = i;
                    firey[fire_count] = j;
                    fire_count++;
                }
            }
        }

        int saved = 0; // number of trees left after burning

        if(m==0) {
            saved = burn(); // does the burn thing
        } else if(m==1) {
            saved = burn();

            for(int i=0; i<tree_count; i++) {
                a[treex[i]][treey[i]] = 0;
                saved = max(saved, burn());
                a[treex[i]][treey[i]] = 1;
            }
        } else {
            saved = burn();

            for(int i=0; i<tree_count; i++) {
                a[treex[i]][treey[i]] = 0;
                saved = max(saved, burn());
                a[treex[i]][treey[i]] = 1;
            }

            for(int i=0; i<tree_count; i++) {
                a[treex[i]][treey[i]] = 0;
                for(int j=i+1; j<tree_count; j++) {
                    a[treex[j]][treey[j]] = 0;
                    saved = max(saved, burn());
                    a[treex[j]][treey[j]] = 1;
                }
                a[treex[i]][treey[i]] = 1;
            }
        } // when m==2
        
        cout << "#" << t << " " << saved << endl;
    }

    return 0;
}