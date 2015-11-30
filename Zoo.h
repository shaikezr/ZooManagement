// File: Zoo.h
//
// A Zoo has an owner and animals in the order they were caught.
//
// A new Zoo has no animals and owner is the string you give it.


#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string>
using namespace std;

class Zoo {
  private:
    string owner;    // owner's name
    string *cage;    // dynamic array of animals, 1 string/animal
    int count;       // # of animals in Zoo, size of cage

  public:

   // Constructor 1   
   
   Zoo(); 
   // Pre: none
   // Post: owner's name has been initialized to "nobody".
   //       count is set to 0.
   //       cage pointer is set to NULL.
    
    
    // Constructor 2  
    
    Zoo(string n);  
   
   // Pre: none
   // Post: owner's name has been initialized to n.
   //       count is set to 0.
   //       cage pointer is set to NULL.
   

     // destructor
    ~Zoo();       
    

    // MEMBER FUNCTIONS
      string name();
    // Pre: none
    // Post: returns owner's name
    
   void operator=(const Zoo& z); // assignment operator
    // Pre: none
    // Modifies: self
    // Post: Copy's all animals to self. Does not change owner.
   
    
    
       // FRIEND FUNCTIONS
     friend Zoo operator+(const Zoo& z, string a);
    // Pre: none
    // Post: returns z with same owner and animals,
    //       animal a added to the end.
    
    
    
     friend ostream& operator<<(ostream& out, const Zoo& z);
    // Pre: none
    // Post: prints out z's contents (animal1, animal2, etc.), 
    //       and returns out stream.
   
   friend bool operator<=(string a, const Zoo& z);
    // Pre: none
    // Post: returns true if animal a is in Zoo z.
    //       the owner does not count as an animal.
  


 };  // end class Zoo


 // NONMEMBER FUNCTIONS

Zoo operator+(string a, const Zoo&);
// Pre: none
// Post: returns z with same owner and animals,
//       animal a added to the end.


void operator+=(Zoo& z, string a);
// Pre: none
// Modifies: z
// Post: z has same animals and owner,
//       animal a added to the end.
//       returns the modified z.

 #endif
 
 
 
