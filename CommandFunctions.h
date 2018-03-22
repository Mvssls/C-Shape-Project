//
// Created by v_mik on 3/22/2018.
//

#include <iostream>

#ifndef UNTITLED_COMMANDFUNCTIONS_H
#define UNTITLED_COMMANDFUNCTIONS_H

#endif //UNTITLED_COMMANDFUNCTIONS_H

void showHelp()
{
    std::cout<<"/------------------------------------------------------------/" << std::endl;
    std::cout<<"/------------------------------------------------------------/" << std::endl;
    std::cout<<"# newcircle [circleName] [centerX] [centerY] [radius]"          << std::endl;
    std::cout<<"# newrect [rectName] [positionX] [positionY] [width] [height]"  << std::endl;
    std::cout<<"# newrhomb [circleName] [positionX] [positionY] [widthSide]"    << std::endl;
    std::cout<<"# scaleup [shapeName] [scaleupValue]"                           << std::endl;
    std::cout<<"# translate [shapeName] [ValueX] [ValueY]"                      << std::endl;
    std::cout<<"# areas"                                                        << std::endl;
    std::cout<<"# draw"                                                         << std::endl;
    std::cout<<"# delete [shapeName]"                                           << std::endl;
    std::cout<<"/------------------------------------------------------------/" << std::endl;
    std::cout<<"/------------------------------------------------------------/" << std::endl;
}