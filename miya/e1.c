#include <stdio.h>

int get_numstudents(char *);


int main(void)
{

	int stu;
	char *fileName;


	printf("ファイル名：");
	scanf("%s", fileName);


	stu = get_numstudents(fileName);

	printf("クラスの人数：%d 人", stu);


	return 0;
}


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

	while((c=getc(fp)) != EOF)
	{
		if(c == '\n')	x++;
	}


	return x;

}
