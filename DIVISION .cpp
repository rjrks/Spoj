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


ll const p=1000000007;

//return 2^n mod p

ll mod(ll n){
    
    if(n==1)return 2;
    
    ll x=mod(n/2);
    ll a=(x*x)%p;
    
    if(n%2!=0)a=(a*2)%p;
    
    return a;
    
    
    
}







int main(){
    
    uint64_t a;
    
    while(scanf("%llu",&a)!=EOF){
        
        //scanf("%lld",&a);
        
        ll temp;
        
        if(a%2==0)temp=mod(a)-1;
        else temp=mod(a)-2;
        
        if(temp<0)temp+=p;
        
        temp=(temp*333333336)%p;
        temp=(temp+1)%p;
        
        printf("%lld",temp);
        printf("\n");
        
    }
    
}

/*
 
 TESTCASES
 
 
 
 */



