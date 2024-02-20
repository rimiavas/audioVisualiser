#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Load audio file
    sound.load("OneLoveByShubh.wav");

    // Create GUI
    gui.setup();
    gui.add(volume.set("volume", 0.5, 0, 1));
    gui.add(decay.set("decay", 0.5, 0, 1));

    // Initialize FFT bands
    fft = new float[500]();
    for (int i = 0; i < 500; i++) {
        fft[i] = 0;
    }

    // Number of FFT bands to analyze
    bands = 450;

	// Petal count
	petalCount = 25 ;

	// Petal size  
	petalSize = 450;

	// Seed count
	seedCount = 150;

	// Seed size
	seedSize = 160;
}

//--------------------------------------------------------------
void ofApp::update(){

    // Update audio system
    ofSoundUpdate();

    // Set volume from GUI
    sound.setVolume(volume);

    // Initialize soundSpectrum array
    soundSpectrum = new float[bands]();  
    // Get audio spectrum data
    soundSpectrum = ofSoundGetSpectrum(bands);

    // Smooth FFT bins 
    for (int i = 0; i < bands; i++) {
        fft[i] *= decay;
        if (fft[i] < soundSpectrum[i]) {
            fft[i] = soundSpectrum[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {

    // Draw GUI
    gui.draw();

    // add text at the bottom of the canvas
    ofSetColor(255, 255, 255); // black
    ofDrawBitmapString("Press Spacebar to play audio", 20, ofGetHeight() - 50 + 20);

    soundSpectrum = ofSoundGetSpectrum(bands);

    // Draw sunflower
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofNoFill();  // Set to no fill
    ofSetLineWidth(2);  // Set line width for outline

    // Draw petals
    // Loop through petals
    for (int i = 0; i < petalCount; i++) {

        float angle = i * 360.0 / petalCount + 10;
        float petalGrowth = soundSpectrum[i % bands] * 50;

        ofPushMatrix();
        ofRotate(angle);

        ofSetColor(255, 255, 0); // yellow
        ofDrawRectangle(-petalSize / 2 + petalGrowth, -petalSize / 2 + petalGrowth, petalSize + petalGrowth, petalSize + petalGrowth);

        ofPopMatrix();

    }

    // Draw seeds
    // Loop through seeds
    for (int i = 0; i < seedCount; i++) {

        // Calculate the rotation angle for this seed
    // Based on the loop index and total number of seeds

        float angle = i * 360.0 / seedCount;
        // Animate size based on audio
        // Get the audio spectrum data for this seed
        // Modulo the spectrum bins so we loop through them
        float seedGrowth = soundSpectrum[i % bands] * 50; 

        ofPushMatrix();
        // Rotate the coordinate system for this seed
        ofRotate(angle);

        ofSetColor(138, 89, 0); // brown
        ofDrawRectangle(0 , 0, seedSize - 10 + seedGrowth, seedSize + seedGrowth);

        ofPopMatrix();

    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') { // play audio when space bar is pressed
        sound.play();
        sound.setLoop(true);
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
