/*
 *  This file contains a implementation of an ownership-aware pointer type for C++
 *	This file is a part of own-ptr
 *	Copyright (c) 2021, Zhenyu Bai
 *
 *	own-ptr is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	own-ptr is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with OTAWA; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 *	02110-1301  USA
 */

#include "OwnershipPtr.hpp"
int main(){
    struct Point{
        int x, y;
    };

    auto x = new Point();

    // Construction on the stack: you can build empty ptr, they point to null, they are assignable
    OwnedPtr<Point> ptr1 = x;
    BorrowedPtr<Point> ptr2 = x;

    // Construction from rvalue prevent a 'leak' e.g. you can not do anything about the native pointer like the x
    OwnedPtr<Point> ptr4{Point()};
    // A better way to be clear that we are allocating on the heap (we are calling new) which may be not that clear in the example above
    auto ptr3 = OwnedPtr<Point>::newFrom(Point());

    // They can not be allocated on the heap, it is meaningless
    //auto ptr5  = new OwnedPtr<int>(&x); ERROR, OwnedPtr is not allowed to be allocated on the heap
    //auto ptr6 = new BorrowedPtr<int>(*ptr1);   ERROR, BorrowedPtr is not allowed to be allocated on the heap

    // Borrow an OwnedPtr:
    BorrowedPtr<Point> ptr5 = ptr1;
    // You can not gain ownership from BorrowedPtr;
    //OwnedPtr<int> ptr6 = ptr5; // ERROR

    // You can transfer the ownership:
    OwnedPtr<Point> ptr7 = ptr3;
    // Now, ptr3 points to null

    //use it by operator * and ->
    (*ptr7).x ++;
    ptr7->y ++;

    return 0;

    // Once the only owner ptr7 goes out-of-scope, it is automatically freed.
}
