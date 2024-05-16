#pragma once

#include "iconverter.h"
#include <fstream>

class ToUpperCaseConverter : public IConverter
{
public:
    ToUpperCaseConverter() = default;
    ~ToUpperCaseConverter() override;

    void setFile(const File& file) override;
    void setResult(const Result& result) override;
    void convert() override;

private:
    using FileStream = std::ifstream;
    using ResultStream = std::ofstream;

    FileStream file {};
    ResultStream result {};
};