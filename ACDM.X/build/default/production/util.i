# 1 "util.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/opt/microchip/xc8/v2.46/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "util.c" 2



# 1 "./util.h" 1


# 1 "./config.h" 1




typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef signed char schar;
typedef signed long slong;
typedef signed int sint;
typedef unsigned long long u64_t;
typedef unsigned int u32_t;
# 4 "./util.h" 2

# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/stddef.h" 1 3



# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/musl_xc8.h" 1 3
# 5 "/opt/microchip/xc8/v2.46/pic/include/c99/stddef.h" 2 3
# 19 "/opt/microchip/xc8/v2.46/pic/include/c99/stddef.h" 3
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 1 3
# 24 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef long int wchar_t;
# 128 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef unsigned size_t;
# 138 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef int ptrdiff_t;
# 174 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef __int24 int24_t;
# 210 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 20 "/opt/microchip/xc8/v2.46/pic/include/c99/stddef.h" 2 3
# 6 "./util.h" 2
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/stdbool.h" 1 3
# 7 "./util.h" 2
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/stdlib.h" 1 3
# 10 "/opt/microchip/xc8/v2.46/pic/include/c99/stdlib.h" 3
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/features.h" 1 3
# 11 "/opt/microchip/xc8/v2.46/pic/include/c99/stdlib.h" 2 3
# 21 "/opt/microchip/xc8/v2.46/pic/include/c99/stdlib.h" 3
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 1 3
# 22 "/opt/microchip/xc8/v2.46/pic/include/c99/stdlib.h" 2 3

int atoi (const char *);
long atol (const char *);

long long atoll (const char *);

double atof (const char *);


float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);

long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);


unsigned long __strtoxl(const char * s, char ** endptr, int base, char is_signed);

unsigned long long __strtoxll(const char * s, char ** endptr, int base, char is_signed);
# 55 "/opt/microchip/xc8/v2.46/pic/include/c99/stdlib.h" 3
int rand (void);
void srand (unsigned);

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));







__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);

long long llabs (long long);


typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

typedef struct { long long quot, rem; } lldiv_t;


div_t div (int, int);
ldiv_t ldiv (long, long);

lldiv_t lldiv (long long, long long);


typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);
# 8 "./util.h" 2
# 1 "config/default/definitions.h" 1
# 48 "config/default/definitions.h"
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/stdint.h" 1 3
# 26 "/opt/microchip/xc8/v2.46/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 1 3
# 133 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef unsigned __int24 uintptr_t;
# 148 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef __int24 intptr_t;
# 164 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;
# 179 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef long int32_t;





typedef long long int64_t;
# 194 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;
# 215 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "/opt/microchip/xc8/v2.46/pic/include/c99/stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 148 "/opt/microchip/xc8/v2.46/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "/opt/microchip/xc8/v2.46/pic/include/c99/stdint.h" 2 3
# 49 "config/default/definitions.h" 2


# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/stdio.h" 1 3
# 24 "/opt/microchip/xc8/v2.46/pic/include/c99/stdio.h" 3
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 1 3
# 12 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 143 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef __int24 ssize_t;
# 255 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef long long off_t;
# 409 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 25 "/opt/microchip/xc8/v2.46/pic/include/c99/stdio.h" 2 3
# 52 "/opt/microchip/xc8/v2.46/pic/include/c99/stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);





int ungetc(int, FILE *);
int getch(void);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);





void putch(char);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

__attribute__((__format__(__printf__, 1, 2)))
int printf(const char *restrict, ...);
__attribute__((__format__(__printf__, 2, 3)))
int fprintf(FILE *restrict, const char *restrict, ...);
__attribute__((__format__(__printf__, 2, 3)))
int sprintf(char *restrict, const char *restrict, ...);
__attribute__((__format__(__printf__, 3, 4)))
int snprintf(char *restrict, size_t, const char *restrict, ...);

__attribute__((__format__(__printf__, 1, 0)))
int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__printf__, 2, 0)))
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__printf__, 3, 0)))
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

__attribute__((__format__(__scanf__, 1, 2)))
int scanf(const char *restrict, ...);
__attribute__((__format__(__scanf__, 2, 3)))
int fscanf(FILE *restrict, const char *restrict, ...);
__attribute__((__format__(__scanf__, 2, 3)))
int sscanf(const char *restrict, const char *restrict, ...);

__attribute__((__format__(__scanf__, 1, 0)))
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__scanf__, 2, 0)))
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 52 "config/default/definitions.h" 2
# 123 "config/default/definitions.h"
void SYS_Initialize( void *data );
# 9 "./util.h" 2
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/string.h" 1 3
# 25 "/opt/microchip/xc8/v2.46/pic/include/c99/string.h" 3
# 1 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 1 3
# 421 "/opt/microchip/xc8/v2.46/pic/include/c99/bits/alltypes.h" 3
typedef struct __locale_struct * locale_t;
# 26 "/opt/microchip/xc8/v2.46/pic/include/c99/string.h" 2 3

void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);

char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);

char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);

int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);

int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);

char *strchr (const char *, int);
char *strrchr (const char *, int);

size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);

size_t strlen (const char *);

char *strerror (int);




char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);




void *memccpy (void *restrict, const void *restrict, int, size_t);
# 10 "./util.h" 2
# 72 "./util.h"
struct hCfg
{
   uint16_t hwVer;
   uint8_t keyPadEn;
   uint8_t readerEn;
   uint8_t statusLedMode;
   uint8_t xstatusLedColor;
   uint16_t idleTime;
   uint16_t doorOpenTime;
   uint32_t maxDoorOpenTime;
   uint16_t autoLockTime;
   float regValtage;
   float adcRes1;
   float adcRes2;
   float adcRes3;
   char hum_a;
   char hum_b;
   char hum_c;
   uint8_t boot;
};
# 135 "./util.h"
uchar eepromisbusy(void);

void eeprom_read_string(uint offset, uchar * data, uchar datalen);
void eeprom_write_string(uint offset, uchar * data, uchar datalen);

ulong get_rand(void);
void Delay(ulong delay_count_max);
void rs485bufferclear(uchar * bbufer, uchar len);
void rs485buffercopy(uchar* dest, uchar* src, uchar len);
void rs485bufferclear_long(ulong * bbufer, uchar len);
# 153 "./util.h"
           uchar calculateCRC8(uchar * inData, uchar dataLen);
           int16_t cali_sensor(uint16_t adValue);
# 5 "util.c" 2


void Delay(ulong delay_count_max)
{
    ulong delay_count = 0;

    for (delay_count = 0; delay_count < delay_count_max; delay_count++)
    {
        ;
    }

}

uchar calculateCRC8(uchar * inData, uchar dataLen)
{
    uchar i = 0, j = 0, crc = 0;

    for (j = 0; j < dataLen; j++)
    {
        crc ^= *inData++;
        for (i = 0; i < 8; i++)
        {
            if ((crc & 0x80) != 0)
            {
                crc <<= 1;
                crc ^= 0x07;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}
