#pragma once

#include "iconvertercreator.h"

class ToUpperCaseConverterCreator final : public IConverterCreator
{
protected:
    IConverter::Ptr createImpl() const override;
};