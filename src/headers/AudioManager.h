#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    bool loadMusic(const std::string& filename);
    void playMusic();
    void stopMusic();
    void setMusicLoop(bool loop);

private:
    sf::Music music;
};

#endif // AUDIOMANAGER_H
