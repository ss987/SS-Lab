#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *f1,*f2,*f3,*f4,*f5;
    char label[20],opcode[20],operand[20],code[20],mneumonic[20];
    int locctr,start,len,length;
    f1=fopen("input.txt","r");
    f2=fopen("optab.txt","r");
    f3=fopen("inter.txt","w");
    f4=fopen("symtab.txt","w");
    f5=fopen("len.txt","w");
    fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
    if(strcmp(opcode,"START")==0){
        start=atoi(operand);
        locctr=start;
        fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        fscanf(f1,"%s\t%s\t%s",label,opcode,operand);    
    }
    else{
        locctr=0;
    }
    while(strcmp(opcode,"END")!=0){
        fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"**")!=0){
			fprintf(f4,"%s\t%d\n",label,locctr);
		}
        fscanf(f2,"%s\t%s",code,mneumonic);
        while(strcmp(code,"END")!=0){
            if(strcmp(code,opcode)==0){
                locctr+=3;
                break;
            }
            fscanf(f2,"%s\t%s",code,mneumonic);
        }
        if(strcmp(opcode,"WORD")==0){
			locctr+=3;
		}
		else if(strcmp(opcode,"RESW")==0){
			locctr+=3*(atoi(operand));
		}
		else if(strcmp(opcode,"RESB")==0){
			locctr+=atoi(operand);
		}
		else if(strcmp(opcode,"BYTE")==0){
			if(operand[0]=='C'){
				len=strlen(operand)-3;
				locctr+=len;
			}
			else if(operand[0]=='X'){
				++locctr;
			}
		}
        fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
    }
    fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    length=locctr-start;
	fprintf(f5,"%X",length);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	fclose(f5);
    return 0;
}