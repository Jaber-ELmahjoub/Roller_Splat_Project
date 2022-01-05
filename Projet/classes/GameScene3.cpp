#include "GameScene3.h"
#include "PauseScene.h"
#include "GameOver.h"


USING_NS_CC;

Scene* GameScreen3::createScene()
{
    auto scene = Scene::create();

    auto layer = GameScreen3::create();


    scene->addChild(layer);

    return scene;
}


// on "init" you need to initialize your instance
bool GameScreen3::init()
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
            CC_CALLBACK_1(GameScreen3::GoToPauseScene, this));
    pauseItem->setPosition(Point(pauseItem->getContentSize().width -
        (pauseItem->getContentSize().width / 4) + origin.x,
        visibleSize.height - pauseItem->getContentSize().height +
        (pauseItem->getContentSize().width / 4) + origin.y));
    auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);



    auto sprite = Sprite::create("player.png");
    sprite->setPosition(Vec2(144, 27));
    this->addChild(sprite, 1);


    auto lvl3 = Sprite::create("3.png");
    lvl3->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 140));
    this->addChild(lvl3, 1);

    auto obs = Sprite::create("trajet 3.png");
    obs->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(obs, -1);

    auto back = Sprite::create("white.png");
    back->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y -15 ));
    this->addChild(back, -2);


    auto eventListener = EventListenerKeyboard::create();



    eventListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
        int offsetX = 0, offsetY = 0;
        float x = event->getCurrentTarget()->getPositionX();
        float y = event->getCurrentTarget()->getPositionY();

        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            x = event->getCurrentTarget()->getPositionX();
            y = event->getCurrentTarget()->getPositionY();
            if ((x == 336 && y == 27) || (x == 336 && y == 256))
            {
                CCLOG("success");
                offsetX = -113;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x-113, y), 19.0f, Color4F::ORANGE);
                this->addChild(drawNode, -2);
            }
            else if (x == 336 && y == 125)
            {
                CCLOG("success");
                offsetX = -192;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x-192, y), 19.0f, Color4F::ORANGE);
                this->addChild(drawNode, -2);
            }
            else CCLOG("not in position");
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            x = event->getCurrentTarget()->getPositionX();
            y = event->getCurrentTarget()->getPositionY();
            if ((x == 144 && y == 125))
            {
                CCLOG("success");
                offsetX = 192;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x+192, y), 20.0f, Color4F::ORANGE);
                this->addChild(drawNode, -2);
            }
            else if ((x == 223 && y == 256)) {
                CCLOG("success");
                offsetX = 192;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x + 192, y),20.0f, Color4F::ORANGE);
                this->addChild(drawNode, -2);
                auto scene = GameOver::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
            }
            else if (x == 223 && y == 27)
            {
                CCLOG("success");
                offsetX = 113;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x+113, y), 20.0f, Color4F::ORANGE);
                this->addChild(drawNode, -2);
            }
            else CCLOG("not in position");
            break;;

        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            x = event->getCurrentTarget()->getPositionX();
            y = event->getCurrentTarget()->getPositionY();
            if ((x == 144 && y == 27))
            {
                CCLOG("success");
                offsetY = 98;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x, y +98 ), 20.0f, Color4F::ORANGE);
                this->addChild(drawNode, -2);

            }

            else if (x == 223 && y == 27) {
                CCLOG("success");
                offsetY = 229;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x, y+229), 20.0f, Color4F::ORANGE);
                this->addChild(drawNode, -2);
            }
            else if (x == 336 && y == 27) {
                CCLOG("success");
                offsetY = 98;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x, y + 98), 20.0f, Color4F::ORANGE);
                this->addChild(drawNode, -2);
            }
            else CCLOG("not in position");
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            x = event->getCurrentTarget()->getPositionX();
            y = event->getCurrentTarget()->getPositionY();
            if ((x == 336 && y == 125) || (x == 144 && y == 125))
            {
                CCLOG("success");
                offsetY = -98;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x, y -98), 20.0f, Color4F::ORANGE);
                this->addChild(drawNode, -2);
            }
            else if (x == 223 && y == 256) {
                CCLOG("success");
                offsetY = -229;
                drawNode = DrawNode::create();
                drawNode->drawSegment(Vec2(x, y), Vec2(x, y - 229), 20.0f, Color4F::ORANGE);
                this->addChild(drawNode, -2);
            }
            else CCLOG("not in position");
            break;
        }




        auto moveTo = MoveTo::create(0.2, Vec2(event->getCurrentTarget()->getPositionX() + offsetX, event->getCurrentTarget()->getPositionY() + offsetY));
        event->getCurrentTarget()->runAction(moveTo);




    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);


    return true;
}


void GameScreen3::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene = PauseMenu::createScene();
    Director::getInstance()->pushScene(scene);
}
