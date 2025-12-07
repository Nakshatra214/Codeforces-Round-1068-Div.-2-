#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <chrono>
 
using namespace std;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
void solve() {
    int ab;
    long long bc;
    if (!(cin >> ab >> bc)) return;
    
    vector<int> cd(ab);
    for(int i = 0; i < ab; ++i) {
        cin >> cd[i];
    }
    
    sort(cd.begin(), cd.end());
    cd.erase(unique(cd.begin(), cd.end()), cd.end());
    
    int de = cd.size();
    
    for(int x : cd) {
        if (bc / x > ab) {
            cout << -1 << "\n";
            return;
        }
    }
 
    unordered_map<int, int, custom_hash> ef;
    ef.reserve(de * 2);
    for(int i = 0; i < de; ++i) {
        ef[cd[i]] = i;
    }
 
    vector<bool> fg(de, false);
    vector<int> gh;
 
    for(int i = 0; i < de; ++i) {
        if(fg[i]) continue;
        
        int hi = cd[i];
        gh.push_back(hi);
        
        for(long long ij = hi; ij <= bc; ij += hi) {
            if(ef.find((int)ij) == ef.end()) {
                cout << -1 << "\n";
                return;
            }
            fg[ef[(int)ij]] = true;
        }
    }
 
    cout << gh.size() << "\n";
    for(int i = 0; i < gh.size(); ++i) {
        cout << gh[i] << (i == gh.size() - 1 ? "" : " ");
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}
//nakshatra