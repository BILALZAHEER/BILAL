#include <sys/types.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>


int main ()
{
   int sum1=0,sum2=0,sum3=0,sum4=0;
    int cid;
    int status=0;
    int array[100],i;
    for(i=0;i<100;i++)		 
       array[i]=i+1;
    cid =vfork ();
    if (cid < 0)
    {
        printf ("Fork Failed\n");
       
    }
    else if (cid == 0)
    {
        int i;
           for(i=0;i<25;i++)
                 sum1+=array[i];
     	int cid2;
	cid2=vfork();
	if(cid2<0)
	{
        	printf ("Fork Failed\n");
	}   
	else if(cid2==0)
	{
            int i;
           for(i=25;i<50;i++)
                sum2+=array[i];
		int cid3;
		cid3=vfork();
		if(cid3<0)
		{
			printf ("Fork Failed\n");
	         }
		else if(cid3==0)
		{
			 int i;
		     for(i=50;i<75;i++)
	    		sum3+=array[i];
                         int cid4;
                         cid4=vfork();
                      if(cid4<0)
                       {
                        printf ("Fork Failed\n");
                       }
                       else if(cid4==0)
                        {
                             int i;
                             for(i=75;i<100;i++)
                                    sum4+=array[i];
                            exit(-1);
                        }
                  exit(-1);
               }
             exit(-1);
        }
       exit(-1);
     }  
     else
     {
        wait(&status);
        printf("TOTAL %d\n",sum1+sum2+sum3+sum4); 
     }
    return 0;

}
