//
//  touchpull.h
//  WarGame
//
//  Created by futurebike on 17/5/2.
//
//

#ifndef __BallonLayer_H__
#define __BallonLayer_H__
#include "cocos2d.h"
#include "Box2D/Box2D.h"
using namespace cocos2d;

#define PTM_RATIO 32
#define WORLD_TO_SCREEN(n) ((n) * PTM_RATIO)

namespace DestoryColor
{
    class BallonLayer : public Layer{
    public:
        BallonLayer();
        virtual ~BallonLayer();
        
        void onEnter();
        
        CREATE_FUNC(BallonLayer);
        
        void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags);
        
        virtual void update(float dt);
        virtual bool onTouchBegan(Touch * pTouches, Event * pEvent);
        virtual void onTouchEnded(Touch * pTouches, Event * pEvent);
    private:
        Sprite* m_ballon;
		b2Body* m_ballonBody;
        b2Body* m_edgBody;
        bool m_touch;
    };
}

#endif /* touchpull_h */
