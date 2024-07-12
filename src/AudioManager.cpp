#include "headers/AudioManager.h"

AudioManager::AudioManager() {}

AudioManager::~AudioManager() {
    stopMusic();
}

bool AudioManager::loadMusic(const std::string& filename) {
    if (!music.openFromFile(filename)) {
        std::cerr << "Error loading audio file: " << filename << std::endl;
        return false;
    }
    return true;
}

void AudioManager::playMusic() {
    music.play();
}

void AudioManager::stopMusic() {
    music.stop();
}

void AudioManager::setMusicLoop(bool loop) {
    music.setLoop(loop);
}
