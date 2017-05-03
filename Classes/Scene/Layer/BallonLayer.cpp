//
//  touchpull.cpp
//  WarGame
//
//  Created by futurebike on 17/5/2.
//
//

#include "BallonLayer.h"

USING_NS_CC;

namespace DestoryColor {
	BallonLayer::BallonLayer()
    : m_ballon(nullptr)
    {
    }
    
	BallonLayer::~BallonLayer()
    {
        
    }
    
	void BallonLayer::onEnter()
    {
        Layer::onEnter();
        
        m_ballon = Sprite::create("CloseNormal.png");
        m_ballon->setPosition(Vec2(400,400));
        this->addChild(m_ballon);
        setTouchEnabled(true);
        setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    }
    
	bool BallonLayer::onTouchBegan(Touch * pTouches, Event * pEvent)
    {
        float speed = 144.0f;
        m_ballon->stopAllActions();
        m_ballon->runAction(MoveTo::create((720-m_ballon->getPositionY())/speed, Vec2(400,720)));
        
        return true;
    }
    
	void BallonLayer::onTouchEnded(Touch * pTouches, Event * pEvent)
    {
        float speed = 72.0f;
        m_ballon->stopAllActions();
        m_ballon->runAction(MoveTo::create(m_ballon->getPositionY()/speed, Vec2(400,0)));
    }
}