#Todo

## Must do's
sfx on goal
proper freeing of resources
buildable release from git
distributable build to play

## Bugs & Known issues
Ball moving inside of paddle
    Something wrong with ball/paddle collision
        Handle ball moving into paddle but not paddle into ball

## List of everything
### Gameplay 
Proper ball paddle collision: Ball launch angle and speed affected by where hit on paddle
Ball Launch Angle Detection: Make sure it doesn't exceed a maximum

# Done
sfx with UI and gameplay
Win conditions in game
Win Menu
Menu Navigation

Finished Menu Options

### Menu Options (Done)
#### Video (Done)
(Done) V-Sync
(Done) Windowed/Full Screen
(Skip) Resolution
(Skip) Frame Rate Cap

#### Audio (Done)
(Skip) Main Volume
(Done) Sound FX Volume
(Skip) Music Volume

#### Controls (Done)
(Done) Input Rebinding

##### Mouse (Skip)
Sensetivity

##### UI (Done)
- Select
- Back
- Up
- Down
- Right
- Left

##### Gameplay (Done)
- Left Paddle
  - Up/Down
- Right Paddle
  - Up/Down

# Skip
Render vertical walls with texture
Skipping gameplay customization

#### Gameplay Customization
##### Paddle
Color
Initial Position
Speed
Size
image/texture

##### Ball
Color
Initial Position
Speed
Size
image/texture

###### Respawn
position
speed
direction

##### Midline
Size
Color
image/texture

##### Walls
Color
Initial Position
Size
image/texture

##### Goal 
Color
Initial Position
Size
image/texture

Pause Menu
Refactor into sub components to reuse (basis for engine)
Refactor into Entity and Components (basis for EC engine)
Save/Load App Settings
Save/Load Input Settings
Lose audio when changing video settings
    Can't reload SDL_Init() twice
