//
//  ArrayStack.cpp
//  stackClass
//
//  Created by Usaid Ali Syed on 2025-02-10.
//

#include "ArrayStack.hpp"
#include <cassert>

template <class ItemType>
ArrayStack<ItemType>:: ArrayStack(): topItemIndex(-1) {}

template <class ItemType>
bool ArrayStack<ItemType>:: isEmpty() const{
    return topItemIndex == -1;
}

template <class ItemType>
bool ArrayStack<ItemType>::push(const ItemType &item) {
    

    
    if (topItemIndex < DEFAULT_CAPACITY - 1) {
        topItemIndex++;
        items[topItemIndex] = item;
        return true;
    }
    
    return false;
}

template <class ItemType>
bool ArrayStack<ItemType>::pop() {

    
    if (!isEmpty()) {
        topItemIndex--;
        return true;
    }
    
    return false;
}

template <class ItemType>
ItemType ArrayStack<ItemType>::peek() const{
    assert(!isEmpty());
    return items[topItemIndex];
}


