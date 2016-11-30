# ofxKeyboard

## usage
```cpp
// in header
ofxKeyboard* key;

// in yourApp::setup()
key = ofxKeyboard::get();

// and get button input
if (key->isPressed('A')) { ofLog() << "pressed a"; }
if (key->isPushing('A')) { ofLog() << "pushing a"; }
if (key->isRelease('A')) { ofLog() << "release a"; }

if (key->anyKey()) { ofLog() << "pressed any key"; }

// another type
if (ofxKeyboard::get()->isPressed('A')) { ofLog() << "pressed a"; }
```

## my another ofxAddon
[ofxJoystick](https://github.com/Lacty/ofxJoystick) for GamePad.

## contact
**@Lost206** -twitter    
**akira206@gmail.com** -gmail

## lisence
ofxKeyboard under MIT lisence    
