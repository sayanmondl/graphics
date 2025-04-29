### **Graphics Programming using OpenGL**

#### **Running programs in Windows:-**

1. Install MSYS2 from https://www.msys2.org/.

2. Open MSYS2 UCRT terminal.

3. Install `gcc` and `freeglut`.

   ```bash
   pacman -Sy mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-freeglut
   ```

4. Add `C:/msys64/ucrt64/bin` to your user environment variables.

5. Run:

   ```bash
   gcc file.c -lopengl32 -lglu32 -lfreeglut -lm
   ./a.exe
   ```

   `-lm` flag is needed if you have included `<math.h>` in the header.

6. If you are using vs code, copy this [tasks.json](.vscode/tasks.json) file to your `tasks.json` file. If you do not have a `tasks.json` file, create one in `.vscode/` folder, to run the program in one click.

7. If you already have your own `tasks.json`, add these flags inside `args`:

   ```bash
   "-lfreeglut", "-lopengl32", "-lglu32", "-lm"
   ```

<br/>

#### **Running programs in Ubuntu / Debian based Linux:-**

1. Open a terminal window.

2. Install the necessary dependencies:

   ```bash
   sudo apt update
   sudo apt install gcc freeglut3-dev
   ```

3. Write or open your OpenGL C source file (e.g., `file.c`).

4. Compile and run:

   ```bash
   gcc file.c -lGL -lGLU -lglut -lm
   ./a.out
   ```

5. (Optional) For convenience, you can write a Makefile or use a build system like CMake or configure VS Code tasks similarly using the `args`:
   ```json
   "-lGL", "-lGLU", "-lglut", "-lm"
   ```
