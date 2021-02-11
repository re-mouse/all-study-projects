#include "C.hpp"

C::C() {}

C::~C() {}

C &C::operator=(C const &) { return *this; }

C::C(C const &) {}