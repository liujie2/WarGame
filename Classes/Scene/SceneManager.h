#ifndef _RUSHGIRL_SCENEMANAGER_
#define _RUSHGIRL_SCENEMANAGER_

#include "cocos2d.h"
#include "Utilities/Utilities.h"
#include "Utilities/Singleton.h"

USING_NS_CC;

namespace DestoryColor
{
    enum EScene
    {
        e_Scene_Invalid,
        e_Scene_Home
    };

    class SceneManager : public Ref
    {
    public:
        DECLARE_SINGLETON(SceneManager);

    public:
        void EnterScene(EScene eScene);

        Scene* GetCurrentScene();
        EScene GetCurrentSceneType();

    private:
        Scene* m_currentScene;
        EScene m_currentSceneType;
    };
}

#endif
