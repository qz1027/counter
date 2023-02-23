#include "manageMent.h"

manageMent::manageMent() :m_num1(0), m_num2(0), m_sym(0), m_Tresult(0), m_result(0) {}
manageMent::~manageMent() {}

void manageMent::menu()
{
	cout << "********************************************" << endl;
	cout << "********************************************" << endl;
	cout << "--------------- 算术运算器 -----------------" << endl << endl;
	cout << "***** 1、练习加法 +    2、练习减法 - *******" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "***** 3、练习加法 *    4、练习除法 / *******" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "***** 5、使用说明      6、退出       *******" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "************ 7、显示计算记录 ***************" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "********************************************" << endl << endl;
}

void manageMent::run()
{
	int num = 0;															//选择分支序号
	calculate flag;															//创建一个对象便于使用成员函数
	this->menu();
	while (true) {
		int i = NUM;														//记录循环次数
		cout << "请进行选择:";
		while (true) {
			cin >> num;
			cout << endl;
			if (num >= 1 && num <= 7)break;
			else {
				cout << "选择有误，请重新进行正确的选择:";
			}
		}
		int num1 = 0;
		if (num != 6 && num != 5 && num != 7) {
			cout << endl;
			cout << "请选择模式： 1、简单    2、困难: ";
			while (true) {
				cin >> num1;
				if (num1 == 1 || num1 == 2)break;
				else cout << "选择有误，请重新选择:";
			}
			cout << endl;													//便于美观的换行
		}
		switch (num)
		{
		case manageMent::add: {
			this->setSym('+');												//设置运算符号
			while (i) {
				this->creatNum(num1);
				this->m_Tresult = flag.add(m_num1, m_num2);					//计算出正确结果
				this->sameFun();
				i--;
			}
			break;
		}
		case manageMent::sub: {
			this->setSym('-');
			while (i) {
				this->creatNum(num1);
				this->m_Tresult = flag.sub(m_num1, m_num2);
				this->sameFun();
				i--;
			}
			break;
		}
		case manageMent::mul: {
			this->setSym('*');
			while (i) {
				this->creatNum(num1);
				this->m_Tresult = flag.mul(m_num1, m_num2);
				this->sameFun();
				i--;
			}
			break;
		}
		case manageMent::remove: {
			this->setSym('/');
			while (i) {
				this->creatNum1(num1);												//选择难易
				this->m_Tresult = flag.remove(m_num1, m_num2);						//计算出正确结果
				if (num1 == 2) {
					this->m_Tresult = (int)(100.0 * m_Tresult + 0.5) / 100.0;		//如果选择难，则将正确答案保留两位小数
				} 
				double num1;
				while (true) {
					cout << "请计算: " << this->getNum1() << " " << this->getSym() << " " << this->getNum2() << " = ";
					cin >> num1;
					this->setResult(num1);
					if (this->isRight()) {
						cout << "恭喜你计算正确!" << endl << endl;
						this->writeTxt();
						system("pause");
						system("cls");
						this->menu();
						break;
					}
					else {
						cout << "算错了哦！请再试一次!" << endl << endl;
						system("pause");
						system("cls");
						this->menu();
					}
				}
				i--;
			}
			break;
		}
		case manageMent::help: {
			this->introduce();
			system("pause");
			system("cls");
			this->menu();
			break;
		}
		case manageMent::Exit: {
			this->exitSystem();
			break;
		}
		case manageMent::show: {
			cout << "已计算的题目如下:" << endl << endl;
			this->showInformation();
			system("pause");
			system("cls");
			this->menu();
		}
		}
	}
}

void manageMent::sameFun()
{
	double num;
	while (true) {
		cout << "请计算: " << this->getNum1() << " " << this->getSym() << " " << this->getNum2() << " = ";
		cin >> num;
		this->setResult(num);
		if (this->isRight()) {
			cout << "恭喜你计算正确!" << endl << endl;
			this->writeTxt();
			system("pause");
			system("cls");
			this->menu();
			break;
		}
		else {
			cout << "算错了哦！请再试一次!" << endl << endl;
			system("pause");
			system("cls");
			this->menu();
		}
	}
}

void manageMent::creatNum(int num)
{
	srand((unsigned int)time(NULL));											//设置随机数种子，随机数随系统时间变化
	if (num == 1) {
		this->m_num1 = rand() % MAX + 1.0;
		while (true) {
			int temp = rand() % MAX + 1.0;
			if (temp < this->m_num1 || temp == this->m_num1) {
				this->m_num2 = temp;
				break;
			}
		}
	}
	else {
		this->m_num1 = rand() % MAX1 + 20.0;
		while (true) {
			int temp = rand() % MAX1 + 20.0;
			if (temp < this->m_num1 || temp == this->m_num1) {
				this->m_num2 = temp;
				break;
			}
		}
	}
}

void manageMent::creatNum1(int num)
{
	srand((unsigned int)time(NULL));
	if (num == 1) {																//可整除
		this->m_num1 = rand() % MAX + 1.0;
		while (true) {
			int temp = rand() % MAX + 1.0;
			if ((temp < this->m_num1 || temp == this->m_num1) && m_num1 % temp == 0) {
				this->m_num2 = temp;
				break;
			}
		}
	}
	else {
		this->m_num1 = rand() % MAX1 + 20.0;
		while (true) {
			int temp = rand() % MAX1 + 20.0;
			if (temp < this->m_num1 || temp == this->m_num1) {
				this->m_num2 = temp;
				break;
			}
		}
	}
}

void manageMent::writeTxt()
{
	fstream ofs;
	ofs.open(FILE, ios::in | ios::app);											//打开文件
	ofs << this->m_num1 << "\t" << this->m_sym << "\t" << this->m_num2 << "\t=\t" << this->m_Tresult << endl;
	ofs.close();
}

void manageMent::exitSystem()
{
	int num = 0;
	cout << "确认退出？ 1、是   2、否" << endl;
	while (true) {
		cin >> num;
		if (num == 1 || num == 2)break;
		else {
			cout << "选择有误，请重新进行选择: ";
		}
	}
	if (num == 1) {
		cout << endl << "程序已退出!欢迎下次使用！" << endl;
		exit(666);
	}
}

void manageMent::introduce()
{
	cout << "\t\t\t使用说明\t\t" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "1、在选择相应的加减乘除运算后，需要选择相应的难易程度" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "2、在选择一个运算后，程序默认会出3道运算符号相同的题目" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "3、难易程度说明：" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "\t简单模式: 题目的两个运算数在1 - 20之间，并且在除法练习的时候可以整除" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "\t困难模式: 题目的两个运算数在20 — 100之间，在进行除法练习的时候不一定可以整除（不能整除的将结果保留两位小数）" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl << endl;
}

void manageMent::showInformation()
{
	ifstream ifs;
	ifs.open(FILE, ios::in);										//以只读的形式打开
	if (!ifs.is_open())cout << "文件打开失败!" << endl;
	char temp[1024];
	while (!ifs.eof()) {
		ifs.getline(temp, 1024);									//从TXT文件中读取一排数据到temp中
		cout << temp << endl;
	}

}

void manageMent::setSym(char sym) { this->m_sym = sym; }

double manageMent::getNum1() { return this->m_num1; }

double manageMent::getNum2() { return this->m_num2; }

char manageMent::getSym() { return this->m_sym; }

bool manageMent::isRight() { return this->m_Tresult == this->m_result; }		//相同返回真，表示运算正确

void manageMent::setResult(double result) { this->m_result = result; }