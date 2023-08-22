#include "s21_string.h"

char *s21_errnum[] = {
#ifdef __APPLE__
    [0] = "Undefined error: 0",
    [1] = "Operation not permitted",
    [2] = "No such file or directory",
    [3] = "No such process",
    [4] = "Interrupted system call",
    [5] = "Input/output error",
    [6] = "Device not configured",
    [7] = "Argument list too long",
    [8] = "Exec format error",
    [9] = "Bad file descriptor",
    [10] = "No child processes",
    [11] = "Resource deadlock avoided",
    [12] = "Cannot allocate memory",
    [13] = "Permission denied",
    [14] = "Bad address",
    [15] = "Block device required",
    [16] = "Resource busy",
    [17] = "File exists",
    [18] = "Cross-device link",
    [19] = "Operation not supported by device",
    [20] = "Not a directory",
    [21] = "Is a directory",
    [22] = "Invalid argument",
    [23] = "Too many open files in system",
    [24] = "Too many open files",
    [25] = "Inappropriate ioctl for device",
    [26] = "Text file busy",
    [27] = "File too large",
    [28] = "No space left on device",
    [29] = "Illegal seek",
    [30] = "Read-only file system",
    [31] = "Too many links",
    [32] = "Broken pipe",
    [33] = "Numerical argument out of domain",
    [34] = "Result too large",
    [35] = "Resource temporarily unavailable",
    [36] = "Operation now in progress",
    [37] = "Operation already in progress",
    [38] = "Socket operation on non-socket",
    [39] = "Destination address required",
    [40] = "Message too long",
    [41] = "Protocol wrong type for socket",
    [42] = "Protocol not available",
    [43] = "Protocol not supported",
    [44] = "Socket type not supported",
    [45] = "Operation not supported",
    [46] = "Protocol family not supported",
    [47] = "Address family not supported by protocol family",
    [48] = "Address already in use",
    [49] = "Can't assign requested address",
    [50] = "Network is down",
    [51] = "Network is unreachable",
    [52] = "Network dropped connection on reset",
    [53] = "Software caused connection abort",
    [54] = "Connection reset by peer",
    [55] = "No buffer space available",
    [56] = "Socket is already connected",
    [57] = "Socket is not connected",
    [58] = "Can't send after socket shutdown",
    [59] = "Too many references: can't splice",
    [60] = "Operation timed out",
    [61] = "Connection refused",
    [62] = "Too many levels of symbolic links",
    [63] = "File name too long",
    [64] = "Host is down",
    [65] = "No route to host",
    [66] = "Directory not empty",
    [67] = "Too many processes",
    [68] = "Too many users",
    [69] = "Disc quota exceeded",
    [70] = "Stale NFS file handle",
    [71] = "Too many levels of remote in path",
    [72] = "RPC struct is bad",
    [73] = "RPC version wrong",
    [74] = "RPC prog. not avail",
    [75] = "Program version wrong",
    [76] = "Bad procedure for program",
    [77] = "No locks available",
    [78] = "Function not implemented",
    [79] = "Inappropriate file type or format",
    [80] = "Authentication error",
    [81] = "Need authenticator",
    [82] = "Device power is off",
    [83] = "Device error",
    [84] = "Value too large to be stored in data type",
    [85] = "Bad executable (or shared library)",
    [86] = "Bad CPU type in executable",
    [87] = "Shared library version mismatch",
    [88] = "Malformed Mach-o file",
    [89] = "Operation canceled",
    [90] = "Identifier removed",
    [91] = "No message of desired type",
    [92] = "Illegal byte sequence",
    [93] = "Attribute not found",
    [94] = "Bad message",
    [95] = "EMULTIHOP (Reserved)",
    [96] = "No message available on STREAM",
    [97] = "ENOLINK (Reserved)",
    [98] = "No STREAM resources",
    [99] = "Not a STREAM",
    [100] = "Protocol error",
    [101] = "STREAM ioctl timeout",
    [102] = "Operation not supported on socket",
    [103] = "Policy not found",
    [104] = "State not recoverable",
    [105] = "Previous owner died",
    [106] = "Interface output queue is full",
    [107] = "Unknown error:"
#endif
#ifdef __linux
        [0] = "Success",
    [1] = "Operation not permitted",
    [2] = "No such file or directory",
    [3] = "No such process",
    [4] = "Interrupted system call",
    [5] = "Input/output error",
    [6] = "No such device or address",
    [7] = "Argument list too long",
    [8] = "Exec format error",
    [9] = "Bad file descriptor",
    [10] = "No child processes",
    [11] = "Resource temporarily unavailable",
    [12] = "Cannot allocate memory",
    [13] = "Permission denied",
    [14] = "Bad address",
    [15] = "Block device required",
    [16] = "Device or resource busy",
    [17] = "File exists",
    [18] = "Invalid cross-device link",
    [19] = "No such device",
    [20] = "Not a directory",
    [21] = "Is a directory",
    [22] = "Invalid argument",
    [23] = "Too many open files in system",
    [24] = "Too many open files",
    [25] = "Inappropriate ioctl for device",
    [26] = "Text file busy",
    [27] = "File too large",
    [28] = "No space left on device",
    [29] = "Illegal seek",
    [30] = "Read-only file system",
    [31] = "Too many links",
    [32] = "Broken pipe",
    [33] = "Numerical argument out of domain",
    [34] = "Numerical result out of range",
    [35] = "Resource deadlock avoided",
    [36] = "File name too long",
    [37] = "No locks available",
    [38] = "Function not implemented",
    [39] = "Directory not empty",
    [40] = "Too many levels of symbolic links",
    [41] = "Unknown error 41",
    [42] = "No message of desired type",
    [43] = "Identifier removed",
    [44] = "Channel number out of range",
    [45] = "Level 2 not synchronized",
    [46] = "Level 3 halted",
    [47] = "Level 3 reset",
    [48] = "Link number out of range",
    [49] = "Protocol driver not attached",
    [50] = "No CSI structure available",
    [51] = "Level 2 halted",
    [52] = "Invalid exchange",
    [53] = "Invalid request descriptor",
    [54] = "Exchange full",
    [55] = "No anode",
    [56] = "Invalid request code",
    [57] = "Invalid slot",
    [58] = "Unknown error 58",
    [59] = "Bad font file format",
    [60] = "Device not a stream",
    [61] = "No data available",
    [62] = "Timer expired",
    [63] = "Out of streams resources",
    [64] = "Machine is not on the network",
    [65] = "Package not installed",
    [66] = "Object is remote",
    [67] = "Link has been severed",
    [68] = "Advertise error",
    [69] = "Srmount error",
    [70] = "Communication error on send",
    [71] = "Protocol error",
    [72] = "Multihop attempted",
    [73] = "RFS specific error",
    [74] = "Bad message",
    [75] = "Value too large for defined data type",
    [76] = "Name not unique on network",
    [77] = "File descriptor in bad state",
    [78] = "Remote address changed",
    [79] = "Can not access a needed shared library",
    [80] = "Accessing a corrupted shared library",
    [81] = ".lib section in a.out corrupted",
    [82] = "Attempting to link in too many shared libraries",
    [83] = "Cannot exec a shared library directly",
    [84] = "Invalid or incomplete multibyte or wide character",
    [85] = "Interrupted system call should be restarted",
    [86] = "Streams pipe error",
    [87] = "Too many users",
    [88] = "Socket operation on non-socket",
    [89] = "Destination address required",
    [90] = "Message too long",
    [91] = "Protocol wrong type for socket",
    [92] = "Protocol not available",
    [93] = "Protocol not supported",
    [94] = "Socket type not supported",
    [95] = "Operation not supported",
    [96] = "Protocol family not supported",
    [97] = "Address family not supported by protocol",
    [98] = "Address already in use",
    [99] = "Cannot assign requested address",
    [100] = "Network is down",
    [101] = "Network is unreachable",
    [102] = "Network dropped connection on reset",
    [103] = "Software caused connection abort",
    [104] = "Connection reset by peer",
    [105] = "No buffer space available",
    [106] = "Transport endpoint is already connected",
    [107] = "Transport endpoint is not connected",
    [108] = "Cannot send after transport endpoint shutdown",
    [109] = "Too many references: cannot splice",
    [110] = "Connection timed out",
    [111] = "Connection refused",
    [112] = "Host is down",
    [113] = "No route to host",
    [114] = "Operation already in progress",
    [115] = "Operation now in progress",
    [116] = "Stale file handle",
    [117] = "Structure needs cleaning",
    [118] = "Not a XENIX named type file",
    [119] = "No XENIX semaphores available",
    [120] = "Is a named type file",
    [121] = "Remote I/O error",
    [122] = "Disk quota exceeded",
    [123] = "No medium found",
    [124] = "Wrong medium type",
    [125] = "Operation canceled",
    [126] = "Required key not available",
    [127] = "Key has expired",
    [128] = "Key has been revoked",
    [129] = "Key was rejected by service",
    [130] = "Owner died",
    [131] = "State not recoverable",
    [132] = "Operation not possible due to RF-kill",
    [133] = "Memory page has hardware error",
    [134] = "Unknown error"
#endif
};

long double s21_pow(long double a, int b) {
  long double res = 1;
  if (b == 0) {
    res = 1;
  } else if (b > 0) {
    for (int i = 0; i < b; i++) {
      res = res * a;
    }
  } else {
    b = b * (-1);
    for (int i = 0; i < b; i++) {
      res = res * (1.0 / a);
    }
  }
  return res;
}

int CharToInt(char c) {
  int res = 0;
  switch (c) {
    case '0':
      res = 0;
      break;
    case '1':
      res = 1;
      break;
    case '2':
      res = 2;
      break;
    case '3':
      res = 3;
      break;
    case '4':
      res = 4;
      break;
    case '5':
      res = 5;
      break;
    case '6':
      res = 6;
      break;
    case '7':
      res = 7;
      break;
    case '8':
      res = 8;
      break;
    case '9':
      res = 9;
      break;
    default:
      break;
  }
  return res;
}

int IntToChar(int c) {
  char res;
  switch (c) {
    case 0:
      res = '0';
      break;
    case 1:
      res = '1';
      break;
    case 2:
      res = '2';
      break;
    case 3:
      res = '3';
      break;
    case 4:
      res = '4';
      break;
    case 5:
      res = '5';
      break;
    case 6:
      res = '6';
      break;
    case 7:
      res = '7';
      break;
    case 8:
      res = '8';
      break;
    case 9:
      res = '9';
      break;
    default:
      res = -1;
      break;
  }
  return res;
}

int Len(const char *p) {
  int schet = 0;
  for (; *p >= '0' && *p <= '9'; p++, schet++) {
  }
  return schet;
}

int Result(const char *str, int len) {
  int res = 0;
  int startpow = len - 1;
  for (int i = 0; i < len; i++) {
    res = res + (CharToInt(*str) * s21_pow(10, startpow));
    str++;
    startpow--;
  }
  return res;
}

const char *Flag(const char *format, int *flag, int *error) {
  if (*format == ' ' && *(format + 1) == '-') {
    *flag = 0;
    format = format + 2;
  } else if ((*format == '+' && *(format + 1) == '-') ||
             (*format == '-' && *(format + 1) == '+')) {
    *flag = 1;
    format = format + 2;
  } else if (*format == ' ') {
    *flag = 2;
    format++;
  } else if (*format == '+') {
    *flag = 3;
    format++;
  } else if (*format == '-') {
    *flag = 4;
    format++;
  } else if (*flag == -1) {
  } else {
    *error = 1;
  }
  return format;
}

const char *Weigh(const char *format, int *wei, int *len) {
  int col = 0;
  while (((*format >= '0' && *format <= '9') || (*format == '.')) && col <= 1) {
    if (*format == '.') {
      col++;
    } else if (*wei == -1 && col == 0) {
      *wei = Result(format, Len(format));
    } else if (*len == -1 && col == 1) {
      *len = Result(format, Len(format));
    }
    format++;
  }
  return format;
}

int Reallen(long double res) {
  int reallen = -1;
  if ((int)res == 0) {
    reallen = 1;
  } else {
    while ((res / s21_pow(10, reallen)) >= 1) {
      reallen++;
    }
  }
  return reallen;
}

void ResultChar(long double res, char *result, int reallen, int finallen,
                int len_mas) {
  char *p = result;
  int gran = finallen * (-1);
  int startpow = reallen - 1;
  while (len_mas--) {
    if (startpow == -1) {
      *p = '.';
      p++;
      len_mas++;
    }
    reallen = res / s21_pow(10, startpow);
    if (startpow < gran && reallen >= 5) {
      *(p - 1) = *(p - 1) + 1;
    } else {
      *p = IntToChar(reallen);
      p++;
    }
    res = res - (reallen * s21_pow(10, startpow));
    startpow--;
  }
  *p = '\0';
}

int Minus(long double *res, int flag_f) {
  int minus = 0;
  if (*res < 0 && flag_f != 0) {
    *res = *res * (-1);
    minus = 1;
  } else if (flag_f == 0 || flag_f == 2) {
    minus = -1;
  }
  return minus;
}

int LenMas(int len, int reallen, int flag_f) {
  int len_mas = 0;
  if ((len == 0 && flag_f == 1) || flag_f < 0) {
    len_mas = reallen;
  } else if (len > 0 && flag_f == 1) {
    len_mas = reallen + len + 1;
  } else if (flag_f == 0) {
    len_mas = 1;
  } else if (flag_f == 2) {
    len_mas = len;
  }
  return len_mas;
}

char *WrightingSym(char *str, int n, char a) {
  for (int i = 0; i < n; i++, str++) {
    *str = a;
  }
  return str;
}

char *WrightingZnak(char *str, int flag, int minus) {
  if ((flag == 1 || flag == 4 || flag == 3 || flag == -1) && minus != -1) {
    if (minus == 0 && (flag == 1 || flag == 3)) {
      str = WrightingSym(str, 1, '+');
    } else if (minus == 1) {
      str = WrightingSym(str, 1, '-');
    }
  }
  return str;
}

char *WrightingString(char *str, int n, char *reschar) {
  for (int i = 0; i < n; i++, str++, reschar++) {
    *str = *reschar;
  }
  return str;
}

int ColN(int flag_f, int finallen, int reallen) {
  int col_n = 0;
  if (flag_f < 0 && finallen > reallen) {
    col_n = finallen - reallen;
  }
  return col_n;
}

int ColP(int wei, int len_mas, int col_n, int flag, int minus) {
  int col_p = wei - col_n - len_mas;
  if ((flag == 1 || flag == 3 || minus == 1) && flag != 2 && flag != 0) {
    col_p--;
  }
  return col_p;
}

char *Wrighting(char *str, int len_mas, char *reschar, int col_n, ...) {
  va_list point;
  va_start(point, col_n);
  int col_p = va_arg(point, int);
  int minus = va_arg(point, int);
  int flag = va_arg(point, int);
  if (flag == 2 || flag == 3 || flag == -1) {
    str = WrightingSym(str, col_p, ' ');
  }
  str = WrightingZnak(str, flag, minus);
  str = WrightingSym(str, col_n, '0');
  str = WrightingString(str, len_mas, reschar);
  if (flag == 0 || flag == 1 || flag == 4) {
    str = WrightingSym(str, col_p, ' ');
  }
  *str = '\0';
  va_end(point);
  return str;
}

int FinalLen(int len, int flag_f, char *resstr1) {
  int finallen;
  if (len == -1 && flag_f == 1) {
    finallen = 6;
  } else if (len == -1 && flag_f == 2) {
    finallen = s21_strlen(resstr1);
  } else if (len == -1) {
    finallen = 0;
  } else {
    finallen = len;
  }
  return finallen;
}

void ForString(char *reschar, int len_mas, char *ch) {
  char *p = reschar;
  int l = len_mas;
  while (*ch && l--) {
    *p = *ch;
    p++;
    ch++;
  }
  *p = '\0';
}

char *FinalResult(va_list point, char *str, ...) {
  va_list point_f;
  va_start(point_f, str);
  int flag_f = va_arg(point_f, int), wei = va_arg(point_f, int),
      len = va_arg(point_f, int), flag = va_arg(point_f, int);
  char *ch = S21_NULL;
  long double res = 0;
  if (flag_f == -1 || flag_f == 0) {
    res = va_arg(point, int);
  } else if (flag_f == 2) {
    ch = va_arg(point, char *);
  } else if (flag_f == -2) {
    res = va_arg(point, unsigned int);
  } else if (flag_f == -3) {
    res = va_arg(point, long int);
  } else if (flag_f == -4) {
    res = va_arg(point, long unsigned int);
  } else if (flag_f == 1) {
    res = va_arg(point, double);
  }
  int finallen = FinalLen(len, flag_f, ch), minus = Minus(&res, flag_f),
      reallen = Reallen(res), len_mas = LenMas(finallen, reallen, flag_f);
  char *reschar = malloc(sizeof(char) * (len_mas + 1));
  if (flag_f < 0 || flag_f == 1) {
    ResultChar(res, reschar, reallen, finallen, len_mas);
  } else if (flag_f == 0) {
    *reschar = (char)res;
    *(reschar + 1) = '\0';
  } else if (flag_f == 2) {
    ForString(reschar, len_mas, ch);
  }
  int col_n = ColN(flag_f, finallen, reallen);
  int col_p = ColP(wei, len_mas, col_n, flag, minus);
  str = Wrighting(str, len_mas, reschar, col_n, col_p, minus, flag);
  free(reschar);
  va_end(point_f);
  return str;
}

const char *Switch(const char *format, int *flag_f) {
  switch (*format) {
    case 'h':
      format++;
      switch (*format) {
        case 'u':
          *flag_f = -2;
          break;
        default:
          break;
      }
      break;
    case 'l':
      format++;
      switch (*format) {
        case 'i':
          *flag_f = -3;
          break;
        case 'd':
          *flag_f = -3;
          break;
        case 'u':
          *flag_f = -4;
          break;
        case 'c':
          *flag_f = 0;
          break;
        case 's':
          *flag_f = 2;
          break;
        default:
          break;
      }
      break;
    case 'u':
      *flag_f = -2;
      break;
    case 'f':
      *flag_f = 1;
      break;
    case 'c':
      *flag_f = 0;
      break;
    case 's':
      *flag_f = 2;
      break;
    default:
      break;
  }
  return format;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list point;
  va_start(point, format);
  int error = 0;
  char *p = str;
  while (*format != '\0' && error == 0) {
    while (*format != '%' && *format != '\0') {
      *p = *format;
      p++;
      format++;
    }
    format++;
    int exit = 0;
    while (*format != '%' && *format != '\0' && exit == 0 && error == 0) {
      int len = -1, wei = -1, flag = -1, flag_f = -1;
      format = Flag(format, &flag, &error);
      format = Weigh(format, &wei, &len);
      format = Switch(format, &flag_f);
      if (*format == 'd' || *format == 'i' || *format == 'u' ||
          *format == 'f' || *format == 's' || *format == 'c') {
        p = FinalResult(point, p, flag_f, wei, len, flag);
        exit = 1;
      }
      if (*format != '\0') {
        format++;
      }
    }
  }
  va_end(point);
  return p - str;
}

s21_size_t s21_strlen(const char *string) {
  int s = '\0';
  for (; *(string + s); s++) {;}
  return s;
}

int s21_strcmp(const char *str1, const char *str2) {
  for (; *str1 && *str1 == *str2; str1++, str2++) {;}
  return *str1 - *str2;
}

char *s21_strcpy(char *dest, const char *src) {
  char *p = dest;
  while ((*p++ = *src++)) {
  }
  return dest;
}

char *s21_strcat(char *dest, const char *src) {
  int s = 0;
  for (int i = 0; dest[i] != '\0'; i++) {
    s = i;
  }
  int i;
  if (dest[s] == '\0') {
    i = s;
  } else {
    i = s + 1;
  }
  for (int m = i, j = 0; src[j] != '\0'; m++, j++) {
    dest[m] = src[j];
    s = m;
  }
  dest[s + 1] = '\0';
  return dest;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int size = (int)n * sizeof(char);
  int i = sizeof(char);
  void *str_find = (void *)str;
  if (str_find != S21_NULL) {
    int check = 0;
    for (int j = 0; j < size; j = j + i, str_find = (char *)str_find + i) {
      if (*((char *)str_find) == c) {
        check = 1;
        break;
      }
    }
    if (check == 0) {
      str_find = S21_NULL;
    }
  }
  return str_find;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int a, indicator = 0;
  while (n--) {
    if (*((char *)str1) != *((char *)str2)) {
      a = *((char *)str1) - *((char *)str2);
      indicator = 1;
      break;
    } else {
      str1 = (char *)str1 + 1;
      str2 = (char *)str2 + 1;
    }
  }
  if (indicator == 0) {
    a = 0;
  }
  return a;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *p = dest;
  const char *q = src;
  while (n--) {
    *p++ = *q++;
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *p = dest;
  const char *q = src;
  if (q < p) {
    s21_size_t i = 0;
    while (++i <= n) {
      p[n - i] = q[n - i];
    }
  } else {
    while (n-- > 0) {
      *(p++) = *(q++);
    }
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *p = str;
  while (n--) {
    *p++ = (char)c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int s = 0;
  for (int i = 0; dest[i] != '\0'; i++) {
    s = i;
  }
  int i;
  if (dest[s] == '\0') {
    i = s;
  } else {
    i = s + 1;
  }
  for (int m = i, j = 0; src[j] != '\0' && n--; m++, j++) {
    dest[m] = src[j];
    s = m;
  }
  dest[s + 1] = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  while (*str != c && *str != '\0') {
    str++;
  }
  if (*str != c) {
    str = S21_NULL;
  }
  return (char *)str;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (; *str1 && *str1 == *str2 && n--; str1++, str2++) {;}
  return *str1 - *str2;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *p = dest;
  int indicator = 0;
  do {
    if (!n--) {
      indicator = 1;
      break;
    }
  } while ((*p++ = *src++));
  if (indicator == 0) {
    while (n--) {
      *p++ = 0;
    }
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t n = 0;
  while (*str1 != '\0') {
    if (s21_strchr(str2, *str1) != S21_NULL) {
      break;
    } else {
      str1++;
      n++;
    }
  }
  return n;
}

char *s21_strerror(int errnum) {
  char *a = malloc(sizeof(char) * (Reallen(errnum) + 2));
#ifdef __APPLE__
  int n = 106;
#endif
#ifdef __linux
  int n = 133;
#endif
  if (errnum <= 0 || errnum >= n) {
    s21_sprintf(a, "%s %d", s21_errnum[n + 1], errnum);
  }
  free(a);
  return (errnum >= 0 && errnum <= n) ? s21_errnum[errnum] : a;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *a;
  int indicator = 0;
  while (*str1) {
    if (s21_strchr(str2, *str1++)) {
      indicator = 1;
      a = (char *)--str1;
      break;
    }
  }
  if (indicator == 0) {
    a = S21_NULL;
  }
  return a;
}

char *s21_strrchr(const char *str, int c) {
  char *a = S21_NULL;
  do {
    if (*str == (char)c) {
      a = (char *)str;
    }
  } while (*str++);
  return a;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t a = 0;
  while (*str1 && s21_strchr(str2, *str1++)) {
    a++;
  }
  return a;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t n = s21_strlen(needle);
  char *a;
  int indicator = 0;
  while (*haystack) {
    if (s21_memcmp(haystack, needle, n) == 0) {
      a = (char *)haystack;
      indicator = 1;
      break;
    } else {
      haystack++;
    }
  }
  if (indicator == 0) {
    a = S21_NULL;
  }
  return a;
}

char *s21_strtok(char *str, const char *delim) {
  static char *p = S21_NULL;
  char *m = S21_NULL;
  int indicator = 0;
  if (str != S21_NULL) {
    p = str;
  } else if (p == S21_NULL) {
    indicator = 1;
    m = p;
  }
  if (indicator == 0) {
    if (p) {
      str = p + s21_strspn(p, delim);
    } else {
      str = (char *)s21_strspn(p, delim);
    }
    p = str + s21_strcspn(str, delim);
    if (p == str) {
      indicator = 1;
      p = S21_NULL;
      m = p;
    }
    if (indicator == 0) {
      p = *p ? *p = 0, p + 1 : 0;
      m = str;
    }
  }
  return m;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *b = malloc(sizeof(char) * (s21_strlen((char *)src) + 1));
  char *a = b;
  while (*src) {
    if (s21_strchr(trim_chars, *src) == S21_NULL) {
      *a = *src;
      a++;
    }
    src++;
  }
  *a = '\0';
  return (void *)b;
}

void *s21_to_upper(const char *str) {
  int err = 0;
  char *tmpStr = malloc(sizeof(char) * s21_strlen(str) + 1);
  char *firstEl = tmpStr;
  if (*str) {
    tmpStr = s21_strcpy(tmpStr, str);
    while (*tmpStr) {
      if (*tmpStr >= 'a' && *tmpStr <= 'z') {
        *tmpStr -= 32;
      }
      tmpStr++;
    }
  } else {
    err = 1;
  }
  return err ? S21_NULL : firstEl;
}

void *s21_to_lower(const char *str) {
  int err = 1;
  char *tmpStr = malloc(sizeof(char) * s21_strlen(str) + 1);
  char *firstEl = tmpStr;
  if (*str) {
    tmpStr = s21_strcpy(tmpStr, str);
    while (*tmpStr) {
      if (*tmpStr >= 'A' && *tmpStr <= 'Z') {
        *tmpStr += 32;
      }
      tmpStr++;
    }
    err = 0;
  }
  return err ? S21_NULL : firstEl;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  int err = 1;
  char *result = malloc(sizeof(char) * (s21_strlen(src) + s21_strlen(str) + 1));
  char *firstElResult = result;
  if (*src && (size_t)start_index < s21_strlen(src)) {
    size_t flag = 0;
    while (*src) {
      if (flag == start_index) {
        result = s21_strcat(result, str);
        result += (int)s21_strlen(str);
      } else {
        *result = *src;
        src++;
        result++;
        *result = '\0';
      }
      flag++;
    }
    err = 0;
  } else if (*str == '\0') {
    err = 0;
  }
  return err ? S21_NULL : firstElResult;
}
