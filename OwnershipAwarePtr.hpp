/*
 *  This file contains a implementation of an ownership-aware pointer type for C++
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

#ifndef OWNERSHIPPTR_H
#define OWNERSHIPPTR_H


template<class T>
struct OwnedPtr{
    OwnedPtr():_ptr(nullptr){};
    OwnedPtr(T* t):_ptr(t){};
    ~OwnedPtr(){delete _ptr;};
    void* operator new (unsigned long count)=delete;
    void* operator new[] (unsigned long count)=delete;
    operator T* (){return _ptr;};
    T* _ptr;
};

template<class T>
struct BorrowedPtr{
    BorrowedPtr():_ptr(nullptr){};
    BorrowedPtr(OwnedPtr<T>& t):_ptr(t._ptr){};
    BorrowedPtr(T* ptr):_ptr(ptr){};
    ~BorrowedPtr()= default;;
    void operator delete  ( void* ptr )=delete;
    void operator delete[]( void* ptr )=delete;
    T& operator*(){return *_ptr;}
    T* _ptr;
};

#endif //OWNERSHIPPTR_H
