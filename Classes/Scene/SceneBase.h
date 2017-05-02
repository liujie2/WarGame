#ifndef _RUSHGIRL_SCENEBASE_
#define _RUSHGIRL_SCENEBASE_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

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

        const Layer* GetUiLayer() const;

    protected:
        Layer* m_pUiLayer;
    };
}

#endif