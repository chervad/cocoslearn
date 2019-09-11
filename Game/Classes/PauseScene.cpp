#include "PauseScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* PauseMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = PauseMenu::create();
	scene->addChild(layer);
    return scene;
}

bool PauseMenu::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    return true;
}

void PauseMenu::Resume(Ref *pSender) {
	Director::getInstance()->popScene();
}

void PauseMenu::GoToMainMenuScene(Ref *pSender) {
	auto scene = MainMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

void PauseMenu::Retry(Ref *pSender) {
	auto scene = GameScreen::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}
