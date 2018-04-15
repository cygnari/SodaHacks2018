#include "AR Mario Kart.h"

// Declare our game instance
AR Mario Kart game;

AR Mario Kart::AR Mario Kart()
    : _scene(NULL), _wireframe(false)
{
}

void AR Mario Kart::initialize()
{
    // Load game scene from file
    _scene = Scene::load("res/demo.scene");

    // Get the box model and initialize its material parameter values and bindings
    Node* boxNode = _scene->findNode("box");
    Model* boxModel = dynamic_cast<Model*>(boxNode->getDrawable());
    Material* boxMaterial = boxModel->getMaterial();

    // Set the aspect ratio for the scene's camera to match the current resolution
    _scene->getActiveCamera()->setAspectRatio(getAspectRatio());
}

void AR Mario Kart::finalize()
{
    SAFE_RELEASE(_scene);
}

void AR Mario Kart::update(float elapsedTime)
{
    // Rotate model
    _scene->findNode("box")->rotateY(MATH_DEG_TO_RAD((float)elapsedTime / 1000.0f * 180.0f));
}

void AR Mario Kart::render(float elapsedTime)
{
    // Clear the color and depth buffers
    clear(CLEAR_COLOR_DEPTH, Vector4::zero(), 1.0f, 0);

    // Visit all the nodes in the scene for drawing
    _scene->visit(this, &AR Mario Kart::drawScene);
}

bool AR Mario Kart::drawScene(Node* node)
{
    // If the node visited contains a drawable object, draw it
    Drawable* drawable = node->getDrawable(); 
    if (drawable)
        drawable->draw(_wireframe);

    return true;
}

void AR Mario Kart::keyEvent(Keyboard::KeyEvent evt, int key)
{
    if (evt == Keyboard::KEY_PRESS)
    {
        switch (key)
        {
        case Keyboard::KEY_ESCAPE:
            exit();
            break;
        }
    }
}

void AR Mario Kart::touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex)
{
    switch (evt)
    {
    case Touch::TOUCH_PRESS:
        _wireframe = !_wireframe;
        break;
    case Touch::TOUCH_RELEASE:
        break;
    case Touch::TOUCH_MOVE:
        break;
    };
}
