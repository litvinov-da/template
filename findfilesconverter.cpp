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
}

void FindFilesConverter::setFile(const File &file)
{
	this->file = file;
}

void FindFilesConverter::setResult(const Result &result)
{
    this->result.open(result);
}

void FindFilesConverter::convert()
{
        if(std::find(searchNames.cbegin(), searchNames.cend(), file) != searchNames.cend()) {
            result << file;
        }

    result.close();
}
