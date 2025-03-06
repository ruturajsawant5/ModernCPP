#include "Product.h"
#include <iostream>

Product::Product (const Integer &id) : m_id (id)
{
  std::cout << "Product(const Integer &id)" << std::endl;
}

Product::~Product () { std::cout << "~Product" << std::endl; }

Product::operator Integer ()
{
  std::cout << "Product::operator Integer()" << std::endl;
  return m_id;
}

const Integer &
Product::GetValue ()
{
  std::cout << "Product::GetValue()" << std::endl;
  return m_id;
}