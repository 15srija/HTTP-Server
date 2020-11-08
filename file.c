#include<stdio.h>
#include<string.h>
void array(FILE *fp ,char filecontent [])
{
int i;
char message[1000];
while(1)
{	
i=fscanf(fp,"%[^\n]\n",message);
if(i==EOF)
break;
strcat(filecontent,message);
}
}
