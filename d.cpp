#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
void solve() {
    ll bc, cd;
    if (!(cin >> bc >> cd)) return;
 
    int de = 66; 
    vector<int> ef(de, 0);
    for (int i = 0; i < 62; ++i) {
        if ((bc >> i) & 1) ef[i] = 1;
    }
 
    vector<int> fg(de + 1, 0);
    for (int i = 0; i < de; ++i) {
        fg[i+1] = fg[i] + (ef[i] == 0 ? 1 : 0);
    }
 
    ll gh = min((ll)70, cd);
    
    vector<vector<ll>> hi(de, vector<ll>(gh + 1, -1));
 
    for (int i = 0; i < de; ++i) hi[i][0] = 0;
 
    for (int i = 0; i < de - 1; ++i) {
        if (i > 0) {
            for (int w = 0; w <= gh; ++w) {
                hi[i][w] = max(hi[i][w], hi[i-1][w]);
            }
        }
 
        if (ef[i+1] == 0) {
            for (int j = i; j >= 0; --j) {
                int jk = 1 + (fg[i+1] - fg[j]);
                int kl = i - j + 1;
 
                if (jk > gh) continue;
 
                for (int w = jk; w <= gh; ++w) {
                    ll lm = 0;
                    if (j >= 2) lm = hi[j-2][w - jk];
                    else lm = (w == jk ? 0 : -1); 
                    
                    if (w > jk && j < 2) { 
                         lm = 0; 
                    }
 
                    if (j < 2) {
                        if (w >= jk) hi[i][w] = max(hi[i][w], (ll)kl);
                    } else {
                        if (hi[j-2][w - jk] != -1) {
                            hi[i][w] = max(hi[i][w], hi[j-2][w - jk] + kl);
                        }
                    }
                }
            }
        }
    }
 
    ll ij = 0;
    for (int w = 0; w <= gh; ++w) {
        if (hi[de-2][w] != -1) {
            ij = max(ij, hi[de-2][w] + (cd - w));
        }
    }
 
    cout << ij << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ab;
    if (cin >> ab) {
        while(ab--) {
            solve();
        }
    }
    return 0;
}
//nakshatra