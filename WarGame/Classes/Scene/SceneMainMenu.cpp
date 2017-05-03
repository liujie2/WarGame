#include "Utilities/Utilities.h"
#include "Scene/SceneManager.h"
#include "Scene/SceneMainMenu.h"
#include "Scene/Layer/touchpull.h"


//#include "GameObject/GameObjectManager/GameObjectManager.h"
//#include "GameObject/BlockObject/BlockBase.h"
//#include "Scene/Layers/MainMenuLayer.h"
//#include "GameLogic/MusicLogic/MusicLogic.h"

namespace DestoryColor
{
    SceneMainMenu::SceneMainMenu()
    {
        
    }

    SceneMainMenu::~SceneMainMenu()
    {
    }
    
   

    /*SceneMainMenu* SceneMainMenu::create()
    {
        SceneMainMenu *ret = new SceneMainMenu();
        if (ret && ret->init())
        {
            ret->autorelease();
            return ret;
        }
        else
        {
            CC_SAFE_DELETE(ret);
            return nullptr;
        }
    }*/
    

    void SceneMainMenu::update( float dt )
    {
        SceneBase::update(dt);
        
    }

    void SceneMainMenu::onEnter()
    {
        SceneBase::onEnter();
        auto layer = TouchPull::create();
        this->addChild(layer); 
    }

    void SceneMainMenu::onExit()
    {
        SceneBase::onExit();
    }
}
