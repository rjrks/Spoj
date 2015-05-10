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
typedef long long ll;

#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}



int a[44723];
bool vis[44723];
int prime[4650];

int lastp;


int power[4650];

void sieve(){
    
    for(int i=1;i<=44722;i++){
        a[i]=i; vis[i]=false;
    }
    
    for(int i=2;i<=44722;i++){
        
        if(vis[i]==true)continue;
        
        for(int j=2*i;j<=44722;j=j+i){
            
            vis[j]=true;
            a[j]=-1;
            
        }
    }
    int count=2;
    prime[1]=2;
    
    for(int i=3;i<=44722;i=i+2){
        
        if(vis[i]==false){prime[count]=a[i];
            count++;
        }
    }
    
    
}




void factor(int n){
    
    lastp=-1;
    
    for(int i=1;i<=4648;i++){
        
        power[i]=0;
        if(n==1)continue;
        
        while(true) {
            
            if(n%prime[i]==0){n=n/prime[i];power[i]++;}
            else break;
            
            if(n==1)break;
            
            
        }
    }
    
    if(n!=1)lastp=n;
    
    
    
}








int main(){
    
    
    sieve();
    
    int tc;
    scanint(tc);
    
    while(tc--){
        
        
        
        int n;
        scanint(n);
        
        if(n==0){printf("%d",0); printf("\n"); continue;}
        
        factor(n);
        
        int phi=1;
        
        
        
        for(int i=1;i<4649;i++){
            
            if(power[i]==0)continue;
            
            phi*=(prime[i]-1)*pow(prime[i], (power[i]-1));
            
            
            
            
            
            
        }
        
        if(lastp!=-1)phi*=(lastp-1);
        
        
        printf("%d",phi);
        printf("\n");
        
        
    }
    
    
}