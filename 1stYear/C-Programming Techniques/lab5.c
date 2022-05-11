#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct aux
{
    uint8_t ei_mag0;
    uint8_t ei_mag1;
    uint8_t ei_mag2;
    uint8_t ei_mag3;
    uint8_t ei_class;
    uint8_t ei_data;
    uint8_t ei_version;
    uint8_t ei_osabi;
};
typedef struct aux ELF;
int main(int argc, char **argv)
{
    FILE *f;
    ELF elf;
    f = fopen("tf", "rb");
    if (f == NULL)
    {
        printf("ERROR OPEN\n");
        exit(1);
    }
    fread(&elf, 1, sizeof(ELF), f);
    printf("b0=%d b1=%d b2=%d b3=%d b4=%d b5=%d b6=%d b7=%d\n", elf.ei_mag0, elf.ei_mag1, elf.ei_mag2, elf.ei_mag3, elf.ei_class, elf.ei_data, elf.ei_version, elf.ei_osabi);
    if ((elf.ei_mag0 == 0x7F) && (elf.ei_mag1 == 'E') && (elf.ei_mag2 == 'L') && (elf.ei_mag3 == 'F'))
    {
        printf("it if an elf file\n");
    }
    if (elf.ei_class == 1)
    {
        printf("32 bit format\n");
    }
    else if (elf.ei_class == 2)
        printf("64 bit format\n");
    if (elf.ei_data == 1)
    {
        printf("little endianess\n");
    }
    else if (elf.ei_data == 2)
        printf("big endianess\n");
    if (elf.ei_version == 1)
        printf("current version\n");
    if (elf.ei_osabi == 0x00)
        printf("ABI = System V");
    else if (elf.ei_osabi == 0x01)
        printf("ABI =  HP-UX");
    else if (elf.ei_osabi == 0x02)
        printf("ABI =  NetBSD");
    else if (elf.ei_osabi == 0x03)
        printf("ABI =  Linux");
    else if (elf.ei_osabi == 0x04)
        printf("ABI =  GNU Hurd");
    else if (elf.ei_osabi == 0x06)
        printf("ABI =  Solaris");
    else if (elf.ei_osabi == 0x07)
        printf("ABI =  	AIX");
    else if (elf.ei_osabi == 0x08)
        printf("ABI =  IRIX");
    else if (elf.ei_osabi == 0x09)
        printf("ABI =  FreeBSD");
    else if (elf.ei_osabi == 0x0A)
        printf("ABI =  Tru64");
    else if (elf.ei_osabi == 0x0B)
        printf("ABI =  Novell Modesto");
    else if (elf.ei_osabi == 0x0C)
        printf("ABI =  OpenBSD");
    else if (elf.ei_osabi == 0x0D)
        printf("ABI =  OpenVMS");
    else if (elf.ei_osabi == 0x0E)
        printf("ABI =  NonStop Kernel");
    else if (elf.ei_osabi == 0x0F)
        printf("ABI =  AROS");
    else if (elf.ei_osabi == 0x10)
        printf("ABI =  Fenix OS");
    else if (elf.ei_osabi == 0x11)
        printf("ABI =  CloudABI");
    else if (elf.ei_osabi == 0x12)
        printf("ABI =  Stratus Technologies OpenVOS");

    // printf("read from file %d\n", x);
    return 0;
}