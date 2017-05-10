#pragma once
#ifndef __BackGroundLayer_H__
#define __BackGroundLayer_H__

#include "cocos2d.h"

namespace DestoryColor {
    class BackGroundLayer : public cocos2d::Layer
    {
    public:
        BackGroundLayer();
        ~BackGroundLayer();

        
        CREATE_FUNC(BackGroundLayer);

        void onEnter();

        void initBG();

        virtual void update(float delta);

    private:
        cocos2d::Sprite *background_1;
        cocos2d::Sprite *background_2;

        float speedX;
        float posX1;
        float posX2;
    };
}

#endif
