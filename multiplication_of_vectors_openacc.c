#include <stdio.h>
#include <openacc.h>
#define N 100000
#define n 2
#include <time.h>
int main()
{	
	time_t st,ed;
	st=clock();
	double diff;
	double a[N];
	double b[N];
	double c=0;
	int i=0;
     

	for(i=0;i<N;i++){

		a[i]=1;
			
	}
	for(i=0;i<N;i++){
		b[i]=1;			
		}


#pragma acc parallel 

{

	
	for(i=0;i<N;i++){
		c+=a[i]*b[i];
			
			}
}
    	      printf("\n%lf\n ",c);  

	ed=clock();
	diff=(ed-st)/CLOCKS_PER_SEC;
	printf("\nstart = %.16g\nend = %.16g\ndiff = %.16g seconds\n",st,ed,diff);

} 


