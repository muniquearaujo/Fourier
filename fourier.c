#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void coeficientes(double *x, double *y, int m, char *outroa)
{	FILE *arq;
	double *a, *b, *akbk, sseno, scosseno;
	int k, j;
   
	a = malloc(m*sizeof(double));
	b = malloc(m*sizeof(double));
	akbk = malloc(m*sizeof(double));
  
	arq = fopen(outroa, "w");
  
  	scosseno = 0.0;
  	sseno = 0.0;
  	 
  	for(k=0; k<m; k++)
  	{	
  		for(j=0;j<(2*m)-1;j++)
      		{  
      			scosseno = scosseno + y[j]*cos((k)*x[j]);
    			sseno = sseno + y[j]*sin((k)*x[j]);		 
   		} 
	
        	a[k] = (1.0/m)*(scosseno);
     		b[k] = (1.0/m)*(sseno);
        	akbk[k] = pow(a[k], 2) + pow(b[k],2);
        	
        	fprintf(arq, "%lf\t %lf\t %lf\t  \n", a[k], b[k], akbk[k]); 
	} 
}
int main(int argc, char **argv)
{ 
    FILE *arq;
    int i, m;
    double *x, *y;
    
    x = malloc(100000*sizeof(double));
    y = malloc(100000*sizeof(double));
    
    arq = fopen(argv[1], "r");
    if(!arq)
    {	
    	printf("Erro:\n");	
    }
    
    i=0;
    
    while(fscanf(arq, "%lf %lf", &x[i], &y[i]) !=EOF) 
    {
    	i++;
    }
    
    m=i;
    
    x=realloc(x, m*sizeof(*x));
    y=realloc(y, m*sizeof(*y));
    
    coeficientes(x,y,m,argv[2]);   
}
