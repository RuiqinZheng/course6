#include<math.h>
#include<stdio.h>
#include <openacc.h>
#include <sys/time.h>
#include <accel.h>
#include<omp.h>



int main()
{	
	double  start1=clock( );
	double time_chuanxing;
	int m1;
	int j1;
	int s1=0;
	FILE *fp1;       
	fp1=fopen("sushu_list_serial.txt","w");
	if(fp1!=NULL)

	
	for(m1=2;m1<=100000;m1++)
		{
			for(j1=2;j1<=m1;j1++)
		                if(m1%j1==0) break;
		                if(j1==m1)        

		                        {
		                                s1++;
		                                fprintf(fp1,"%d\n",m1);
		                                
		                        }                       
		}

	double end1 = clock( );  
	time_chuanxing=end1-start1;


	int i2;
   	
	struct timeval t1, t2;
	long diff;
		

	int m2;
	int j2;
	int s2=0;
	FILE *fp2;    
	gettimeofday( &t1, NULL );
   
	fp2=fopen("sushu_list_acc.txt","w");
	if(fp2!=NULL)

#pragma acc loop 
	for(m2=2;m2<=100000;m2++)
	{
	        for(j2=2;j2<=m2;j2++)
	                if(m2%j2==0) break;
	                if(j2==m2)        
	                        {
	                                s2++;
	                                fprintf(fp2,"%d\n",m2);
                                
	                        }                       
	}
	gettimeofday( &t2, NULL );
	diff= (t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec - t1.tv_usec);
	printf("\nnumber of prime number:%d\n",s2);
   	printf("\ndiff_acc = %.16g seconds\nspeedup_acc = %.16g\n", diff ,diff/time_chuanxing);  
  

		
	



		
	
	



}
