#pragma once
 
class IntArray {
private:
    int *p_values; // For storage of values
    int capacity; // Number of storage locations allocated
    int cur_size; // Number of storage locations used
    void expand(int new_capacity);
public:
    // Constructor - Creates a dynamic array of size zero
    IntArray();
    IntArray(int array_size); //parameter Constructor. 
    // Destructor - Recover memory allocated by the object
    ~IntArray() { delete[] p_values; }
    // append - Adds an element to the array, increasing 
    //  its size by 1
    void append(int value);
       // resize - Changes the size of the array
    void resize(int new_size);
    // get - Returns the value stored at the given position
    int get(int pos) const ; 
    // insert - Inserts the value at the given position, 
    //  increasing the size by 1
    void insert(int pos, int value);
    // remove - Removes the value at the given position,
    //  decreasing the size of the array by 1
    void remove(int pos);
    // set - Change the value stored at the given position
    void set(int pos, int value); 
    // size - Returns the current size of the array
    int size() const { return cur_size; }
    //returns the min; 
    int min() const; 
    //returns the max; 
    int max() const; 
    //returns min's address.
    IntArray pmin() const;
    //returns max's address. 
    IntArray pmax() const;  
};

