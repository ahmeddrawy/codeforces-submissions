//
// Created by ahmed_drawy on 18/08/19.
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
char reverse (char c) {
    if(c == ')')return '(';
    return ')';
}
pair<int , char> valid(string s ){
    if( s[0] == ')' && s[s.size()- 1] == '(')
        return {-1, 'V'};    /// invalid
//    if(s[0] == ')')reverse(s.begin( ) , s.end());
    stack<char> mstack ;
    mstack.push(s[0]);
    lp(i,1,s.size()){
        if(!mstack.empty()){
            char curr = mstack.top();
            if(s[i] == reverse(curr) && s[i] ==')'){
                mstack.pop();
                continue;
            }
        }
        mstack.push(s[i]);
    }
    int open = 0 ,close = 0 ;
    while(!mstack.empty()){
        auto curr= mstack.top();mstack.pop();
        if(curr == '(')open++;
        else           close ++;
    }
    if(open && close )
        return {-1 , 'V'};
//    open = max(open , close)
    if(open){
        return {open , '('};
    }
    else if(close){
        return {close , ')'};
    }
    else  return {0,'0'};
//    return {mstack.size() , !mstack.empty()? mstack.top() : '0'};
}

int main() {
    smile();
    int n ; cin >> n;
    map<int  , int   > closing ;
    map<int  , int   > opening ;
    int cnt = 0 , mx = 0 ;
    lp(i,0,n){
        string s;cin >>s;
        auto curr = valid(s);
        if(curr.first!= -1 ){
            if(curr.second == '('){
                opening[curr.first]++;
                mx = max(mx , curr.first);
            }
            else if(curr.second == ')'){
                closing[curr.first]++;
                mx = max(mx , curr.first);
            }
            else {
                cnt++;
            }

        }

    }
    cnt /=2; ///dividing valid by 2 because making pairs
    lp(i,1,mx+1){ /// if string need one closing we must have at least one opening
        cnt += min(opening[i] , closing[i]);
    }
    cout<<cnt;

}