//

//  Created by Rohan on 30/08/14.

//  Copyright (c) 2014 Rohan. All rights reserved.

//



#include <math.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>







using namespace std;
typedef long long llong;

llong const mod=500000003;


llong nfac[1000001];


llong modpow(llong a, llong p){
    //calculates a^p (mod p)
    
    if(p==1)return a;
    
    llong x=modpow(a,p/2);
    llong r=(x*x)%mod;
    
    if(p%2!=0)r=(r*a)%mod;
    
    return r;
    
}

llong modinv(llong a,llong p){
    
    return modpow(a, p-2);
    
}


int main(){
    nfac[0]=1;
    llong n,x,y;
    
    cin>>n>>x>>y;
    if(x<0)x=-1*x;
    
    if(y<0)y=-1*y;
    
    
    for(llong i=1;i<=n;i++){
        
        nfac[i]=(i*nfac[i-1])%mod;
        
    }
    
    
    
    if(n<(x+y))cout<<0;
    else if((n-x-y)%2!=0)cout<<0;
    
    else{
        llong r,l,u,d;
        llong ans=0;
        
        llong sum=(n-x-y)/2;
        
        for(llong i=0;i<=sum;i++){
            
            l=i;
            d=sum-i;
            r=l+x;
            u=d+y;
            
            
            llong temp;
            
            temp=(nfac[r]*nfac[u])%mod;
            temp=(temp*nfac[d])%mod;
            temp=(temp*nfac[l])%mod;
            
            temp=modinv(temp, mod);
            temp=(nfac[n]*temp)%mod;
            
            ans=(ans+temp)%mod;
            
            
        }
        
        
        
        cout<<ans;
        
        
        
        
        
    }
    
    
    
}

