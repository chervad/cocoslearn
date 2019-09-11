#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "PauseScene.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene* GameScreen::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScreen::create();
	scene->addChild(layer);
    return scene;
}

bool GameScreen::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	auto pauseItem = MenuItemImage::create("GameScreen/Pause_Button.png"
										 , "GameScreen/Pause_Button(Click).png"
										 , CC_CALLBACK_1(GameScreen::GoToPauseScene, this));
	auto widthPauseItem = pauseItem->getContentSize().width;
	auto heightPauseItem = pauseItem->getContentSize().height;
	auto pointX = (0.75 * widthPauseItem) + origin.x;
	auto pointY = visibleSize.height - (0.75 * heightPauseItem) + origin.y;
	pauseItem->setPosition(Point(pointX, pointY));

	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

    return true;
}

void GameScreen::GoToPauseScene(Ref *pSender) {
	auto scene = PauseMenu::createScene();
	Director::getInstance()->pushScene(scene);
}
 
void GameScreen::GoToGameOverScene(Ref *pSender) {
	auto scene = GameOverScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}
