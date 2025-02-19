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
bool isValidNumber(int &num, int min, int max)
//تاكد ان الرقم رقم وبين الاختيارات اللي عايزينها
{
    if (cin.fail() || cin.peek() != '\n' || num < min || num > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}
/*تعريف المتغيرات ب
map
بدل ما تعرف كل متغير لوحده*/
// لو عايزة تضيفي حاجة يا ميري ضيفي!!
map <string, int> inventory =
{
    {"Cheese",100}, {"Eggs",100},{"Bread",100},
    {"Milk",100},{"Chicken",100},{"Rice",100},
    {"Fries",100},{"Tea",100},{"Pasta",100},
    {"Salad",100}, {"Meat",100}, {"Coffee",100},
    {"Nuts", 100},{"Fruits",100}, {"Yogurt",100},
    {"Juice",100}
};
void InventoryManagement()
{
    for (const auto& item : inventory)
    {
        cout << item.first << ": " << item.second << " unit(s)\n";
    }
    cout << "======================================\n";
}

void foodandbevareg ()
{
    const int meals = 4;
    string mealsName[4] = {"Breakfast Meal", "Lunch Meal", "Dinner Meal", "Snacks"};
    string contents[4][4] =
    {
        {"Cheese", "Eggs", "Bread", "Milk"},
        {"Chicken", "Rice", "Fries", "Tea"},
        {"Pasta", "Salad", "Meat", "Coffee"},
        {"Nuts", "Fruits", "Yogurt", "Juice"}
    };
    int prices[4] = {55, 210, 250, 85};

    setcolor(11);
    typetext("\t\t Welcome to Food and Beverage Management System \n");

    typetext("\t\t=============<<   Hotel Menu   >>============\n");
    setcolor(9);
    for (int i = 0; i < meals; i++)
    {
        cout << i + 1 << ". " << mealsName[i] << "\tPrice = " << prices[i] << " LE\n\n";
        this_thread::sleep_for(chrono::milliseconds(50));
        //عشان يبقى لاين باي لاين زي ما ميري عايزة

        cout << "  Contents:\n";
        this_thread::sleep_for(chrono::milliseconds(50));
        for (int j = 0; j < 4; j++)
        {
            cout << "  " << contents[i][j] << endl;
            this_thread::sleep_for(chrono::milliseconds(50));
        }
        cout << "\n=============================\n";
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    int choice, quantity, price = 0;
    string mealName;

    setcolor(7);
    cout << "Select the number of the meal you want to order (1-4): ";
    cin >> choice;
    //input chek
    while (!isValidNumber(choice, 1, 4))//يبقى رقم بين ال1وال4
    {
        setcolor(4);
        cout << "\n This choice isn't available. Please enter another choice (1-4): ";
        setcolor(7);
        cin >> choice;
    }

    switch (choice)
        //سويتش عشان اعرف اعمل كاونتر للمخزون
    {
    case 1:
        mealName = "Breakfast Meal";
        price = prices[0];
        break;
    case 2:
        mealName = "Lunch Meal";
        price = prices[1];
        break;
    case 3:
        mealName = "Dinner Meal";
        price = prices[2];
        break;
    case 4:
        mealName = "Snacks";
        price = prices[3];
        break;
    }

    cout << "Enter the quantity: ";
    cin >> quantity;
    while (!isValidNumber(quantity, 1, 100))
    {
        setcolor(4);
        cout << "\n Please enter a valid quantity (1-100): ";
        setcolor(7);
        cin >> quantity;
    }

    int totalCost = price * quantity;
    //الفاتورة

    cout << "\n=========== Bill ===========\n";
    cout << "Meal: " << mealName << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total Cost: " << totalCost << " LE" << endl;
    cout << "======================================\n";
    //نستأذنك يا بشمهندسة هناخد كام حاجة من عندك
    for( int j=0; j<4; j++)
    {
        // نعمل سترينج في المكونات باسم الله
        string ingredient = contents[choice-1][j];
        //هنا احنا بنعمل سترينج بيخزن فيها مكونات الوجبة اللي احنا عايزينها عشان اولا
        //نتأكدان مكوناتها موجودة في اراي المخزن
        if( inventory [ingredient] >= quantity)
        {
            //لو موجودة هنطرحها منه
            //واستخدمنا لوب عشان نتأكد من انه بيطرح من كل العناصر
            inventory[ingredient] -= quantity;
        }

        else
        {
            setcolor(4);
            cout<<"Not enough "<< ingredient <<"in inventory";
        }
    }
            setcolor(9);
            typetext("The inventory is successfully updated ! ");

        cout<<"if you want to check press 0, otherwise interested press any key";
        bool check;
        cin>>check;
        if(!check)
        {
            InventoryManagement();
        }
        else
        {
            system("cls");
            typetext(" end ");
        }
    }




int main()
{
    typetext("===== Welcome to DOT Hotel Management System! ===== \n \n Please choose an option:\n");

    setcolor(1); //كل واحدة تختار اللون اللي هتستمر بيه في السكشن بتاعها!
    typetext("1. Room Management.\n");
    setcolor(9);

    typetext("2. Food and Beverage Management.\n");
    setcolor(5);

    typetext("3. Inventory Management. \n");
    setcolor(3);

    typetext("4. Bill and Payment.\n");
    int choose;
    cout << "Please enter a number between 1 and 4: ";
    cin >> choose;
    while (!isValidNumber(choose, 1, 4))
    {
        setcolor(4);
        cout << "Invalid input! Please enter a valid number between 1 and 4: ";
        setcolor(7);
        cin >> choose;
    }

    system("cls");
    switch(choose)
    {
    case(1):
    {
        setcolor(1);
        typetext ("\t\t ===== Room Management ===== \n\n");
        break;
    }
    case(2):
    {
        setcolor(9);
        typetext ("\t\t===== Food and Beverage Management ===== /n");
        foodandbevareg();
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
