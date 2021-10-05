/*
 *  This file contains examples of using the ownership-aware pointers
 *	This file is part of OTAWA
 *	Copyright (c) 2021, Zhenyu Bai, IRIT UPS.
 *
 *	OTAWA is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	OTAWA is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with OTAWA; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 *	02110-1301  USA
 */

#include "OwnershipAwarePtr.hpp"
int main(){
    int x;

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
    return 0;
}
