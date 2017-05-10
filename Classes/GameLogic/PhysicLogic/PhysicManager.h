//
//  PhysicManger.h
//  WarGame
//
//  Created by 刘姐 on 2017/5/10.
//
//

#ifndef PhysicManager_h
#define PhysicManager_h

#include "cocos2d.h"
#include "Utilities/Utilities.h"
#include "Utilities/Singleton.h"
#include "Box2D/Box2D.h"

USING_NS_CC;
#define PTM_RATIO 32
#define WORLD_TO_SCREEN(n) ((n) * PTM_RATIO)

namespace DestoryColor {
    class PhysicManager : public Ref
    {
    public:
        DECLARE_SINGLETON(PhysicManager);
    public:
        b2World* GetWorld();
    private:
        b2World* m_world;
        b2Vec2 m_gravity;
    };
}


#endif /* PhysicManger_h */
