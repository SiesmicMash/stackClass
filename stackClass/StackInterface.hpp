//
//  StackInterface.hpp
//  stackClass
//
//  Created by Usaid Ali Syed on 2025-02-10.
//

#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_
template<class ItemType>
class StackInterface {
public:
    
    virtual bool isEmpty() const = 0;
    virtual bool push(const ItemType &item) = 0;
    virtual bool pop() = 0;
    virtual ItemType peek() const = 0;
    virtual ~StackInterface() {}
};
#endif /* StackInterface_hpp */
