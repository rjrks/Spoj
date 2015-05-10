
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
#include <algorithm>

using namespace std;



int main(){
    
    int k,l,n1,m;
    cin>>k>>l>>m;
    
    
    for(int i=0;i<m;i++){
        
        cin>>n1;
        bool a[n1+1];
        a[n1]=false;
        
        a[n1-1]=true;
        
        for(int i=n1-2;i>=0;i--){
            
            if(a[i+1]==0 && i+1<=n1)a[i]=true;
            else if(a[i+k]==0 && i+k<=n1)a[i]=true;
            else if(a[i+l]==0 && i+l<=n1)a[i]=true;
            else a[i]=false;
            
            
        }
        
        if(a[0])cout<<"A";
        else cout<<"B";
    }
}