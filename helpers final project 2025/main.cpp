#include <iostream>
#include <thread>
//اللي بتعمل تأخر زمني بين اي كود والتاني
#include <chrono>
//اللي فيها وحدات الزمن اصلا لول
#include <windows.h>
//اللي بتتعامل مع الكونسول
#include <cctype>
//بتتحقق من نوع الكراكترز
#include <map>
//مكتبة الماب
using namespace std;
// ولأني انسان موسوس جبت دالة بتعمل ستايل للكتابة عشان يبقى شكلها حلو
void typetext (const string &text)
{
    for (char c : text)
    {
        cout<<c<<flush;
        this_thread::sleep_for(chrono::milliseconds(25));
        /*flush
        عشان يرضى يطبع كل حرف لوحده وبعدين ييروح لسطر ال
        sleep
        وينام لخمسة وعشرين مللي ثانية*/
    }
    cout << endl;
}
/* نعمل دالة عشان اغير لون الخط في الكونسول */
void setcolor (int color)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), color);
    /*GetStdHandle
    STD_OUTPUT_HANDLE دي عبارة عن دالة بتشبك في الي الاوتبوب اللي طالع في الكونسول عشان تغير فيه حاجة وفي حالتناي دي اسمه بشكل مؤقت
    SetConsoleTextAttribute وبعد كده بتدخله في

    SetConsoleTextAttribute
دي بقى دالة جاهزة في مكتبة الويندوز بتاخد برامترين الاول الحاجة اللي عايز تلونها والتاني رقم اللون اللي انتي عايزه*/

    /*الا بقى دالة تتشك على الان بوت انه رقم ومش حاجة تاني*/
}
bool isValidNumber(int &num)
{
    cin >> num;
    if (cin.fail() || cin.peek() != '\n')
    {
        /*cin.fail() بس بيتحقق إذا كان الإدخال كله غلط (زي لو المستخدم كتب حرف بدل رقم).
        لكن
          cin.peek() بتتأكد إنه ما فيش أي حاجة زيادة بعد الرقم، حتى لو كان الإدخال الأساسي صح.
        */
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}
void InventoryManagement()
{
    /*تعريف المتغيرات ب
    map
    بدل ما تعرف كل متغير لوحده*/
    // لو عايزة تضيفي حاجة يا ميري ضيفي!!
    map <string, int> inventory =
    {
        {"chicken", 1000},
        {"rice", 100},
        {"beef", 1000},
        {"tomato", 1000},
        {"onion", 1000},
        {"celery", 1000},
        {"lemon", 1000}
    };

    // عرض المخزون
    cout << "Welcome to our inventory management system:\n\n";
    cout << "Our remaining stock:\n";
    for (auto item : inventory)
    {
        cout << item.first << " = " << item.second << endl;
    }
}


int main()
{
    typetext("===== Welcome to DOT Hotel Management System! ===== \n \n Please choose an option:\n");

    //setcolor(); //كل واحدة تختار اللون اللي هتستمر بيه في السكشن بتاعها!
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
        {  setcolor(4);
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
        InventoryManagement();
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
