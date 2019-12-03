//
//  HelperFunctions.cpp
//  Kursayin
//
//  Created by Liana Mkhitaryan on 10/9/19.
//  Copyright © 2019 Liana Mkhitaryan. All rights reserved.
//

#include "FileReader.hpp"
#include <cstdlib>

FileReader::FileReader(const char * filePath, int numberLines)
    :_lineCount(numberLines)
    ,_file(fopen(filePath, "rb"))
{
    if (!_file)
    {
        perror("Error while opening file");
        std::exit(0);
    }
    readLines();
}

FileReader::~FileReader() {
    fclose(_file); 
}

void FileReader::goEnd() {
    if (fseek(_file, 0, SEEK_END))
        perror("fseek() failed");
}
void FileReader::goForward() {
    if (fseek(_file, --_pos, SEEK_SET))//if succsess fseek returns 0
        perror("fseek() failed");
}
void FileReader::show() {
    printf("Printing last %d lines -\n", _lineCount);
    char str[200];
    while (fgets(str, sizeof(str), _file))
        printf("%s", str);
    printf("\n\n");
}
void FileReader::readLines() {
    goEnd();
    _pos = ftell(_file);
    int count = 0;
    while (_pos)
    {
        goForward();
        if (fgetc(_file) == '\n')
            if (count++ == _lineCount)
                break;
    }
}

