#include <stdio.h>
#include <math.h>

main()
{
	int i=0, j, k, m;
	FILE *p;
	
	p = fopen("pitch.txt", "r");
	
	printf("\nNúmero de pontos: ");
	scanf("%d", &m);
	
	float x[m], y[m];
	float a[m/2], b[m/2];
	
	for(i=0;i<m;i++)
	{
		fscanf(p, "%f", &y[i]);
		x[i] = -(M_PI) + ((float)i/m)*(2*M_PI);
	}
	
	for(k=0;k<(m/2);k++)
	{
		a[k] = 0;
		b[k] = 0;
	
		for(j=0;j<(m-1);j++)
		{
			a[k] += y[j]*cos(k*x[j])/m;
			b[k] += y[j]*sin(k*x[j])/m;
		}
	}
	
	fclose(p);
	
	p = fopen ("dadospi.dat", "w");
	
	for(i=0;i<m;i++)
		fprintf(p, "%f %f\n", x[i], y[i]);
		
	fclose (p);
	
	p = fopen ("transfpi.dat", "w");
	
	for(k=0;k<m/2;k++)
		fprintf(p, "%f %f %f\n", a[k], b[k], (pow(a[k],2)+pow(b[k],2)));
		
	fclose (p);
}
