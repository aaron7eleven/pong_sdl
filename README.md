# pong_sdl
Built using SDL and C++

Ready to play builds in [Releases](https://github.com/aaron7eleven/pong_sdl/releases) and on [aaron7eleven's itch.io](https://aaron7eleven.itch.io/pong-sdl)

# Installation
1. Clone Repo
2. Download SDL libraries
   1. [SDL](https://github.com/libsdl-org/SDL/releases/tag/release-2.28.4) - SDL2-devel-2.28.4-VC.zip
   2. [SDL_image](https://github.com/libsdl-org/SDL_image/releases/tag/release-2.6.3) - SDL2_image-devel-2.6.3-VC.zip
   3. [SDL_ttf](https://github.com/libsdl-org/SDL_ttf/releases/tag/release-2.20.2) - SDL2_ttf-devel-2.20.2-VC.zip [Github]
   4. [SDL_mixer](https://github.com/libsdl-org/SDL_mixer/releases/tag/release-2.6.3) - SDL2_mixer-devel-2.6.3-VC.zip [Github]
3. Make directories for each SDL library
   1. SDL - C:\SDL
   2. SDL_image - C:\SDL_image
   3. SDL_ttf - C:\SDL_ttf
   4. SDL_mixer - C:\SDL_mixer
4. Extract .zip of each SDL libraries and copy contents into respective SDL library directory
5. Open Visual Studio (I used 2022)

# Features
- Local Multiplayer
- Input Rebinding for UI and Gameplay
- Video Settings: 
  - V-Sync (Default: Enabled)
  - Window Mode
    - Windowed (1280x720) (Default)
    - Fullscreen
- Audio Settings: Sound FX
- FPS Counter

# Known Issues
- Potential memory leak
  - Not freeing resources
- Ball/Paddle Collision is questionable

# Goals
- Practice C++
- Learn and practice game engine development
- Make a retro game
- Have fun! 😃

Feel free to reach out to me at aaron7eleven.game.dev at gmail.com for any questions or issues. 😃
