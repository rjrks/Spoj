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
#include <algorithm>




using namespace std;
typedef long long ll;

 int main(){
    int tc;
    cin>>tc;
    
    while(tc--){
    int n,k;
    cin>>n>>k;
    
    
    char a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    
    int lc[n+1],rc[n+1];
    lc[n]=1; rc[1]=1;
    for(int i=n-1;i>=1;i--){
        if(a[i]==a[i+1])lc[i]=1+lc[i+1];
        else lc[i]=1;
    }
    
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1])rc[i]=1+rc[i-1];
        else rc[i]=1;
    }


    int lptr=1, rptr=n;
    
    int ans=0;
    while(true){
     
        if(rptr-lptr+1<=k){
            
            if(lc[lptr]>=k ||rc[rptr]>=k)ans+=1;
            else ans=0;
            break;
        }
        
        ans+=1;
        if(lc[lptr]>=rc[rptr])rptr-=min(k,rc[rptr]);
        else lptr+=min(lc[lptr],k);
        
    }
 
        
    if(ans)cout<<ans;
    else cout<<-1;
    cout<<endl;
    
    }
}

// 1 5 1 rrgrr
// 1 6 3 abcaab
// 5 3 rgggr
// 5 6 aaaav