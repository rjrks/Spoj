
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
#include <stack>
#include <list>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

long long const mod=1000000007;

class matrix{
public:
    long long m[2][2];
    
    
    matrix(){
        
        memset(m, 0, sizeof(m));
        
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


matrix global;

matrix fibonacci(long long n){
    
    if(n==1)return global;
    
    long long h=(n/2);
    matrix temp=fibonacci(h);
    matrix r= matmult(temp, temp);
    
    if(n%2==1)r=matmult(r, global);
    return r;
    
    
    
}


int main(){
    
    
    
    
    int tc;
    cin>>tc;
    while(tc--){
        
        
        long long n;
        cin>>n;
        
        matrix ans=fibonacci(n+3);
        
        long long result=(ans.m[0][1]-2)%mod;
        
        cout<<result<<endl;
        
    }
    
}