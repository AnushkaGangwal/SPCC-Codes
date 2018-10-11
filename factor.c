#include <stdio.h>
#include <string.h>
char token[10][10];
char out1[20];
char out2[20];
int j;

void makeToken(char input[],int length)
{
	int i=3,k=0;
	j=0;
	while(i<length)
	{
		while(input[i]!='|')
		{
			if(input[i]=='\0')
				break;
			token[j][k++]=input[i];
			i++;
		}
		j++;
		i++;  
		k=0;
	}
}

void factoring()
{
	int i=0,k=0,l,m=0;
	while(token[0][i]==token[1][i])
	{
		out1[k++]=token[0][i];
		i++;
	}
	l=i;
	while(token[0][i]!='\0')
	{
		out2[m++]=token[0][i];
		i++;
	}
	out2[m++]='|';
	while(token[1][l]!='\0')
	{
		out2[m++]=token[1][l];
		l++;
	}
}

void main()
{
	int i,length;
	char input[50];
	printf("Enter input production in format A->Ab|c|d:\n");
	scanf("%s",input);
	length=strlen(input);
	makeToken(input,length);
	printf("The tokens are:\n");
	for(i=0;i<j;i++)
		printf("%s\n",token[i]);
	factoring();
	printf("After factoring:\n");
	printf("A->");
	i=0;
	while(out1[i]!='\0')
	{
		printf("%c",out1[i]);
		i++;
	}
	printf("A*\n");
	printf("A*->");
	i=0;
	while(out2[i]!='\0')
	{
		printf("%c",out2[i]);
		i++;
	}
	printf("\n");
}