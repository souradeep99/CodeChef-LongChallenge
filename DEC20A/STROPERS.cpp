#include <bits/stdc++.h>
using namespace std;
#define int long long int
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=100005;
#define M 998244353
#define double long double
#define BINF 100000000000000
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 17500001
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;


void solve(){
    
    string s;
    cin >> s;
    int n = s.length();
    //deb(n)
    set<tuple<int, int, int>>deep[n + 1];

    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++){
        a[i] = s[i - 1] - '0';
        a[i] += a[i - 1];
    }

    for(int i = 1; i <= n; i++){
        int even = 0, odd = 0;
        for(int j = i; j <= n; j++){
            int one = a[j] - a[i - 1], len = j - i + 1;
            if(one & 1) odd++;
            else even++;
            deep[len].insert(make_tuple(one, even, odd));
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += (int)deep[i].size();

    cout << ans << "\n";

}


#undef int 
int main() {
#define int long long int
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("optput.txt", "w", stdout); 
#endif
     
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

return 0;  
} 



