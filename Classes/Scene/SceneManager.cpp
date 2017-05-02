#include "Scene/SceneManager.h"
#include "Scene/SceneMainMenu.h"
#include "SimpleAudioEngine.h"
//#include "GameLogic/CharacterLogic/MainCharacter.h"
//#include "Scene/SceneSudoku.h"
//#include "GameLogic/ItemLogic/ItemLogic.h"
//#include "Scene/ScenePlot.h"
//#include "GameLogic/PlotLogic/PlotLogic.h"

namespace DestoryColor
{
    IMPLEMENT_SINGLETON(SceneManager);

    SceneManager::SceneManager()
        : m_currentScene(nullptr)
        , m_currentSceneType(e_Scene_Invalid)
        , m_scaleY(1.0f)
    {
        //MainCharacter::CreateSingleton();
        
        //for (unsigned int i = 1; i < 66; ++i) {
        //    ItemLogic::Singleton().AddItem(i);
        //}
    }

    SceneManager::~SceneManager()
    {
        //MainCharacter::DestroySingleton();
    }

    Scene* SceneManager::GetCurrentScene()
    {
        return m_currentScene;
    }

    EScene SceneManager::GetCurrentSceneType()
    {
        return m_currentSceneType;
    }

    float SceneManager::GetScaleY()
    {
        return m_scaleY;
    }

    void SceneManager::SetScaleY( float scaleValue )
    {
        m_scaleY = scaleValue;
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
            {
                /*if (PlotLogic::Singleton().NeedShowScenePlot())
                    pNewScene = ScenePlot::create();
                else*/
                    pNewScene = SceneMainMenu::create();
            }
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