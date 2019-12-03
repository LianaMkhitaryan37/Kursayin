//
//  main.cpp
//  Kursayin
//
//  Created by Liana Mkhitaryan on 10/9/19.
//  Copyright © 2019 Liana Mkhitaryan. All rights reserved.
//

#include "FileReader.hpp"
#include <iostream>
int main(int argc, const char * argv[]) {
    std::string fileName;
    std::cout<<"Enter file name"<<std::endl;
    std::cin>>fileName;
    fileName ="/Users/lianamkhitaryan/" + fileName;
    FileReader manager(fileName.c_str());
    manager.show();
}

