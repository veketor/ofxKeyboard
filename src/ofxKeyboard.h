#pragma once
#include "ofMain.h"


// note that, this is singleton class
class ofxKeyboard {
private:
	struct timeInfo
	{
		uint64_t pressedTime;
		uint64_t releasedTime;
		bool released;
		uint64_t timePressedMillis()
		{
			if (releasedTime >0)
			{
				return releasedTime - pressedTime;
			}
			else
			{
				return ofGetElapsedTimeMillis() - pressedTime;
			}
		}
	};
	set<int> pressed_;
	set<int> pushing_;
	set<int> release_;
	map<int, timeInfo> keyTimePressed_;

	void flashInput(ofEventArgs &args);
	void keyPressed(ofKeyEventArgs &event);
	void keyReleased(ofKeyEventArgs &event);
	void clearOnExit(ofEventArgs &args);
	
	ofxKeyboard();
	
	// make sure there are no copies
	ofxKeyboard(ofxKeyboard const&);
	void operator=(ofxKeyboard const&);
  
public:
  static ofxKeyboard* get();

  // events
  bool isPressed(int key) const;
  uint64_t getTimePressed(int key);
  bool isPushing(int key) const;
  bool isRelease(int key) const;
  
  // return true when any pressed
  bool anyKey() const;
  // return true when any is been pushing
  bool anyKeyPushing() const;
  //clear al buffers
  void flushKeys();
};
