#include <iostream>
#include <string>
#include "List.h"
using namespace std;

// function prototypes
void instructions();
template<typename T> void testList(List<T>& obj, const string& type);

int main(void) {
   // test List of int values
   List<int> integerList;
   testList(integerList, "integer"); 

   // test List of double values
   List<double> doubleList;
   testList(doubleList, "double"); 
} 

// display program instructions to user
void instructions() {
   cout << "Enter one of the following:\n"
        << "  1 to insert at beginning of list\n" 
        << "  2 to insert at end of list\n" 
        << "  3 to delete from beginning of list\n" 
        << "  4 to delete from end of list\n"
        << "  5 to search value from the list\n"
        << "  6 to end list processing\n";
} 
    
// function to test a List
template<typename T> void testList(List<T>& listObject, const string& typeName) {
   cout << "Testing a List of " << typeName << " values\n";
   instructions(); // display instructions

   int choice; // store user choice
   T value; // store input value

   do { // perform user-selected actions
      cout << "? ";
      cin >> choice;

      switch (choice) {
      case 1: // insert at beginning
         cout << "Enter " << typeName << ": ";
         cin >> value;
         listObject.insertAtFront(value);
         listObject.print();             
         break;
      case 2: // insert at end
         cout << "Enter " << typeName << ": ";
         cin >> value;
         listObject.insertAtBack(value);
         listObject.print();            
         break;
      case 3: // remove from beginning
         if (listObject.removeFromFront(value)) {
            cout << value << " removed from list\n";
         }

         listObject.print();
         break;
      case 4: // remove from end
         if (listObject.removeFromBack(value)) {
            cout << value << " removed from list\n";
         }

         listObject.print();
         break;
      case 5:
         cout << "Enter number to find: ";
         cin >> value;
         if(listObject.find(value) != -1){
            cout << "The index of the number is: " << listObject.find(value) << endl;
         }
         else {
            cout << "The number is not in the list." << endl;
         }

         listObject.print();
      }
   } while (choice < 6); 

   cout << "End list test\n\n";
} 