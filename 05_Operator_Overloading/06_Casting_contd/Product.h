#pragma once
#include "Integer.h"
class Product
{
  Integer m_id;

public:
  Product (const Integer &id);
  ~Product ();
  operator Integer ();
  const Integer &GetValue ();
};