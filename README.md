# ofxKeyboard

## usage
```cpp
// in header
ofxKeyboard* key;

// in yourApp::setup()
key = ofxKeyboard::get();

// and get button input
if (key.isPressed('A')) { ofLog() << "pressed a"; }
if (key.isPushing('A')) { ofLog() << "pushing a"; }
if (key.isRelease('A')) { ofLog() << "release a"; }

// another type
if (ofxKeyboard::get()->isPressed('A')) { ofLog() << "pressed a"; }
```

## contact
**@Lost206** -twitter    
**akira206@gmail.com** -gmail

## lisence
ofxKeyboard under MIT lisence    
