//
//  PhysicManager.cpp
//  WarGame
//
//  Created by 刘姐 on 2017/5/10.
//
//

#include "PhysicManager.h"
#include "Utilities/GLES-Render.h"

namespace DestoryColor {
    IMPLEMENT_SINGLETON(PhysicManager);
    
    PhysicManager::PhysicManager():m_world(nullptr),m_gravity()
    {
        m_gravity.Set(0.0f, -9.8f);
        bool doSleep = true;
        
        m_world = new b2World(m_gravity);
        m_world->SetAllowSleeping(doSleep);
        
        auto debugDraw = new GLESDebugDraw(PTM_RATIO);
        uint flags = 0;
        flags += b2Draw::e_shapeBit;
        flags += b2Draw::e_jointBit;
        flags += b2Draw::e_centerOfMassBit;
        debugDraw->SetFlags(flags);
        m_world->SetDebugDraw(debugDraw);
    }
    
    PhysicManager::~PhysicManager()
    {
        
    }
    
    b2World* PhysicManager::GetWorld()
    {
        return m_world;
    }
}
