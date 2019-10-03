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
ll M[2][2];
void matrixMultiply (ll Matrix[2][2] , ll mid[2][2] ){
    int res[2][2] = {{0,0 } , {0,0}};

    for (int i = 0; i<2 ; ++i) {
        for (int j = 0; j <2 ; ++j) {
            for (int k = 0; k <2 ; ++k) {
                res[i][j] = add(res[i][j],multipy( Matrix[i][k],mid[k][j]));
            }
        }
    }
    for (int l = 0; l <2 ; ++l) {
        for (int i = 0; i < 2; ++i) {
            Matrix[l][i] = res[l][i];
        }
    }
//    return res;



}

void binpow( ll y[2][2],int b ) {
    if(b== 0 || b==1) {
        return  ;

    }
    binpow(y, b/2);
//    matrixMultiply(y, y);
//    vector<vector<ll >> y = binpow(b/2);
    matrixMultiply(y , y);
    if(b&1)
         matrixMultiply(y , M);
    return ;

}
/// matrix exponetiation to get M^n-1 * base  case
//int  matrix[2][2];
int main() {
    smile();
    int n  ; cin >> n >> MOD;
    M[0][0] = 3;
    M[0][1] = 1;
    M[1][0] = 0;
    M[1][1] = 1;
    ll y[2][2];
    for (int l = 0; l <2 ; ++l) {
        for (int i = 0; i <2 ; ++i) {
            y[l][i] = M[l][i];
        }
    }
    int mid[2][1] = {2 , 2};
    if(n==1)
        cout << 2%MOD;
    else {
        binpow(y , n-1);
        vector<vector<ll> >res(2);
        res[0].push_back(0);
        res[1].push_back(0);
        for (int i = 0; i<2 ; ++i)
            for (int j = 0; j <1 ; ++j)
                for (int k = 0; k <2 ; ++k) {
                    res[i][j] =  add(res[i][j],multipy( y[i][k],mid[k][j]));
                }
        cout << (res[0][0]) ;
    }
    return 0;



}