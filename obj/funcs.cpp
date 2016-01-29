// funcs.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.hpp"


//----------------------
//ファイル名を受け取る関数
//----------------------
void HomeRoom::getFileName()
{
	printf("File Name:");
	scanf("%s", fname);
}

//----------------------
//学生数を数える関数
//----------------------
int HomeRoom::get_numstudents()
{

	int x=0;
	char c;
	FILE *fp;


	if ((fp = fopen(fname, "r")) == NULL) 
	{
		printf("File Open Error.\n");
		exit(-1);
	}

	while ((c=getc(fp)) != EOF)
	{
		if(c == '\n')	x++;
	}

	fclose(fp);


	num = x;
	return num;

}

//----------------------
//学生情報を格納する関数
//----------------------
void HomeRoom::load_data()
{

	int i, stu;
	FILE *fp;
	int no, sex, pt;
	char family[20], first[20];


	if ((fp = fopen(fname, "r")) == NULL)
    {
	   	printf("File Open Error.");
		exit(-1);
	}


	stu = get_numstudents();

	data = new student [stu];


	for(i = 0; i < stu; i++)
	{
		fscanf(fp, "%d %s %s %d %d", &no, family, first, &sex, &pt);
		data[i].no = no;
		strcpy(data[i].family, family);
		strcpy(data[i].first, first);
		data[i].sex = sex;
		data[i].pt = pt;
	}


	fclose(fp);

}

//構造体の内容を表示する関数
void HomeRoom::print_list()
{

	int i;
	char a1, a2;
	char *s;

	for(i = 0; i < num; i++)
	{
		a1 = (data[i].first[0])-32;
		a2 = (data[i].family[0])-32;
		s = &(data+i)->family[1];

		printf("[%02d] \t %c. %c%-20s", data[i].no, a1, a2, s);
		printf("%d %d\n", data[i].sex, data[i].pt);
	}

	
}

//ポイントの平均を求める関数
double HomeRoom::average(int sex)
{

	double ave;
	int i, c=0;
	int po=0;

	for (i = 0; i < num; i++)
	{
			if((data[i].sex) == sex)
			{
				po += data[i].pt;
				c++;
			}
	}	



	ave = (double)po / (double)c;


	return ave;
}

//文字列の最大長を返す関数
int HomeRoom::get_maxnamelength()
{

	int mlen = 0;
	int i;


	for (i = 0; i < num; i++)
	{
		if ((unsigned int)mlen < strlen(data[i].family))
		mlen = strlen(data[i].family);
	}

	maxnlen = mlen;	

	return mlen;

}

//苗字の長さが最大の方の一覧表示
void HomeRoom::printMaxNameLength()
{

	int i;

	
	for (i = 0; i < num; i++)
	{
		if ((unsigned int)maxnlen == strlen(data[i].family))
		{
			printf("[%02d]  %-20s %-20s", data[i].no, data[i].first, data[i].family);
			printf("%d %d\n", data[i].sex, data[i].pt);
		}
	}


}


//特定文字列(引数)を含む方の検索・一覧表示
void HomeRoom::print_specifiedname(char *ss)
{

	int i;
	char *ptr;


	for(i = 0; i < num; i++)
	{
		if ((ptr = strstr(data[i].family, ss)) != NULL)	
		{
			if (data[i].no < 10)
				printf("[%02d]   %s %s\n", data[i].no, data[i].family, data[i].first);
			
		}
		else if ((ptr = strstr(data[i].first, ss)) != NULL)
		{
				printf("[%02d]  %s %s\n", data[i].no, data[i].family, data[i].first);
		}
	}
}

void HomeRoom::sortOfPoint(int ord)
{

	student tmp;
	int i, j;


	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num-1; j++)
		{
			if (data[j].pt < data[j+1].pt)
			{
				tmp = *(data+j);
				*(data+j) = *(data+j+1);
				*(data+j+1) = tmp;
			}
		}
	}

}

HomeRoom::HomeRoom()
{
	data = 0;
	num = 0;
}

HomeRoom::~HomeRoom()
{
	if (data) delete[] data;
}
