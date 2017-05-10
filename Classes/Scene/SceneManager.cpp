#include "Scene/SceneManager.h"
#include "Scene/SceneMainMenu.h"

namespace DestoryColor
{
    IMPLEMENT_SINGLETON(SceneManager);

    SceneManager::SceneManager()
        : m_currentScene(nullptr)
        , m_currentSceneType(e_Scene_Invalid)
    {
    }

    SceneManager::~SceneManager()
    {
    }

    Scene* SceneManager::GetCurrentScene()
    {
        return m_currentScene;
    }

    EScene SceneManager::GetCurrentSceneType()
    {
        return m_currentSceneType;
    }

    void DestoryColor::SceneManager::EnterScene( EScene eScene )
    {
        NotificationCenter::getInstance()->postNotification("EnterNewScene", this);

        m_currentSceneType = eScene;

        auto director = Director::getInstance();
        Scene* pNewScene  = nullptr;

        switch (eScene)
        {
        case e_Scene_Home:
            pNewScene = SceneMainMenu::create();
            break;
        default:
            break;
        }

        if (!m_currentScene)
        {
            m_currentScene = pNewScene;
            director->runWithScene(pNewScene);
        }
        else
        {
            m_currentScene = pNewScene;
            if (m_currentSceneType == e_Scene_Home)
                director->replaceScene(m_currentScene);
            else
                director->replaceScene(m_currentScene);
        }
    }
}
