#include "GameOverScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* GameOverScreen::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScreen::create();
	scene->addChild(layer);
    return scene;
}

bool GameOverScreen::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    return true;
}

void GameOverScreen::GoToGameScene(Ref *pSender) {
	auto scene = GameScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameOverScreen::GoToMainMenuScene(Ref *pSender) {
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}
