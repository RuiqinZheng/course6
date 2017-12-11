#include <stdio.h>
#include <omp.h>
#define N 100000
#define n 2
int main()
{
	double start = omp_get_wtime( );  
	double a[N];
	double b[N];
	double c=0;
	int i;
     

	for(i=0;i<N;i++){

		a[i]=1;
			
	}
	for(i=0;i<N;i++){
		b[i]=1;			
		}


	omp_set_num_threads(n);
#pragma omp parallel shared(a,b,c) private(i)  
{
#pragma omp for reduction(+:c)
	
	for(i=0;i<N;i++){
		c+=a[i]*b[i];
			
			}
}
    	      printf("%lf ",c);  



	double end = omp_get_wtime( );  
	printf("\nstart = %.16g\nend = %.16g\ndiff = %.16g seconds\n",start,end,end-start);

} 


