#ifndef __BgScene_H__
#define __BgScene_H__

#include "cocos2d.h"

using namespace cocos2d;

namespace DestoryColor{
	class BgLayer : public Layer{
	public:
		BgLayer();
		~BgLayer();

		void onEnter();

		CREATE_FUNC(BgLayer);

	public:
		Size visibleSize;
		Vec2 origin;

		virtual void update(float delta);

	public:
		Sprite* m_bgSprite1;
		Sprite* m_bgSprite2;
		void initBG();
	};
}
#endif