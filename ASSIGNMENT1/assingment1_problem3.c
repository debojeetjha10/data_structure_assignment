#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N= 10000;
int M =1000000;
int max(int a,int b);
int find_big(int*arr1,int*arr2,int j,int k);
void add(int*arr1, int*arr2, int*ans, int n, int m);
void subtract(int arr1[], int arr2[], int ans[], int n, int m);

int main()
{

	char num1[N];
	char num2[N];
	int arr1[N];
	int arr2[N];
	int ans[M];
	int key;

	printf("Enter the 1st number:");
	scanf("%s",num1);
	printf("\nEnter the 2nd number:");
	scanf("%s",num2);
	printf("\nPress 1 for addition and 2 for subtraction:");
	scanf("%d",&key);

	int n=strlen(num1);
	int m=strlen(num2);
	int j=0,k=0;
	for(int i=0; i<n; i++)
	{
		if(num1[i]=='-')
			continue;
		else
		{
			arr1[j]=num1[i]-'0';
			j++;
		}
	}
	for(int i=0; i<m; i++)
	{
		if(num2[i]=='-')
			continue;
		else
		{
			arr2[k]=num2[i]-'0';
			k++;
		}
	}

	int big=find_big(arr1,arr2,j,k);
        printf("Result = ");
	if(key==1)
	{
		if(num1[0]=='-'&&num2[0]!='-')
		{
			if(big==1)
			{
				printf("-");
				subtract(arr1,arr2,ans,j,k);
			}
			else
			{
				subtract(arr2,arr1,ans,k,j);
			}

		}
		else if(num1[0]!='-'&&num2[0]=='-')
		{
			if(big==1)
			{
				subtract(arr1,arr2,ans,j,k);
			}
			else
			{
				printf("-");
				subtract(arr2,arr1,ans,k,j);
			}
		}
		else if(num1[0]=='-'&&num2[0]=='-')
		{
			printf("-");
			add(arr1,arr2,ans,j,k);
		}
		else 
		{
			add(arr1,arr2,ans,j,k);
		}
	}

	else if(key==2)
	{
		if(num1[0]=='-'&&num2[0]!='-')
		{
			printf("-");
			add(arr1,arr2,ans,j,k);
		}
		else if(num2[0]=='-'&&num1[0]!='-')
		{
			add(arr1,arr2,ans,j,k);
		}
		else if(num1[0]=='-'&&num2[0]=='-')
		{
			if(big==1)
			{
				printf("-");
				subtract(arr1,arr2,ans,j,k);
			}
			else
			{
				subtract(arr2,arr1,ans,k,j);
			}
		}
		else 
		{
			if(big==1)
			{
				subtract(arr1,arr2,ans,j,k);
			}
			else
			{
				printf("-");
				subtract(arr2,arr1,ans,k,j);
			}
		}
	}
	printf("\n");
	return 0;
}

void subtract(int arr1[], int arr2[], int ans[], int n, int m)
{
	int ct=0,carry=0;
	int l=n-m;
	for(int i=m-1; i>=0; i--)
	{
		int sub=arr1[i+l]-arr2[i]-carry;
		if(sub<0)
		{
			sub+=10;
			carry=1;
		}
		else
		{
			carry=0;
		}
		ans[ct]=sub;
		ct++;
	}	
	for(int i=l-1; i>=0; i--)
	{
		if(arr1[i]==0&&carry)
		{
			ans[ct]=9;
			ct++;
			continue;
		}
		int sub=arr1[i]-carry;
		if(i>0||sub>0)
			ans[ct]=sub;
		carry=0;
		ct++;
	}
	for(int i=ct-1; i>=0; i--)
	{
		printf("%d",ans[i]);
	}
}
int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
void add(int*arr1, int*arr2, int*ans, int n, int m)
{
	int i=n-1,j=m-1,sum=0,carry=0,ct=0;
	int k=max(n,m)-1;
	while(i>=0&&j>=0)
	{
		sum=arr1[i]+arr2[j]+carry;
		ans[k]=sum%10;
		carry=sum/10;
		i--;
		j--;
		k--;
		ct++;
	}
	if(i>=0)
	{
		while(i>=0)
		{
			sum=arr1[i]+carry;
			ans[k]=sum%10;
			carry=sum/10;
			i--;
			k--;
			ct++;
		}
	}
	else if(j>=0)
	{
		while(j>=0)
		{
			sum=arr2[j]+carry;
			ans[k]=sum%10;
			carry=sum/10;
			j--;
			k--;
			ct++;
		}
	}
	if(carry>0)
	{
		for(int i=ct; i>=0; i--)
		{
			ans[i+1]=ans[i];
		}
		ans[0]=carry;
	}

	for(int i=0; i<ct; i++)
	{
		printf("%d",ans[i]);
	}
}
int find_big(int*arr1,int*arr2,int j,int k)
{
	if(j>k)
		return 1;

	else if(k>j)
		return 2;

	else
	{
		for(int i=0; i<j; i++)
		{
			if(arr1[i]==arr2[i])
				continue;
			else if(arr1[i]>arr2[i])
				return 1;
			else if(arr2[i]>arr1[i])
				return 2;
		}
	}
	return 1;
}
/*output:
Enter the 1st number:6867836393687686686836

Enter the 2nd number:6387776676888998891198

Press 1 for addition and 2 for subtraction:1
Result = 1325561307057668557803
*/