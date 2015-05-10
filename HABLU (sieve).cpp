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
#include <map>




//no. of prime less than 10^6 are 78498
using namespace std;

typedef long long ll;


bool a[1000001]={false};
ll prime[80000];

void sieve(){
    int count=0;
    for(int i=2;i<=1000000;i++){
        
        
        if(!a[i]){
            for(int j=2*i;j<=1000000;j=j+i){a[j]=true;}
            
            prime[count]=i;count++;
        }
        
    }
    
}



int main(){
    
    
    sieve();
    
    int tc;
    cin>>tc;
    while(tc--){
        ll n,s,tempo;
        cin>>n>>s;
        tempo=n;
        bool onef=true;
        
        
        //CANCELLING ALL COMMON FACTORS
        for(int i=0;i<s;i++){
            
            int in;
            cin>>in;
            
            if(in==1){onef=false; break;}
            while(n%in==0)n/=in;
            
        }
        //ENDS
        
        bool flag=false;
        if(tempo==n)flag=true;
        
        if(!onef)cout<<0;
        
        
        else{
            
            ll fact=1;
            
            for(int i=0;i<78498 && prime[i]*prime[i]<=n;i++){
                
                
                int power=0;
                while(true){
                    
                    if(n%prime[i]==0){n/=prime[i]; power++;}
                    else break;
                }
                
                fact*=(power+1);
                
            }
            
            if(n>1)fact=fact*2;
            
            if(flag)fact--;
            cout<<fact<<endl;
            
        }
    }
    
}