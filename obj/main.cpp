//main.cpp

#include <stdio.h>
#include "funcs.hpp"

int main(int argc, char *argv[])
{

	HomeRoom HR;


	//学生データファイルの入力
	HR.getFileName();	


	printf("\n\n===========================\n\n");

	//データの読み込み・一覧表示
	HR.load_data();
	HR.print_list();

	printf("\n\n===========================\n\n");

	//男女別ポイント平均
	double avm = HR.average(MALE);
	double avf = HR.average(FEMALE);


	printf("男性平均 = %.2f\n", avm);
	printf("女性平均 = %.2f\n", avf);
	printf("\n");

	printf("\n\n===========================\n\n");
	
	//名字の最大文字数の取得・一覧表示
	int fmax = HR.get_maxnamelength();
	printf("最大文字数 = %d 文字\n", fmax);
	HR.printMaxNameLength();

	printf("\n\n===========================\n\n");

	//名前に特定の文字列を含む学生の一覧表示
	if (argc >= 2)
	{
		printf("検索文字列 : %s\n", argv[1]);
		HR.print_specifiedname(argv[1]);
	}
	
	printf("\n\n===========================\n\n");

	//ポイント順にソート・一覧表示
	HR.sortOfPoint(0);
	HR.print_list();
//	s.sortOfPoint(1);
//	s.print_list();

	//============



	return 0;
}
