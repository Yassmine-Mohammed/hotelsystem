#include <iostream>
#include <thread>
//«··Ì » ⁄„·  √Œ— “„‰Ì »Ì‰ «Ì ﬂÊœ Ê«· «‰Ì
#include <chrono>
//«··Ì ›ÌÂ« ÊÕœ«  «·“„‰ «’·« ·Ê·
#include <windows.h>
//«··Ì »  ⁄«„· „⁄ «·ﬂÊ‰”Ê·
#include <cctype>
//»  Õﬁﬁ „‰ ‰Ê⁄ «·ﬂ—«ﬂ —“
using namespace std;
// Ê·√‰Ì «‰”«‰ „Ê”Ê” Ã»  œ«·… » ⁄„· ” «Ì· ··ﬂ «»… ⁄‘«‰ Ì»ﬁÏ ‘ﬂ·Â« Õ·Ê
void typetext (const string &text)
{
    for (char c : text)
    {
        cout<<c<<flush;
        this_thread::sleep_for(chrono::milliseconds(25));
        /*flush
        ⁄‘«‰ Ì—÷Ï Ìÿ»⁄ ﬂ· Õ—› ·ÊÕœÂ Ê»⁄œÌ‰ ÌÌ—ÊÕ ·”ÿ— «· sleep ÊÌ‰«„ ·Œ„”… Ê⁄‘—Ì‰ „··Ì À«‰Ì…*/
    }
    cout << endl;
}
/* ‰⁄„· œ«·… ⁄‘«‰ «€Ì— ·Ê‰ «·Œÿ ›Ì «·ﬂÊ‰”Ê· */
int setcolor (int color)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), color);
    return 7;
    /*GetStdHandle
    STD_OUTPUT_HANDLE œÌ ⁄»«—… ⁄‰ œ«·… » ‘»ﬂ ›Ì «·Ì «·«Ê »Ê» «··Ì ÿ«·⁄ ›Ì «·ﬂÊ‰”Ê· ⁄‘«‰  €Ì— ›ÌÂ Õ«Ã… Ê›Ì Õ«· ‰«Ì œÌ «”„Â »‘ﬂ· „ƒﬁ 
    SetConsoleTextAttribute Ê»⁄œ ﬂœÂ » œŒ·Â ›Ì
    SetConsoleTextAttribute
    œÌ »ﬁÏ œ«·… Ã«Â“… ›Ì «·ÊÌ‰œÊ“ » «Œœ »—«„« —Ì‰ «·«Ê· »ÌﬂÊ‰ ·Õ«Ã… «··Ì ⁄⁄«Ì“…*/
    /*⁄«Ì“Ì‰ »ﬁÏ œ«·…   ‘ﬂ ⁄·Ï «·«‰ »Ê */
}
bool isValidNumber(int &num)
{
    cin >> num;
    if (cin.fail() || cin.peek() != '\n')
    {
        /*cin.fail() »” »Ì Õﬁﬁ ≈–« ﬂ«‰ «·≈œŒ«· ﬂ·Â €·ÿ (“Ì ·Ê «·„” Œœ„ ﬂ » Õ—› »œ· —ﬁ„).
        ·ﬂ‰
          cin.peek() »  √ﬂœ ≈‰Â „« ›Ì‘ √Ì Õ«Ã… “Ì«œ… »⁄œ «·—ﬁ„° Õ Ï ·Ê ﬂ«‰ «·≈œŒ«· «·√”«”Ì ’Õ.
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

    //setcolor(); //ﬂ· Ê«Õœ…  Œ «— «··Ê‰ «··Ì Â ” „— »ÌÂ ›Ì «·”ﬂ‘‰ » «⁄Â«!
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
