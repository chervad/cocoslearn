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
