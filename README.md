# Image-to-ascii-art-convertor:
This c program reads a PPM image file (P6 format), converts each pixel to grayscale, maps each pixel to an ASCII character (based on brightness), and prints the image as ASCII art.
An Image to ASCII Art Converter in C is a fun and educational project that involves reading an image file, converting its pixel values to grayscale, and then mapping those values to ASCII characters to generate a textual representation of the image. Here's a complete overview of what the project involves:

📌 Project Title:
Image to ASCII Art Converter in C.

🎯 Objective:
To convert an image (typically in a simple format like PGM or BMP) into ASCII art by:

1:Reading the image file and extracting pixel values.
2:Converting the image to grayscale if it's in color.
3:Mapping grayscale values to ASCII characters based on brightness.
4:Printing or saving the ASCII art to the console or a text file.

🧠 Concept Behind ASCII Art:
An image is made of pixels with color or grayscale intensity.
In ASCII art, each pixel is represented by a character from a predefined ASCII character set, where:
Bright characters (' ', '.') represent lighter pixels.
Dark characters ('#', '@') represent darker pixels.
Example ASCII scale (from lightest to darkest):

🧱 Steps Involved:

1. Choose an Image Format:
   
Start with an easy format like PGM (Portable GrayMap) or BMP because they have simpler headers.

You can also use external libraries (like stb_image.h or libbmp) to load images.

2. Read the Image File:
   
Read image metadata (width, height, and pixel data).

If using BMP, skip the header and parse the pixels.

For PGM (ASCII P2 or binary P5), it's easier as they are grayscale by design.

3. Convert RGB to Grayscale (if using color images) using this formula:

gray = 0.299 * R + 0.587 * G + 0.114 * B 

4. Map Pixels to ASCII Characters:
   
Normalize grayscale value (0–255) to the index of your ASCII character set.

5. Print or Save the ASCII Art:
   
Loop over all pixels and print the corresponding ASCII character.
You can print to console or write to a text file.

🛠️ Tools & Libraries

Language: C

Optional Libraries:

stb_image.h (for reading JPG, PNG, etc.)

libbmp (for BMP)

Compiler: gcc/clang

Text Editor/IDE: VS Code, Code::Blocks, etc.

📈 Learning Outcomes

1.Understanding image formats.

2.File handling in C.

3.Image processing basics (grayscale conversion).

4.Mapping logic (intensity → ASCII).

5.Console/text file output.

🧩 Possible Extensions

1.Support for color images.

2.Use dynamic image loading (e.g., using stb_image.h).

3.Create a GUI version using libraries like GTK or SDL.

4.Adjust brightness/contrast.

5.Resize image to fit screen width.

