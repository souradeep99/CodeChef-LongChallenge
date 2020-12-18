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
    int n, x;
    cin >> n >> x;
    vector<int>v(n, 0), ans(n, 0);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<int>bit[31];
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 31; j++){
            if(v[i] & (1LL << j))
                bit[j].push_back(i);
        }
    }
    int ok = 0;

    for(int i = 0; i + 1 < n and x > 0; i++){
        for(int j = 30; j >= 0 and x > 0; j--){
            if((v[i] & (1LL << j)) and bit[j].size() > 1 and x > 0){
                v[bit[j].back()] ^= (1LL << j);
                bit[j].pop_back();
                v[bit[j].back()] ^= (1LL << j);
                bit[j].pop_back();
                x--;
                if(n > 2)
                    ok = 1;
            }else if((v[i] & (1LL << j)) and bit[j].size() and x > 0){
                v[bit[j].back()] ^= (1LL << j);
                bit[j].pop_back();
                v.back() ^= (1LL << j);
                x--;
            }
        }
    } 

    if((x & 1) and n == 2){
        v[n - 2] ^= 1; v[n - 1] ^= 1;
    }
    

    for(int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << "\n";


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



