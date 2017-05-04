#include "BackGroundLayer.h"

USING_NS_CC;

namespace DestoryColor {
    BackGroundLayer::BackGroundLayer():background_1(nullptr),background_2(nullptr),speedX(1),posX1(0),posX2(0)
    {}
    BackGroundLayer::~BackGroundLayer()
    {}

    void BackGroundLayer::onEnter()
    {
        Layer::onEnter();

        initBG();

        this->scheduleUpdate();
    }

    void BackGroundLayer::initBG()
    {
        background_1 = Sprite::create("bg1.png");
        background_1->setPosition(Vec2(640, 360));
        this->addChild(background_1);

        background_2 = Sprite::create("bg2.png");
        background_2->setPosition(Vec2(1920, 360));
        this->addChild(background_2);
    }

    void BackGroundLayer::update(float delta)
    {
        posX1 = background_1->getPositionX();
        posX2 = background_2->getPositionX();

        posX1 -= speedX;
        posX2 -= speedX;

        background_1->setPositionX(posX1);
        background_2->setPositionX(posX2);

        if (fabs(posX1) == this->background_1->getContentSize().height)
        {
            background_1->setPositionX(background_2->getPositionX() + background_2->getContentSize().width);

            Sprite* t = background_1;
            background_1 = background_2;
            background_2 = t;
        }
    }
}