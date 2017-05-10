//
//  touchpull.cpp
//  WarGame
//
//  Created by futurebike on 17/5/2.
//
//

#include "BallonLayer.h"
#include "Utilities/GLES-Render.h"
#include "GameLogic/PhysicLogic/PhysicManager.h"

namespace DestoryColor {
	BallonLayer::BallonLayer()
		: m_ballon(nullptr), m_ballonBody(nullptr),m_touch(false),m_edgBody(nullptr)
	{
	}

	BallonLayer::~BallonLayer()
	{

	}

	void BallonLayer::onEnter()
	{
		Layer::onEnter();
        Size s = Director::getInstance()->getVisibleSize();
		m_ballon = Sprite::create("CloseNormal.png");
        m_ballon->setVisible(true);
		m_ballon->setPosition(Vec2(400, 400));
		this->addChild(m_ballon);

        PhysicManager::Singleton().GetWorld();

		b2BodyDef ballonDef;
		ballonDef.type = b2_dynamicBody;
		ballonDef.userData = m_ballon;
		ballonDef.linearDamping = 0.0f;
		ballonDef.position = b2Vec2(m_ballon->getPositionX() / PTM_RATIO, m_ballon->getPositionY() / PTM_RATIO);
		m_ballonBody = PhysicManager::Singleton().GetWorld()->CreateBody(&ballonDef);

		b2CircleShape circle;
        circle.m_radius = 15/PTM_RATIO;
		b2FixtureDef ballonFixtureDef;
		ballonFixtureDef.shape = &circle;
		ballonFixtureDef.density = 0.1f;
		ballonFixtureDef.friction = 0.6f;
		ballonFixtureDef.restitution = 0.6f;

		m_ballonBody->CreateFixture(&ballonFixtureDef);

		//define ground
		b2BodyDef groundDef;
		groundDef.type = b2_staticBody;
		b2PolygonShape groundShape;
		b2FixtureDef groundFixture;
        
        //PhysicsManager::Singleton().GetWorld()->

		groundDef.position = b2Vec2(640 / PTM_RATIO, 0);
		groundShape.SetAsBox(1280/PTM_RATIO, 10/PTM_RATIO);
		groundFixture.shape = &groundShape;
		b2Body* bottomBorder = PhysicManager::Singleton().GetWorld()->CreateBody(&groundDef);
		bottomBorder->CreateFixture(&groundFixture);
        
        //define sky
        b2BodyDef skyBodyDef;
        skyBodyDef.position.Set(0, 0);
        
        b2Body* skyBody = PhysicManager::Singleton().GetWorld()->CreateBody(&skyBodyDef);
        
        b2EdgeShape skyShape;
        
        skyShape.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO));
        
        skyBody->CreateFixture(&skyShape,0);
        
        // 设置多边形
        /*b2Vec2 vertices[3];
        vertices[0].Set(0.0f, 0.0f);
        vertices[1].Set(1.0f, 0.0f);
        vertices[2].Set(0.0f, 1.0f);
        int32 count = 3;
        
        b2PolygonShape polygon;
        b2BodyDef trangleDef;
        b2FixtureDef trangleFixture;
        
        polygon.Set(vertices, count);
        trangleDef.type = b2_dynamicBody;
        trangleDef.position = b2Vec2(500/PTM_RATIO, 500/PTM_RATIO);
        trangleFixture.shape = &polygon;
        trangleFixture.density = 7.8f;
        trangleFixture.restitution = 0.2f;
        trangleFixture.friction = 3.0f;
        b2Body* trangleBody = PhysicManager::Singleton().GetWorld()->CreateBody(&trangleDef);
        trangleBody->CreateFixture(&trangleFixture);
        
        
        // 设置其他形状
        b2Vec2 edgeVertices[4];
        edgeVertices[0].Set(1.7f, 0.0f);
        edgeVertices[1].Set(1.0f, 2.5f);
        edgeVertices[2].Set(0.0f, 0.0f);
        edgeVertices[3].Set(-1.7f, 0.4f);
        int32 edgeCount = 4;
        b2Vec2 v0(1.7f, 0.0f);
        b2Vec2 v1(1.0f, 0.25f);
        b2Vec2 v2(0.0f, 0.0f);
        b2Vec2 v3(-1.7f,0.4f);
        
        b2EdgeShape edge;
        b2PolygonShape edgeShape;
        edgeShape.Set(edgeVertices,edgeCount);
        edge.Set(v1, v2);
        edge.m_hasVertex0 = true;
        edge.m_hasVertex3 = true;
        edge.m_vertex0 = v0;
        edge.m_vertex3 = v3;
        
        b2BodyDef edgeBodyDef;
        b2FixtureDef edgeFixture;
        
        edgeBodyDef.type = b2_dynamicBody;
        edgeBodyDef.position = b2Vec2(600/PTM_RATIO, 400/PTM_RATIO);
        edgeFixture.density = 0.0f;
        edgeFixture.restitution = 0.2f;
        edgeFixture.friction = 1.0f;
        edgeFixture.shape = &edgeShape;
        m_edgBody = PhysicManager::Singleton().GetWorld()->CreateBody(&edgeBodyDef);
        m_edgBody->CreateFixture(&edgeFixture);
        
        b2Vec2 trangleVertices[3];
        trangleVertices[0].Set(1.7f, 0.0f);
        trangleVertices[1].Set(1.0f, 2.5f);
        trangleVertices[2].Set(0.0f, 0.9f);
        int32 trangleCount = 3;
        
        b2PolygonShape trangle2Shape;
        b2BodyDef trangle2Def;
        b2FixtureDef trangle2Fixture;
        
        trangle2Shape.Set(trangleVertices, 3);
        trangle2Def.type = b2_dynamicBody;
        trangle2Def.position = b2Vec2(600/PTM_RATIO,400/PTM_RATIO);
        trangle2Fixture.density = 7.8f;
        trangle2Fixture.restitution = 0.2f;
        trangle2Fixture.friction = 3.0f;
        trangle2Fixture.shape = &trangle2Shape;
        b2Body* trangle2Body = PhysicManager::Singleton().GetWorld()->CreateBody(&trangle2Def);
        trangle2Body->CreateFixture(&trangle2Fixture);*/
        
        this->scheduleUpdate();
        setTouchEnabled(true);
		setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	}

    void BallonLayer::update(float dt)
    {
        int velocityIterations = 8;
        int positionIterations = 3;
        
        PhysicManager::Singleton().GetWorld()->Step(dt, velocityIterations, positionIterations);
        for (auto b = PhysicManager::Singleton().GetWorld()->GetBodyList(); b; b = b->GetNext())
        {
            if (b->GetUserData() != NULL)
            {
                auto myActor = (Sprite*)b->GetUserData();
                myActor->setPosition(Vec2(b->GetPosition().x*PTM_RATIO, b->GetPosition().y*PTM_RATIO));
                myActor->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle())*PTM_RATIO);
                
                if (myActor->getPositionY() < - WORLD_TO_SCREEN(1)
                    || myActor->getPositionX() < - WORLD_TO_SCREEN(1)
                    || myActor->getPositionX() > Director::getInstance()->getVisibleSize().width+WORLD_TO_SCREEN(1))
                {
                    removeChild(myActor);
                    PhysicManager::Singleton().GetWorld()->DestroyBody(b);
                }
                
            }
        }
        
        if(m_touch)
        {
            m_ballonBody->ApplyForce(b2Vec2(0.0f, 30.0f), m_ballonBody->GetWorldCenter(),true);
            //m_ballonBody->ApplyLinearImpulse(b2Vec2(0.0f,30000000000*PTM_RATIO), m_ballonBody->GetWorldCenter(), true);
            //m_ballonBody->SetLinearVelocity(b2Vec2(0.0f, 10*PTM_RATIO));
        }
    }
    
    void BallonLayer::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
    {
        GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION);
        PhysicManager::Singleton().GetWorld()->DrawDebugData();
    }
    
    bool BallonLayer::onTouchBegan(Touch * pTouches, Event * pEvent)
    {
//        float speed = 144.0f;
//        m_ballon->stopAllActions();
//        m_ballon->runAction(MoveTo::create((720- m_ballon->getPositionY())/speed, Vec2(400,720)));
        m_touch = true;
        return true;
    }
    
    void BallonLayer::onTouchEnded(Touch * pTouches, Event * pEvent)
    {
        m_touch = false;
        float speed = 72.0f;
        m_ballon->stopAllActions();
        m_ballon->runAction(MoveTo::create(m_ballon->getPositionY()/speed, Vec2(400,0)));
    }
}
