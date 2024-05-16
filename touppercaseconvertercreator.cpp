#include "touppercaseconvertercreator.h"
#include "touppercaseconverter.h"

IConverter::Ptr ToUpperCaseConverterCreator::createImpl() const
{
    return std::make_shared<ToUpperCaseConverter>();
}