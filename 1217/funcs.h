//funcs.h
//伝言：早く完成させろ


//ヘッダファイルインクルード
//#ifndef _STDIO_H
//#ifndef _STDLIB_H
//#ifndef 




//プリプロ
#define MALE 0
#define FEMALE 1



//クラス定義
//学生情報格納用
class  STUDENT {

	private:
		int no;
		char family[20];
		char first[20];
		int sex;			//0->男性	1->女性
		int pt;

	public:
};

//乱数ポイント格納用
class POINT {

	private:
		int num;	//要素数
		double pt;	//ポイント合計

	public:
		avarage
};





#ifndef _FUNCS_H_
#define _FUNCS_H

//funcs.c内の関数プロトタイプ宣言
int load_data(char *, struct STUDENT **);
void print_list(struct STUDENT *, int);
double average(struct STUDENT *, int, int);
int get_maxnamelength(struct STUDENT *, int);
void print_nfamilyname(struct STUDENT *, int ,int);
void print_specifiedname(struct STUDENT *, int, char *);
void sort_pt(struct STUDENT *, int);
void free_data(struct STUDENT *);

#endif // _FUNCS_H
