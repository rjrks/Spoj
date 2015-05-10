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
#include <list>
#include <stack>
using namespace std;
typedef long long ll;

ll mod=1000000007;

class matrix{
public:
    ll m[2][2];
    
    
    matrix(){
        m[0][0]=1;
        m[0][1]=1;
        m[1][0]=1;
        m[1][1]=0;
        
        
    }
    
    
};


matrix matmult(matrix mat1, matrix mat2){
    
    matrix res;
    
    res.m[0][0]=(mat1.m[0][0]*mat2.m[0][0]+mat1.m[0][1]*mat2.m[1][0])%mod;
    res.m[0][1]=(mat1.m[0][0]*mat2.m[0][1]+mat1.m[0][1]*mat2.m[1][1])%mod;
    res.m[1][0]=(mat1.m[1][0]*mat2.m[0][0]+mat1.m[1][1]*mat2.m[1][0])%mod;
    res.m[1][1]=(mat1.m[1][0]*mat2.m[0][1]+mat1.m[1][1]*mat2.m[1][1])%mod;
    
    
    return res;
    
}


matrix fibo(matrix a, ll n){
    
    if(n==1)return a;
    
    matrix x=fibo(a, n/2);
    matrix r=matmult(x, x);
    
    if(n%2!=0)r=matmult(r, a);
    
    return r;
    
    
    
}








int main(){
    
    int tc;
    scanf("%d",&tc);
    
    while(tc--){
        ll n;
        scanf("%lld",&n);
        
        
        matrix k;
        
        matrix ans=fibo(k, n+1);
        
        ll f1=ans.m[0][1];
        
        ll f2=ans.m[0][0];
        
        // cout<<f1<<" "<<f2<<endl;
        
        ll res= (f1*f2)%mod;
        res=res-1;
        
        if(res<0)res+=mod;
        
        printf("$");
        printf("%lld \n",res);
        
        
        
        
    }}

/*
 
 
 1
 
 
 
 */

