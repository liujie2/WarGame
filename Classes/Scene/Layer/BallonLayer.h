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

using namespace cocos2d;

namespace DestoryColor
{
    class BallonLayer : public Layer{
    public:
		BallonLayer();
		virtual ~BallonLayer();
        
        void onEnter();
        
		CREATE_FUNC(BallonLayer);
        
        virtual bool onTouchBegan(Touch * pTouches, Event * pEvent);
        virtual void onTouchEnded(Touch * pTouches, Event * pEvent);
    private:
        Sprite* m_ballon;
    };
}

#endif /* touchpull_h */
