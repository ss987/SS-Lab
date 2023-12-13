#include<stdio.h>
int main(){
    int np,nf,refstr[50],i,frame[10],j,k,avail,fault=0;
    printf("Enter no of pg:");
    scanf("%d",&np);
    printf("Enter pg:");
    for(i=0;i<np;i++){
        scanf("%d",&refstr[i]);
    }
    printf("Enter no of frame:");
    scanf("%d",&nf);
    for(i=0;i<nf;i++){
        frame[i]=-1;
    }
    printf("Incoming\t\tframe\t\tFault\n");
    j=0;
    for(i=0;i<np;i++){
        printf("%d\t\t",refstr[i]);
        avail=0;
        for(k=0;k<nf;k++){
            if(frame[k]==refstr[i]){
                avail=1;
                for(k=0;k<nf;k++){
                    printf("%d ",frame[k]);
                }
                printf("H\n");
            }
        }
        if(avail==0){
            frame[j]=refstr[i];
            j=(j+1)%nf;
            fault++;
            for(k=0;k<nf;k++){
                    printf("%d ",frame[k]);
                }
            printf("F\n");
        }
    }
    printf("Page fault %d\n",fault);
    return 0;
}