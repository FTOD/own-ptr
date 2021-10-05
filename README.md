# own-ptr
An owner-aware pointer type for C++. The concept being implemented is the ownership like in Rust. Principles are below:
- They are two types of pointer, the *OwnedPointer* and the *BorrowedPointer*;
- At a moment, there is only one owner of a native pointer;
- When the only owner of the native pointer goes out-of-scope, the pointer is automatically freed(deleted);
- Both *OwnedPointer* and *BorrowedPointer* can not be allocated on the heap, they behave like primitive types;
- One can borrow an owned pointer, i.e. available conversion from owned pointer to borrowed pointer;
- One can not own a borrowed pointer i.e. impossible to convert from borrowed pointer to owned pointer;
- When assigning an owned pointer to another one, the assigned one gains the ownership, old one is nullified (like the move operations in the std)

So what we can do:
```cpp
struct Point{
int x, y;
};

auto x = new Point();

// Construction on the stack: you can build empty ptr, they point to null, they are assignable
OwnedPtr<Point> ptr1 = x;
BorrowedPtr<Point> ptr2 = x;

// Borrow an OwnedPtr:
BorrowedPtr<Point> ptr5 = ptr1;
// You can not gain ownership from BorrowedPtr;
//OwnedPtr<int> ptr6 = ptr5; // ERROR

// You can transfer the ownership:
OwnedPtr<Point> ptr7 = ptr1;
// Now, ptr1 points to null

//use it by operator * and ->
(*ptr7).x ++;
ptr7->y ++;

return 0;

// Once OwnedPtr ptr7 goes out-of-scope, it is automatically freed.
```

Example above is extracted from **example.cpp** you can play with it as the Makefile is provided.

## How to use
Copy the header file (**OwnershipPtr.hpp**) in you project.

## Eventual configurations
You may want to add some exception like assert(_ptr!=nullptr) in case of using null pointers.