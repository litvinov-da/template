#include "iconvertercreator.h"
#include "findfileconvertercreator.h"
#include "touppercaseconvertercreator.h"

enum ErrorCode
{
    NO_ERROR_CODE = 0,
    NO_ARGUMENT_CODE,
    NO_RESULT_FILE
};

enum
{
    MODE_INDEX = 1,
    START_FILES_INDEX = 2
};

enum Mode
{
    FIND_FILES_MODE = 0,
    TO_UPPER_CASE_MODE
};

int main(int argc, char** argv) {

    if(argc < MODE_INDEX) {
        return NO_ARGUMENT_CODE;
    }

    if(argc < START_FILES_INDEX) {
        return NO_RESULT_FILE;
    }

    int resultIndex = argc - 1;
    std::string resultFileName {argv[resultIndex]};
    int mode = std::atoi(argv[MODE_INDEX]);
    auto getCreator = [mode](char** argv) -> IConverterCreator::Ptr {
        if(mode == FIND_FILES_MODE) {
            return std::make_shared<FindFileConverterCreator>(argv[START_FILES_INDEX]);
        } else { // TO_UPPER
            return std::make_shared<ToUpperCaseConverterCreator>();
        }
        };

    /* skip executable file name and maybe the first file if find file converter */
    for(int i = mode == FIND_FILES_MODE
            ? START_FILES_INDEX + 1
            : MODE_INDEX + 1; 
        i < resultIndex; 
        ++i) {
            auto creator = getCreator(argv);
            creator->setFile(argv[i]);
            creator->setResult(resultFileName);
            auto converter = creator->create();
            converter->convert();
        }
    
}