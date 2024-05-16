#include "touppercaseconverter.h"

ToUpperCaseConverter::~ToUpperCaseConverter()
{
    if(file.is_open())
        file.close();
    if(result.is_open())
        result.close();
}

void ToUpperCaseConverter::setFile(const File &file)
{
    this->file.open(file);
}

void ToUpperCaseConverter::setResult(const Result &result)
{
    this->result.open(result);
}

void ToUpperCaseConverter::convert()
{
    char literal;
    while(file >> literal) {
        result << std::toupper(literal);
    }
    file.close();
    result.close();
}
