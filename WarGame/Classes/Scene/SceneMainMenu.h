#ifndef _RUSHGIRL_SCENEMAINMENU_
#define _RUSHGIRL_SCENEMAINMENU_

#include "Scene/SceneBase.h"


namespace DestoryColor
{
    class SceneMainMenu : public SceneBase
    {
    public:
        SceneMainMenu();
        virtual ~SceneMainMenu();

        //static SceneMainMenu* create();
        CREATE_FUNC(SceneMainMenu);
        virtual void onEnter();
        virtual void onExit();

        virtual void update(float dt);

    private:
        Text* m_title;
        
        int m_elementTypeCubeIndex;
    };
}

#endif