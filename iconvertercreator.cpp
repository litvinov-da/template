#include "iconvertercreator.h"

void IConverterCreator::setFile(File file)
{
    this->file = std::move(file);
}

void IConverterCreator::setResult(const Result& result)
{
    this->result = std::move(result);
}

IConverter::Ptr IConverterCreator::create() const
{
    auto converter = createImpl();
    converter->setFile(std::move(file));
    converter->setResult(std::move(result));
    return converter;
}