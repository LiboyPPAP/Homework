#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <conio.h>

using namespace std;
bool debug = false;
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
	system("title = ͨѶ¼���˵�");
	
	cout << "�����Ӧ����ѡ���ܣ�" << endl;
	cout << "|--------------------|--------------------|" << endl;
	cout << "|1.�½�һ����ϵ��    |    2.ɾ��ָ����ϵ��|" << endl;
	cout << "|--------------------|--------------------|" << endl;
	cout << "|3.��ѯָ����ϵ��    |    4.�鿴ȫ����ϵ��|" << endl;
	cout << "|--------------------|--------------------|" << endl;
	cout << "|5.�����������ɫ    |    6.�˳�ͨѶ¼����|" << endl;
	cout << "|--------------------|--------------------|" << endl;
	return _getch();
}

void Menu1()
{
	system("title = �½�һ����ϵ��");
	string name, Telnum, address;
	system("cls");
	counter++;

	cout << "�����������ĺ���ƴ��ȫƴ" << endl;
	cin >> name;
	NameList.push_back(name);
	Temp.Name = name;
	system("cls");

	cout << "������" << name << "�ĵ绰����" << endl;
	cin >> Telnum;
	NumList.push_back(Telnum);
	Temp.TelNum = Telnum;
	system("cls");

	cout << "������" << name << "����ϵ��ַ" << endl;
	cin >> address;
	AddList.push_back(address);
	Temp.Address = address;
	system("cls");

	HashListCreate();
	cout << "�ɹ��½���ϵ�ˣ�" << name << endl;
	system("pause");
	system("cls");

}

void Menu2()
{
	system("title = ɾ��ָ����ϵ��");
	string name;
	int i;
	system("cls");
	if (counter == 0)
	{
		cout << "��ǰͨѶ¼��û����ϵ�ˣ��޷�ִ��ɾ������" << endl;

	}
	else if (counter == 1)
	{
		name = NameList[0];
		counter--;
		Hashlist.clear();
		NameList.clear();
		NumList.clear();
		AddList.clear();
		cout << "��ǰͨѶ¼����һ�ˣ��ɹ�ɾ����ϵ��" << name << endl;
	}
	else
	{
		counter--;
		cout << "�������ɾ����ϵ��������" << endl;
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
			cout << "�ɹ�ɾ����ϵ��" << name << endl << endl;
		}

		else
		{
			system("cls");
			cout << "δ�ҵ���ϵ��" << name << endl << endl;
		}
	}
	system("pause");
	system("cls");
}

void Menu3()
{
	system("title = ��ѯָ����ϵ��");
	string name;
	int Hash;
	system("cls");
	if(counter==0)cout<<"����ϵ�˿ɹ�����";
	else 
	{
	cout << "�������������ϵ������ƴ��ȫƴ��" << endl;
	cin >> name;
	Hash = HashFunc(name);

	if (Recordlist[Hash] == true)
	{
		cout << "---------------------------------------------" << endl;
		cout << "|    ������|" << name << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|  �绰�ţ�|" << Hashlist[Hash].TelNum << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|��ϵ��ַ��|" << Hashlist[Hash].Address << endl;
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
		cout << "|    ������|" << name << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|  �绰�ţ�|" << p->TelNum << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|��ϵ��ַ��|" << p->Address << endl;
		cout << "---------------------------------------------" << endl << endl << endl;
		
	}
	}
	system("pause");
	system("cls");
}

void Menu4()
{
	system("title = �鿴ȫ����ϵ��");
	system("cls");
	if(counter==0)cout<<"��ǰͨѶ¼����ϵ�˿ɹ��鿴"<<endl;
	else 
	{
	for (int i = 0; i < NameList.size(); i++)
	{
		cout << "---------------------------------------------" << endl;
		cout << "|    ������|" << NameList[i] << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|  �绰�ţ�|" << NumList[i] << endl;
		cout << "|--------------------------------------------" << endl;
		cout << "|��ϵ��ַ��|" << AddList[i] << endl;
		cout << "---------------------------------------------" << endl << endl << endl;
	}
    }  
	system("pause");
	system("cls");
}

void Menu5()
{
	system("title = �����������ɫ");
	system("cls");
	cout << "|--------------------|--------------------|" << endl;
	cout << "|1.�鿴Ԥ�������    |    2.�Զ���ѡ����ɫ|" << endl;
	cout << "|--------------------|--------------------|" << endl;
	char select = _getch();
	system("cls");
	if (select == '1')
	{
		cout << "|--------------|--------------|" << endl;
		cout << "|1.Ĭ������    |    2.��������|" << endl;
		cout << "|--------------|--------------|" << endl;
		cout << "|3.�ڰ�����    |    4.��������|" << endl;
		cout << "|--------------|--------------|" << endl;
		select = _getch();
		if (select == '1')
		{
			system("color 0F");
			system("title= ͨѶ¼ $ Ĭ������");
			system("cls");
			cout << "������ĳɹ�" << endl;
		}
		else if (select == '2')
		{
			system("color F0");
			system("title= ͨѶ¼ $ ��������");
			system("cls");
			cout << "������ĳɹ�" << endl;
		}
		else if (select == '3')
		{
			system("color 08");
			system("title= ͨѶ¼ $ �ڰ�����");
			system("cls");
			cout << "������ĳɹ�" << endl;
		}
		else if (select == '4')
		{
			system("color E0");
			system("title= ͨѶ¼ $ ��������");
			system("cls");
			cout << "������ĳɹ�" << endl;
		}
	}
	else if (select == '2')
	{
		char Back, Front;
		cout << "����ɫ������ɫѡ����ͬʱ�����ᷢ���ı�" << endl << endl;
		cout << "��ѡ�񱳾�ɫ" << endl;
		cout << "0 = ��ɫ       8 = ��ɫ" << endl;
		cout << "1 = ��ɫ       9 = ����ɫ" << endl;
		cout << "2 = ��ɫ       A = ����ɫ" << endl;
		cout << "3 = ǳ��ɫ     B = ��ǳ��ɫ" << endl;
		cout << "4 = ��ɫ       C = ����ɫ" << endl;
		cout << "5 = ��ɫ       D = ����ɫ" << endl;
		cout << "6 = ��ɫ       E = ����ɫ" << endl;
		cout << "7 = ��ɫ       F = ����ɫ" << endl;
		Back = _getch();
		
		system("cls");
		cout << "��ѡ������ɫ" << endl;
		cout << "0 = ��ɫ       8 = ��ɫ" << endl;
		cout << "1 = ��ɫ       9 = ����ɫ" << endl;
		cout << "2 = ��ɫ       A = ����ɫ" << endl;
		cout << "3 = ǳ��ɫ     B = ��ǳ��ɫ" << endl;
		cout << "4 = ��ɫ       C = ����ɫ" << endl;
		cout << "5 = ��ɫ       D = ����ɫ" << endl;
		cout << "6 = ��ɫ       E = ����ɫ" << endl;
		cout << "7 = ��ɫ       F = ����ɫ" << endl;
		Front = _getch();
		char Color[9] = "color ";
		Color[6] = Back;
		Color[7] = Front;
		system(Color);
		system("cls");
		cout << "�ɹ��Զ���ѡ����ɫ" << endl;
	}

	else
	{
		system("cls");
		cout << "�������ʧ��" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	
	system("title = ͨѶ¼�����˵�");

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
			cout << "##��ѡ����ȷ�����ֽ���ѡ��##" << endl << endl;
		}
	}

	return 0;
}
