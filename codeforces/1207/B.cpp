//
// Created by ahmed_drawy on 22/08/19.
/// educational contest 71
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
int n , m ;
int a[51][51];
int b[51][51];
bool check(int i ,int j){
    return a[i+1][j] ==1 && a[i][j+1] == 1 && a[i+1][j+1]==1;
}
int main() {
    smile();
     cin >> n >> m  ;

    lp(i,0,n){
        lp(j,0,m){
            cin>>a[i][j];
        }
    }
    vector<pii> mvec;
    lp(i,0,n-1){
        lp(j,0,m-1){
            if(a[i][j] == 1  && check (i,j) ){
                b[i][j]=b[i+1][j] = b[i][j+1] = b[i+1][j+1]=1;
                mvec.push_back({i+1,j+1});
            }

        }
    }
//    lp(i,0,n) {
//        lp(j, 0, m) {
//            cout<<b[i][j]<<' ';
//        }
//        cout<<endl;
//    }
            lp(i,0,n){
        lp(j,0,m){
            if(a[i][j]!=b[i][j]){
                cout<<-1;
                return 0;
            }
        }
    }
    cout << mvec.size()<<'\n';
    for (int k = 0; k < mvec.size(); ++k) {
        cout<<mvec[k].first<<' '<<mvec[k].second<<'\n';
    }


}