
#include "ofxKeyboard.h"


ofxKeyboard::ofxKeyboard() {
  ofAddListener(ofEvents().update     , this, &ofxKeyboard::flashInput);
  ofAddListener(ofEvents().keyPressed , this, &ofxKeyboard::keyPressed);
  ofAddListener(ofEvents().keyReleased, this, &ofxKeyboard::keyReleased);
  ofAddListener(ofEvents().exit, this, &ofxKeyboard::clearOnExit);
}

ofxKeyboard* ofxKeyboard::get() {
  static ofxKeyboard instance;
  return &instance;
}

void ofxKeyboard::flashInput(ofEventArgs &args)
{
	pressed_.clear();
	release_.clear();
	//Check keyTimePressed_ map and delete released keys
	map<int, timeInfo>::const_iterator it = keyTimePressed_.begin();
	while ( it != keyTimePressed_.end())
	{
		if (it->second.released)
		{
			it = keyTimePressed_.erase(it);
		}
		else
		{
			it++;
		}
	}
}


void ofxKeyboard::clearOnExit(ofEventArgs & args)
{
	flushKeys();
}

void ofxKeyboard::keyPressed(ofKeyEventArgs &event) 
{
	int key = event.key;

	if (pushing_.find(key) == pushing_.end()) 
	{
		pressed_.insert(key);
		pushing_.insert(key);
		timeInfo keyTimeInfo;
		keyTimeInfo.pressedTime = ofGetElapsedTimeMillis();
		keyTimeInfo.releasedTime = 0;
		keyTimeInfo.released = false;
		keyTimePressed_.insert(std::pair<int, timeInfo>(key, keyTimeInfo));
	}
}
void ofxKeyboard::keyReleased(ofKeyEventArgs &event) {
  //int key = event.keycode;
  int key = event.key;
  
  release_.insert(key);
  pushing_.erase(pushing_.find(key));
  std::map<int, timeInfo>::iterator it = keyTimePressed_.find(key);
  if (it != keyTimePressed_.end())
  {
	  it->second.releasedTime = ofGetElapsedTimeMillis();
	  it->second.released = true;
  }

}

bool ofxKeyboard::isPressed(int key) const {
  if(pressed_.find(key) != pressed_.end()) {
    return true;
  }
  return false;
}

uint64_t ofxKeyboard::getTimePressed(int key)
{
	std::map<int, timeInfo>::iterator it = keyTimePressed_.find(key);
	if (it != keyTimePressed_.end())
	{
		return it->second.timePressedMillis();
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

bool ofxKeyboard::anyKeyPushing() const
{
	if (pushing_.size()) {
		return true;
	}
	return false;
}

void ofxKeyboard::flushKeys()
{
	pressed_.clear();
	pushing_.clear();
	release_.clear();
	keyTimePressed_.clear();
}
