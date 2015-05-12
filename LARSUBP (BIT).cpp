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

ll btree[10]={0};
ll mod=1000000007;
int len;


string ip()
{
    string i="";
    int temp=getchar_unlocked();
    while(temp<'0'||temp>'9')
        temp=getchar_unlocked();
    while(temp>='0'&&temp<='9')
    {
        i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}


void init(){
    
    for(int i=0;i<10;i++)btree[i]=0;
}

ll getsum(int ind){
    
    ll sum=0;
    while(ind>0){
        
        sum=(sum+btree[ind])%mod;
        ind-=ind&(-ind);
        
    }
    return sum;
}

void update(int ind, ll val){
    
    if(ind<0)return;
    while(ind<=9){
        btree[ind]+=val;
        ind+=ind&(-ind);
        
    }
}


int main()
{
    int tc;
    scanf("%d",&tc);
    
    for(int i=1;i<=tc;i++){
    
        
        init();
        
        ll ans=0;
        string in;
        in=ip();
        len=in.length();
        
        for(int i=0;i<len;i++){
            
            int a=in[i]-'0';
            int s=getsum(a-1);
            
            ans=(ans+(s+1))%mod;
            update(a, s+1);
        }
        
        printf("Case "); printf("%d",i); printf(": ");
        printf("%lld\n",ans);
    }
}

