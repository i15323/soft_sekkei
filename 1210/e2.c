#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STUDENT{

	int no;
	char family[20];
	char first[20];
	int sex;
	int pt;
};


//関数プロトタイプ
int get_numstudents(char *);				//クラスの学生数を数える関数
void put(int, char *, struct STUDENT *);	//構造体STUDENTにファイルの内容を格納
void show(int ,struct STUDENT *);			//構造体の内容を整形表示


/*<><><><><><><><><>
	メイン関数
<><><><><><><><><>*/

int main(void)
{

	int stu;
	char *fileName;
	struct STUDENT *p;


	printf("ファイル名：");
	scanf("%s", fileName);


	stu = get_numstudents(fileName);

	p = malloc(sizeof(struct STUDENT)*stu);

	put(stu, fileName, p);
	show(stu, p);

	free(p);


	return 0;
}

/*<><><><><><><><><>
	追加関数
<><><><><><><><><><>*/

int get_numstudents(char *fileName)
{

	int x;
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

void put(int num, char *fileName, struct STUDENT *p)
{

	int i;
	FILE *fp;
	


	if ((fp = fopen(fileName, "r")) == NULL)
       	printf("File Open Error.");


	for(i = 0; i < num; i++)
		fscanf(fp, "%d %s %s %d %d", &(p[i].no), p[i].family, p[i].first, &(p[i].sex), &(p[i].pt));

	fclose(fp);
}

void show(int x, struct STUDENT *p)
{

	int i;
	char c1, c2;

	for(i = 0; i < x; i++)
	{
		if(p[i].no < 10)	printf("[0%d] \t %c. %s", p[i].no, ((p[i].first)[0])-32, p[i].family);
		else 				printf("[%d] \t %c. %s", p[i].no, ((p[i].first)[0])-32, p[i].family);
		
		if(strlen(p[i].family) > 9) printf("\t\t"); 
		else 						printf("\t\t\t");
		
		printf("%d %d\n", p[i].sex, p[i].pt);

	}

}
