#pragma once

#include "iconverter.h"
#include <fstream>
#include <list>

class FindFilesConverter : public IConverter
{
public:
    using Searchable = std::list<std::string>;

    FindFilesConverter(Searchable searchable);
    ~FindFilesConverter() override;

    void setFile(const File& file) override;
    void setResult(const Result& result) override;
    void convert() override;

private:
    using FileStream = std::ifstream;
    using ResultStream = std::ofstream;

    Searchable searchNames {};
    File file {};
    ResultStream result {};    
};
