//
//  cWorld.hpp
//  TestSMFL
//
//  Created by Mariano de Diego Biosca on 19/11/16.
//  Copyright © 2016 Mariano de Diego Biosca. All rights reserved.
//

#ifndef cWorld_hpp
#define cWorld_hpp

//Standard
#include <stdio.h>
#include <vector>

//Local
#include "cGameObject.hpp"

class World
{
private:
    std::vector<GameObject> objList;
    
public:
    World();
    ~World();
    
};

#endif /* cWorld_hpp */
