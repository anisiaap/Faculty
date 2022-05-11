#include<stdio.h>
void skipspaces(){
    int c;
    //c=getchar();
    while((c=getchar())==' '){
    ;
    }
    ungetc(c,stdin);
}
unsigned sumofDig(unsigned sum){
    int c;
    int nr, cif;
    //sum=0;
    c=getchar();//take the first digit char
    nr=c-'0';//transform in in a base 1 nr
    while(nr/10!=0){//if i am not at the end of nr
	cif=nr%10;
	sum=sum+cif;
    }
return sum;
}




unsigned maxL(){
    
    int c;
    int length=0;
    int sum=0;
    c=getchar();
    while(c!='-'||c!=EOF){//if i didnt encounter a -
	//ungetc(c,stdin);
	//if(c==' '){
	    //skipspaces();
	    //}//skip if the files begins with spaces
	if(c=='+'){
	    sum=sumofDig(sum);
	    if(sum%2==0){
		length++;
	    }
	}
	else if(c>='0'&&c<='9'){//if c is a digit not a space
	    ungetc(c,stdin);
	    sum=sumofDig(sum);
	    if(sum%2==0){
		length++;
	    }
	    }
	c=getchar();
	}
return length;



}	
int main(){
    int x;

    x=maxL();



return 0;
}