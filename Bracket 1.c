#include<stdio.h>
const int max =100;
//char arr[20]="{({})([])}}";
//char arr[20]="[{{({})([])}}]";
char arr[30]="(()){{{[]}{[][]}}";
int s[max],top=-1;
void push(int val);
void pop();
char top_val();
void showall();
void main()
{
	int i=0,val;
	while(arr[i]!=NULL)
	{
		if(arr[i]=='{'||arr[i]=='['||arr[i]=='(')
		{
			val=arr[i];
			push(val);
		}
		else if(s[top]=='{'&&arr[i]=='}')
		{
			pop();
		}
		else if(s[top]=='('&&arr[i]==')')
		{
			pop();
		}
		else if(s[top]=='['&&arr[i]==']')
		{
			pop();
		}
		else if(top==-1)
		{
			if(arr[i]=='}'||arr[i]==')'||arr[i]==']')
			push(arr[i]);
			break;
		}
		i++;
	}

	if(top_val()=='}')
	{
		printf("closing braket overflow\n");
	}
	else if(top_val()=='{')
	{
		printf("opening braket overflow\n");
	}
	else if(top==-1)
	{
		printf("Balanced\n");
	}
	else
	{
		printf("unmatched\n");
	}
}
void push(int val)
{
	if(top+1>max)
		printf("u cant push this value cz stack is over full\n");
	else
		s[++top]=val;
}
char top_val()
{
	//printf("%d\n",s[top]+48);
	return s[top];
}
void pop()
{
	if(top<-1)
		printf("this stack is empty\n");
	else
		--top;
}
