
# Hook-Raylib Binding

Enable the robust features of the [Raylib](https://www.raylib.com) game library in the [Hook](https://github.com/fabiosvm/hook-lang) programming language through this binding. Dive into game development, leveraging the best of both worlds.

## Building

To build the binding, you need to have some dependencies installed:

- [Hook](https://github.com/fabiosvm/hook-lang)
- [Raylib](https://www.raylib.com)
- [CMake](https://cmake.org)

After installing the dependencies, you can build the binding using the `build.sh` script:

```
./build.sh
```

## Installing

To install the binding, you can use the `install.sh` script:

```
./install.sh
```

## Usage

If you installed the binding, you can use it in your Hook scripts like this:

```js
import "raylib" as rl;
let { LIGHTGRAY, RAYWHITE } = rl.colors;

rl.InitWindow(800, 450, "raylib [core] example - basic window");

while (!rl.WindowShouldClose()) {
  rl.BeginDrawing();
  rl.ClearBackground(RAYWHITE);
  rl.DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
  rl.EndDrawing();
}

rl.CloseWindow();
```

## Running Examples

To run the examples located in the `examples` directory, type something like this:

```
hook examples/first_window.hook
```

## License

This binding is licensed under the [MIT License](LICENSE).
