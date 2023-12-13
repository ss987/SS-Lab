#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,arr[50],i,total=0,head;
    printf("Enter size:");
    scanf("%d",&n);
    printf("Enter array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter head:");
    scanf("%d",&head);
    for(i=0;i<n;i++){
        total+=abs(arr[i]-head);
        head=arr[i];
    }
    printf("%d\n",total);
    return 0;
}