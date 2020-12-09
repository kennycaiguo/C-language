#include<stdio.h>

void showArrayElemants(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("element(%d): %d ",i,arr[i]);
    }
}

void main(){
     int a[]={2,3,6,7,9,14,56,45,65,67};
     showArrayElemants(a,sizeof(a)/sizeof(a[0]));
}