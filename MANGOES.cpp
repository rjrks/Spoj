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
#include <map>
#include <set>
#include <algorithm>




using namespace std;

typedef long long ll;



int main()
{
    
    int tc;
    scanf("%d",&tc);
    
    while(tc--){
    ll n;
    scanf("%lld",&n);
    
    ll terms;
    
    if(n%2==0)terms=(n-2)/2;
    else terms=(n-2)/2+1;
        
        
    ll sum=(terms*terms)%n;
    
        
    printf("%lld\n",sum);
    }


}