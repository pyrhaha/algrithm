
//未解决重复字符的问题：如str1=abab,str2=abbb
#include<iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void main()
{
	string str1 = "ABCBDAB";
  	string str2 = "BDCABA";
	int str1Len = str1.length();
	int str2Len = str2.length();
	int arr[50][50] = {0};//试一下memset
	int i = 1;
	int j = 1;
	bool flag = 1;//用于除去在匹配的时候出现重复字符，重复计数，不然如出现AA时在循环中会加两次
	for(i = 1;i <= str1Len;i++)//遍历str1数组
	{
		for(j=1;j <= str2Len;++j)//遍历str2数组
		{
			if (str2[j-1] == str2[j])
			{
				flag = 0;
			}
			else
			{
				flag = 1;
			}
			if(str1[i-1] == str2[j-1] && flag)//若字符串中的字符相等，则在前一个元素时公共子序列的基础上加1
			{
				arr[i][j] = arr[i-1][j-1] + 1;
			}
			else
			{
				if (arr[i][j-1] > arr[i-1][j])
				{
					arr[i][j] = arr[i][j-1];
				}
				else
				{
					arr[i][j] = arr[i-1][j];
				}
				
			}
		}
	}

	//打印arr数组
	for (i = 0; i<= str1Len;++i)
	{
		for ( j = 0;j <= str2Len;++j)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

	i = str1Len;
	j = str2Len;
	string strResult = "";
	while (arr[i][j] != 0)
	{
		if(arr[i][j] == arr[i][j-1])
		{
			j--;
		}
		else
		{
			if(arr[i][j] == arr[i-1][j])//若相等则表示是在str1前面一个元素加1的
			{
				i--;
			}
			else
			{
				strResult += str2[j-1];
				i--;
				j--;
			}
		}
	}
	
	int strlength = strResult.length();
	char result[10] = {0};
	for(i = 0;i < strlength;++i)
	{
		result[i] = strResult[strlength-i-1];
	}
	printf("%s\n",result);

	
}











































