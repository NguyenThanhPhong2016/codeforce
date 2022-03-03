#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());

/*
const int mod = 1e9 + 7 ;
const int N = 1e5 + 10  ;
int fac[N];
int inv[N];
int power( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=pow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
} */
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 100  ;
int a[N] ;
const int mod = 1e9 + 7;
void solve(){
    int n  ;cin>>n ;
    int ans  = 0;
    int i = 1 ;
    while( n != 0 ){
        while( a[i] == -1 ) i++;
        ans = ( ans + i* ( n -  n / a[i]  ) ) % mod  ;
        n = n / a[i] ;
        i++;
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    a[ 0 ] = -1;
    a[ 1 ] = -1 ;
    for(int i = 2 ; i < N ; i++){
        if( a[i] == 0 ){
            for(int j = i + i ; j < N ; j= j + i ){
                a[j] = -1;
            }
            for(int j = i ; j < N ; j = j * i ){
                a[j] =  i ;
            }
        }
    }
    for(int i = 1 ;i < N ; i++){
        //cout<<i<<" "<<a[i]<<endl;
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}
