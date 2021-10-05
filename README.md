# own-ptr
An owner-aware pointer type for C++. The concept being implemented is the ownership like in Rust. Principles are below:

- One can never *delete* (*free*) a borrowed pointer;
- One can *delete* an owned pointer;
- One can borrow an owned pointer, i.e. available conversion from owned pointer to borrowed pointer;
- One can not own a borrowed pointer i.e. impossible to convert from borrowed pointer to owned pointer;

Examples below are extracted from **example.cpp**. You can try it out you-self, the Makefile is provided.
```cpp
    /**
     *  Construction
     */
    // Construction on the stack: you can build empty ptr, they point to null
    OwnedPtr<int> ptr1;
    BorrowedPtr<int> ptr2;
    // Then they can be assigned (constructor called, copy assignment called)
    ptr1 = &x;
    ptr2 = &x;

    // Construction on the stack, taking a pointer
    OwnedPtr<int>ptr3  (&x);
    BorrowedPtr<int> ptr4 (&x);

    // They can not be allocated on the heap, it is meanless
    //auto ptr5  = new OwnedPtr<int>(&x); ERROR, OwnedPtr is not allowed to be allocated on the heap
    //auto ptr6 = new BorrowedPtr<int>(*ptr1);   ERROR, BorrowedPtr is not allowed to be allocated on the heap

    /**
     * Conversion between OwnedPtr and BorrowedPtr: OP -> BP is OK, BP -> OP is KO
     */
     // ptr1 = ptr2;  // BP -> OP: ERROR
     ptr2 = ptr1; // OP -> BP : OK

     /**
      * Destruction
      */
    // You can delete a OwnedPtr, it will free the real pointer
    delete ptr1;
    // You can not delete a BorrowedPtr
    // delete ptr2; // ERROR
```