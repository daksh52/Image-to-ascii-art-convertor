#include <stdio.h>
#include <stdlib.h>

const char ASCII_CHARS[] = "$@B%8&WM#*oahkbdpqwmZ0OQLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

// Linked list node for one pixel
typedef struct Pixel {
    unsigned char r, g, b;
    unsigned char gray;
    char ascii;
    struct Pixel* next;
} Pixel;

typedef struct {
    Pixel* head;
    int width;
    int height;
} Image;

// Create a pixel node
Pixel* create_pixel(unsigned char r, unsigned char g, unsigned char b) {
    Pixel* p = (Pixel*)malloc(sizeof(Pixel));
    p->r = r;
    p->g = g;
    p->b = b;
    p->gray = (unsigned char)(0.2126 * r + 0.7152 * g + 0.0722 * b);  // grayscale
    int idx = (p->gray * (sizeof(ASCII_CHARS) - 2)) / 255;
    p->ascii = ASCII_CHARS[idx];
    p->next = NULL;
    return p;
}

// Load PPM (P6) image
Image* load_ppm(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) { perror("File open failed"); return NULL; }

    char format[3];
    int width, height, maxval;
    fscanf(fp, "%2s\n%d %d\n%d\n", format, &width, &height, &maxval);

    if (format[0] != 'P' || format[1] != '6') {
        fprintf(stderr, "Not a valid P6 PPM file.\n");
        fclose(fp);
        return NULL;
    }

    Image* img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->head = NULL;

    Pixel* current = NULL;
    for (int i = 0; i < width * height; i++) {
        unsigned char rgb[3];
        if (fread(rgb, 1, 3, fp) != 3) break;

        Pixel* p = create_pixel(rgb[0], rgb[1], rgb[2]);
        if (!img->head)
            img->head = p;
        else
            current->next = p;
        current = p;
    }

    fclose(fp);
    return img;
}

// Print ASCII art
void print_ascii(Image* img) {
    Pixel* p = img->head;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            if (p) {
                printf("%c", p->ascii);
                p = p->next;
            }
        }
        printf("\n");
    }
}

// Cleanup
void free_image(Image* img) {
    Pixel* p = img->head;
    while (p) {
        Pixel* next = p->next;
        free(p);
        p = next;
    }
    free(img);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }

    Image* img = load_ppm(argv[1]);
    if (!img) return 1;

    print_ascii(img);
    free_image(img);
    return 0;
}
