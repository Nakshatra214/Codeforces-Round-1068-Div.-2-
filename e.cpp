#include <bits/stdc++.h>
using namespace std;
 
int ab;               // n
vector<int> bc;       // permutation
vector<int> cd;       // cd[val] = index (position of each value)
 
pair<int,int> ef(int x, int y) {
    cout << "? " << x << " " << y << "\n";
    cout.flush();
 
    int u, v;
    if (!(cin >> u >> v)) exit(0);
    if (u == -1 && v == -1) exit(0);
 
    if (u >= 1 && u <= ab && v >= 1 && v <= ab && u != v) {
        int val_u = bc[u];
        int val_v = bc[v];
        swap(bc[u], bc[v]);
        cd[val_u] = v;
        cd[val_v] = u;
    }
    return {u, v};
}
 
bool gh() {
    for (int i = 1; i <= ab; ++i)
        if (bc[i] != i) return false;
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int ij;
    if (!(cin >> ij)) return 0;
 
    while (ij--) {
        cin >> ab;
 
        bc.assign(ab+1, 0);
        cd.assign(ab+1, 0);
 
        for (int i = 1; i <= ab; ++i) {
            cin >> bc[i];
            cd[bc[i]] = i;
        }
 
        if (gh()) {
            cout << "!\n";
            cout.flush();
            continue;
        }
 
        int kl = (int)floor(2.5 * ab + 800.0);
        int lm = 0;
 
        for (int i = 1; i <= ab/2 && lm < kl; ++i) {
            int j = ab - i + 1;
 
            while ((bc[i] != i || bc[j] != j) && lm < kl) {
                int pi = cd[i];
                int pj = cd[j];
 
                if (pi == j || pj == i) {
                    ef(i, j);
                    lm++;
                } else {
                    ef(pi, j);
                    lm++;
                }
            }
        }
 
        if (ab % 2 == 1 && lm < kl) {
            int mid = (ab + 1) / 2;
            while (bc[mid] != mid && lm < kl) {
                if (mid != 1) {
                    ef(1, mid);
                    lm++;
                } else break;
            }
        }
 
        cout << "!\n";
        cout.flush();
    }
    return 0;
}
//nakshatra