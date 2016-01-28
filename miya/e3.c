#include <stdio.h>

struct POINT {

	int num;
	double pt;
};


struct POINT count(char *, int);

int main(void)
{

	char *fileName;
	struct POINT m, w;


	printf("ファイル名：");
	scanf("%s", fileName);

	//男性のポイントを計算
	m = count(fileName, 0);

	//女性のポイントを計算
	w = count(fileName, 1);

	printf("男性平均 = %5.2lf\n", m.pt/m.num);
	printf("女性平均 = %5.2lf\n", w.pt/w.num);
	
	
	return 0;

}

struct POINT count(char *fileName, int sei)
{
	int no, sex, pt=0;
	char n1[20], n2[20];
	struct POINT st = {0, 0};
	FILE *fp;
	

	if ((fp = fopen(fileName, "r")) == NULL)
		printf("File Open Error.");


	while ((fscanf(fp, "%d %s %s %d %d", &no, n1, n2, &sex, &pt)) != EOF)
	{
			if(sex == sei){
				(st.num)++;
				st.pt += pt;
			}
	}
	
	return st;

}
