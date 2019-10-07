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

ll k ;

bool can(int mid , vector<ll > &price , vector<ll>&ration ){
    ll ans = 0 ;
    vector<ll> res;
    for (int j = 0; j <mid  ; ++j) {
        res.push_back(ration[j]);

    }
    sort(res.rbegin() , res.rend());
    for (int i = 0; i <mid ; ++i) {
        ans += res[i] *price[i]/100;
    }
    if(ans >= k )
        return true;
    return false ;


}
int main() {
    smile();
    int n ; cin >> n;
     while(n-- ){
         int q; cin >> q;
         vector<ll > price(q,0);
         vector<ll>ration(q,0);
         for (int i = 0; i <q ; ++i) {
             cin >> price[i];
         }

         ll x , a;  cin >> x >> a;
         ll y , b;  cin >> y >> b;
         cin >> k ;
         for (int j = a , i = 1; j*i  <q+1 ; i++) {
//             ration[j] = {x,y};
             ration[j*i-1] = x;
         }
         for (int j = b, i = 1; j*i  <q+1 ;i++) {
             ration[j*i-1] += y;
//             ration[j]  = j;
         }
         sort(price.rbegin() , price.rend());
//         sort(ration.rbegin() , ration.rend());
        int l = 0 , r = q;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(can(mid , price ,ration )){
                r = mid ;
            }
            else {
                l = mid +1;

            }
        }
        if(!can(l, price , ration))
            cout << -1 << endl;
        else
            cout << l << endl;

     }
}