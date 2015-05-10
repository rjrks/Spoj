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
#include <map>
#include <list>
#include <stack>


using namespace std;


typedef unsigned long long ll;










int main(){
    
    
    
    int tc;
    cin>>tc;
    while(tc--){
        
        ll a[63];
        
        a[1]=0; a[2]=1; a[3]=0; a[4]=3;
        
        for(int i=5;i<=57;i++){
            
            if(i%2!=0){a[i]=0; continue;}
            
            ll num=(i-2)*(i-1);
            ll den=(i/2)*(i-1-i/2);
            
            a[i]=(a[i-2]*num)/den;
        }
        
        
        
        
        ll sum[61];
        
        sum[0]=0;
        for(int i=1;i<=57;i++){
            
            sum[i]=sum[i-1]+a[i];
            
            
            
        }
        
        
        ll n;
        cin>>n;
        
        int x=log2l(n);
        
        if(x==58 || x==59)cout<<"20164267233747049"<<endl;
        else if(x==60)cout<<"79296558016177761"<<endl;
        else if(x==1)cout<<1<<endl;
        else cout<<sum[x]<<endl;
    }
}
