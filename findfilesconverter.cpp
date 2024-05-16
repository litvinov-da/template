#include "findfilesconverter.h"
#include <algorithm>
FindFilesConverter::FindFilesConverter(Searchable searchable)
    : searchNames(std::move(searchable))
{
}

FindFilesConverter::~FindFilesConverter()
{
    if(result.is_open())
        result.close();
    if(file.is_open())
        file.close();
}

void FindFilesConverter::setFile(const File &file)
{
    this->file.open(file);
}

void FindFilesConverter::setResult(const Result &result)
{
    this->result.open(result);
}

void FindFilesConverter::convert()
{
    std::string name;
    while(file >> name) {
        if(std::find(searchNames.cbegin(), searchNames.cend(), name) != searchNames.cend()) {
            result << name;
        }
    }

    file.close();
    result.close();
}
