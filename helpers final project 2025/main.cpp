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
#include <iomanip>
//ضروري عشان نضيف دالة setw اللي بتظبط المسافات بين الكلمات
using namespace std;
int total_price_food;
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

    //الا بقى دالة تتشك على الان بوت انه رقم ومش حاجة تاني/
}
bool isValidNumber(int &num, int min, int max)
//تاكد ان الرقم رقم وبين الاختيارات اللي عايزينها
{
    if (cin.fail() || cin.peek() != '\n' || num < min || num > max)
        /*cin.fail() بيتأكد إن المدخل مش نص
        cin.clear(); → بيصلح حالة الخطأ لو المستخدم دخل حاجة غلط.
        cin.ignore(10000, '\n'); → بيتخلص من أي حروف أو مدخلات غير صحيحة.*/
    {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}
//عشان نطمن ع الشهر
int getMonthNumber(string month)
{
    map<string, int> months =
    {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
        {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
        {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };

    if (isdigit(month[0]))   // لو دخل رقم
    {
        int num = stoi(month);
        return isValidNumber(num, 1, 12) ? num : -1; // لازم يكون بين 1 و 12
    }

    return months.count(month) ? months[month] : -1; // لو كان اسم صحيح يرجعه، لو غلط -1
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
    cout << "\n=========== ========= ===========" << endl;
    setcolor(13);
    cout << left << setw(15) << "Item" << "Quantity" << endl;
    cout << "---------------------------------" << endl;

    for (const auto& item : inventory) {
        cout << left << setw(15) << item.first << item.second << " unit(s)\n";
    }

    cout << "=================================\n";

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
    cout << left << setw(25) << "Total Room Cost:" << total_price_room_stay << " LE\n";
    cout << left << setw(25) << "Total Restaurant Cost:" << total_price_food << " LE\n";
    cout << left << setw(25) << "Subtotal:" << subTotal << " LE\n";
    cout << left << setw(25) << "Tax (10%):" << tax << " LE\n";
    cout << "----------------------------------------\n";
    cout << left << setw(25) << "TOTAL BILL:" << grandTotal << " LE\n";
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
    totalfoodcost(price,quantity);
    //الفاتورة
    total_price_food = totalfoodcost(price,quantity);

    cout << "\n========== Bill ==========\n";
    cout << left << setw(10) << "Meal: " << mealName << endl;
    cout << left << setw(10) << "Quantity: " << quantity << endl;
    cout << left << setw(10) << "Total Cost: " << totalfoodcost(price, quantity) << " LE" << endl;
    //استخدام left: لمحاذاة النص إلى اليسار.

    cout << "==========================\n";

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
//نعمل بتحول الشهور والسنين لايام
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
    setcolor(6);
    typetext("NOTEING that rooms '5','10','15','20','25'and '30'have two beds.\n");
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
            //هنا بنعمل تشيك انه على رقم الاوضة اللي خدها في اراي الاوض المتاحة بدالة find/
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

                typetext("You choose room '12',\nits price 200 LE and its specifications are Single bed,Wardrobe,TV,Wi-Fi,Balcony with view,Daily Cleaning and Room Service\n");

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
        }
    }
    //نبدأ ناخد تاريخ الوصول
    int day,year,month;//بما ان صعب نتحقق من الشهر كسترينج فاحنا نريح دماغنا ونحوله لانتجر وخلاص
    string monthStr;
    //نعمل دو وايل عشان نتشك اذا كان اليوزر كتب التاريخ صح ولو لا هيعيد اللوب من الاول
    int chickdate;
    do
    {
        setcolor(7);
        cout<<"Please, Enter arrival date (day , month and year).\n\n";
        setcolor(2);
        cout<<"Enter arrival Day (it must be a number between 1 and 31).\n";
        setcolor(7);
        cin>>day;
        //نتأكد من اليوم
        while (!isValidNumber(day,1,31))
        {

            setcolor(4);
            typetext("Inter a valid day,between 1 and 31.\n");
            setcolor(7);
            cin>>day;
        }

        setcolor(2);
        cout << "Enter arrival Month (full name, e.g., January): \n";
        setcolor(7);
        cin >> monthStr;//ندخله كسترينج
        month = getMonthNumber(monthStr);//هنا حولناه لانتجر
        while (month == -1)
        {
            setcolor(4);
            cout << "Enter a valid month (1-12 or full name): \n";
            setcolor(7);
            cin >> monthStr;
            month = getMonthNumber(monthStr);
        }
        setcolor(2);
        cout << "Enter arrival year ( It must be a number between 2025-2030): \n";
        setcolor(7);
        cin>>year;
        //نتأكد من السنة
        while(!isValidNumber (year,2025,2030))
        {
            setcolor(4);
            typetext("Inter a valid year,between 2025 and 2030.\n");
            setcolor(7);
            cin>>year;
        }
        setcolor(7);
        cout<<"the arrival date you entered is:"<<" "<<day<<" / "<<month<<" / "<<year<<"\n";

        cout<<"Are you sure? No (Enter 0), Yes (Enter any other key)\n";

        setcolor(7);
        cin>>chickdate;
        cout<<endl;
    }
    while(!chickdate);

    //ناخد تاريخ الرحيل
    //نفس الكلام بس نخلي بالنا إن تاريخ الذهاب لازم يكون بعد تاريخ العودة فهنعمل do while
    int day2,year2,month2;
    string month2Str;
    int chickexitdate;//عشان حبيت الحكاية هيهيهيهي
    do
    {
        do
        {
            setcolor(7);
            cout<<"Please, Enter exit date (day , month and year).\n";
            setcolor(6);
            typetext("The exist date must be after the arrival date.\n");

            setcolor(2);
            cout<<"Please,Enter exit date Day (it must be a number between 1 and 31).\n";
            setcolor(7);
            cin>>day2;
            //نتأكد من رقم اليوم
            while (!isValidNumber(day2,1,31))
            {

                setcolor(4);
                typetext("Inter a valid day,between 1 and 31.");
                setcolor(7);
                cin>>day2;
            }

            setcolor(2);
            cout << "Enter exit month (full name, e.g., January): \n";
            setcolor(7);
            cin>>month2Str;
            month2 = getMonthNumber(month2Str);
            //نتحقق من الشهر
            while (month2 == -1)
                //تذكر أن الفانكشن بتاعت جيت مانث هترجع سالب واحد لو اليوزر دخل رقم او اسم مش موجود في شهور ربنا اللي فوق في الدالة
            {
                setcolor(4);
                cout << "Enter a valid month (1-12 or full name): \n";
                setcolor(7);
                cin >> month2Str;
                month2 = getMonthNumber(month2Str);
            }
            setcolor(2);
            cout << "Enter exit year ( It must be a number between 2025-2030 and after or equal to arrival year): \n";
            setcolor(7);
            cin>>year2;
            //نتشك على السنة
            while(!isValidNumber (year2,2025,2030))
            {
                setcolor(4);
                typetext("Inter a valid year,between 2025 and 2030.\n");
                setcolor(7);
                cin>>year2;
            }

        }
        while (year2 < year || (year2 == year && month2 < month) || (year2 == year && month2 == month && day2 <= day));
        setcolor(7);


        cout<<"the exit date you entered is:"<<" "<<day2<<" / "<<month2Str<<" / "<<year2<<"\n";

        cout<<"Are you sure? No (Enter 0), Yes (Enter any other key)\n";

        setcolor(7);
        cin>>chickexitdate;
        cout<<endl;

    }
    while (!chickexitdate);

    setcolor(11);
    typetext("Your reservation is confirmed, if you need any assistance please do not hesitate to contact us.\n Enjoy your stay!\n");

    //اعتذر يا بشمهندسة هتحشر هنا بردوه
    //عدد ليالي الاقامة
    int nights = calculateNights(day, monthStr, year, day2, month2Str, year2);
    cin.ignore();
    cout<<"Press Enter to show your bill";
    cin.get();
    //بوقف البرنامج لحد ما يضغط انتر

    if (nights != -1)
    {
        system("cls");
        setcolor(6);
        double totalPrice = totalroomprice(nights, roomrent);
        total_price_room_stay = totalPrice;
        cout << "========== The Bill ==========\n\n";
        cout << left << setw(20) << "Room number:" << room << endl << endl;
        this_thread::sleep_for(chrono::milliseconds(100));

        cout << left << setw(20) << "Date of arrival:" << day << " / " << month << " / " << year << endl << endl;
        this_thread::sleep_for(chrono::milliseconds(100));

        cout << left << setw(20) << "Date of exit:" << day2 << " / " << month2 << " / " << year2 << endl << endl;
        this_thread::sleep_for(chrono::milliseconds(100));

        cout << left << setw(20) << "Total nights stayed:" << nights << endl;
        this_thread::sleep_for(chrono::milliseconds(100));

        cout << left << setw(20) << "Total price:" << totalPrice << " LE" << endl << endl;
        this_thread::sleep_for(chrono::milliseconds(100));

    }

    typetext("If you want to book a meal, Please inter 0, otherwise press any key");
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
    setcolor(6);
    cout << "\n========================================\n";
    cout << "          FINAL HOTEL INVOICE           \n";
    cout << "========================================\n";
    cout << left << setw(30) << "Total Room Cost:" << total_price_room_stay << " LE\n";
    cout << left << setw(30) << "Total Restaurant Cost:" << total_price_food << " LE\n";
    cout << left << setw(30) << "Subtotal:" << subTotal << " LE\n";
    cout << left << setw(30) << "Tax (10%):" << tax << " LE\n";
    cout << "----------------------------------------\n";
    cout << left << setw(30) << "TOTAL BILL:" << grandTotal << " LE\n";
    cout << "========================================\n";
}
int main()
{
    typetext("===== Welcome to DOT Hotel Management System! ===== \n \n Please choose an option:\n");

    setcolor(2); //كل واحدة تختار اللون اللي هتستمر بيه في السكشن بتاعها!
    typetext("1. Room Management.\n");
    setcolor(9);

    typetext("2. Food and Beverage Management.\n");
    setcolor(5);

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
        cout << left << setw(30) << "Total Room Cost:" << 0 << " LE\n";
        cout << left << setw(30) << "Total Restaurant Cost:" << 0 << " LE\n";
        cout << left << setw(30) << "Subtotal:" << 0 << " LE\n";
        cout << left << setw(30) << "Tax (10%):" << 0 << " LE\n";
        cout << "----------------------------------------\n";
        cout << left << setw(30) << "TOTAL BILL:" << 0 << " LE\n";
        cout << "========================================\n";

    }
    }
    return 0;
}
