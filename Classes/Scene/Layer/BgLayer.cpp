#include "BgLayer.h"

USING_NS_CC;

namespace DestoryColor{
	BgLayer::BgLayer()
	{

	}

	BgLayer::~BgLayer()
	{

	}

	void BgLayer::onEnter()
	{
		Layer::onEnter();

		initBG();

		this->scheduleUpdate();
	}

	void BgLayer::initBG()
	{
		m_bgSprite1 = Sprite::create("bg1.png");
		m_bgSprite1->setPosition(Vec2(640, 360));
		this->addChild(m_bgSprite1, 0);

		m_bgSprite2 = Sprite::create("bg2.png");
		m_bgSprite2->setPosition(Vec2(1920, 360));
		this->addChild(m_bgSprite2, 0);
	}

	void BgLayer::update(float delta)
	{
		Layer::update(delta);
		int posX1 = m_bgSprite1->getPositionX();
		int posX2 = m_bgSprite2->getPositionX();

		int iSpeed = 1;

		posX1 -= iSpeed;
		posX2 -= iSpeed;

		Size bgSize = m_bgSprite1->getContentSize();

		if (posX1 <= -bgSize.width / 2)
		{
			posX1 = bgSize.width + bgSize.width / 2;
		}

		if (posX2 <= -bgSize.width / 2)
		{
			posX2 = bgSize.width + bgSize.width / 2;
		}

		m_bgSprite1->setPositionX(posX1);
		m_bgSprite2->setPositionX(posX2);
	}
}