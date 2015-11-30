
// FILE:  Zoo.cpp
// IMPLEMENTATION FILE FOR CLASS Zoo


#include "Zoo.h"

Zoo :: Zoo()   
 // Pre: none
 // Post: owner's name has been initialized to "nobody".
 //       count is set to 0.
 //       cage pointer is set to NULL.   

 { 
  owner = "nobody";
  cage = NULL;
  count = 0;
 }


Zoo :: Zoo( string n )   
 // Pre: none
 // Post: owner's name has been initialized to n.
 //       count is set to 0. 
{ 
  owner = n;
  cage = NULL;
  count = 0;
}


string Zoo :: name() 
// Pre: none
// Post: returns owner's name
{
  return owner;
}


void Zoo :: operator=(const Zoo& z)
// Pre: none
// Modifies: self
// Post: Copied all animals to self. Does not change owner.
{
  if (this != &z) {
    delete [] cage;
    count = z.count;
    cage = new string[count];
    for (int i=0; i<count; i++) {
      cage[i] = z.cage[i];
    }
  }
}

Zoo operator+(const Zoo& z, string a)
// Pre: none
// Post: returns z with same owner and animals,
//       animal a added to the end.

{    
   Zoo newZoo;
   newZoo.owner = z.owner;
   newZoo.count = z.count + 1;
   newZoo.cage = new string[newZoo.count];
   for (int i=0; i<newZoo.count; i++){
    if (i>=z.count){
      newZoo.cage[i] = a;
    }
    else{
      newZoo.cage[i] = z.cage[i];
    }
   }
   return newZoo;
}



ostream& operator<<(ostream& out, const Zoo& z)
 // Pre: none
 // Post: prints out z's contents (animal1, animal2, etc.), 
 //       and returns out stream.
{
   out << z.owner << "'s" <<" Zoo " << '('<< z.count << " animals "
       << ')' << ':' <<endl;
   for (int i=0; i<z.count; i++)
   {
      out<< z.cage[i];
      out<< endl;
   }
   return out;
}


Zoo :: ~Zoo()       
// the object's pointer variable to cage has been deleted.
{
    cage = NULL;    
    
    
}

bool operator<=(string a, const Zoo& z)
    // Pre: none
    // Post: returns true if animal a is in Zoo z.
    //       the owner does not count as an animal.
{
    for (int i = 0; i<z.count; i++){
      if (z.cage[i]==a){
        return true;  
      }
    }
    return false;
 }


// NONMEMBER FUNCTIONS
Zoo operator+(string a, const Zoo& z)
//Pre:  none
//Post: returns z with same owner and animals,
//      animal a added to the end.
{
  Zoo newZoo;
  newZoo = z;
  newZoo += a;  
  return newZoo;
    
    
}


void operator+=(Zoo& z, string a)
//Pre: none
//Modifies: z
//Post: z has same animals and owner, animal a added to the end.
{
    z = z + a;
}


