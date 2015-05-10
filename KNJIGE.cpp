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






int main(){
    
    int n;
    cin>>n;
    
    int a[n+1];
    
    for(int i=0;i<n;i++)cin>>a[i];
    
    int temp=n;
    
    int ans=0;
    for(int i=temp-1;i>=0;i--){
        
        if(a[i]==n)n--;
        else ans++;
        
    }
    
    cout<<ans;
}
