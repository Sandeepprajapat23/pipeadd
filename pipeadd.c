#include <unistd.h>
 #include <stdio.h>
 #define BUFF_SIZE 1024

    int add(int, int);

 int main()
 {
     
     int id;
    pid_t pfd1[2];
    pid_t pfd2[2];
    pipe(pfd1);
    pipe(pfd2);
    
    int  buffer[]={2,3};
    int sum=0;

    id=fork();

    if(0==id)
    {
        read(pfd1[0],buffer,2);
        close(pfd1[1]);
        printf("first no.  and second no. is %d and %d\n",buffer[0],buffer[1]);
        sum=add(buffer[0],buffer[1]);
        write(pfd2[1],&sum,sizeof(int));
        close(pfd2[0]);
        
    }
    else{
        write(pfd1[1],buffer,2);
        close(pfd1[0]);
        read(pfd2[0],&sum,sizeof(int));
        close(pfd2[1]);
        printf("sum is %d",sum);
    }
    return 0;
 }
 int add(int a,int b)
    {
        int sum;
        sum=a+b;
        return sum;
    }