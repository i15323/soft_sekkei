//funcs.hpp


#ifndef _FUNCS_H_
#define _FUNCS_H


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




#endif // _FUNCS_H
