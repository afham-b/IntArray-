#include "intarray.h"
#include <iostream>
using namespace std;
 
void print(const IntArray& a);
 
int main() {
  int size; 
     IntArray array1= IntArray(size);      //initialized the constructor with parameter 

    cout << "\nEnter size of array" << endl; 
    cin >> size; 

    for(int i=0; i<size; i++){
      array1.append(10*i+10);        //creates array that increaments in 10s. 
    }
    print(array1); 


char input; 
do {               // program loops until user quits. 
    cout << "\nEnter s to resize, i to insert, r to remove."
         << "\nEnter m for max and min, p for max and min pointers."
         << "\nOr enter q to quit" <<endl; 
    cin >> input; 

    switch(input){                 
      case 's':                                              //switch case for what user wants to do. 
        cout << "Enter new array size" <<endl; 
        int newsize; 
        cin >> newsize;                                    //resizes
        array1.resize(newsize); 
        print(array1);
        break; 
      case 'i':
        int pos;
        int value; 
        cout << "Enter array position and desire value" << endl; 
        cin >> pos >> value ;                         //insert function
        array1.insert(pos, value); 
        print(array1);
        break;
      case 'r':
        int rpos; 
        cout << "Enter array position to remove" << endl; 
        cin >> rpos; 
        array1.remove(rpos);             //calls remove function
        print(array1);
        break;
      case 'm':
        cout <<" The index of the max value is at: " << 
        array1.max() << " . The index of the minimum value is at: " <<       
        array1.min() <<endl;                       //calls function for min and max index. 
        break;
      case 'p':
        //cout << "The address of the max value is: " << array1.pmax() << endl; 
        //     << " . The address of the min value is: " <<tostring(array1.pmin()) << endl; 
        break; 
      default: input='q'; 
    } 

}while (input != 'q'); 

#ifdef _MSC_VER
    system("pause");
#endif
    return 0;
}
 
void print(const IntArray& a) {                //prints array
    for (int i = 0; i < a.size(); i++)
        if (i>0){
        cout << " " << a.get(i);} 
    cout << endl;
}
