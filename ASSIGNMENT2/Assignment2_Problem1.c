#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[10000],in_file[10000], out_file[10000];
char ch;
int n;

void solve()
{
	FILE *in, *out;

	in = fopen(in_file, "r");
	if (in == NULL) {
		printf("Cannot open source file.\n");
		exit(1);
	}
	out = fopen(out_file, "w");
	if (out == NULL) {
		printf("Cannot open destination file.\n");
		exit(1);
	}
    int k=0;
	do 
	{		
		ch = getc(in);
		if(ch!='0'&&ch!='1')
			break;
		str[k++]=ch;
	}
	while (!feof(in));

	int len=strlen(str);
	char arr[1005][1005];
	for(int i=0; i<=1000; i++)
	{
		for(int j=0; j<=1000; j++)
		{
			arr[i][j]='\0';
		}
	}

    int i,x=0;
	for(i=0; i<len; i++)
	{
		int y=0;
		if(str[i]=='0')
		{
			int ct=1;
			arr[x][y]=str[i];
			for(int j=i+1; j<len; j++)
			{
				int flag=0;
				if(str[j]=='1'&&ct<n)
				{
					arr[x][++y]=str[j];
					i=j;
					break;
				}

				else if(str[j]=='1'&&ct==n)
				{
					i=j-1;
					break;
				}

				else if(str[j]=='0')
				{
					if(ct<n)
					{
						arr[x][++y]=str[j];
						ct++;
						if(ct==n||j==len-1)
						{
							i=j;
							flag=1;
							break;
						}
					}
				}

				if(flag)
					break;
			}

			x++;
		}

		else
		{
			arr[x][y]=str[i];
			if(n==2&&i+1<len&&str[i+1]=='1')
			{
				arr[x][++y]=str[i+1];
				i++;
			}
			else if(n==3&&i+2<len&&str[i+1]=='1'&&str[i+2]=='1')
			{
				arr[x][++y]=str[i+1];
				arr[x][++y]=str[i+2];
				i=i+2;
			}
			else if(n==4&&i+3<len&&str[i+1]=='1'&&str[i+2]=='1'&&str[i+3]=='1')
			{
				arr[x][++y]=str[i+1];
				arr[x][++y]=str[i+2];
				arr[x][++y]=str[i+3];
				i=i+3;
			}
			
			x++;
 
		}

	}
    
    int temp=0,incr=0;
	while(arr[x-1][temp]!='\0')
	{
		temp++;
	}

	if(arr[x-1][temp-1]=='0'&&temp<n)
	{
		while(temp!=n)
		{
			temp++;
			incr++;
			arr[x-1][temp-1]='0';
		}

	}

	char a[10][6]={"1","11","111","1111","01","00","000","0000","001","0001"};
	int freq[10]={0};
    
    fprintf(out,"ORIGINAL STRING : %s\n",str);
    fprintf(out, "ORIGINAL LENGTH = %d\n",strlen(str));
    fputs("\nANS ARRAY:\n",out);
    
    for(int i=0; i<x; i++)
    {
    	fprintf(out, "%s\n", arr[i]);
    	for(int j=0; j<10; j++)
    	{
    		if(strcmp(arr[i],a[j])==0)
    			freq[j]++;
    	}
    }
    
    fprintf(out, "\nNUMBER OF SUB-STRINGS =%d",x);
    fprintf(out, "\nSTRINGS\t\tFREQUENCY\tLENGTH\n");
    
    int new_len=0;
    for(int i=0; i<10; i++)
    {
    	if(freq[i]!=0)
    	{
    		fprintf(out, "\n%s\t\t%d\t\t%d", a[i],freq[i],strlen(a[i])*freq[i]);
    		new_len+=strlen(a[i])*freq[i];
    	}
    	
    }
    fprintf(out, "\n\nNEW LENGTH = %d\n",new_len);
    fprintf(out,"INCR. IN LENGTH =%d\n",incr);
    
    char ans[10005];
    if(n==2)
    {
    	char p[4][7]={"1","01","00","11"};
    	char rep[4]={'A','B','C','D'};
    	int k=0;
    	for(int i=0; i<x; i++)
        {
	    	for(int j=0; j<4; j++)
	    	{
	    		if(strcmp(arr[i],p[j])==0)
	    		{
	    			ans[k]=rep[j];
	    			k++;
	    		}
	    	}
        }
        
    }
    else if(n==3)
    {
    	char p[5][7]={"1","01","001","000","111"};
    	char rep[5]={'A','B','C','D','E'};
    	int k=0;
    	for(int i=0; i<x; i++)
        {
	    	for(int j=0; j<5; j++)
	    	{
	    		if(strcmp(arr[i],p[j])==0)
	    		{
	    			ans[k]=rep[j];
	    			k++;
	    		}
	    	}
        }

    }
    else if(n==4)
    {
    	char p[6][7]={"1","01","001","0001","0000","1111"};
    	char rep[6]={'A','B','C','D','E','F'};
    	int k=0;
    	for(int i=0; i<x; i++)
        {
	    	for(int j=0; j<6; j++)
	    	{
	    		if(strcmp(arr[i],p[j])==0)
	    		{
	    			ans[k]=rep[j];
	    			k++;
	    		}
	    	}
        }

    }

    int ori_len=strlen(str);
    int ans_len=strlen(ans);
    double reduc=((double)ori_len-ans_len)*100/ori_len;
    
    fprintf(out, "\n\nAFTER PROPER REPLACEMENT OF CHARACTERS,NEW STRING IS : %s",ans);
    fprintf(out, "\nNEW STRING LENGTH = %d", strlen(ans));
    fprintf(out, "\n% REDUCTION IN LENGTH = %lf",reduc);

    fclose(out);
	fclose(in);
}

int main()
{
	printf("Enter name of the source file :");
    scanf("%10000s", in_file);
    printf("\nEnter name of the destination file :");
    scanf("%10000s", out_file);
	printf("\nEnter the value of N: ");
	scanf("%d",&n);

	solve();

	return 0;
}