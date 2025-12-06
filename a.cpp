#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; 
    cin >> t;
    while (t--) {
        int ab, bc; 
        cin >> ab >> bc;
        string cd;  
        cin >> cd;
 
        int ef = 0; // ef = remaining forced-awake classes (k counter)
        int gh = 0; // gh = number of classes we can sleep through
 
        for (int i = 0; i < ab; ++i) {
            if (cd[i] == '1') {
                // must stay awake in this class and next bc classes
                ef = bc;
            } else {
                if (ef > 0) {
                    // forced to stay awake due to a previous important class
                    ef--;
                } else {
                    // can sleep through this class
                    gh++;
                }
            }
        }
 
        cout << gh << '\n';
    }
    return 0;
}