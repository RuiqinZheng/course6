#include<math.h>
#include<stdio.h>
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




	int i=3;
   	
	double start = omp_get_wtime( ); 
	omp_set_num_threads(i);
	int m;
	int j;
	int s=0;
	FILE *fp;       
	fp=fopen("sushu_list.txt","w");
	if(fp!=NULL)

#pragma omp parallel for reduction(+:s)private(j) 
	
	for(m=2;m<=100000;m++)
	{
	        for(j=2;j<=m;j++)
	                if(m%j==0) break;
	                if(j==m)        
	                        {
	                                s++;
	                                fprintf(fp,"%d\n",m);
                                
	                        }                       
	}

	printf("\nnumber of prime number:%d\n",s);
	printf("\nnumber of threads:%d\n",i);

	double end = omp_get_wtime( );  
   	printf("\ndiff_openmp = %.16g seconds\nspeedup_openmp = %.16g\n", end - start,(end-start)/time_chuanxing);  
		

}
