#include<algorithm> 
#include<iostream>
#include<string>

#include "DummyClass.h"

DummyClass::DummyClass()
{
}

DummyClass::~DummyClass()
{
}

void DummyClass::write_from_dummy_class(std::string msg)
{
    std::string reversed_str = msg;
    std::reverse(reversed_str.begin(), reversed_str.end());

    WRITE_TRACE(reversed_str);
}