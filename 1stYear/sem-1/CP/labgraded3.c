#include<stdio.h>


void eatNr(){
    int c;
    while((c=getchar())>='0'&&c<='9'){
    }
    ungetc(c,stdin);

}



void nrofPos(){
    int c,c1,c2;
    int posnr=0;
    c=getchar();
    while(c!=EOF){
	if(c>='0'&&c<='9'){//the first nr from the input
	    eatNr();
	    posnr++;
	}
	c=getchar();
	//printf("%c",c);
	while(c!=EOF){//rest of nr from input
	    c1=getchar();
	    c2=getchar();
	    if(c1==' '&&c2=='+'){
		eatNr();
		posnr++;
	    }
	    if(c1=' '&&c2>='0'&&c2<='9'&&c1!=EOF&&c2!=EOF){
		eatNr();
		posnr++;
	    }
	    
	c=getchar();
	}


printf("%d",posnr);

}




int main(){
    
    nrofPos();



return 0;
}