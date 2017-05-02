#include "Scene/SceneBase.h"

namespace DestoryColor
{
    SceneBase::SceneBase()
    {
    }

    SceneBase::~SceneBase()
    {
    }
    
    bool SceneBase::init()
    {
        Scene::init();
        return true;
    }
    
    void SceneBase::update(float dt)
    {
        Scene::update(dt);
    }
}