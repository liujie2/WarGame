#include "Utilities/Utilities.h"
#include "Scene/SceneManager.h"
#include "Scene/SceneMainMenu.h"
#include "Scene/Layer/BallonLayer.h"
#include "Scene/Layer/BackGroundLayer.h"
#include "Scene/Layer/ObstacleLayer.h"

namespace DestoryColor
{
	SceneMainMenu::SceneMainMenu() 
    {
        
    }

    SceneMainMenu::~SceneMainMenu()
    {
    }

    void SceneMainMenu::update( float dt )
    {
        SceneBase::update(dt);
    }

    void SceneMainMenu::onEnter()
    {
        SceneBase::onEnter();

		// defined ballon
        auto ballon = BallonLayer::create();
        this->addChild(ballon,2); 
		
        auto obstacle = ObstacleLayer::create();
        this->addChild(obstacle, 2);
        
        auto bg = BackGroundLayer::create();
        this->addChild(bg,1);
    }

    void SceneMainMenu::onExit()
    {
        SceneBase::onExit();
    }
}
