#include <stdio.h>
#include <ctype.h>
int n;
char input[20][20];

void addToResult(char result[],char c)
{
	int i;
	for(i=0;result[i]!='\0';i++)
	{
		if(result[i]==c)
			return;
	}
	result[i]=c;
	result[i+1]='\0';
}

void first(char result[],char c)
{
	int i,j,foundEp,k;
	char subResult[20];
	subResult[0]='\0';
	result[0]='\0';
	if(!(isupper(c)))
	{
		addToResult(result,c);
		return;
	}
	for(i=0;i<n;i++)
	{
		if(input[i][0]==c)
		{
			if(input[i][2]=='$')
				addToResult(result,'$');
			else
			{
				j=2;
				while(input[i][j]!='\0')
				{
					foundEp=0;
					first(subResult,input[i][j]);
					for(k=0;subResult[k]!='\0';k++)
						addToResult(result,subResult[k]);
					for(k=0;subResult[k]!='\0';k++)
					{
						if(subResult[k]=='$')
						{
							foundEp=1;
							break;
						}
					}
					if(!foundEp)
						break;
					j++;
				}
			}
		}
	}
}

void main()
{
	int i;
	char c;
	char choice;
	char result[20];
	printf("Enter number of productions: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter production #%d: ",i+1);
		scanf("%s",input[i]);
	}
	do
	{
		printf("\nFind the first of: ");
		scanf(" %c",&c);
		first(result,c);
		printf("The first of %c = { ",c);
		for(i=0;result[i]!='\0';i++)
			printf("%c ",result[i]);
		printf(" }\n");
		printf("Do you wish to continue? (Y/N): ");
		scanf(" %c",&choice);
	} while(choice=='Y');	
}