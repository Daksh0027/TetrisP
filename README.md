# Tetris (Raylib C++)

A simple Tetris clone built with C++ and [raylib](https://www.raylib.com/).

## Features

- Classic Tetris gameplay
- Custom colors and fonts
- Sound effects and background music
- High score tracking (saved in `highscore.txt`)
- Mute/unmute button for music

## Requirements

- [raylib](https://www.raylib.com/) (C++ bindings)
- C++14 compatible compiler (e.g., g++, clang++)
- [w64devkit](https://github.com/skeeto/w64devkit) (for Windows, as configured in `.vscode`)

## Building

### Windows (VS Code)

1. Install raylib and w64devkit.
2. Open the project in Visual Studio Code.
3. Press `Ctrl+Shift+B` and select `build debug` or `build release`.

### Manual Build

```sh
# Example for Windows with MinGW
g++ src/*.cpp -o main.exe -I<raylib_include_path> -L<raylib_lib_path> -lraylib -lopengl32 -lgdi32 -lwinmm
```

## Running

- Run the built executable (`main.exe` on Windows).
- Use arrow keys to move and rotate blocks.
- Press the mute button to toggle music.
- High scores are saved in `highscore.txt`.

## File Structure

- `src/` - Source code
- `Font/` - Custom font
- `Sounds/` - Sound effects and music
- `highscore.txt` - High score storage
- `.vscode/` - VS Code configuration

## Credits

- [raylib](https://www.raylib.com/) for graphics and audio
- Font: [monogram.ttf](Font/monogram.ttf)
- Sound effects: in `Sounds/`
