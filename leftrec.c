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

void removerec()
{
	int i,k,l=0,m=0;
	for(i=0;i<j;i++)
	{
		if(token[i][0]=='A')
		{
			k=1;
			while(token[i][k]!='\0')
			{
				out2[l++]=token[i][k++];
			}
			out2[l++]='A';
			out2[l++]='*';
			out2[l++]='|';
		}
		else
		{
			k=0;
			while(token[i][k]!='\0')
			{
				out1[m++]=token[i][k++];
			}
			out1[m++]='A';
			out1[m++]='*';
			out1[m++]='|';
		}
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
	removerec();
	printf("After removing recursion:\n");
	printf("A->");
	i=0;
	while(out1[i+1]!='\0')
	{
		printf("%c",out1[i]);
		i++;
	}
	printf("\nA*->");
	i=0;
	while(out2[i]!='\0')
	{
		printf("%c",out2[i]);
		i++;
	}
	printf("Ep\n");
}