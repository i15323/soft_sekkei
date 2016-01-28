//main.cpp 1218 => 1222 => 0115
//3IT KOMATSU Seiya

#include <stdio.h>
#include "funcs.hpp"

int main(int argc, char *argv[])
{

	STUDENT s;


	//学生データファイルの入力
	s.getFileName();	

	printf("\n\n===========================\n\n");

	//データの読み込み・一覧表示
	s.load_data();
	s.print_list();

	printf("\n\n===========================\n\n");

	//男女別ポイント平均
	double avm = s.average(MALE);
	double avf = s.average(FEMALE);


	printf("男性平均 = %.2f\n", avm);
	printf("女性平均 = %.2f\n", avf);
	printf("\n");

	printf("\n\n===========================\n\n");
	
	//名字の最大文字数の取得・一覧表示
	int fmax = s.get_maxnamelength();
	printf("最大文字数 = %d 文字\n", fmax);
	s.printMaxNameLength();

	printf("\n\n===========================\n\n");

	//名前に特定の文字列を含む学生の一覧表示
	if (argc >= 2)
	{
		printf("検索文字列 : %s\n", argv[1]);
		s.print_specifiedname(argv[1]);
	}
	
	printf("\n\n===========================\n\n");

	//ポイント順にソート・一覧表示
	s.sortOfPoint(0);
	s.print_list();
//	s.sortOfPoint(1);
//	s.print_list();

	//============

	//学生データ解放
	s.free_data();


	return 0;
}
