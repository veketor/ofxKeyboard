
#pragma once
#include "ofMain.h"


// note that, this is singleton class
class ofxKeyboard {
private:
  set<int> pressed_;
  set<int> pushing_;
  set<int> release_;
  
  
  void flashInput(ofEventArgs &args);
  
  void keyPressed(ofKeyEventArgs &event);
  void keyReleased(ofKeyEventArgs &event);
  
  ofxKeyboard();
  
  // make sure there are no copies
  ofxKeyboard(ofxKeyboard const&);
  void operator=(ofxKeyboard const&);
  
public:
  static ofxKeyboard* get();

  // events
  bool isPressed(int key) const;
  bool isPushing(int key) const;
  bool isRelease(int key) const;
  
  // return true when any pressed
  bool anyKey() const;
};
