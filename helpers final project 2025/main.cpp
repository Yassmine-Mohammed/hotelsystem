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
#include <algorithm>
// ضرورية لاستخدام find
using namespace std;
string meal_name;
int the_quantity;
int total_price_food;
int room_numeber;
int nights_number;
int total_price_room_stay;

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
//عرفناها بره الدالة عشان تشتغل في اككتر من واحدة
map <string, int> inventory =
{
    {"Cheese",100}, {"Eggs",100},{"Bread",100},
    {"Milk",100},{"Chicken",100},{"Rice",100},
    {"Fries",100},{"Tea",100},{"Pasta",100},
    {"Salad",100}, {"Meat",100}, {"Coffee",100},
    {"Nuts", 100},{"Fruits",100}, {"Yogurt",100},
    {"Juice",100}
};
int totalfoodcost(int price, int quantity)
{
    int totalcost = price * quantity;
    return totalcost;
}
void InventoryManagement()
{
    for (const auto& item : inventory)
    {
        cout << item.first << ": " << item.second << " unit(s)\n";
    }
    setcolor(6);
    cout<<"\nPress Enter to show your bill";
    cin.ignore();
     cin.get();
    int subTotal = total_price_food + total_price_room_stay; // المجموع قبل الضريبة
    double tax = subTotal * 0.10; // 10% ضريبة
    double grandTotal = subTotal + tax; // الإجمالي النهائي بعد الضريبة

    cout << "\n========================================\n";
    cout << "          FINAL HOTEL INVOICE           \n";
    cout << "========================================\n";
    cout << "Total Room Cost: " << total_price_room_stay << " LE\n";
    cout << "Total Restaurant Cost: " << total_price_food << " LE\n";
    cout << "Subtotal: " << subTotal << " LE\n";
    cout << "Tax (10%): " << tax << " LE\n";
    cout << "----------------------------------------\n";
    cout << "TOTAL BILL: " << grandTotal << " LE\n";
    cout << "========================================\n";


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
        meal_name= "Breakfast Meal";
        price = prices[0];
        break;
    case 2:
        mealName = "Lunch Meal";
        meal_name= "Lunch Meal";

        price = prices[1];
        break;
    case 3:
        mealName = "Dinner Meal";
        meal_name=  "Dinner Meal";

        price = prices[2];
        break;
    case 4:
        mealName = "Snacks";
        meal_name=  "Snacks";

        price = prices[3];
        break;
    }

    cout << "Enter the quantity: ";
    cin >> quantity;
    the_quantity =quantity;
    while (!isValidNumber(quantity, 1, 100))
    {
        setcolor(4);
        cout << "\n Please enter a valid quantity (1-100): ";
        setcolor(7);
        cin >> quantity;
    }
    totalfoodcost(price,quantity);
    //الفاتورة
    total_price_food = totalfoodcost(price,quantity);

    cout << "\n=========== Bill ===========\n";
    cout << "Meal: " << mealName << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total Cost: " << totalfoodcost(price,quantity) << " LE" << endl;
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

    cout<<"if you want to check in the inventory press 0, otherwise interested press any key";
    int check;
    cin>>check;
    if(check==0)
    {
        InventoryManagement();
    }
    else
    {
        system("cls");
        cout<<"================ END ================";
    }
}
//نعمل دالة بتحسب عدد الايام وبالتالي هتحسب عدد الليالي
int convertToDays(int day, string month, int year)
{
    map<string, int> monthDays =
    {
//نحول الاشهر لايام عشان نجمعهم مع بعض زيالناس
        {"January", 0}, {"February", 31}, {"March", 59}, {"April", 90},
        {"May", 120}, {"June", 151}, {"July", 181}, {"August", 212},
        {"September", 243}, {"October", 273}, {"November", 304}, {"December", 334}
    };
    // لو الشهر دخل كرقم نحوله لاسم
    //حتة فزلكة صغننة كده
    map<int, string> numToMonth =
    {
        {1, "January"}, {2, "February"}, {3, "March"}, {4, "April"},
        {5, "May"}, {6, "June"}, {7, "July"}, {8, "August"},
        {9, "September"}, {10, "October"}, {11, "November"}, {12, "December"}
    };
    if (isdigit(month[0]))
    {
        //stoi بتحول الاسترينج لرقم انتجر عادي
        int monthNum = stoi(month);
        if (monthNum < 1 || monthNum > 12)
        {
            cout << "Invalid month number!" << endl;
            return -1;
        }
        //حولناه من الماب اللي فوق عادي جدا
        //يعني شفنا الرقم اللي دلخلناه ايه وجبنا الشهر اللي لازق فيه
        month = numToMonth[monthNum];
    }

    if (monthDays.find(month) == monthDays.end())
        //نتطمن ان العميل في وعيه ومش هيدخل اس شهر غلط
    {
        cout << "Invalid month name!" << endl;
        return -1;
    }
    //كده هنجمع عدد الايام على عدد الايام اللي في الاشهر
    //مهو الهري اللي فوق كله عشان الحتة دي!!!
    int totalDays = monthDays[month] + day;

    return totalDays;
}
//واخيرا هنحسب الليالي
int calculateNights(int day1, string month1, int year1, int day2, string month2, int year2)
{
    //نحط مجموع الايام كلها من اول السنة لحد تاريخ الوصول في day1
    //نحط مجموع الايام من اول السنة لحد تاريخ الذهاب في day2
    int days1 = convertToDays(day1, month1, year1);
    int days2 = convertToDays(day2, month2, year2);
    //نتاكد تاني ان العميل في وعيه ومدخل تواريخ غلط + التأكد اللي عملناه في النبوت
    if (days1 == -1 || days2 == -1)
    {
        cout << "Invalid date input!" << endl;
        return -1;
    }
    //وأخيرا هنحسب الليالي عشان نضربها في التمن ونحطها  في الفاتورة
    int totalNights = days2 - days1 + (year2-year1)*365;
    return totalNights;
}
int totalroomprice (int nights,int roomrent)
{

    long long total = nights*roomrent;
    return total;
}

void roommanegment()
{
    setcolor(2);
    typetext("Welcome to our hotel, Sir !\n\n we have 30 rooms of different types of rooms: Standard, Deluxe and Suite.\n\n") ;

    setcolor(7);
    typetext("The rooms from 1 to 10 are Standard.\n");
    typetext("The rooms from 11 to 20 are Deluxe.\n");
    typetext("The rooms from 21 to 30 are Suite.\n");

    setcolor(2);
    typetext("Now I will show you the available room numbers and their prices per night in our hotel.\n\n");
    int rooms[10]= {5,7,8,10,11,12,15,20,22,25};
    int prices[10]= {100,100,100,120,200,200,220,220,300,320};



    setcolor(7);

    for(int i=0; i<10; i++)
    {

        cout<<"the number of the room is:"<<" "<<rooms[i]<<"\n";
        cout<<"the price of this room is:"<<" "<<prices[i]<<" "<<"LE"<<"\n\n";
        this_thread::sleep_for(chrono::milliseconds(100));


    }
    int roomrent=0;

    setcolor(2);
    typetext("if you want to book a room, Please do the following steps.\n\n");
    //رقم الاوضة
    cout<<"Please, Enter the number of the room.\n\n";
    int room;
    setcolor(7);
    cin>>room;
    setcolor(2);
    //هنعمل input هنسميه wrong عشان لو داس ع رقم مش موجود في ارقام الغرف المتحة فيقدر يدخل رقم تاني
    while(1)
    {
        if(find(begin(rooms), end(rooms), room)!= end(rooms))
            /*هنا بنعمل تشيك انه على رقم الاوضة اللي خدها في اراي الاوض المتاحة بدالة find*/
            //begin يعني دور من البداية
            //end يعني لحد النهاية
            //الدالة دي لو لقت الاوضة بترجع مكانها الاوضة لكن لو ملقتهاش هترجع انها وصلت لاخر المصفوفة وملقتهاش
            //فاحنا بنقول انها الدالة لو مرجعتش end(rooms)
            //يبقى لقتها لكن لو لقتها يبقى يعوض علينا ربنا
        {
            switch(room)
            {
            case(5):
            {
                setcolor(2);

                roomrent = 100;
                typetext("You choose room '5' ,\nits price 100 LE and its specifications are Single bed,Wardrobe,TV,Daily Cleaning and Room Service\n");
                break;
            }
            case(7):
            {
                setcolor(2);

                roomrent = 100;

                typetext("You choose room '7' ,\nits price 100 LE and its specifications are Single bed,Wardrobe,TV,Daily Cleaning and Room Service\n");
                break;
            }
            case(8):
            {
                setcolor(2);

                roomrent = 100;

                typetext("You choose room '8' ,\nits price 100 LE and its specifications are Single bed,Wardrobe,TV,Daily Cleaning and Room Service \n");
                break;
            }
            case(10):
            {
                setcolor(2);

                roomrent = 120;

                typetext("You choose room '10',\nits price 120 LE and its specifications are Double bed,Wardrobe,TV,Daily Cleaning and Room Service\n");
                break;
            }
            case(11):
            {
                setcolor(2);

                roomrent = 200;

                typetext("You choose room '11' ,\nits price 200 LE and its specifications are Single bed,Wardrobe,TV,Wi-Fi,Balcony with view,Daily Cleaning and Room Service\n");
                break;
            }
            case(12):

            {
                setcolor(2);

                roomrent = 200;

                typetext("You choose room '12,\nits price 200 LE and its specifications are Single bed,Wardrobe,TV,Wi-Fi,Balcony with view,Daily Cleaning and Room Service\n");

                break;
            }
            case(15):
            {
                setcolor(2);

                roomrent = 220;

                typetext("You choose room '15',\nits price 220 LE and its specifications are Double bed,Wardrobe,TV,Wi-Fi,Balcony with view,Daily Cleaning and Room Service\n");
                break;
            }
            case(20):
            {
                setcolor(2);

                roomrent = 220;

                typetext("You choose room '20',\nits price 220 LE and its specifications are Double bed,Wardrobe,TV,Wi-Fi,Balcony with view,Daily Cleaning and Room Service\n");;
                break;
            }
            case(22):
            {
                setcolor(2);

                roomrent = 300;

                typetext("You choose room '22',\nits price 300 LE and its specifications are Single bed,Wardrobe,TV,Wi-Fi,Balcony with view,Seating area,Air Conditioning/Heating,Daily Cleaning and Room Service\n");
                break;
            }
            case(25):
            {
                setcolor(2);

                roomrent = 320;

                typetext("You choose room '25',\n its price 320 LE and its specifications are Double bed,Wardrobe,TV,Wi-Fi,Balcony with view,Seating area,Air Conditioning/Heating,Daily Cleaning and Room Service\n");
                break;
            }
            }
            break;
        }
        else
        {
            setcolor(4);
            typetext("Sorry sir, This room is not available, Please choose another.");
            setcolor(7);
            cin>>room;
            room_numeber=room;
        }
    }
    //نبدأ ناخد تاريخ الوصول
    int day,year;
    string month;

    cout<<"Please, enter arrival date (day , month and year).\n\n";
    setcolor(7);
    cin>>day>>month>>year;
    //نتأكد منه
    while(!isValidNumber (year,2025,2030))
    {
        setcolor(4);
        typetext("Inter a valid year,between 2025 and 2030.");
        setcolor(7);
        cin>>year;
    }
    cout<<"the arrival date you entered is:"<<" "<<day<<" "<<month<<" "<<year<<"\n\n";

    //ناخد تاريخ الرحيل
    int day2,year2;
    string month2;
    setcolor(2);
    cout<<"please,enter exit date (day , month and year).\n\n";
    setcolor(7);
    cin>>day2>>month2>>year2;
    while(!isValidNumber (year2,2025,2030) || year2 < year || year2 == year && stoi(month2) < stoi(month) || year2 == year && stoi(month2) == stoi(month) && day2<day)
    {
        setcolor(4);
        typetext("Inter a valid year,between 2025 and 2030.");
        setcolor(7);
        cin>>year2;
    }
    cout<<"the exit date you entered is:"<<" "<<day2<<" "<<month2<<" "<<year2<<"\n\n";

    //اعتذر يا بشمهندسة هتحشر هنا بردوه
    //عدد ليالي الاقامة
    int nights = calculateNights(day, month, year, day2, month2, year2);
    nights_number = nights;

    if (nights != -1)
    {
        system("cls");
        setcolor(6);
        typetext("========== The Bill ==========\n\n");
        cout<<"Room number: "<< room << endl;
        this_thread::sleep_for(chrono::milliseconds(100));

        cout<<"date of arrival: "<< day <<" / "<<month<<" / "<<year << endl;
        this_thread::sleep_for(chrono::milliseconds(100));

        cout<<"date of exit: "<< day2<<" / "<<month2<<" / "<<year2 << endl;
        this_thread::sleep_for(chrono::milliseconds(100));

        cout<<"Total nights stayed: "<< nights << endl;
        totalroomprice(nights,roomrent);
        cout<<  "Total price: "<< totalroomprice(nights,roomrent)<<endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        total_price_room_stay = totalroomprice(nights,roomrent);

    }

    typetext("If you want to order your meal, Please inter 0, otherwise press any key");
    int chick2;
    cin>>chick2;
    if(chick2==0)
    {
        system("cls");

        foodandbevareg();
    }
    else
    {
        system("cls");
        cout<<"================ END ================";
    }
}
void bill ()
{
    int subTotal = total_price_food + total_price_room_stay; // المجموع قبل الضريبة
    double tax = subTotal * 0.10; // 10% ضريبة
    double grandTotal = subTotal + tax; // الإجمالي النهائي بعد الضريبة

    cout << "\n========================================\n";
    cout << "          FINAL HOTEL INVOICE           \n";
    cout << "========================================\n";
    cout << "Total Room Cost: " << total_price_room_stay << " LE\n";
    cout << "Total Restaurant Cost: " << total_price_food << " LE\n";
    cout << "Subtotal: " << subTotal << " LE\n";
    cout << "Tax (10%): " << tax << " LE\n";
    cout << "----------------------------------------\n";
    cout << "TOTAL BILL: " << grandTotal << " LE\n";
    cout << "========================================\n";

}
int main()
{
    typetext("===== Welcome to DOT Hotel Management System! ===== \n \n Please choose an option:\n");

    setcolor(2); //كل واحدة تختار اللون اللي هتستمر بيه في السكشن بتاعها!
    typetext("1. Room Management.\n");
    setcolor(9);

    typetext("2. Food and Beverage Management.\n");
    setcolor(13);

    typetext("3. Inventory Management. \n");

    setcolor(3);
    typetext("4. Bill and Payment.\n");
    int choose;
    setcolor(7);
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
        setcolor(2);
        typetext ("\t\t ================= Room Management ================= \n\n");
        roommanegment();
        break;
    }
    case(2):
    {
        setcolor(9);
        typetext ("\t\t================= Food and Beverage Management ================= /n");
        foodandbevareg();
        break;
    }
    case(3):
    {
        setcolor(5);
        typetext( "\t\t================= Inventory Management ================= \n\n");
        InventoryManagement();
        break;
    }
    case(4):
    {
        setcolor(6);
        cout << "\n========================================\n";
        cout << "          FINAL HOTEL INVOICE           \n";
        cout << "========================================\n";
        cout << "Total Room Cost: " << 0 << " LE\n";
        cout << "Total Restaurant Cost: " << 0 << " LE\n";
        cout << "Subtotal: " << 0 << " LE\n";
        cout << "Tax (10%): " << 0 << " LE\n";
        cout << "----------------------------------------\n";
        cout << "TOTAL BILL: " << 0 << " LE\n";
        cout << "========================================\n";

    }
    }
    return 0;
}
