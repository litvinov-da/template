#pragma once

#include <memory>
#include <string>

class IConverter
{
public:
    using Ptr = std::shared_ptr<IConverter>;
    using ConstPtr = std::shared_ptr<IConverter>;
    
    using File = std::string;
    using Result = File;

    IConverter() = default;
    virtual ~IConverter() = default;
    
    IConverter(const IConverter&) = delete;
    IConverter& operator=(const IConverter&) = delete;
    
    IConverter(IConverter&&) = delete;
    IConverter& operator=(IConverter&&) = delete;

    virtual void setFile(const File& file) = 0;
    virtual void setResult(const Result& result) = 0;
    virtual void convert() = 0;    
};