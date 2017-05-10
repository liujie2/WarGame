#ifndef _RUSHGIRL_SCENEMAINMENU_
#define _RUSHGIRL_SCENEMAINMENU_

#include "Scene/SceneBase.h"
#include "Box2D/Box2D.h"
#include "cocos2d.h"

using namespace cocos2d;

#define PTM_RATIO 32
#define WORLD_TO_SCREEN(n) ((n) * PTM_RATIO)

namespace DestoryColor
{
    class SceneMainMenu : public SceneBase
    {
    public:
        SceneMainMenu();
        virtual ~SceneMainMenu();
        
        CREATE_FUNC(SceneMainMenu);
        
        virtual void onEnter();
        virtual void onExit();

        virtual void update(float dt);
    };
}

#endif
