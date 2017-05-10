//
//  ObstacleLayer.cpp
//  WarGame
//
//  Created by 刘姐 on 2017/5/10.
//
//

#include "ObstacleLayer.h"
#include "Utilities/VisibleRect.h"


namespace DestoryColor {
    ObstacleLayer::ObstacleLayer()
    {
        
    }
    
    ObstacleLayer::~ObstacleLayer()
    {
        
    }
    
    void ObstacleLayer::onEnter()
    {
        Layer::onEnter();
        
        INIT_FSM(Sleep);
        
        this->scheduleUpdate();
    }
    
    void ObstacleLayer::update(float dt)
    {
        GetFsm().Update();
    }
    
    float ObstacleLayer::getSleepTime()
    {
        return CCRANDOM_0_1() * 2.0f;
    }
    
    bool ObstacleLayer::getSwitchSide()
    {
        if(CCRANDOM_0_1() == 1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    
    IMPLEMENT_STATE_BEGIN(ObstacleLayer, Sleep)
    {
        STATE_CONSTRUCTOR_BEGIN
        {
            float sleepTime = getSleepTime();
            runAction(Sequence::create(DelayTime::create(sleepTime), CallFunc::create([this](){
                if (getSwitchSide()) {
                    GetFsm().SwitchState(STATE(CreateUp));
                }
                else{
                    GetFsm().SwitchState(STATE(CreateDown));
                }
                
            }), NULL));
        }
        STATE_CONSTRUCTOR_END
        
        STATE_UPDATE_BEGIN
        {
            
        }
        STATE_UPDATE_END
        
        STATE_DESTRUCTOR_BEGIN
        {
        }
        STATE_DESTRUCTOR_END
    }
    IMPLEMENT_STATE_END
    
    IMPLEMENT_STATE_BEGIN(ObstacleLayer, CreateUp)
    {
        STATE_CONSTRUCTOR_BEGIN
        {
            
            Sprite* sprite = Sprite::create("CloseNormal.png");
            sprite->setPosition(VisibleRect::rightTop());
            this->addChild(sprite);
            sprite->runAction(Sequence::create(MoveTo::create(5.0f, Vec2(0,VisibleRect::height())), CallFunc::create([this,sprite](){
                sprite->removeFromParent();
            }), NULL));
        }
        STATE_CONSTRUCTOR_END
        
        STATE_UPDATE_BEGIN
        {
            GetFsm().SwitchState(STATE(Sleep));
        }
        STATE_UPDATE_END
        
        STATE_DESTRUCTOR_BEGIN
        {
        }
        STATE_DESTRUCTOR_END
    }
    IMPLEMENT_STATE_END
    
    IMPLEMENT_STATE_BEGIN(ObstacleLayer, CreateDown)
    {
        STATE_CONSTRUCTOR_BEGIN
        {
            Sprite* sprite = Sprite::create("CloseNormal.png");
            sprite->setPosition(VisibleRect::rightBottom());
            this->addChild(sprite);
            sprite->runAction(Sequence::create(MoveTo::create(5.0f, Vec2(0,0)), CallFunc::create([this,sprite](){
                sprite->removeFromParent();
            }), NULL));
        }
        STATE_CONSTRUCTOR_END
        
        STATE_UPDATE_BEGIN
        {
            GetFsm().SwitchState(STATE(Sleep));
        }
        STATE_UPDATE_END
        
        STATE_DESTRUCTOR_BEGIN
        {
        }
        STATE_DESTRUCTOR_END
    }
    IMPLEMENT_STATE_END
}
