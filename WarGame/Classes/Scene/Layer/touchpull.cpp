//
//  touchpull.cpp
//  WarGame
//
//  Created by futurebike on 17/5/2.
//
//

#include "touchpull.h"

USING_NS_CC;

namespace DestoryColor {
    TouchPull::TouchPull()
    : m_pull(nullptr)
    {
    }
    
    TouchPull::~TouchPull()
    {
        
    }
    
    void TouchPull::onEnter()
    {
        Layer::onEnter();
        
        m_pull = Sprite::create("CloseNormal.png");
        m_pull->setPosition(Vec2(400,400));
        this->addChild(m_pull);
        setTouchEnabled(true);
        setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    }
    
    bool TouchPull::onTouchBegan(Touch * pTouches, Event * pEvent)
    {
        float speed = 144.0f;
        m_pull->stopAllActions();
        m_pull->runAction(MoveTo::create((720-m_pull->getPositionY())/speed, Vec2(400,720)));
        
        return true;
    }
    
    void TouchPull::onTouchEnded(Touch * pTouches, Event * pEvent)
    {
        float speed = 72.0f;
        m_pull->stopAllActions();
        m_pull->runAction(MoveTo::create(m_pull->getPositionY()/speed, Vec2(400,0)));
    }
}