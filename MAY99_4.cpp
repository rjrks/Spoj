#include <math.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <algorithm>




using namespace std;


typedef long long ll;

ll mod=10000007;
ll phi=9988440;

ll modpow(ll a, ll p){
    //calculates a^p (mod p)
    
    if(p==1)return a;
    
    ll x=modpow(a,p/2);
    ll r=(x*x)%mod;
    
    if(p%2!=0)r=(r*a)%mod;
    
    return r;
    
}

int main(){
    
    
    
    int n,r;
    ll fn=1,fr=1,fnr=1;
    
    
    scanf("%d",&n);
    scanf("%d",&r);
    
    if(n<r){printf("-1"); return 0;}
    
    for(int i=1;i<=n-1;i++)fn=(fn*i)%mod;
    for(int i=1;i<=r-1;i++)fr=(fr*i)%mod;
    for(int i=1;i<=n-r;i++)fnr=(fnr*i)%mod;
    
    
    ll ans=(fn*modpow((fr*fnr)%mod, phi-1))%mod;
    
    printf("%lld",ans);
    
}

