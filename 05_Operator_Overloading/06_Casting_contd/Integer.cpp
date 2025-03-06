#include "Integer.h"
#include <iostream>

Integer::Integer ()
{
  std::cout << "Integer::Integer()" << std::endl;
  p_int = new int (0);
}

Integer::Integer (int value)
{
  std::cout << "Integer::Integer(int value)" << std::endl;
  p_int = new int (value);
}

Integer::Integer (const Integer &obj)
{
  std::cout << "Integer::Integer(const Integer& obj)" << std::endl;
  p_int = new int (*obj.p_int);
}

Integer::Integer (Integer &&obj)
{
  std::cout << "Integer::Integer(Integer&& obj)" << std::endl;
  p_int = obj.p_int;
  obj.p_int = nullptr;
}

Integer::~Integer ()
{
  std::cout << "Integer::~Integer()" << std::endl;
  delete p_int;
}

void
Integer::SetValue (int value)
{
  *p_int = value;
}

int
Integer::GetValue () const
{
  return *p_int;
}

Integer
Integer::operator+ (const Integer &obj)
{
  Integer temp;
  *temp.p_int = *p_int + *obj.p_int;
  return temp;
}

Integer &
Integer::operator++ ()
{
  ++(*p_int);
  return *this;
}

Integer
Integer::operator++ (int)
{
  Integer temp (*this);
  ++(*p_int);
  return temp;
}

bool
Integer::operator== (const Integer &obj)
{
  if (*p_int == *obj.p_int)
    return true;
  return false;
}

Integer &
Integer::operator= (const Integer &obj)
{
  // avoid self assignment
  if (this != &obj)
    {
      delete p_int;
      p_int = new int (*obj.p_int);
    }
  return *this;
  // WHY RETURN CHAINING a = b = c;
}

// for 5 + obj
Integer
operator+ (int x, const Integer &y)
{
  Integer temp;
  temp.SetValue (x + y.GetValue ());
  return temp;
}

std::ostream &
operator<< (std::ostream &out, const Integer &obj)
{
  out << *obj.p_int;
  return out;
}

std::istream &
operator>> (std::istream &in, Integer &obj)
{
  int temp;
  in >> temp;

  *obj.p_int = temp;

  return in;
}

void
Integer::operator() ()
{
  std::cout << *p_int << std::endl;
}

Integer::operator int ()
{
  std::cout << "Integer::operator int()" << std::endl;
  return *p_int;
}