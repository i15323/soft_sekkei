//funcs.hpp
//伝言：早く完成させろ


//ヘッダファイルインクルード
//#ifndef _STDIO_H


//プリプロ
#define MALE 0
#define FEMALE 1


//構造体定義
struct STUDENT_DATA {

	int no;
	char family[20];
	char first[20];
	int sex;
	int pt;
	
};

//クラス定義
class  STUDENT {

	private:
		int num;			//学生数
		int maxnlen;			//最大文字長
		char fname[20];			//読み出しファイル名
		struct STUDENT_DATA *p;		//データ格納先

	public:
		void getFileName();
		int get_numstudents();
		void load_data();
		void print_list();
		double average(int);
		int get_maxnamelength();
		void printMaxNameLength();
		void print_specifiedname(char *);
		void sortOfPoint(int);			//0:降順 1:昇順
		void free_data();
		STUDENT();				//コンストラクタ
		~STUDENT();				//デストラクタ
};


#ifndef _FUNCS_H_
#define _FUNCS_H

/*funcs.c内の関数プロトタイプ宣言
int load_data(char *, struct STUDENT **);
void print_list(struct STUDENT *, int);
double average(struct STUDENT *, int, int);
int get_maxnamelength(struct STUDENT *, int);
void print_nfamilyname(struct STUDENT *, int ,int);
void print_specifiedname(struct STUDENT *, int, char *);
void sort_pt(struct STUDENT *, int);
void free_data(struct STUDENT *);
*/

#endif // _FUNCS_H
