#ifndef __APPMACROS_H__
#define __APPMACROS_H__

/* For demonstrating using one design resolution to match different resources,
   or one resource to match different design resolutions.

   [Situation 1] Using one design resolution to match different resources.
     Please look into Appdelegate::applicationDidFinishLaunching.
     We check current device frame size to decide which resource need to be selected.
     So if you want to test this situation which said in title '[Situation 1]',
     you should change ios simulator to different device(e.g. iphone, iphone-retina3.5, iphone-retina4.0, ipad, ipad-retina),
     or change the window size in "proj.XXX/main.cpp" by "CCEGLView::setFrameSize" if you are using win32 or linux plaform
     and modify "proj.mac/AppController.mm" by changing the window rectangle.

   [Situation 2] Using one resource to match different design resolutions.
     The coordinates in your codes is based on your current design resolution rather than resource size.
     Therefore, your design resolution could be very large and your resource size could be small.
     To test this, just define the marco 'TARGET_DESIGN_RESOLUTION_SIZE' to 'DESIGN_RESOLUTION_2048X1536'
     and open iphone simulator or create a window of 480x320 size.

   [Note] Normally, developer just need to define one design resolution(e.g. 960x640) with one or more resources.
 */

#include "cocos2d.h"

#define DESIGN_RESOLUTION_480X320    0
#define DESIGN_RESOLUTION_1024X768   1
#define DESIGN_RESOLUTION_2048X1536  2

typedef struct tagResource
{
    cocos2d::CCSize size;
    char directory[100];
}Resource;

static Resource smallResource  =  { cocos2d::CCSizeMake(480, 320),   "iphone" };
static Resource mediumResource =  { cocos2d::CCSizeMake(1024, 768),  "ipad"   };
static Resource largeResource  =  { cocos2d::CCSizeMake(2048, 1536), "ipadhd" };

static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(640, 1136);

// The font size 24 is designed for small resolution, so we should change it to fit for current design resolution
#define TITLE_FONT_SIZE  (cocos2d::CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width / smallResource.size.width * 24)


// These are the switchers to debug game
//#define DEBUG_SKIP_MAIN_MENU
//#define DEBUG_HIDE_TEXT
//#define DEBUG_NO_MONSTER
//#define DEBUG_NO_GENERAL
//#define DEBUG_NO_GPE
//#define DEBUG_NO_TITLE
//#define DEBUG_NO_BACK_TO_MAIN_MENU
//#define DEBUG_FAKE_FIREBALL_INPUT
#define DEBUG_DRAW_DEBUG_SHAPE
//#define DEBUG_NO_UI
//#define ONLINE_MODE
//#define TEST_BASIC

// Gameplay

enum EMoveDirection
{
	eMD_Top,
	eMD_Right,
	eMD_Bottom,
	eMD_Left,

	eMD_Count,
	eMD_Invalid
};

enum EInputStatus
{
	eIS_Began,
	eIS_Move,
	eIS_End,
	eIS_Cancled,

	eIS_Count,
	eIS_Invalid
};

#endif /* __APPMACROS_H__ */
