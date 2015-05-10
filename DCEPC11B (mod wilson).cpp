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


using namespace std;

long long prime;

long long modinv(long long a, long long p ){
    if(p==1)return a;
    
    long long x=modinv(a, p/2);
    long long r=(x*x)%prime;
    
    if(p%2!=0)r=(r*a)%prime;
    
    return r;
}




int main(){
    int tc;
    cin>>tc;
    while(tc--){
        
        long long n,p;
        cin>>n>>p;
        long long lhs=1;
        if(n>=p)cout<<0<<endl;
        else if(n==(p-1))cout<<n<<endl;
        else{
            prime=p;
            for(long long i=p-1;i>n;i--){
                
                lhs=(lhs*(i%p))%p;
                
            }
            
            
            long long inv=-1*modinv(lhs, p-2);
            if(inv<0)inv=inv+p;
            cout<<inv<<endl;
            
            
            
            
        }
    }
}
