#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<sys/wait.h>

void main()
{
 int a[3],lc=0,wc=0,sc=0,i; 
char str1[20],str2[20];
printf("\nEnter the string for parent process \n");
fgets(str1,20,stdin);
int p1[2],p2[2],p3[2];
pipe(p1);pipe(p2);pipe(p3);
write(p1[1],&str1,20);
pid_t f=fork();
close(p1[1]);
if(f==0)
{
	read(p1[0],&str2,20);
	close(p1[0]);
	int d;
	for(i=0;i<strlen(str2);i++)
	{
		d=0;
		lc++;
		if(str2[i]==' '||str2[i]=='.'||str2[i+1]=='\n')
		{
			wc++;
		}
		if(str2[i]=='.'||str2[i+1]=='\n')
		{
			sc++;
		}
	}

	write(p2[1],&lc,sizeof(lc));
	write(p2[1],&wc,sizeof(wc));
	write(p2[1],&sc,sizeof(sc)); 
	close(p2[1]);
	exit(0); 
}

read(p2[0],&lc,sizeof(lc));
read(p2[0],&wc,sizeof(wc));
read(p2[0],&sc,sizeof(sc));
close(p2[0]);
printf("\nNumber of characters is %d",lc-1);
printf("\nNumber of words is %d",wc);
printf("\nNumber of sentences is %d",sc);
}






















