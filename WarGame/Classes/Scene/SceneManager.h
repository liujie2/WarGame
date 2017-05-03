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
        e_Scene_Home,
        e_Scene_Suduku,
        e_Scene_Plot
    };

    class SceneManager : public Ref
    {
    public:
        DECLARE_SINGLETON(SceneManager);

    public:
        void EnterScene(EScene eScene);

        Scene* GetCurrentScene();
        EScene GetCurrentSceneType();

        float GetScaleY();
        void SetScaleY(float scaleValue);

    private:
        Scene* m_currentScene;
        EScene m_currentSceneType;

        float m_scaleY;
    };
}

#endif