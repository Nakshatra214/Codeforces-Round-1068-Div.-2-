#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
void solve() {
    int ab; 
    cin >> ab;
    
    vector<ll> bc(ab), cd(ab);
    for (int i = 0; i < ab; ++i) cin >> bc[i];
    for (int i = 0; i < ab; ++i) cin >> cd[i];
    
    ll de = 0;
    ll ef = 0;
    
    for (int i = 0; i < ab; ++i) {
        ll fg = max(de - bc[i], cd[i] - ef);
        ll gh = min(ef - bc[i], cd[i] - de);
        
        de = fg;
        ef = gh;
    }
    
    cout << de << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
//nakshatra