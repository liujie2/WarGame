#ifndef _RUSHGIRL_SCENEBASE_
#define _RUSHGIRL_SCENEBASE_

#include "cocos2d.h"

USING_NS_CC;
using namespace ui;

namespace DestoryColor
{
    class SceneBase : public Scene
    {
    public:
        SceneBase();
        virtual ~SceneBase();

        virtual bool init();
        virtual void update(float dt);
    };
}

#endif
