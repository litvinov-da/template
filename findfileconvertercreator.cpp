#include "findfileconvertercreator.h"


FindFileConverterCreator::FindFileConverterCreator(const File &sourceFile)
{
    std::ifstream source {sourceFile};
    std::string name {};
    while(source >> name) {
        namesFromSourceFile.push_back(name);
    }
}

IConverter::Ptr FindFileConverterCreator::createImpl() const
{
    return std::make_shared<FindFilesConverter>(std::move(namesFromSourceFile));
}
