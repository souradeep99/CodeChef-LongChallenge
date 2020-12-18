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
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 1);
    for(int i = 1; i <= n; i++)
        v[i] = i;

    int K = k;
    k = n - k;
    for(int i = 1; i <= n and k > 0; i += 2, k--){
        v[i] *= -1;
    }
    int r = n - n % 2;
    while(k > 0){
        k--;
        v[r] *= -1;
        r -= 2;
    }

    int c = 0, s = 0;
    for(int i = 1; i <= n; i++){
        s += v[i];
        if(s > 0) c++;
    }
    assert(c == K);

    for(int i = 1; i <= n; i++)
        cout << v[i] << ' ';
    cout << endl;
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



