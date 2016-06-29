#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
 FILE *fp;
 FILE *fw;
 char ch;
 char line[1000];

 int start,end,s=0;
 start=atoi(argv[1]);
 end=atoi(argv[2]);
 fw=fopen(argv[3],"w");

 fp=fopen("pcut_print.prt","r");
 while(fgets(line,sizeof line,fp) != NULL){
 	
 	for(int i=0;i<strlen(line);i++){
 		if ((int)line[i] == 12){
 			
 			s+=1;
 			break;
 		}
 	}
 	if (s==end){
 		fclose(fw);
 		fclose(fp);
 		break;
 	}
 	if (s>=start-1){
 		fprintf(fw,"%s\n",line);
 	}
 	
}

return 0;

}