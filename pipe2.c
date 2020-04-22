#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<sys/wait.h>

void main()
{ 
int a[3],lc=0,wc=0,sc=0,i; 
char str1[20],str2[40];
printf("\nEnter the string for parent process \n");
gets(str1);
int p1[2],p2[2],p3[2];
pipe(p1);pipe(p2);pipe(p3);
write(p1[1],&str1,40);
pid_t f=fork();
close(p1[1]);
if(f==0)
{
	read(p1[0],&str2,40);
	close(p1[0]);
	printf("\nEnter the second string \n");
       	gets(str1);
	int d;
	i=strlen(str2);
	str2[i]=' ';
	int j;
	for(j=0;j<strlen(str1);j++)
	{
		str2[i++]=str1[j];
	}
	str2[i]='\0';
	write(p2[1],&str2,sizeof(str2));
	close(p2[1]);
	exit(0); 
}
read(p2[0],&str1,sizeof(str1));
close(p2[0]);
printf("\nConcatinated String is %s",str1);
}