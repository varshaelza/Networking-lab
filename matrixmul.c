#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
 #include<unistd.h>
 
 struct mul 
 {
     int a;
     int b;
     int res;
 };
 void *multiply(void *arg)
{
    struct mul * point=(struct mul*)arg;
    int first=point->a;
    int second=point->b;
    point->res=first*second;

}
 void main()
 {   srand(time(0));
     int r1,r2,c1,c2,a[10][10],b[10][10],c[10][10],i,j,k; 
    r1=rand()%4+1;
    c1=rand()%4+1;
    r2=c1;
    c2=rand()%4+1;
    struct mul t;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
             a[i][j]=rand()%4+1;
        }
    }
    
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
             b[i][j]=rand()%4+1;
        }
    }
    
    printf("\nFIRST MATRIX\n");
     for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
     
    printf("\nSECOND MATRIX\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
              printf("%d  ",b[i][j]);
        }
        printf("\n");
    }
    
    pthread_t t1;
    
    
     for (i = 0; i < r1; i++)
    {
       for(j=0;j<c2;j++)
        {
             c[i][j]=0;
             for(k=0;k<c1;k++)
            {
                t.a=a[i][k];
                t.b=b[k][j];
                pthread_create(&t1,NULL,multiply,(void *)&t);
                pthread_join(t1,NULL);

                c[i][j]+=t.res;

            }
        }
    }
    printf("\nRESULT MATRIX\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
             printf("%d ",c[i][j]);       
             }
            printf("\n");
    }
    
    
    
 }