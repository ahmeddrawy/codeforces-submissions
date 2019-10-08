/// Educational Codeforces Round 74 - by ahmed_drawy 08/10/19
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v));
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
#define debug(x) cerr << x<<endl;
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
int randomF() {
    return  (rand() * RAND_MAX + rand()) % 1000000;

}

int MOD ;
int mod(ll x){
    return (x%MOD + MOD)%MOD;
}
long long add(long long x, long long y)
{
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}
ll multipy(ll x , ll y ){
    return ((x%MOD) *(y%MOD))%MOD;
}
const int N = 1e6 + 5;
int factor[N];
void sieve() {
//    factor[0] = 0 ;
    factor[1] = 1;
    for (ll i = 2; i * i < N; ++i) {
        if (factor[i])
            continue;
        for (ll j = i * i; j < N; j += i)
            factor[j] = i;
    }
}

int main() {
    smile();
    int t ; cin >>t;
//    cout <<(ll)1e18<<endl;
//    exit(0);
    while(t--){
        int n , r; cin >> n >> r;
        vector<int> vec(n);
        for (int i = 0; i <n ; ++i) {
            cin >> vec[i];
        }
        sort(vec.begin() , vec.end());
        vec.erase( unique(vec.begin() , vec.end()) , vec.end());
        int i = 0 ;
        for (int j = sz(vec)-1 ; j >=0  ; --j , i++) {
            if(vec[j]<= i*r)
                break;
        }
        cout << i << endl;

    }

}