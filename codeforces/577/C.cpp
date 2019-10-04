/// 147 -uva - by ahmed_drawy 28/09/19
#include<bits/stdc++.h>
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
const int N = 1e3 + 5;
int factor[N];
int sieve() {

    for (int i = 2; i * i < N; ++i) {
        if (factor[i])
            continue;
        for (int j = i * i; j < N; j += i)
            factor[j] = i;
    }
}

bool visited[N];
int main() {
    smile();
    int n ; cin >> n ;
    vector<int> res;

    sieve();
    set<int >mset;
    for (int k = 2; k <=n ; ++k) {
        if(!factor[k]) {
            int curr = 1;
            while(curr <= n/k){
                curr*=k;
                mset.insert(curr);

            }

        }
    }

    cout << mset.size() <<endl;
    for(auto it :mset)cout << it << " ";
}