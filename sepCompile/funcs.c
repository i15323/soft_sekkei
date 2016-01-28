// funcs.c 1218

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

//ファイル内用のプロトタイプ
int get_numstudents(char *);
struct POINT count(struct STUDENT *, int, int);


//学生数を数える関数
int get_numstudents(char *fileName)
{

	int x=0;
	char c;
	FILE *fp;


	if ((fp = fopen(fileName, "r")) == NULL) 
	{
		printf("File Open Error.");
		return -1;
	}

	while ((c=getc(fp)) != EOF)
	{
		if(c == '\n')	x++;
	}

	fclose(fp);


	return x;

}

//構造体STUDENTに学生情報を格納する関数(get_numstudents依存)
int load_data(char *fileName, struct STUDENT **p)
{

	int i, stu;
	FILE *fp;
	struct STUDENT *s;


	if ((fp = fopen(fileName, "r")) == NULL)
       	printf("File Open Error.");

	//get_numstudents()を呼び出して学生数を数える
	stu = get_numstudents(fileName);

	//get_numstudentsで得られた値分の領域確保
	s = *p;
	s = (struct STUDENT *)malloc(sizeof(struct STUDENT)*stu);


	for(i = 0; i < stu; i++)
		fscanf(fp, "%d %s %s %d %d", &s[i].no, s[i].family, s[i].first, &s[i].sex, &s[i].pt);

	fclose(fp);


	*p = s;
	return stu;
}

//構造体の内容を表示する関数
void print_list(struct STUDENT *p, int x)
{

	int i;


	for(i = 0; i < x; i++)
	{
		if(p[i].no < 10)
			printf("[0%d] \t %c. %s", p[i].no, ((p[i].first)[0])-32, p[i].family);
		else printf("[%d] \t %c. %s", p[i].no, ((p[i].first)[0])-32, p[i].family);

		if (strlen(p[i].family) < 4) printf("\t\t\t\t");
		else if (strlen(p[i].family) < 9 && strlen(p[i].family) >= 4) printf("\t\t\t");
		else printf("\t\t");
		
		printf("%d %d\n", p[i].sex, p[i].pt);

	}

	
}

//学生のポイントを数える関数
struct POINT count(struct STUDENT *seito, int sei, int n)
{
	
	int i;
	struct POINT st;
	

	for (i = 0; i < n; i++) 
	{ 
			if((seito[i].sex) == sei)
			{
				(st.num)++;
				st.pt += seito[i].pt;
			}
	}
	

	return st;
}


//ポイントの平均を求める関数
double average(struct STUDENT *p, int n, int sex)
{

	double ave;
	struct POINT pp;

	//学生数とポイント合計を求める
	pp = count(p, sex, n);


	//count()関数から平均を求める
	ave = pp.pt / (double)pp.num;


	return ave;
}

//文字列の最大長を返す関数
int get_maxnamelength(struct STUDENT *p, int n)
{

	int mlen = 0;
	int i;


	for (i = 0; i < n; i++)
	{
		if (mlen < strlen(p[i].family))
		mlen = strlen(p[i].family);
	}


	return mlen;

}

//苗字の長さが最大の方の一覧表示
void print_nfamilyname(struct STUDENT *p, int n, int mlen)
{

	int i;

	
	for (i = 0; i < n; i++)
	{
		if (mlen == strlen(p[i].family))
		{
			
			if (p[i].no < 10)
				printf("[0%d] \t %s %s", p[i].no, p[i].first, p[i].family);
			else printf("[%d] \t %s %s", p[i].no, p[i].first, p[i].family);

			if (strlen(p[i].family)+strlen(p[i].first) > 13) printf("\t\t"); 
			else printf("\t\t\t");
			
			printf("%d %d\n", p[i].sex, p[i].pt);

		}
	}


}


//特定文字列(引数)を含む方の検索・一覧表示
void print_specifiedname(struct STUDENT *p, int n, char *ss)
{

	int i;
	char *ptr;


	for(i = 0; i < n; i++)
	{
		if ((ptr = strstr(p[i].family, ss)) != NULL)	
		{
			if (p[i].no < 10)
				printf("[0%d] \t %s %s\n", p[i].no, p[i].family, p[i].first);
			else printf("[%d] \t %s %s\n", p[i].no, p[i].family, p[i].first);
			
		}
		else if ((ptr = strstr(p[i].first, ss)) != NULL)
		{
			if (p[i].no < 10)
				printf("[0%d] \t %s %s\n", p[i].no, p[i].family, p[i].first);
			else printf("[%d] \t %s %s\n", p[i].no, p[i].family, p[i].first);	
		}
	}
}

//ポイント順でソート...バブルソートしか書けません！すみません(__)
void sort_pt(struct STUDENT *p, int n)
{

	struct STUDENT tmp;
	int i, j;


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-1; j++)
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

//学生データ解放
void free_data(struct STUDENT *p)
{
	free(p);
}
