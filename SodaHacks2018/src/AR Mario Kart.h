#ifndef AR Mario Kart_H_
#define AR Mario Kart_H_

#include "gameplay.h"

using namespace gameplay;

/**
 * Main game class.
 */
class AR Mario Kart: public Game
{
public:

  form Main_Menu {
    position = 0, 0;
    autoWidth = true;
    autoHeight = true;

  }
    /**
     * Constructor.
     */
    AR Mario Kart();

    /**
     * @see Game::keyEvent
     */
	void keyEvent(Keyboard::KeyEvent evt, int key);

    /**
     * @see Game::touchEvent
     */
    void touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex);

protected:

    /**
     * @see Game::initialize
     */
    void initialize();

    /**
     * @see Game::finalize
     */
    void finalize();

    /**
     * @see Game::update
     */
    void update(float elapsedTime);

    /**
     * @see Game::render
     */
    void render(float elapsedTime);

private:

    /**
     * Draws the scene each frame.
     */
    bool drawScene(Node* node);

    Scene* _scene;
    bool _wireframe;
};

#endif
