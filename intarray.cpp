#include "intarray.h"
 
IntArray::IntArray(){
  p_values= new int[10]; 
  capacity=10;
  cur_size=0; 
}

IntArray::IntArray(int array_size) { 
  p_values = new int[array_size]; 
  capacity= array_size; 
  cur_size = 0; 
}

void IntArray::append(int value) {
    // Increase capacity if cur_size == capacity
    if (cur_size == capacity)
        expand(capacity + 10);
    // Add value to next position in the array
    p_values[cur_size] = value;
    cur_size++;
} 
 
void IntArray::expand(int new_capacity) {
    if (new_capacity <= capacity)
        return;
    int *p = p_values;
    capacity = new_capacity;
    p_values = new int[capacity];
    for (int i = 0; i < size(); i++)
        p_values[i] = p[i];
    delete[] p;
}
 
void IntArray::resize(int new_size) {
    if (new_size > cur_size) {
        expand(new_size);
        for (int i = cur_size; i < new_size; i++)
            p_values[i] = 0;
    }
    cur_size = new_size;
}

   int IntArray::get(int pos) const{ 
    if (pos <= cur_size)               //returns value of array position. 
        return p_values[pos];
    else return 0; 
   }

void IntArray::insert(int pos, int value) { 
  cur_size++;                          //increases the size.                 
  for (int i=pos; i<(cur_size-pos); i++){   //loop to shift the values to the right
    p_values[i+1]=p_values[i];              
  }
  p_values[pos] = value; 
}

void IntArray::remove(int pos) {             //removes a value from the size. 
  for (int i=pos; i<(cur_size-pos); i++){    //left shifts the value in arrays. 
    p_values[i]=p_values[i+1]; 
  }
  cur_size--;                   //decreaments the size of the array. 
}

void IntArray::set(int pos, int value) {
  if (pos <= cur_size)              // sets the specifc position to the desire value
    p_values[pos] = value; 
  }

int IntArray::min() const {      
    int index=0;
    int min=p_values[0]; 
    for (int i=0; i<cur_size; i++){     //loops that looks for minimum value
        if (p_values[i] <min) {
          index= i; 
          min= p_values[i]; 
        }
    }
    return index;                //return's minimum index. 
    }

int IntArray::max() const {
    int index=0;                      //loops that looks for max values and returns index. 
    int max=p_values[0]; 
    for (int i=0; i<cur_size; i++){
        if (p_values[i] >max) {
          index= i; 
          max= p_values[i]; 
        }
    }
    return index; 
}

IntArray IntArray::pmin() const{           //returns pointer of min value index. 
  *p_values=IntArray::min();
  return *p_values; 
}

IntArray IntArray::pmax() const{           //returns pointer of max value index. 
  *p_values=IntArray::max();
  return *p_values; 
}