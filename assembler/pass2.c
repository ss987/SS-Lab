#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){
    
    FILE *f1,*f2,*f3,*f4,*f5,*f6;
    
    char label[20],addr[20],opcode[20],operand[20],ad[20],symname[20],symval[20],opname[20],opval[20],len[10],size[10];
    int length,locctr,start;
    f2=fopen("optab.txt","r");
    f1=fopen("inter.txt","r");
    f3=fopen("symtab.txt","r");
    f4=fopen("len.txt","r");
    f5=fopen("list.txt","w");
    f6=fopen("obj.txt","w");
    fscanf(f1,"%s\t%s\t%s\t%s",addr,label,opcode,operand);
    
    fscanf(f4,"%s",len);
    fscanf(f4,"%s",size);
    
    if(strcmp(opcode,"START")==0){
        start=atoi(operand);
        
        fprintf(f5,"%s\t%s\t%s\t%s\n",addr,label,opcode,operand);
        fprintf(f6,"H^%s  ^00%s^0000%s\n",label,operand,len);
        fprintf(f6,"T^00%s^%s",operand,size);
        fscanf(f1,"%s\t%s\t%s\t%s",addr,label,opcode,operand);
        
    }
    while(strcmp(opcode,"END")!=0){
        if(strcmp("BYTE",opcode)==0){
            fprintf(f5,"%s\t%s\t%s\t%s\t",addr,label,opcode,operand);            
            sprintf(ad,"%x",operand[2]);
            fprintf(f5,"%s\n",ad);
            fprintf(f6,"^%s",ad); 
                           
        }
        else if(strcmp("WORD",opcode)==0){
            sprintf(ad,"%x",atoi(operand));
            fprintf(f5,"%s\t%s\t%s\t%s\t00000%s\n",addr,label,opcode,operand,ad);
            fprintf(f6,"^00000%s",ad);
           
        }
        else if(strcmp("RESW",opcode)==0 || strcmp("RESB",opcode)==0){
            fprintf(f5,"%s\t%s\t%s\t%s\n",addr,label,opcode,operand);            
            
        }
        else{
            fscanf(f2,"%s\t%s",opname,opval);
            fscanf(f3,"%s\t%s",symname,symval);
            while(getc(f2)!=EOF){
                if(strcmp(opcode,opname)==0){
                    
                    break;
                }
                fscanf(f2,"%s\t%s",opname,opval);
            }
            fseek(f2,0,SEEK_SET);
            while(getc(f3)!=EOF){
                if(strcmp(operand,symname)==0){
                    
                    break;
                }
                fscanf(f3,"%s\t%s",symname,symval);
            }
            fseek(f3,0,SEEK_SET);
            fprintf(f5,"%s\t%s\t%s\t%s\t%s%s\n",addr,label,opcode,operand,opval,symval);
            fprintf(f6,"^%s%s",opval,symval);
            
        }
        fscanf(f1,"%s\t%s\t%s\t%s",addr,label,opcode,operand);
        
    }
    fprintf(f5,"%s\t%s\t%s\t%s\n",addr,label,opcode,operand);
    fprintf(f6,"\nE^00%d",start);
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
        
    return 0;
}