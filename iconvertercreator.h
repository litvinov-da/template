#pragma once
#include <memory>

#include "iconverter.h"

class IConverterCreator
{
public:
    using Ptr = std::shared_ptr<IConverterCreator>;
    using ConstPtr = std::shared_ptr<IConverterCreator>;
    
    using File = IConverter::File;
    using Result = IConverter::Result;

    IConverterCreator() = default;
    virtual ~IConverterCreator() = default;
    
    IConverterCreator(const IConverterCreator&) = delete;
    IConverterCreator& operator=(const IConverterCreator&) = delete;
    
    IConverterCreator(IConverterCreator&&) = delete;
    IConverterCreator& operator=(IConverterCreator&&) = delete;
    
    void setFile(File file);
    void setResult(const Result& result);
    IConverter::Ptr create() const;

protected:
    virtual IConverter::Ptr createImpl() const = 0;

private:
    File file {};
    Result result {}; 
};