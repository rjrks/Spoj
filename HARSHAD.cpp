///

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
#include <map>
#include <list>
#include <stack>
#include <algorithm>




using namespace std;
typedef long long ll;

int a[1000001];
bool v[1000001];

std::map<int, bool>prime;


void sieve(){
    
    for(int i=1;i<=1000000;i++){
        
        a[i]=i; v[i]=false;
    }
    
    a[1]=-1;
    
    for(int i=2;i<=1000000;i++){
        
        if(v[i]==true)continue;
        
        for(int j=2*i;j<=1000000;j+=i){
            
            
            if(v[j]==true)continue;
            
            v[j]=true;
            a[j]=-1;
        }
        
    }
    
    
    
}


int dev(int n){
    
    int t1=n;
    int s=0;
    
    while(true){
        
        s+=t1%10;
        
        t1/=10;
        
        
        if(t1==0)break;
    }
    
    return s+n;
    
}





int main(){
    
    
    sieve();
    
    
    for(int i=1;i<=1000000;i++){
        
        int t=dev(i);
        
        if(t>1000000)continue;
        a[t]=-1;
        
    }
    
    int count[1000001];
    
    count[0]=0;
    
    for(int i=1;i<=1000000;i++){
        
        if(a[i]==-1)count[i]=count[i-1];
        else count[i]=count[i-1]+1;
        
    }
    
    
    
    int q;
    scanf("%d",&q);
    
    while(q--){
        
        int a,b;
        
        
        scanf("%d",&a);
        scanf("%d",&b);
        
        if(a==0)a=1;
        
        
        printf("%d",count[b]-count[a-1]);
        
        printf("\n");
        
        
    }
    
}

/*
 
 TESTCASES
 
 
 
 */



