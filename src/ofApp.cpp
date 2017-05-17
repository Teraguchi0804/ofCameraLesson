#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60); //更新を秒間60コマに指定
    ofBackgroundHex(0x000000); //背景色を黒に
    
    gui.setup();
    
    gui.add(circleSize.setup("label", 100, 0, 400)); //("ラベル名", 初期値, 最小値, 最大値)
    
    gui.add(objPosZ.setup("objPosZ", 0, 0, 3000));
    gui.add(objPosY.setup("objPosY", 0, 0, 3000));
    gui.add(objPosX.setup("objPosX", 0, 0, 3000));
    
    
    gui.add(camPosX.setup("camPosX", 0, 0, 3000));
    gui.add(camPosY.setup("camPosY", 700, 0, 3000));
    gui.add(camPosZ.setup("camPosZ", 2700, 0, 3000));
    
    objPosX_new = 0;
    objPosY_new = 0;
    objPosZ_new = 0;
    
    lookat_x = ofGetWidth()/2;
    lookat_y = ofGetHeight()/2;
    
    isAnime = false;
    
    //(id, easing : ofxEasingクラスのインスタンスを渡す, type : easeIn, easeOut, easeInOut, 初期値, 終了値, _dutration : 何[ms]かけて変化するか, _delay : 何[ms]後にtween開始するか)
    tween.setParameters(1,easing_linear, ofxTween::easeIn, 2700, 0, 2500, 0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //カメラ更新系
//    camera.setPosition(camPosX, camPosY, camPosZ);
    camera.setPosition(camPosX, camPosY, tween.getTarget(0));
    camera.lookAt(ofVec3f(lookat_x, lookat_y, 0));
    
//    lookat_x = sin(ofGetElapsedTimef()*0.8)*10;
//    lookat_y = cos(ofGetElapsedTimef()*2.0)*10;
//    
//    camera.lookAt(ofVec3f(lookat_x, lookat_y, 0));
    
    //オブジェクトを円弧運動させる
//    box.setPosition(200 * sin(ofGetElapsedTimef()*2), 0, 200 * cos(ofGetElapsedTimef()*2));
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(isAnime){
        tween.update();
    }
    
    camera.begin(); //カメラスタート
    
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2); //右手座標系に変換
        ofScale(-1, 1, 1); //右手座標系へ変換
    
        ofSetHexColor(0xffffff); // 描画色を設定
    
        box.set(circleSize);
    
    
        box.setPosition(objPosZ_new, objPosY_new, objPosX_new);
//        box.setPosition(objPosZ, objPosY, objPosX);
        box.drawWireframe();
    
    camera.end(); //カメラスタート終了
    
    gui.draw(); //GUIを描画
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a'){
        if(!isAnime){
            isAnime = true; //Tweenアニメーション開始
//            lookat_x = sin(ofGetElapsedTimef()*0.8)*0.2;
//            lookat_y = cos(ofGetElapsedTimef()*2.0)*0.2;
//            
//            camera.lookAt(ofVec3f(0, lookat_y, lookat_x));
        }
    }
    if(key == 's'){
        isAnime = false;
    }
    if(key == 'd'){
       
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
