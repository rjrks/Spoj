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

long long   mod=1000000007;

long long n,k;

class matrix{
    
public:
    
    long long m[2][2];
    
    
    matrix(){
        
        
        m[0][0]=5;
        m[0][1]=3;
        m[1][0]=3;
        m[1][1]=2;
        
        
    }
    
    
};


matrix msub(matrix m1,matrix m2){
    
    matrix res;
    
    res.m[0][0]=m1.m[0][0]-m2.m[0][0];
    res.m[1][0]=m1.m[1][0]-m2.m[1][0];
    res.m[0][1]=m1.m[0][1]-m2.m[0][1];
    res.m[1][1]=m1.m[1][1]-m2.m[1][1];
    
    return res;
}





matrix matmult(matrix mat1, matrix mat2){
    
    matrix res;
    
    res.m[0][0]=((mat1.m[0][0]*mat2.m[0][0])%mod+(mat1.m[0][1]*mat2.m[1][0])%mod)%mod;
    res.m[0][1]=((mat1.m[0][0]*mat2.m[0][1])%mod+(mat1.m[0][1]*mat2.m[1][1])%mod)%mod;
    res.m[1][0]=((mat1.m[1][0]*mat2.m[0][0])%mod+(mat1.m[1][1]*mat2.m[1][0])%mod)%mod;
    res.m[1][1]=((mat1.m[1][0]*mat2.m[0][1])%mod+(mat1.m[1][1]*mat2.m[1][1])%mod)%mod;
    
    
    return res;
    
}


matrix mpow(matrix m,long long k){
    //calculates M^k
    
    if(k==1)return m;
    
    matrix x=mpow(m,k/2);
    
    matrix r=matmult(x, x);
    
    if(k%2!=0)r=matmult(r, m);
    
    return r;
}

long long modpow(long long a, long long p){
    //calculates a^p (mod p)
    
    if(p==1)return a;
    
    long long x=modpow(a,p/2);
    long long r=(x*x)%mod;
    
    if(p%2!=0)r=(r*a)%mod;
    
    return r;
    
}

long long modinv(long long a,long long p){
    
    return modpow(a, p-2);
    
}







int main(){
    
    int tc;cin>>tc;
    while(tc--){
        
        matrix global;
        long long n;
        cin>>n;
        
        matrix mp=mpow(global,n+1); //m=M^n+1
        
        
        
        matrix m1=msub(mp, global);
        
        matrix id;
        id.m[0][0]=1; id.m[1][0]=0;id.m[0][1]=0; id.m[1][1]=1;
        
        
        matrix m2=msub(global, id);
        
        
        matrix inv;
        
        inv.m[0][0]=m2.m[1][1];
        inv.m[0][1]=-1*m2.m[0][1];
        inv.m[1][0]=-1*m2.m[1][0];
        inv.m[1][1]=m2.m[0][0];
        
        long long det=m2.m[0][0]*m2.m[1][1]-m2.m[0][1]*m2.m[1][0];
        
        
        
        
        matrix temp=matmult(m1, inv);
        
        long long ans=(temp.m[1][1]*modinv(det, mod))%mod;
        if(ans<0)ans=ans+mod;
        cout<<ans<<endl;
        
    }
}
