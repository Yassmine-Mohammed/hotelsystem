#include <iostream>
#include <thread>
//���� ����� ���� ���� ��� �� ��� �������
#include <chrono>
//���� ���� ����� ����� ���� ���
#include <windows.h>
//���� ������� �� ��������
#include <cctype>
//������ �� ��� ���������
using namespace std;
// ����� ����� ����� ��� ���� ����� ����� ������� ���� ���� ����� ���
void typetext (const string &text)
{
    for (char c : text)
    {
        cout<<c<<flush;
        this_thread::sleep_for(chrono::milliseconds(25));
        /*flush
        ���� ���� ���� �� ��� ����� ������ ����� ���� �� sleep ����� ����� ������ ���� �����*/
    }
    cout << endl;
}
/* ���� ���� ���� ���� ��� ���� �� �������� */
int setcolor (int color)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), color);
    return 7;
    /*GetStdHandle
    STD_OUTPUT_HANDLE �� ����� �� ���� ����� �� ��� �������� ���� ���� �� �������� ���� ���� ��� ���� ��� ������� �� ���� ���� ����
    SetConsoleTextAttribute ���� ��� ������ ��
    SetConsoleTextAttribute
    �� ��� ���� ����� �� �������� ����� ��������� ����� ����� ����� ���� ������*/
    /*������ ��� ���� ���� ��� ���� ���*/
}
bool isValidNumber(int &num)
{
    cin >> num;
    if (cin.fail() || cin.peek() != '\n')
    {
        /*cin.fail() �� ������ ��� ��� ������� ��� ��� (�� �� �������� ��� ��� ��� ���).
        ���
          cin.peek() ������ ��� �� ��� �� ���� ����� ��� ����� ��� �� ��� ������� ������� ��.
        */
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}
int main()
{
    typetext("===== Welcome to DOT Hotel Management System! ===== \n \n Please choose an option:\n");

    //setcolor(); //�� ����� ����� ����� ���� ������ ��� �� ������ ������!
    typetext("1. Room Management.\n");
    //setcolor();

    typetext("2. Food and Beverage Management.\n");
    setcolor(5);

    typetext("3. Inventory Management. \n");
    setcolor(3);

    typetext("4. Bill and Payment.\n");
    int choose;
    while (true)
    {
        setcolor(7);
        cout << "Please enter a number between 1 and 4:\n ";
        if (isValidNumber(choose) && choose >= 1 && choose <= 4)
        {
            break;
        }
        else
        {
            cout << "Invalid input! Please enter a valid number.\n";
        }
    }
    system("cls");
    switch(choose)
    {
    case(1):
    {
        //setcolor();
        typetext ("\t\t ===== Room Management ===== \n\n");
        break;
    }
    case(2):
    {
        //setcolor();
        typetext ("\t\t===== Food and Beverage Management ===== \n\n");
        break;
    }
    case(3):
    {
        setcolor(5);
        typetext( "\t\t===== Inventory Management ===== \n\n");
        break;
    }
    case(4):
    {
        setcolor(3);
        typetext ("\t\t===== Bill and Payment ===== \n\n");
        break;
    }
    }
    return 0;
}
