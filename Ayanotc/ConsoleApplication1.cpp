#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

char Calculator1(int T1)    //选择运算符
{
	char Oper1;

	switch (T1)
	{
	case 0: Oper1 = '+'; break;
	case 1: Oper1 = '-'; break;
	case 2: Oper1 = '*'; break;
	case 3: Oper1 = '/'; break;
	default: Oper1 = '+';
		break;
	}

	return Oper1;
}
char Calculator2(int T2)    //选择运算符
{
	char Oper2;

	switch (T2)
	{
	case 0: Oper2 = '+'; break;
	case 1: Oper2 = '-'; break;
	case 2: Oper2 = '*'; break;
	case 3: Oper2 = '/'; break;
	default: Oper2 = '+';
		break;
	}

	return Oper2;
}
char Calculator3(int T3)    //选择运算符
{
	char Oper3;

	switch (T3)
	{
	case 0: Oper3 = '+'; break;
	case 1: Oper3 = '-'; break;
	case 2: Oper3 = '*'; break;
	case 3: Oper3 = '/'; break;
	default: Oper3 = '+';
		break;
	}

	return Oper3;
}

int division(int a, int b)    //除法整除
{
	if (a % b != 0)
	{
		int c = 0;
		do {
			c = a % b;
			a -= c;
		} while (a % b == 0);
	}
	else return a;
	return a;
}

int Sum()
{
	int A = 0, B = 0, C = 0 , D = 0 ;    //计算数字
	int Operate_1 = 0, Operate_2 = 1, Operate_3 = 2;    //运算符
	char  Oper1, Oper2, Oper3;
	int Temp_x = 0;    //运算符个数
	int sum = 0;  //结果

	A = rand() % 100 + 1;     //计算数字
	B = rand() % 100 + 1;
	C = rand() % 100 + 1;
	D = rand() % 100 + 1;

	Operate_1 = rand() % 4;     //运算符
	Operate_2 = rand() % 4;
	Operate_3 = rand() % 4;

	Temp_x = rand() % 2 + 2;    //运算符个数


	ofstream outfile;    // 以写模式打开文件
	outfile.open("afile.txt", ios::app);


	if (Temp_x == 2)
	{
		int m = 0;

		if (Operate_1 == 2 || Operate_1 == 3)
		{	switch (Operate_1)
			{
			case 2:
				m = A * B; break;
			case 3:
				//A = division(A,B);
				m = A / B; break;
			default: 0;
				break;
			}
		switch (Operate_2)
		{
		case 0:
			sum = m + C; break;
		case 1:
			sum = m - C; break;
		case 2:
			sum = m * C; break;
		case 3:
			//m = division(m,C);
			sum = m / C; break;
		default: 0;
			break;
		}
	    }
		else if (Operate_1 == 0 || Operate_1 == 1)
		{
			switch (Operate_2)
			{
			case 0:
				m = B + C; break;
			case 1:
				m = B - C; break;
			case 2:
				m = B * C; break;
			case 3:
				//B = division(B,C);
				m = B / C; break;
			default: 0;
				break;
			}
			switch (Operate_1)
			{
			case 0:
				sum = A + m; break;
			case 1:
				sum = A - m; break;
			default: 0;
				break;
			}
		}
		Oper1=Calculator1(Operate_1);    Oper2 = Calculator2(Operate_2);
		cout << A << Oper1 << B << Oper2 << C << '=' << sum << endl;
		outfile << A << Oper1 << B << Oper2 << C << '=' << sum << endl;    // 向文件写入用户输入的数据
	}
	else if (Temp_x == 3)
	{
		int j = 0, k = 0;
		if (Operate_2 == 0 || Operate_2==1)
		{
			switch (Operate_1)
			{
			case 0:
				j = A + B; break;
			case 1: 
				j = A - B; break;
			case 2:
				j = A * B; break;
			case 3:
				//A = division(A,B);
				j = A / B; break;
			default: 0;
				break;
			}
			switch (Operate_3)
			{
			case 0:
				k = C + D; break;
			case 1:
				k = C - D; break;
			case 2:
				k = C * D; break;
			case 3:
				//C = division(C,D);
				k = C / D; break;
			default: 0;
				break;
			}
			switch (Operate_2)
			{
			case 0:
				sum = j + k; break;
			case 1:
				sum = j - k; break;
				break;
			}
		}
		else if((Operate_2 == 2 || Operate_2 == 3)&&(Operate_1 == 0 || Operate_1 == 1))
		{
			switch (Operate_2)
			{
			case 2:
				j = B * C; break;
			case 3:
				//B = division(B,C);
				j = B / C; break;
			default: 0;
				break;
			}
			switch (Operate_3)
			{
				case 0:
					k = j + D; break;
				case 1:
					k = j - D; break;
				case 2:
					k = j * D; break;
				case 3:
					//j = division(j,D);
					k = j / D; break;
			default:
				break;
			}
			switch (Operate_1)
			{
			case 0:
				sum = A + k;
			case 1:
				sum = A - k;
			default:0;
				break;
			}
		}
		else if ((Operate_1 == 0 || Operate_1 == 1)&&(Operate_2 == 0 || Operate_2 == 1))
		{
			switch (Operate_3)
			{
			case 0:
				k = C + D; break;
			case 1:
				k = C - D; break;
			case 2:
				k = C * D; break;
			case 3:
				//C = division(C,D);
				k = C / D; break;
			default:0;
				break;
			}
			switch (Operate_1)
			{
			case 0:
				j = A + B; break;
			case 1:
				j = A - B; break;
			default:0;
				break;
			}
			switch (Operate_2)
			{
			case 0:
				sum = j + k; break;
			case 1:
				sum = j - k;
			default:
				break;
			}
		}
		else if ((Operate_2 == 2 || Operate_2 == 3)&&(Operate_1 == 2 || Operate_1 == 3))
		{
		switch (Operate_1)
		{
		case 2:
			j = A * B; break;
		case 3:
			//A = division(A,B);
			j = A / B; break;
		default:0;
			break;
		}
		switch (Operate_2)
		{
		case 2:
			k = j * C; break;
		case 3:
			//j = division(j,C);
			k = j / C; break;
		default:0;
			break;
		}
		switch (Operate_3)
		{
		case 0:
			sum = k + D; break;
		case 1:
			sum = k - D; break;
		case 2:
			sum = k * D; break;
		case 3:
			//k = division(k,D);
			sum = k / D; break;
		default:0;
			break;
		}
		}
		else 
		{
		switch (Operate_3)
		{
		case 0:
			k = C + D; break;
		case 1:
			k = C - D; break;
		case 2:
			k = C * D; break;
		case 3:
			//C = division(C,D);
			k = C / D; break;
		default:0;
			break;
		}
		switch (Operate_2)
		{
		case 0:
			j = B + k; break;
		case 1:
			j = B - k; break;
		case 2:
			j = B * k; break;
		case 3:
			//B = division(B,k);
			j = B / k; break;
		default:0;
			break;
		}
		switch (Operate_1)
		{case 0:
			sum = A + j; break;
		case 1:
			sum = A - j; break;
		case 2:
			sum = A * j; break;
		case 3:
			//A = division(A,j);
			sum = A / j; break;
		default:0;
			break;
		}
		}
		
		Oper1 = Calculator1(Operate_1);    Oper2 = Calculator2(Operate_2);     Oper3 = Calculator3(Operate_3);
		cout << A << Oper1 << B << Oper2 << C << Oper3 << D << '=' << sum << endl;
		outfile << A << Oper1 << B << Oper2 << C << Oper3 << D << '=' << sum << endl;
	}

	outfile.close();

		return sum;
}

int main()
{
	srand((unsigned)time(NULL));

	int num = 0;

	cout << "出题数 ： " << endl;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		Sum();
		cout << endl;
	}

	return 0;
}
