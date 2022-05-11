#include <stdio.h>
#include <math.h>
#include <ctype.h>

unsigned readnat_r(unsigned r) {
    int c = getchar();
    if (isdigit(c)) {
	return readnat_r(c - '0' + 10*r);
    }
    else { 
	ungetc(c, stdin); 
	return r; 
    }
}

unsigned readnat(){
     return readnat_r(0); 
    }

double readfrac_r(double r, unsigned counter) {
    int c = getchar();
    int d=0;
    putchar(c);
    putchar('\n');
    //int frac;
    while(isdigit(c)){
	d=c-'0';
	r=r+d/(10^counter);
	//printf("%f",r);
	counter++;
	
	c=getchar();
    }
	//return //readfrac_r( r, counter);
    
    
	//    ungetc(c, stdin); 
	    return r;
}


double readfrac() {
    double d = readnat_r(0);
    getchar();
    return d + readfrac_r(0.0, 0); 
}

int main()
{
    double d = readfrac();
    printf("d = %f", d);

    return 0;
}