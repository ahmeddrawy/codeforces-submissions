//
// Created by ahmed_drawy on 26/08/19.
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

int arr[101];
int n , k ;
int main() {
    smile();
    cin >> n >> k ;
//    inN(arr, n)
    vector<pii> mset(n);
    lp(i,0,n){
        cin >>arr[i];
        mset[i] = {arr[i] , i};
    }
    sort(mset.begin() , mset.end());
    vector<pii> ans(k) ;
    int i = 0 ;
    while (k--){
        int &mn = mset[0].first, &mx = mset[n-1].first;
        if(mx - mn <=1 ){
            break;
        }
        mn++, mx--;
        ans[i++] ={ mset[n-1].second , mset[0].second };
        sort(mset.begin() , mset.end());
    }
    cout << mset[n-1].first - mset[0].first<<" ";
    cout  << i << "\n";
    for (int j = 0 ; j < i ;++j){
        cout<<ans[j].first+1<<" "<<ans[j].second+1 << "\n";
    }

}