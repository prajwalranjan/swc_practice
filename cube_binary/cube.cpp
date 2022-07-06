#include <iostream>

using namespace std;

int main() {

    int T;
    cin >> T;

    for(int t=1; t<=T; t++) {
        int n;
        cin >> n;

        int nums[n*n];

        for(int i=0; i<n*n; i++) {
            cin >> nums[i];
        }

        //i: vertical axis, j: depth, k: horizontal
        int i=0, j=0, k=0, count=0, ans=0;

        bool cube[n][n][n];
        int index = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int val = nums[index++];
                for(int k=n-1; k>=0; k--) {
                    cube[i][j][k] = val % 2;
                    val >>= 1;
                }
            }
        }

        // Horizontal axis scanning
        for(i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                count = 0;
                for(int k=0; k<n; k++) {
                    count += cube[i][j][k];
                }

                if(count==0) {
                    ans++;
                }
            }
        }

        // Vertical axis scanning
        for(j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                count = 0;
                for(int i=0; i<n; i++) {
                    count += cube[i][j][k];
                }

                if(count==0) {
                    ans++;
                }
            }
        }

        // Depth axis scanning
        for(i=0; i<n; i++) {
            for(int k=0; k<n; k++) {
                count = 0;
                for(int j=0; j<n; j++) {
                    count += cube[i][j][k];
                }

                if(count==0) {
                    ans++;
                }
            }
        }

        // Face diagonals from top face to bottom face in all faces
        for(i=0; i<n; i++) {
            // First diagonal
            j=0, k=0, count=0;
            while(j<n && k<n) {
                count += cube[i][j][k];
                j++, k++;
            }
            if(count==0) {
                ans++;
            }

            // Second Diagonal
            j=0, k=n-1, count=0;
            while(j<n && k>=0) {
                count += cube[i][j][k];
                j++, k--;
            }
            if(count==0) {
                ans++;
            }
        }

        // Face diagonals from back face to front face in all faces
        for(j=0; j<n; j++) {
            // First diagonal
            i=0, k=0, count=0;
            while(i<n && k<n) {
                count += cube[i][j][k];
                i++, k++;
            }
            if(count==0) {
                ans++;
            }

            // Second Diagonal
            i=0, k=n-1, count=0;
            while(i<n && k>=0) {
                count += cube[i][j][k];
                i++, k--;
            }
            if(count==0) {
                ans++;
            }
        }

        // Face diagonals from left face to right face in all faces
        for(k=0; k<n; k++) {
            // First diagonal
            i=0, j=0, count=0;
            while(i<n && j<n) {
                count += cube[i][j][k];
                i++, j++;
            }
            if(count==0) {
                ans++;
            }

            // Second Diagonal
            i=0, j=n-1, count=0;
            while(i<n && j>=0) {
                count += cube[i][j][k];
                i++, j--;
            }
            if(count==0) {
                ans++;
            }
        } 

        // First body diagonal
        i=0, j=0, k=0, count=0;
        while(i<n && j<n && k<n) {
            count += cube[i][j][k];
            i++, j++, k++;
        }
        if(count==0) {
            ans++;
        }

        // Second body diagonal
        i=0, j=0, k=n-1, count=0;
        while(i<n && j<n && k>=0) {
            count += cube[i][j][k];
            i++, j++, k--;
        }
        if(count==0) {
            ans++;
        }

        // Third body diagonal
        i=0, j=n-1, k=0, count=0;
        while(i<n && j>=0 && k<n) {
            count += cube[i][j][k];
            i++, j--, k++;
        }
        if(count==0) {
            ans++;
        }

        // Fourth body diagonal
        i=0, j=n-1, k=n-1, count=0;
        while(i<n && j>=0 && k>=0) {
            count += cube[i][j][k];
            i++, j--, k--;
        }
        if(count==0) {
            ans++;
        }

        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}

/*
input

3
2
0 0 3 1
3
7 7 6 7 7 6 7 7 6
3 
0 0 0 0 0 0 0 0 0

op: 10, check, check
*/