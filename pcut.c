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
 start=atoi(argv[2]);
 end=atoi(argv[3]);
 fw=fopen(argv[4],"w");

 start -= 1;

 fp=fopen(argv[1],"r");
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
	if (s>=start){
 		fprintf(fw,"%s\n",line);
 	}
 	
}

return 0;

}