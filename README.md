# SA-MP Unlock SAA2

**SA-MP Unlock SAA2** is a small patch for **SA-MP** that allows modifications normally blocked by `samp.saa2`. It works by patching the game's memory to unlock restricted features that would otherwise be unavailable.

> ⚠️ **Note:** Currently, it only supports **SA-MP 0.3.7-R3**

## Requirements

* SA-MP 0.3.7-R3
* Visual Studio 2022
* CMake 3.20 or newer
* C++ compiler that supports C++23

## Building

1. Clone the repository:

```bash
git clone https://github.com/mrxenginner/SA-MP-unlock-SAA2.git
cd SA-MP-unlock-SAA2
```

2. Configure the project for **Win32** using CMake:

```cmd
cmake -B build -S . -A "Win32"
```

3. Build the ASI in Release mode:

```cmd
cmake --build build --config Release
```

* The compiled ASI will be located at `build\Release\unlock-saa2.asi`.

## Usage

1. Place the compiled ASI in the **original SA-MP game folder** (where `samp.exe` and `samp.dll` are located).
2. The patch will automatically load and apply the modifications when the game starts.
3. Any files or settings it uses will be loaded from the **game's original folder**, ensuring everything works with your existing installation.
4. When the game closes, the original behavior is restored automatically.
