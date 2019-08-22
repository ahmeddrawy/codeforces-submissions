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

int main() {
    smile();
    int t; cin >> t;
    while(t--){
        int b ,p , f , c ,h; cin >> b >> p >> f>>h >> c;
        int profit = 0;
        if(c> h){
            int curr = min(b/2 , f);
            profit += curr * c ;
            b -= curr *2;
            profit += min(b/2 ,p) * h;
        }
        else {
            int curr = min(b/2 , p);
            profit += curr * h ;
            b -= curr *2;
            curr = min(b/2 ,f);
            profit += min(b/2 ,f) * c;
        }
        cout<<profit<<"\n";


    }


}