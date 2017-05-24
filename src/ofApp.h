#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxFileWatcher.h"
#include "ofxLua.h"
#include "ofxTween.h"


class ofApp : public ofBaseApp, ofxLuaListener {

	public:
        // main
		void setup();
		void update();
		void draw();
    
        void onFileModEvent( ofxFileWatcher::Event& aEvent );

        //input
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        // ofxLua error callback
        void errorReceived(string& msg);
    
        ofCamera camera;
        ofxPanel gui;
        ofxFloatSlider circleSize;
        ofxFloatSlider objPosX;
        ofxFloatSlider objPosY;
        ofxFloatSlider objPosZ;
    
        ofxFloatSlider camPosX;
        ofxFloatSlider camPosY;
        ofxFloatSlider camPosZ;
    
        ofBoxPrimitive box;
    
        ofVec2f pos; //位置情報を格納するための変数
        float angle;
        float lookat_x;
        float lookat_y;
    
        float objPosX_new;
        float objPosY_new;
        float objPosZ_new;
    
        bool isAnime;
    
        ofxTween tween;
        ofxEasingBounce easing_bounce;
        ofxEasingBack   easing_back;
        ofxEasingLinear easing_linear;
        ofxEasingSine   easing_sine;
    
        ofxLua lua;
    
        ofxFileWatcher watcher;
};
