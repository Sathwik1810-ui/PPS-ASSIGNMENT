#include<stdio.h>
#define MAX_SLOT 10000
int isPrime(int n){
    if(n<2)
    return 0;
int d=2;
//this condition avoids multiplication overflow.(like rejecting INT_MAX before checking)
while(d<=n/d){
    if(n%d==0)
    return 0;
d++;
}
return 1;
}
int isRveresed(int n){
//slot 1 is reserved
if(n==1)
return 1;
return 0;
}
int findSlot(int lo,int hi){
    if(lo<1 || hi>MAX_SLOT || lo>hi) return -1;  //to prevent invalid data and unsafe arithmetic.
    for(int slot=lo;slot<=hi;slot++){
        if(!isRveresed(slot) && isPrime(slot))
        return slot;
    }
    return -1;
}
