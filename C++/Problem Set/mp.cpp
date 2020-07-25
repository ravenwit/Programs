#include <unicode/unistr.h>
#include <unicode/ustream.h>

#include <iostream>

int main()
{
    char const * someString = "Eidenges\xe4\xdf";
    icu::UnicodeString someUString( someString, "ISO-8859-1" );
    std::cout << someUString.toLower() << "\n";
    std::cout << someUString.toUpper() << "\n";
    return 0;
}