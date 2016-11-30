
#include "ofxKeyboard.h"


ofxKeyboard::ofxKeyboard() {
  ofAddListener(ofEvents().update     , this, &ofxKeyboard::flashInput);
  ofAddListener(ofEvents().keyPressed , this, &ofxKeyboard::keyPressed);
  ofAddListener(ofEvents().keyReleased, this, &ofxKeyboard::keyReleased);
}

ofxKeyboard* ofxKeyboard::get() {
  static ofxKeyboard instance;
  return &instance;
}

void ofxKeyboard::flashInput(ofEventArgs &args) {
  pressed_.clear();
  release_.clear();
}

void ofxKeyboard::keyPressed(ofKeyEventArgs &event) {
  int key = event.keycode;
  
  if (pushing_.find(key) == pushing_.end()) {
    pressed_.insert(key);
    pushing_.insert(key);
  }
}
void ofxKeyboard::keyReleased(ofKeyEventArgs &event) {
  int key = event.keycode;
  
  release_.insert(key);
  pushing_.erase(pushing_.find(key));
}

bool ofxKeyboard::isPressed(int key) const {
  if(pressed_.find(key) != pressed_.end()) {
    return true;
  }
  return false;
}

bool ofxKeyboard::isPushing(int key) const {
  if (pushing_.find(key) != pushing_.end()) {
    return true;
  }
  return false;
}

bool ofxKeyboard::isRelease(int key) const {
  if (release_.find(key) != release_.end()) {
    return true;
  }
  return false;
}

bool ofxKeyboard::anyKey() const {
  if (pressed_.size()) {
    return true;
  }
  return false;
}
