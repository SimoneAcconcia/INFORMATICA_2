//acconcia simone 4H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C 50 		//va messo 50 e non 49 perchè lo \0 serve per
 				   //chiudere la stringa
#define R 10 
void carica(char s[]);
int contaCaratteri(char s[], char x, char y);
void ordinaStringhe(char ms[][C]);

int main()
{
	char st[R][C];
	int i;
	int r;
	for(i=0;i<R;i++)
	{
		carica(st[i]);
	}
	
	
		r=contaCaratteri(st[0],'f','h');
		printf("%d",r);
		r=contaCaratteri(st[R-1],'f','h'); // avevi messo 9 
		printf("%d",r);
		ordinaStringhe(st);
}


void carica(char s[])
{
	int i=0;
	
		scanf("%s",s);
		if(s[0]>='a'&& s[0]<='z')
		{
			s[0]=s[0]-32;
		}
	}
	
	
int contaCaratteri(char s[], char x, char y)
{
	int i,c=0;
	while(s[i]!='\0')
	{
		if(s[i]==x || s[i]==y) //avevi messo or
		{
			c++;
		}
		i++;
	}
	return c;
}

void ordinaStringhe(char ms[][C])
{
	int i,scambio,j=0;;
	char app[C],c=0;
	do{
		scambio=0;
		for(i=0;i<R-1;i++)
		{
			if(strcmp(ms[i],ms[i+1]) ==1)
			{	strcpy(app,ms[i]);  // lo scambio va fatto con strcpy
				strcpy(ms[i],ms[i+1]);
				strcpy(ms[i+1],app);
				scambio=1;
				
			}
		}
	  }while(scambio==1);
	
}

