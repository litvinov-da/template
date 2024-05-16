#pragma once

#include "ifileconverter.h"
#include <string>
#include <vector>

class SequentialFileConverter : public IFileConverter
{
public:
    SequentialFileConverter() = default;
    ~SequentialFileConverter() override = default;

    void convert(const FileContainer& files, const Result& result) const override;
};