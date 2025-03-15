//
// Created by haxxy on 3/15/25.
//

#ifndef INTERGER_H
#define INTERGER_H

#include <iostream>
class Integer {
    int *m_pInt;
public:
    //Default constructor
    Integer();

    //Parameterized constructor
    Integer(int value);

    //Copy constructor
    Integer(const Integer &obj);

    //Copy Assignment
    Integer& operator=(const Integer& obj);

    //Move constructor
    Integer(Integer &&obj);

    //Move Assignment
    Integer& operator=(Integer&& obj);

    int GetValue()const;
    void SetValue(int value);
    ~Integer();

};



#endif //INTERGER_H
