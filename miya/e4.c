#include <stdio.h>
#include <string.h>


int main(void)
{

	char fileName[20];
	int len=0;
	FILE *fp;

	//格納用
	int no, sex, pt;
	char s1[20], s2[20];
	//

	printf("ファイル名：");
	scanf("%s", &fileName[0]);


	if ((fp = fopen(fileName, "r")) == NULL)
		printf("File Open Error.");


	//最大の長さを見つける用
	while ((fscanf(fp, "%d %s %s %d %d", &no, s1, s2, &sex, &pt)) != EOF)
	{	
		if(strlen(s1)>len)
			len = strlen(s1);
	}


	//ファイル読み取り位置を再設定
	rewind(fp);


	while ((fscanf(fp, "%d %s %s %d %d", &no, s1, s2, &sex, &pt)) != EOF)
	{

		if(strlen(s1)==len)
			printf("[%d] %s %s\n", no, s1, s2);

	}
	

	
	return 0;

}
