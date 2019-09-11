#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"

class GameOverScreen : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(GameOverScreen);

	void GoToGameScene(Ref *pSender);
	void GoToMainMenuScene(Ref *pSender);
};

#endif // __GAMEOVER_SCENE_H__
