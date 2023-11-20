#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

//Creating a struct menuItemType
struct menuItemType
{
    // Declaring variables
    string menuItem;
    double menuPrice;
    // Assigning default values to variables
    menuItemType()
    {
        menuItem = "";
        menuPrice = 0.0;
    }
};

/* load data from input file and populate
 * the data into struct menuItemType
 */
void getData(ifstream& inFile, menuItemType mList[], int listSize)
{
    // Declaring the variables
    string name, str;
    double price;

    // menu type
    ifstream dataIn;
    int index = 0;

    // This for loop will read the data from the input file   
    for (int i = 0; i < listSize; i++)
    {
        //Reading each record from the file
        getline(inFile, str);

        // Finding the index of the dollar char in the string
        index = str.find("$");
        name = str.substr(0, index);
        price = atof(str.substr(index + 1, str.length()).c_str());
        mList[i].menuItem = name;

        mList[i].menuPrice = price;

    }
    // Closing the input file
    dataIn.close();
}

/*
 * This function will display the menu of the item in the restaurants
 */
void showMenu(menuItemType mList[], int listSize)
{
    // function code
       // Function variables
    int count;
    cout << "Welcome to Johnny's Restaurant !" << endl;
    cout << "What would you to order?" << endl;

    // Displaying the menu using the for loop
    for (count = 0; count < listSize; count++)
    {
        cout << "[" << count + 1 << "]";
        cout << setw(30) << left << mList[count].menuItem << '$'
            << mList[count].menuPrice << endl;
    }

}

/*
 * This function will display the billing items ,
 * tax and amount due in the final bill
 */
void printCheck(menuItemType mList[], int listSize, int cList[], int cListLength)
{
    // Declaring variables
    double checkTotal = 0;
    double checkTax = 0;
    ofstream dataOut;
    string outputFile = "check.txt";

    // Declaring the constants
    const double TAX = 0.0886;

    // Opening the input file
    dataOut.open(outputFile.c_str());
    dataOut << fixed << showpoint << setprecision(2);
    dataOut << "Welcome to Johnny's Restaurant !" << endl;
    cout << "Welcome to Johnny's Restaurant !" << endl;

    // Displaying the items in the final check
    for (int i = 0; i < listSize; i++)
    {
        if (cList[i] != 0)
        {
            cout << setw(20) << left << mList[i].menuItem << setw(5) << left << cList[i]
                << '$' << mList[i].menuPrice * cList[i] << endl;
            dataOut << setw(20) << left << mList[i].menuItem << setw(5) << left << cList[i]
                << '$' << mList[i].menuPrice * cList[i] << endl;

            checkTotal += (mList[i].menuPrice * cList[i]);
        }

    }
    // Calculating the tax
    checkTax = checkTotal * TAX;
    checkTotal += checkTax;
    cout << setw(15) << left << "Tax" << setw(11) << right << "$" << checkTax << endl;
    cout << setw(15) << left << "Amount Due " << setw(11) << right << "$" << checkTotal << endl;
    dataOut << setw(15) << left << "Tax" << setw(11) << right << "$" << checkTax << endl;
    dataOut << setw(15) << left << "Amount Due " << setw(12) << right << "$" << checkTotal << endl;
    system("pause");

}

bool isItemSelected(int cList[], int cListLength, int itemNo)
{
    // function code
    if (cList[itemNo - 1] != 0)
    {
        return true;
    }
    else {
        return false;
    }
}

void makeSelection(menuItemType mList[], int listSize, int cList[], int& cListLength)
{
    cListLength = listSize;
    int noOfOrders = 0;
    int orderChoice = 0, orderCnt = 0;

    cin >> noOfOrders;

    for (int i = 0; i < noOfOrders; i++)
    {
        cin >> orderChoice;
        cin >> orderCnt;
        cList[orderChoice - 1] += orderCnt;
    }
}


int main()
{
    // Declaring constant
    const int NO_OF_ITEMS = 8;

    // creating struct array
    menuItemType menuList[NO_OF_ITEMS];
    int choiceList[NO_OF_ITEMS];

    // Declaring variables
    int choiceListLength;
    ifstream inFile;

    cout << fixed << showpoint << setprecision(2);

    // Opening the input file
    inFile.open("menu.txt");
    if (!inFile)
    {
        cout << "Cannot open the input file. Program Terminates!"
            << endl;
        return 1;
    }
    else {
        for (int i = 0; i < NO_OF_ITEMS; i++)
        {
            choiceList[i] = 0;
        }

        // call getData() function
        getData(inFile, menuList, NO_OF_ITEMS);
        // call showMenu() function
        showMenu(menuList, NO_OF_ITEMS);
        cout << endl;
        // call makeSelection() function
        makeSelection(menuList, NO_OF_ITEMS, choiceList, choiceListLength);
        // call printCheck() function        
        cout << endl;
        printCheck(menuList, NO_OF_ITEMS, choiceList, choiceListLength);
    }

    return 0;
}
