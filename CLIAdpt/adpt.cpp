#include "pch.h"

#include "adpt.h"

#include <msclr/marshal_cppstd.h>


int GetDouble(int y) {
    return CSLib::LibClass::getDouble(y);
}

std::string GetMessage() {
    System::String^ str = CSLib::LibClass::getMessage();
    return msclr::interop::marshal_as<std::string>(str);
}
