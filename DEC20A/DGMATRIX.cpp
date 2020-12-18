#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=200005;
#define M 998244353
#define double long double
#define BINF 100000000000000
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 17500001
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;


int n, a[10][10], ans[10][10];
vector<pair<int, int>> pos;
int xx[] = {1, 2, 3, 5, 9};

void rec(int id){
    //cout << i << j << endl;

    if(id == pos.size()){
        int f = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ans[i][j] = a[i - 1][j - 1] - ans[i - 1][j - 1] - ans[i - 1][j] - ans[i][j - 1];
                if(ans[i][j] < 0 or ans[i][j] > 9){
                    f = 1;
                    break;
                }
                if(f) break;
            }
        }

        if(!f){
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= n; j++){
                    cout << ans[i][j];
                }
                cout << endl;
            }
            exit(0);
        }
        
        return ;

    }

    

    ans[pos[id].F][pos[id].S] = 9;
    rec(id + 1);

    ans[pos[id].F][pos[id].S] = 0;
    rec(id + 1);

    ans[pos[id].F][pos[id].S] = 3;
    rec(id + 1);

    ans[pos[id].F][pos[id].S] = 5;
    rec(id + 1);

    ans[pos[id].F][pos[id].S] = 2;
    rec(id + 1);
    
}


void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
   

    for(int i = 0; i <= n; i++)
        pos.pb(mp(0, i));
    for(int i = 1; i <= n; i++)
        pos.pb(mp(i, 0));

    //random_shuffle(pos.begin(), pos.end());
    /*ans[0][0] = 1;
    rec(1);

    ans[0][0] = 9;
    rec(1);

    ans[0][0] = 5;
    rec(1);

    ans[0][0] = 8;
    rec(1);

    ans[0][0] = 3;
    rec(1);*/

    ans[0][0] = 0;
    rec(1);

    ans[0][0] = 2;
    rec(1);

    ans[0][0] = 3;
    rec(1);

    ans[0][0] = 5;
    rec(1);

    ans[0][0] = 7;
    rec(1);

    //ans[0][0] = 3;
    //rec(1);

    
    
    

    assert(false);

}




int main() {

ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("optput.txt", "w", stdout); 
#endif
    
    solve();


return 0;  
} 



