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
    scanf("%d",&tc);
    
    while(tc--){
        int n;
        int k;
        
        scanf("%d",&n);
        scanf("%d",&k);
        
        
        std::map<int, bool>mymap;
        
        for(int i=0;i<=1024;i++)mymap[i]=false;
        
        
        int in[1200];
        
        for(int i=0;i<n;i++){scanf("%d",&in[i]); mymap[in[i]]=true;}
        
        int ntemp=n;
        for(int i=0;i<n;i++){
            
            for(int j=i+1; j<n;j++){
                
                
                int temp=in[i]^in[j];
                
                //       cout<<i<<" "<<j<<" "<<temp<<endl;
                
                if(!mymap[temp]){in[ntemp]=temp;ntemp++; mymap[temp]=true;}
                
            }
            
            n=ntemp;
            
        }
        
        
        // for(int i=0;i<n;i++)cout<<in[i]<<" ";
        
        int maxi=k;
        
        
        for(int i=0;i<n;i++){
            
            maxi=max(maxi, in[i]^k);
            
        }
        
        
        printf("%d",maxi);
        printf("\n");
        
        
        
    }
    
}
// 3 9 12 11 2

// 2 3 4 1 2 3 3 4 1 2 3