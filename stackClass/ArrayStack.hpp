//
//  ArrayStack.hpp
//  stackClass
//
//  Created by Usaid Ali Syed on 2025-02-10.
//

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackInterface.hpp"

template <class ItemType>
class ArrayStack : public StackInterface<ItemType> {

private:
    static const int DEFAULT_CAPACITY = 25;
    ItemType items[DEFAULT_CAPACITY];
    int topItemIndex;
    
public:
    ArrayStack();
    bool isEmpty() const;
    bool push(const ItemType &item);
    bool pop();
    ItemType peek() const;
};

#endif /* ArrayStack_hpp */
