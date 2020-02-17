#include <iostream>

using namespace std;

int main()
{   long long  n , packs , i, j=0 , value;
     char sign;
    cin>>n>>packs;
    for(i=0;i<n ;i++){
        cin>>sign>>value;
        if(sign=='+'){packs=packs+value;}
        else if (sign=='-'){
            if (value>packs){ j=j+1;}
            else{packs=packs-value;}}

        }
        cout<<packs<<"  "<<j ;
    return 0;
}
