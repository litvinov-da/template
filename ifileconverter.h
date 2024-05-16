#pragma once

#include <memory>
#include <list>
#include <string>

class IFileConverter
{
public:
    using Ptr = std::shared_ptr<IFileConverter>;
    using ConstPtr = std::shared_ptr<IFileConverter>;
    
    using File = std::string;
    using FileContainer = std::list<std::string>;
    using Result = File;

    IFileConverter() = default;
    virtual ~IFileConverter() = default;
    
    IFileConverter(const IFileConverter&) = delete;
    IFileConverter& operator=(const IFileConverter&) = delete;
    
    IFileConverter(IFileConverter&&) = delete;
    IFileConverter& operator=(IFileConverter&&) = delete;
    
    virtual void convert(const FileContainer& files, const Result& result) const = 0;
};