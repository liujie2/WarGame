#include "../CommonHeaders.h"

#include "VisibleRect.h"

Rect VisibleRect::s_visibleRect;

void VisibleRect::lazyInit()
{
    if (s_visibleRect.size.width == 0.0f && s_visibleRect.size.height == 0.0f)
    {
        s_visibleRect.size = Director::getInstance()->getVisibleSize();
        s_visibleRect.origin = Director::getInstance()->getVisibleOrigin();
    }
}

Rect VisibleRect::getVisibleRect()
{
    lazyInit();
    return Rect(s_visibleRect.origin.x, s_visibleRect.origin.y, s_visibleRect.size.width, s_visibleRect.size.height);
}

Vec2 VisibleRect::left()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

Vec2 VisibleRect::right()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

Vec2 VisibleRect::top()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height);
}

Vec2 VisibleRect::bottom()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y);
}

Vec2 VisibleRect::center()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

Vec2 VisibleRect::leftTop()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height);
}

Vec2 VisibleRect::rightTop()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height);
}

Vec2 VisibleRect::leftBottom()
{
    lazyInit();
    return s_visibleRect.origin;
}

Vec2 VisibleRect::rightBottom()
{
    lazyInit();
    return Vec2(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y);
}

float VisibleRect::width()
{
    return (right() - left()).x;
}

float VisibleRect::height()
{
    return (top() - bottom()).y;
}