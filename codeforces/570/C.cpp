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
int MOD = 1e9 +7;
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
const int N = (int) 3e5 +5;
bool ok[N];
int main() {
    smile();
    int n , m ; cin >> n >> m ;
    string s ; cin >> s;
    int cnt = 0 , seg = 0 ;
    for (int i = 0; i <s.size() ; ++i) {
        if(s[i] == '.'){
            int j ;
            seg++;
            for ( j = i; j <n ; ++j ,cnt++, ++i) {

                if(s[j]!='.'){

                    break;
                }
                ok[j+1] = 1;
            }

        }
    }
    for (int k = 0; k <m ; ++k) {
        int indx ;char c ; cin >>indx >> c;
//        indx--;
        bool prev = ok[indx];
        bool nw = c=='.';
        if(prev != nw){
            if(prev){
                cnt--;
            }
            else
                cnt++;
            if(ok[indx-1 ] && ok[indx+1] && nw)
                seg--;
            if(ok[indx-1 ] && ok[indx+1] && !nw)
                seg++;

            if(!ok[indx-1]&& !ok[indx+1] && prev)
                seg--;
            if(!ok[indx-1]&& !ok[indx+1] && !prev)
                seg++;


        }
        ok[indx] = nw;
        cout << cnt - seg <<endl;
    }


}
