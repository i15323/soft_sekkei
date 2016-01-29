// funcs.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.hpp"

//ファイル名を受け取る関数
void STUDENT::getFileName()
{
	printf("File Name:");
	scanf("%s", fname);
}

//学生数を数える関数
int STUDENT::get_numstudents()
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

//構造体STUDENTに学生情報を格納する関数(get_numstudents依存)
void STUDENT::load_data()
{

	int i, stu;
	FILE *fp;


	if ((fp = fopen(fname, "r")) == NULL)
    {
	   	printf("File Open Error.");
		exit(-1);
	}


	//get_numstudents()を呼び出して学生数を数える
	stu = get_numstudents();

	//get_numstudentsで得られた値分の領域確保
	p = new struct STUDENT_DATA[stu];


	for(i = 0; i < stu; i++)
		fscanf(fp, "%d %s %s %d %d", &p[i].no, p[i].family, p[i].first, &p[i].sex, &p[i].pt);

	fclose(fp);

}

//構造体の内容を表示する関数
void STUDENT::print_list()
{

	int i;


	for(i = 0; i < num; i++)
	{
			printf("[%02d] \t %c. %c%-20s", p[i].no, ((p[i].first)[0])-32, ((p+i)->family[0])-32, &(p+i)->family[1]);
			printf("%d %d\n", p[i].sex, p[i].pt);
	}

	
}

//ポイントの平均を求める関数
double STUDENT::average(int sex)
{

	double ave;
	int i, c=0;
	int po=0;

	for (i = 0; i < num; i++)
	{
			if((p[i].sex) == sex)
			{
				po += p[i].pt;
				c++;
			}
	}	



	ave = (double)po / (double)c;


	return ave;
}

//文字列の最大長を返す関数
int STUDENT::get_maxnamelength()
{

	int mlen = 0;
	int i;


	for (i = 0; i < num; i++)
	{
		if ((unsigned int)mlen < strlen(p[i].family))
		mlen = strlen(p[i].family);
	}

	maxnlen = mlen;	

	return mlen;

}

//苗字の長さが最大の方の一覧表示
void STUDENT::printMaxNameLength()
{

	int i;

	
	for (i = 0; i < num; i++)
	{
		if ((unsigned int)maxnlen == strlen(p[i].family))
		{
			printf("[%02d]  %-20s %-20s", p[i].no, p[i].first, p[i].family);
			printf("%d %d\n", p[i].sex, p[i].pt);
		}
	}


}


//特定文字列(引数)を含む方の検索・一覧表示
void STUDENT::print_specifiedname(char *ss)
{

	int i;
	char *ptr;


	for(i = 0; i < num; i++)
	{
		if ((ptr = strstr(p[i].family, ss)) != NULL)	
		{
			if (p[i].no < 10)
				printf("[%02d]   %s %s\n", p[i].no, p[i].family, p[i].first);
			
		}
		else if ((ptr = strstr(p[i].first, ss)) != NULL)
		{
				printf("[%02d]  %s %s\n", p[i].no, p[i].family, p[i].first);
		}
	}
}

void STUDENT::sortOfPoint(int ord)
{

	struct STUDENT_DATA tmp;
	int i, j;


	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num-1; j++)
		{
			if (p[j].pt < p[j+1].pt)
			{
			tmp = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = tmp;
			}
		}
	}

}

STUDENT::STUDENT()
{
	p = 0;
	num = 0;
}

STUDENT::~STUDENT()
{
	if (p) delete[] p;
}
