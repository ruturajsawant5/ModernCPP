#pragma once
#include <iostream>

class Integer
{
  int *p_int;

public:
  Integer ();
  Integer (int value);
  Integer (const Integer &obj);
  Integer (Integer &&obj);
  ~Integer ();
  void SetValue (int value);
  int GetValue () const;
  Integer operator+ (const Integer &obj);
  Integer &operator++ ();
  Integer operator++ (int);
  bool operator== (const Integer &obj);
  Integer &operator= (const Integer &obj);
  void operator() ();
  friend std::ostream &operator<< (std::ostream &out, const Integer &obj);
  friend std::istream &operator>> (std::istream &in, Integer &obj);
};

// for 5 + obj
Integer operator+ (int x, const Integer &y);
