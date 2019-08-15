//
// Created by ahmed_drawy on 15/08/19.
// virtual contest sheet
#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))

#define inf 0x3f3f3f3f
typedef long long               ll;
//typedef first                    ft;
//typedef second                   sd;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}

int main() {
    smile();
    int n , m , k ; cin >> n >> m >> k;
    vector<ll> mvec(n+3);
    vector<ll> mans(n+3);
    vector<ll> qur(m+3);
    lp(i,0,n)cin>>mvec[i];
    map <int , pair <pair  <int , int > , ll > > qu;
    lp(i,0,m){
        int x , y; ll  d; cin >> x >> y >> d;
        qu[i] ={{x-1,y-1} , d};
    }
    lp(i,0,k){
        int x, y ; cin >> x >> y;
        x--,y--;
        qur[x]+=1;
        qur[y+1]-=1;
//        lp(j,x,y+1){    /// marking l with the value and r+1 with -ve the value and get cumm sum
//            auto curr= qu[j];
//            mans[curr.first.first]+=curr.second;
//            mans[curr.first.second+1]-=curr.second;
//        }

    }
    lp(i,1,m){
        qur[i]+=qur[i-1];
    }
    lp(i,0,m){
        qu[i].second *=qur[i];
    }
    lp(i,0,m){
        auto curr = qu[i];
        mans[curr.first.first]+=curr.second;
        mans[curr.first.second+1]-=curr.second;

    }
    lp(i,1,n){
        mans[i] +=mans[i-1];
    }
    lp(i,0,n){
        mans[i]+=mvec[i];
    }
    lp(i,0, n)cout<<mans[i] <<" ";
}