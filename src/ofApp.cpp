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
    gui.add(camPosY.setup("camPosY", 375, 0, 3000));
    gui.add(camPosZ.setup("camPosZ", 0, 0, 3000));
    
    
//    box.set( ofGetWidth()*1.25 );
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(pos.x > 0){
       pos.x += 4.0;
    }else if(pos.x < 50){
        pos.x -= 4.0;
    }
    
    pos.y += 3.0;
    
    
    
    //カメラ更新系
    camera.setPosition(camPosX, camPosY, camPosZ);
    camera.lookAt(ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0));
//    camera.setPosition(200 * sin(ofGetElapsedTimef()*2), 375, 200 * cos(ofGetElapsedTimef()*2));
    
    angle += 10;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    camera.begin(); //カメラスタート
        
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2); //右手座標系に変換
        ofScale(-1, 1, 1); //右手座標系へ変換
    
        ofSetHexColor(0xffffff); // 描画色を設定
    
        box.set(circleSize);
        box.setPosition(objPosZ, objPosY, objPosX);
        box.drawWireframe();
    
    camera.end(); //カメラスタート終了
    
    gui.draw(); //GUIを描画
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
