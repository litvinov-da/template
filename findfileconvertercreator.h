#pragma once

#include "iconvertercreator.h"
#include "findfilesconverter.h"
class FindFileConverterCreator : public IConverterCreator
{
public:
    FindFileConverterCreator(const File& sourceFile);

protected:
    IConverter::Ptr createImpl() const override;

private:
    FindFilesConverter::Searchable namesFromSourceFile;
};
