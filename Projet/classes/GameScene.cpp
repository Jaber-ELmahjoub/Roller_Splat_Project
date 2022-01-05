#include "GameScene.h"
#include "GameScene2.h"
#include "PauseScene.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* GameScreen::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScreen::create();
    scene->addChild(layer);
    return scene;
}


// on "init" you need to initialize your instance
bool GameScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto pauseItem =
        MenuItemImage::create("Pause2.png",
            "Pause2.png",
            CC_CALLBACK_1(GameScreen::GoToPauseScene, this));
    pauseItem->setPosition(Point(pauseItem->getContentSize().width -
        (pauseItem->getContentSize().width / 4) + origin.x,
        visibleSize.height - pauseItem->getContentSize().height +
        (pauseItem->getContentSize().width / 4) + origin.y));
    auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    auto sprite = Sprite::create("player.png");
    sprite->setPosition(Vec2(155, 28)); 
    this->addChild(sprite, 1);


    auto lvl1 = Sprite::create("1.png");
    lvl1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 140));
    this->addChild(lvl1, 1);


    auto obs = Sprite::create("trajet 1.png");
    obs->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(obs, -1);



    auto back = Sprite::create("white.png");
    back->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y -50));
    this->addChild(back, -2);


    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
        int offsetX = 0, offsetY = 0;
        float x, y;

        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            x = event->getCurrentTarget()->getPositionX();
            y = event->getCurrentTarget()->getPositionY();
            if ((x == 327 && y == 202))
            {
                CCLOG("success");
                offsetX = -172;
            }
            else CCLOG("not in position");
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            x = event->getCurrentTarget()->getPositionX();
            y = event->getCurrentTarget()->getPositionY();
            if ((x == 155 && y == 202))
            {
                CCLOG("success");
                offsetX = 172;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x + 172, y), 19.0f, Color4F::GREEN);
                this->addChild(drawNode,-2);
            }
            else;
            CCLOG("not in position");
            break;;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            x = event->getCurrentTarget()->getPositionX();
            y = event->getCurrentTarget()->getPositionY();
            if ((x == 327 && y == 28) || (x == 155 && y == 28))
            {
                CCLOG("success");
                offsetY = 174;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x, y + 174), 19.0f, Color4F::GREEN);
                this->addChild(drawNode ,- 2);
            }
            else CCLOG("not in position");
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            x = event->getCurrentTarget()->getPositionX();
            y = event->getCurrentTarget()->getPositionY();
            if ( (x == 155 && y == 202))
            {
                CCLOG("success");
                offsetY = -174;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x, y - 174), 19.0f, Color4F::GREEN);
                this->addChild(drawNode, -2);

            }
            else if ((x == 327 && y == 202)) {
                CCLOG("success");
                offsetY = -174;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x, y - 174), 19.0f, Color4F::GREEN);
                this->addChild(drawNode, -2);
                auto scene = GameScreen2::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
            }
            else CCLOG("not in position");
        
        }
        auto moveTo = MoveTo::create(0.2, Vec2(event->getCurrentTarget()->getPositionX() + offsetX, event->getCurrentTarget()->getPositionY() + offsetY));
        event->getCurrentTarget()->runAction(moveTo);
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);

    
    return true;

}


void GameScreen::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene = PauseMenu::createScene();
    Director::getInstance()->pushScene(scene);
}

