

#include <iostream>
using namespace std;
#include <math.h>       /* sqrt */


#include <math.h>
#include <stack>          // std::stack
#include <queue>
#include <string>
#include <stdlib.h>
#include <algorithm>








void find_sum(int *a,int k,int start,int length){
    int temp1=INFINITY,temp2=INFINITY;
    while(true){
        if((start)>(length-1))break;        //otherwise will lead two solutions
        if(a[start]+a[length-1]>k)length--;
        else if(a[start]+a[length-1]<k){start++;}
        else {
            //repition would occur think
            if(!(a[start]==temp1 && a[length-1]==temp2)){cout<<-1*k<<' '<<a[start]<<' '<<a[length-1]<<endl;}
            temp1=a[start];temp2=a[length-1];
            start++; length--;
        }
    }
    
}





int main(){
    
    //INPUT OF NUMBERS
    int input[100];
    
    int n;
    cin>>n;
    int length=0;
    
    
    for(int i=0;i<n;i++){
        
        int temp; cin>>temp;
        input[i]=temp;
        
    }
    
    length=n;
    
    //SORTING OF NUMBERS O(N^2)
    while(length>0){
        int maximum=-INFINITY;
        
        int index=0;
        for(int i=0;i<length;i++){
            
            if(maximum<input[i]){index=i; maximum=input[i];}        //index stores the index of  maximum value
            
        }
        
        int temp=input[length-1];       //swapping  the largest element
        
        input[length-1]=maximum;
        input[index]=temp;
        
        length--;
        
    }
    //SORTING ENDS--------------------------------------------------------------------------------
    
    length=n;
    
    for(int i=0;i<n;i++)cout<<input[i]<<' ';
    cout<<endl;
    // 10 1 6 -10 17 2 0 5 7 12 -5
    // 10 5 5 5 5 5 5 5 5 5 5
    //4 -1 0 1 2
    //6 -1 0 1 2 -1 -4
    // 10 -1 2 1 0 -2 1 1 10 -9 -1
    
    
    // find_sum(input,1,3,length);
    //cout<<endl<<endl<<endl;
    
    
    int start=1;
    int i=0;
    while(true){
        
        // cout<<i<<' '<<start<<endl;
        
        find_sum(input,-1*input[i],start,length);
        //UPDATE START POINTER BY REMOVING DUPLICATES
        for(int j=start;j<length;j++){
            if(input[i]!=input[j]){start=j;break;}
        }
        
        i=start;
        
        
        
        if(start>length-2)break;    //BECAUSE IF START EXCEEDS LENGTH-3 THERE'LL BE LESS THAN 2 ELEMENTS LEFT
        else start++;
        
    }
    
    
    
    
    
    
}

