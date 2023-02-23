#ifndef __MANAGEMENT_H__
#define __MANAGEMENT_H__
#include<fstream>
#include<ctime>
#include<cmath>
#include"calculate.h"

using namespace std;

#define MAX 20												//简单模式随机数的最大区间
#define MAX1 80												//困难模式随机数的最大区间
#define NUM 3												//选择相应算术后在同算术下的出题数目
#define FILE "text.txt"										//文件名称

class manageMent
{
	enum Calculate											//枚举，便于后面的分支循环
	{
		add = 1,
		sub,
		mul,
		remove,
		help,
		Exit,
		show
	};
public:				//构造和析构
	manageMent();
	~manageMent();
public:
	void run();												//启动函数
	void menu();											//菜单函数
	void sameFun();											//运算函数相同的部分
	void writeTxt();										//将信息写入文件
	void exitSystem();										//退出系统
	void introduce();										//使用说明
	void showInformation();									//显示记录
public:
	void setSym(char sym);									//设置运算符号
	double getNum1();
	double getNum2();
	char getSym();
	bool isRight();											//判断计算结果是否正确
	void setResult(double result);							//设置运算结果
public:
	void creatNum(int num);									//根据困难程度创建随机数
	void creatNum1(int num);								//根据困难程度创建两个是否可以整除的数
private:
	int  m_num1;											//操作数1
	int  m_num2;											//操作数2
	char m_sym;												//运算符号
private:
	double m_Tresult;										//正确答案
	double m_result;										//用户计算出的答案
};



#endif