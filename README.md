# Restaurant Menu System

This C++ program is designed to simulate a simple restaurant menu system. It manages menu items, takes customer orders, calculates the bill, and generates a receipt. Below is a breakdown of the program's functionality:

## File Structure

### Files Included:
- **Main.cpp:** Contains the main logic and functions of the restaurant menu system.
- **menu.txt:** Input file containing menu item details.
- **check.txt:** Output file that stores the final bill and receipt.

## Program Overview

### Struct `menuItemType`
- Defines a structure containing details of menu items: `menuItem` (name) and `menuPrice`.

### Functions

#### `getData(ifstream& inFile, menuItemType mList[], int listSize)`
- Reads data from the input file (`menu.txt`) and populates the `menuItemType` array (`mList[]`) with menu items and their prices.

#### `showMenu(menuItemType mList[], int listSize)`
- Displays the menu items with their respective numbers and prices to the user.

#### `printCheck(menuItemType mList[], int listSize, int cList[], int cListLength)`
- Calculates and prints the bill, including selected items, total cost, tax, and the amount due.
- Writes the bill details to the output file (`check.txt`).

#### `isItemSelected(int cList[], int cListLength, int itemNo)`
- Checks if a specific item has been selected by the customer.

#### `makeSelection(menuItemType mList[], int listSize, int cList[], int& cListLength)`
- Allows customers to make orders by selecting items and quantities.

#### `main()`
- Opens the input file (`menu.txt`) containing menu details.
- Initializes the choice list and retrieves menu items using `getData()` function.
- Displays the menu using `showMenu()` function.
- Allows customers to make selections via `makeSelection()` function.
- Generates and prints the bill using `printCheck()` function.

### Constants
- `NO_OF_ITEMS`: Represents the number of menu items (set to 8 in this program).

## How to Use

1. **Input File Preparation:**
   - Ensure the `menu.txt` file contains the menu items with their prices in the specified format.
  
2. **Compile and Run:**
   - Compile the `Main.cpp` file.
   - Run the compiled program.

3. **Ordering Process:**
   - Follow the instructions provided by the program to make selections.
   - Enter the item number and quantity to place orders.
   - Review the generated bill.

4. **Output:**
   - The program will display the bill with the total cost, tax, and amount due.
   - The receipt will also be saved in the `check.txt` file.
