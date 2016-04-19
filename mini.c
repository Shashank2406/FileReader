#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void delay(double);
double speed(int);

int main()
{
 FILE *fptr;int c=0,wd,z;double y;
 char filename[15];
 char ch[10];
 printf("\nEnter the filename");
 scanf("%s",filename);
 printf("\nEnter the number of words per minute (minimum 40)");
 scanf("%d",&wd);
 fptr=fopen(filename,"r");
 if(fptr==NULL)
 {
     exit(0);
 }
 while(fscanf(fptr,"%s",ch)!=EOF)
 {
     printf("%s ",&ch);
     c++;
     y=speed(wd);
     delay(y);
     if(c==wd)
     {
         printf("\nDo you want to change speed?(1 or 0)");
         scanf("%d",&z);
         if(z==1)
         {
             printf("\nEnter the words per min..");
             scanf("%d",&wd);
         }
         else
            if(z==0)
         {
            c=0;
         }
     }
 }
 fclose(fptr);
 printf("%d",c);
 return 0;
}

void delay(double x)
{
    double c=1,d=1;
    for(c=1;c<=x;c++)
        for(d=1;d<=x;d++)
        {}
}

double speed(int wd)
{
    double x,w,e;
    int q;
    if(wd==40)
    {
        x=17000;
    }
    else
    {
        w=17000;
        q=wd-40;
        q=q/10;
        q=q+1;
        if(q<=10&&q<=20)
        {
          w=w+100;
        }
        else
        if(q>=20&&q<=30)
        {
            w=w-1800;
        }
        else
            if(q>=30&&q<=40)
        {
            w=w+1500;
        }
        else
          if(q>40)
        {
            w=w+2000;
        }
        e=q*300;
        x=w-e;
    }
    return x;
}
