#ifndef _ofx_buttons_
#define _ofx_buttons_


// making all the buttons include ! yay

#define BUTTONS_COLOR_HIGHLIGHT		0x99ff99		// bright green
#define BUTTONS_COLOR_DARK          0x999999
#define BUTTONS_COLOR_MEDIUM        0x77dd77        //0x66cc66
#define BUTTONS_COLOR_LIGHT         0xdddddd

// Fix OF version differences
#if OF_VERSION_MAJOR <= 0 && OF_VERSION_MINOR <= 8
#define		ofDrawRectangle(a,b,c,d)	ofRect(a,b,c,d)
#define		ofDrawEllipse(a,b,c,d)		ofEllipse(a,b,c,d)
#define		ofDrawLine(a,b,c,d)			ofLine(a,b,c,d)
#endif

#include "ofMain.h"
#include "SimpleButton.h"

// list
#include "ListItem.h"
#include "ToggleItem.h"
#include "SliderItem.h"
#include "FlashItem.h"
#include "SelectionItem.h"
//
#include "ButtonPanel.h"

// manager
#include "ButtonManager.h"



#endif

