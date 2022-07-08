#include <iostream>
#include <unordered_set>

using namespace std;

int n, b[10], c[10], d[10];

bool is_valid(int a, int b, int c, int d) {
    int arr_a[5], arr_b[5];
    int count_c=0, count_d=0;

    for(int i=0; i<5; i++) {
        arr_a[i] = a%10;
        arr_b[i] = b%10;

        a = a/10;
        b = b/10;

        if(arr_a[i]==arr_b[i]) {
            count_c++;
            arr_a[i] = -1;
            arr_b[i] = -1;
        }
    }

    if(count_c != c) return false;

    for(int i=0; i<5; i++) {
        if(arr_a[i] != -1) {
            for(int j=0; j<5; j++) {
                if(arr_a[i]==arr_b[j]) {
                    count_d++;
                    arr_a[i] = -1;
                    arr_b[j] = -1;
                    break;
                }
            }
        }
    }

    if(count_d != d) return false;

    return true;
}

int main() {

    int T;
    cin >> T;

    int max_d=-1, max_d_pos=0;

    for(int t=1; t<=T; t++) {
        unordered_set<int> valid_set;

        cin >> n;

        for(int i=0; i<n; i++) {
            cin >> b[i] >> c[i] >> d[i];

            if(d[i] > max_d) {
                max_d = d[i];
                max_d_pos = i;
            }
        }

        for(int a=10000; a<=99999; a++) {
            if(is_valid(a, b[max_d_pos], c[max_d_pos], d[max_d_pos])) {
                valid_set.insert(a);
            }
        }

        for(int i=0; i<n; i++) {
            if(i != max_d_pos) {
                unordered_set<int> temp_valid_set = valid_set;
                for(auto &a: temp_valid_set) {
                    if(!is_valid(a, b[i], c[i], d[i])) {
                        valid_set.erase(a);
                    }
                }
            }
        }

        cout << "#" << t << " " << valid_set.size() << endl;
    }

    return 0;
}

/*

A and B are 5 digit nos
C: exactly C digits must be at same pos in A and B
D: exactly C digits must not be at same pos in A and B

*/

/* N triplets: Bi, Ci, Di; Find number of As that will satisfy these */