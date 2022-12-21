#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <conio.h>

using namespace std;
struct contacts
{
	string Name;
	string TelNum;
	string Address;
	contacts* next = NULL;
};
contacts Temp, * p, * pre;

vector <contacts> Hashlist;
vector <bool> Recordlist;
int counter = 0;

vector <string> NameList;
vector <string> NumList;
vector <string> AddList;

int Asciisum(string name)
{
	int sum = 0;
	for (int i = 0; i < name.size(); i++)
		sum += (int)name[i];
	return sum;
}

int HashFunc(string name)
{
	int Hash;
	Hash = (int)Asciisum(name) % NameList.size();
	return Hash;
}

void HashListCreate()
{
	pre = NULL;
	p = NULL;
	Hashlist.clear();
	Recordlist.clear();

	Hashlist.resize(NameList.size() + 5);
	Recordlist.resize(NameList.size() + 5, true);

	for (int i = 0; i < NameList.size(); i++)
	{

		int Hash = HashFunc(NameList[i]);

		if (Recordlist[Hash] == true)
		{
			Recordlist[Hash] = false;
			
			Hashlist[Hash].Name = NameList[i];
			Hashlist[Hash].TelNum = NumList[i];
			Hashlist[Hash].Address = AddList[i];
		}

		else
		{

			pre = &Hashlist[Hash];
			while (pre->next != NULL)
			{
				pre = pre->next;
			}
			p = new contacts;
			p->Name = Temp.Name;
			p->TelNum = Temp.TelNum;
			p->Address = Temp.Address;
			pre->next = p;

		}
	}
}

char Menu()
{
	system("title = 通讯录主菜单");
	
	cout << "输入对应数字选择功能：" << endl;
	cout << "|--------------------|--------------------|" << endl;
	cout << "|1.新建一个联系人    |    2.删除指定联系人|" << endl;
	cout << "|--------------------|--------------------|" << endl;
	cout << "|3.查询指定联系人    |    4.查看全部联系人|" << endl;
	cout << "|--------------------|--------------------|" << endl;
	cout << "|5.更改主题和配色    |    6.退出通讯录程序|" << endl;
	cout << "|--------------------|--------------------|" << endl;
	return _getch();
}

void Menu1()
{
	system("title = 新建一个联系人");
	string name, Telnum, address;
	system("cls");
	counter++;

	cout << "请输入姓名的汉语拼音全拼" << endl;
	cin >> name;
	NameList.push_back(name);
	Temp.Name = name;
	system("cls");

	cout << "请输入" << name << "的电话号码" << endl;
	cin >> Telnum;
	NumList.push_back(Telnum);
	Temp.TelNum = Telnum;
	system("cls");

	cout << "请输入" << name << "的联系地址" << endl;
	cin >> address;
	AddList.push_back(address);
	Temp.Address = address;
	system("cls");

	HashListCreate();
	cout << "成功新建联系人：" << name << endl;
	system("pause");
	system("cls");

}

void Menu2()
{
	system("title = 删除指定联系人");
	string name;
	int i;
	system("cls");
	if (counter == 0)
	{
		cout << "当前通讯录内没有联系人，无法执行删除操作" << endl;

	}
	else if (counter == 1)
	{
		name = NameList[0];
		counter--;
		Hashlist.clear();
		NameList.clear();
		NumList.clear();
		AddList.clear();
		cout << "当前通讯录仅有一人，成功删除联系人" << name << endl;
	}
	else
	{
		counter--;
		cout << "请输入待删除联系人姓名：" << endl;
		cin >> name;

		for (i = 0; i <= counter; i++)
		{
			if (name == NameList[i])
			{
				NameList.erase(NameList.begin() + i);
				NumList.erase(NumList.begin() + i);
				AddList.erase(AddList.begin() + i);
				break;
			}
		}
		if (i <= counter)
		{
			system("cls");
			HashListCreate();
			cout << "成功删除联系人" << name << endl << endl;
		}

		else
		{
			system("cls");
			cout << "未找到联系人" << name << endl << endl;
		}
	}
	system("pause");
	system("cls");
}

void Menu3()
{
	system("title = 查询指定联系人");
	string name;
	int Hash;
	system("cls");
	if(counter==0)cout<<"无联系人可供查找";
	else 
	{
	cout << "请输入待查找联系人姓名拼音全拼：" << endl;
	cin >> name;
	Hash = HashFunc(name);

	if (Recordlist[Hash] == true)
	{
		cout << "---------------------------------------------" << endl;
		cout << "|    姓名：|" << name << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|  电话号：|" << Hashlist[Hash].TelNum << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|联系地址：|" << Hashlist[Hash].Address << endl;
		cout << "---------------------------------------------" << endl << endl << endl;
		
	}

	else
	{
		p = &Hashlist[Hash];
		while (p->Name != name)
		{
			p = p->next;
		}
		cout << "---------------------------------------------" << endl;
		cout << "|    姓名：|" << name << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|  电话号：|" << p->TelNum << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|联系地址：|" << p->Address << endl;
		cout << "---------------------------------------------" << endl << endl << endl;
		
	}
	}
	system("pause");
	system("cls");
}

void Menu4()
{
	system("title = 查看全部联系人");
	system("cls");
	if(counter==0)cout<<"当前通讯录无联系人可供查看"<<endl;
	else 
	{
	for (int i = 0; i < NameList.size(); i++)
	{
		cout << "---------------------------------------------" << endl;
		cout << "|    姓名：|" << NameList[i] << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|  电话号：|" << NumList[i] << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|联系地址：|" << AddList[i] << endl;
		cout << "---------------------------------------------" << endl << endl << endl;
	}
    }  
	system("pause");
	system("cls");
}

void Menu5()
{
	system("title = 更改主题和颜色");
	system("cls");
	cout << "|--------------------|--------------------|" << endl;
	cout << "|1.查看预设的主题    |    2.自定义选择配色|" << endl;
	cout << "|--------------------|--------------------|" << endl;
	char select = _getch();
	system("cls");
	if (select == '1')
	{
		cout << "|--------------|--------------|" << endl;
		cout << "|1.默认主题    |    2.明亮主题|" << endl;
		cout << "|--------------|--------------|" << endl;
		cout << "|3.黑暗主题    |    4.护眼主题|" << endl;
		cout << "|--------------|--------------|" << endl;
		select = _getch();
		if (select == '1')
		{
			system("color 0F");
			system("title= 通讯录 $ 默认主题");
			system("cls");
			cout << "主题更改成功" << endl;
		}
		else if (select == '2')
		{
			system("color F0");
			system("title= 通讯录 $ 明亮主题");
			system("cls");
			cout << "主题更改成功" << endl;
		}
		else if (select == '3')
		{
			system("color 08");
			system("title= 通讯录 $ 黑暗主题");
			system("cls");
			cout << "主题更改成功" << endl;
		}
		else if (select == '4')
		{
			system("color E0");
			system("title= 通讯录 $ 护眼主题");
			system("cls");
			cout << "主题更改成功" << endl;
		}
	}
	else if (select == '2')
	{
		char Back, Front;
		cout << "背景色和文字色选择相同时将不会发生改变" << endl << endl;
		cout << "请选择背景色" << endl;
		cout << "0 = 黑色       8 = 灰色" << endl;
		cout << "1 = 蓝色       9 = 淡蓝色" << endl;
		cout << "2 = 绿色       A = 淡绿色" << endl;
		cout << "3 = 浅绿色     B = 淡浅绿色" << endl;
		cout << "4 = 红色       C = 淡红色" << endl;
		cout << "5 = 紫色       D = 淡紫色" << endl;
		cout << "6 = 黄色       E = 淡黄色" << endl;
		cout << "7 = 白色       F = 亮白色" << endl;
		Back = _getch();
		
		system("cls");
		cout << "请选择文字色" << endl;
		cout << "0 = 黑色       8 = 灰色" << endl;
		cout << "1 = 蓝色       9 = 淡蓝色" << endl;
		cout << "2 = 绿色       A = 淡绿色" << endl;
		cout << "3 = 浅绿色     B = 淡浅绿色" << endl;
		cout << "4 = 红色       C = 淡红色" << endl;
		cout << "5 = 紫色       D = 淡紫色" << endl;
		cout << "6 = 黄色       E = 淡黄色" << endl;
		cout << "7 = 白色       F = 亮白色" << endl;
		Front = _getch();
		char Color[9] = "color ";
		Color[6] = Back;
		Color[7] = Front;
		system(Color);
		system("cls");
		cout << "成功自定义选择配色" << endl;
	}

	else
	{
		system("cls");
		cout << "主题更改失败" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	
	system("title = 通讯录：主菜单");

	while (1)
	{
		char select = Menu();

		if (select == '1') Menu1();
		else if (select == '2') Menu2();
		else if (select == '3') Menu3();
		else if (select == '4') Menu4();
		else if (select == '5') Menu5();
		else if (select == '6') break;
		
		else
		{
			system("cls");
			cout << "##请选择正确的数字进行选择##" << endl << endl;
		}
	}

	return 0;
}
