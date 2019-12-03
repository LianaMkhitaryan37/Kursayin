//
//  HelperFunctions.hpp
//  Kursayin
//
//  Created by Liana Mkhitaryan on 10/9/19.
//  Copyright © 2019 Liana Mkhitaryan. All rights reserved.
//

#ifndef FileReader_hpp
#define FileReader_hpp

#include <stdio.h>

class FileReader{
public:
    FileReader(const char * filePath, int numberLines = 3);
    void show();
    ~FileReader();
private:
    FILE* _file;
    unsigned long long _pos;
    int _lineCount;
    void goForward();
    void goEnd();
    void readLines();
};
#endif /* HelperFunctions_hpp */
