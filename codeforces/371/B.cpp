//
// Created by ahmed_drawy on 28/08/19.
/// c1 sheet
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
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}

vector<int > factorize(int x) {

    vector<int > mvec(7);

    while (true) {
        bool can = 0 ;

        if(x%2 == 0 ) {
            mvec[2]++;
            x/=2;
            can =1;
        }
        if(x%3 == 0 ) {
            mvec[3]++;
            x/=3;
            can =1;
        }if(x%5 == 0 ) {
            mvec[5]++;
            x/=5;
            can =1;
        }
        if(!can){
            mvec[6] = x;
            break;
        }

    }
    return mvec;
}
int main() {
    smile();
    int a , b ; cin >> a >> b ;
    auto v1 = factorize(a);
    auto v2 = factorize(b);
    if(v1[6] == v2[6]){
        cout<<abs(v1[2] - v2[2]) + abs(v1[5] - v2[5])+abs(v1[3] - v2[3]);
    }
    else cout <<-1;

}