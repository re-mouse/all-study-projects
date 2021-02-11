#include "A.hpp"

A::A() {}

A::~A() {}

A &A::operator=(A const &) { return *this; }

A::A(A const &) {}