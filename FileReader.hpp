//
//  FileReader.hpp
//  Kursayin
//
//  Created by Liana Mkhitaryan on 10/9/19.
//  Copyright © 2019 Liana Mkhitaryan. All rights reserved.
//

#ifndef FileReader_hpp
#define FileReader_hpp

#include <stdio.h>
#include <string>

class FileReader{
public:
    FileReader(const char * filePath, int numberLines = 3);
    std::string show();
    ~FileReader();
private:
    int _lineCount;
    FILE* _file;
    long _pos;
    void goForward();
    void goEnd();
    void readLines();
};
#endif /* HelperFunctions_hpp */
