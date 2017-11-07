#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define np 1024.0

double funcao(double x)
{	
	double s;
	s=sin(5*x)*((rand()%200/100.0 - 1));
   	return (s);
}

void main(int argc, char **argv)
{	double xmin, xmax, x, y, dx;
	FILE *arquivo;

	arquivo=fopen(argv[1], "w");
	
	xmin=-1;	
	xmax=1;
	
	dx= (xmax - xmin)/np;
	
	for(x=xmin; x<xmax; x=x+dx)
	{
		y=funcao(x);
		fprintf(arquivo," %lf %lf\n", x, y);
	}	
}
