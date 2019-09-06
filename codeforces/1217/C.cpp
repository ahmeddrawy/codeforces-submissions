//
// Created by ahmed_drawy on 03/09/19.
/// Educational Codeforces Round 72 (Rated for Div. 2)
#include <bits/stdc++.h>
#include <string.h>
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
//#define dbg (v)    for(auto it : v)cout<<it<<' ';
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
#define endl '\n'
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
vector<string> ms;
const int N = 200005;
void build(){

    lp(i,1, N){
        string r;
        int tmp = i ;
        while(tmp!=0) {r=(tmp%2==0 ?"0":"1")+r; tmp/=2;}
        ms.push_back(r);
    }

}
int main() {
    smile();
    int t ; cin >> t;
//    build();
    while (t--){
        string s ; cin >> s;
        vector<int > zeros(sz(s) , 0);
        zeros[0] = s[0] == '0';
        lp(i,1,sz(s))
            if(s[i] == '0') zeros[i] +=zeros[i-1]+1;
        int ans= 0 ;
        int to = (1<<(min(19 , sz(s ) )));
        for (int j = 1; j <=min(sz(s ) , 19) ; ++j) {
            for (int i = 0; i <=sz(s) - j ; ++i) {
                string curr = s.substr(i,j);
                if(curr[0] =='0')continue;
                int currvalue = 0;
                for (int k = 0; k <sz(curr) ; ++k) {
                    currvalue +=( (1<<(sz(curr) - k -1)) *(curr[k] == '1'));
                }
                if(currvalue == 0 )continue;
                if(currvalue == j )
                    ans++;
                else if(i && currvalue <= j+zeros[i-1] && currvalue>= j){
                    ans++;
                }

            }
        }
        cout << ans << endl;
        continue;
        lp(i,0,to){
            int f = s.find(ms[i]);
            int cnt = 0 ;
            int szf =log2(i+1) +1;
            while(f != string::npos){
                if(f>0) {
                    if (zeros[f - 1] + szf >= i+1) {
                        cnt ++;

                    }
                }
                else if(i+1 == szf)
                    cnt++;
                f= s.find(ms[i] ,f+1);
            }
            ans+=cnt;
        }
        cout << ans<<endl;


    }
}