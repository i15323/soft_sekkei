//main.c 1218 => 1222
//3IT KOMATSU Seiya

#include <stdio.h>
#include "funcs.h"

int main(int argc, char *argv[])
{

	int n;
	char fname[20];
	struct STUDENT *seito = NULL;


	//学生データファイルの入力
	printf("File Name : ");
	scanf("%s", fname);

	printf("\n\n===========================\n\n");

	//データの読み込み・一覧表示
	n = load_data(fname, &seito);
	print_list(seito, n);

	printf("\n\n===========================\n\n");

	//男女別ポイント平均
	double avm = average(seito, n, MALE);
	double avf = average(seito, n, FEMALE);


	printf("男性平均 = %.2f\n", avm);
	printf("女性平均 = %.2f\n", avf);
	printf("\n");

	printf("\n\n===========================\n\n");
	
	//名字の最大文字数の取得・一覧表示
	int fmax = get_maxnamelength(seito, n);
	printf("最大文字数 = %d 文字\n", fmax);
	print_nfamilyname(seito, n, fmax);

	printf("\n\n===========================\n\n");

	//名前に特定の文字列を含む学生の一覧表示
	if (argc >= 2)
	{
		printf("検索文字列 : %s\n", argv[1]);
		print_specifiedname(seito, n, argv[1]);
	}
	
	printf("\n\n===========================\n\n");

	//ポイントが大い順にソート・一覧表示
	sort_pt(seito, n);
	print_list(seito, n);

	//============

	//学生データ解放
	free_data(seito);


	return 0;
}
