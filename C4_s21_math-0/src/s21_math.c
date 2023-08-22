#include "s21_math.h"

/* #define STAT_MEAN_ARR_LONG 7

const long double statMeanArr[STAT_MEAN_ARR_LONG] = {
    S21_NANF, -S21_NANF, S21_INFL, -S21_INFL, 0, 1, -1}; */

long int s21_abs(int x) {
  long int res = (long int)x;
  if (res < 0) {
    res = res * (-1);
  }
  res = (double)res;
  return res;
}

long double s21_fabs(double x) {
  long double res = (long double)x;
  if (res < 0) {
    res = res * (-1);
  }
  res = (double)res;
  return res;
}

long double s21_sqrt(double x) {
  long double res = 0;
  if (x == 0.000000 || x == S21_INFL) {
    res = x * 1;
  } else if (x != x) {
    res = x;
  } else if (x == S21_NANF || x < 0) {
    res = S21_NANF;
  } else {
    long double t;
    res = x / 2;
    do {
      t = res;
      res = (t + (x / t)) / 2;
    } while ((t - res) != 0);
  }
  return res;
}

long double s21_ceil(double x) {
  long double res = (long double)x;
  if (x == S21_INFL) {
    res = x;
  } else if (x == (-1) * S21_INFL) {
    res = x;
  } else if (x < 0) {
    res = (long long int)x;
  } else if (x > 0) {
    if ((x - (long long int)x) != 0) {
      res = (long long int)x;
      res += 1;
    } else {
      res = x;
    }
  }
  res = (double)res;
  return res;
}

long double s21_floor(double x) {
  long double res = (long double)x;
  if (x == S21_INFL) {
    res = x;
  } else if (x == (-1) * S21_INFL) {
    res = x;
  } else if (x < 0) {
    if ((x - (long long int)x) != 0) {
      res = (long long int)x;
      res -= 1;
    } else {
      res = (long long int)x;
    }
  } else if (x > 0) {
    res = (long long int)x;
  }
  res = (double)res;
  return res;
}

long double s21_fmod(double x, double y) {
  long double ost = 0;
  if (y == 0. || x == S21_INFL || x == S21_INFL * -1 || x != x || y != y) {
    ost = S21_NANF;
  } else if (x == 0 && y != 0) {
    ost = 0;
  } else if (x != S21_INFL && (y == S21_INFL || y == (-1) * S21_INFL)) {
    ost = x;
  } else {
    __int128_t res = 0;
    res = x / y;
    ost = x - (res * y);
  }

  return ost;
}

long double s21_pow(double base, double exp) {
  long double res = (long double)base;
  if (base == 0 && exp < 0) {
    res = S21_HUGE_VAL;
  } else if (base != base || base == S21_NANF || exp != exp ||
             exp == S21_NANF) {
    res = S21_NANF;
  } else if (base == 1 || exp == 0) {
    res = 1;
  } else if (base == -1 && (exp == S21_INFL || exp == (-1) * S21_INFL)) {
    res = 1;
  } else if (s21_abs(base) < 1 && exp == (-1) * S21_INFL) {
    res = S21_INFL;
  } else if (s21_abs(base) > 1 && exp == (-1) * S21_INFL) {
    res = 0;
  } else if (s21_abs(base) < 1 && exp == S21_INFL) {
    res = 0;
  } else if (s21_abs(base) > 1 && exp == S21_INFL) {
    res = S21_INFL;
  } else if (exp > 0 && base == S21_INFL) {
    res = S21_INFL;
  } else if (exp < 0 && base == S21_INFL) {
    res = 0;
  } else if (exp == 1 && base > 0) {
    res = base;
  } else if (base == -1 && exp == -1) {
    res = -1;
  } else if (res != 0) {
    if (exp == 0) {
      res = 1;
    } else {
      res = s21_exp((long double)exp * s21_log(res));
    }
  } else {
    res = 0;
  }
  res = (double)res;
  return res;
}

long double s21_row(int free_member, int sign, int step, int start_pow,
                    double x) {
  long double res = 0;
  long double px = 1;
  long double fac = 1;
  long double eps = 1;
  int log = 0;
  if (sign == -2 || sign == -3) {
    log = 1;
    if (sign == -3) {
      sign = 1;
    } else {
      sign = 0;
    }
  }
  for (int i = 1; eps > 0.0000000001; i++) {
    px = px * x;
    if (log == 1) {
      fac = i;
    } else {
      fac = fac * i;
    }
    if (i % step == start_pow) {
      if (sign == 1 || sign == -1) {
        res = res + (sign * (px / fac));
        sign = sign * (-1);
      } else {
        res = res + (px / fac);
      }
    }
    eps = s21_fabs(px / fac);
  }
  res = res + (long double)free_member;
  return res;
}

long double s21_exp(double x) {
  long double sum = 0.0;
  int sign_flag = 0;
  if (x == S21_INFL) {
    sum = x;
  } else if (x == S21_INFL * -1) {
    sum = 0;
  } else {
    if (x < 0) {
      x *= (-1);
      sign_flag = 1;
    }
    if (x >= 646.0) {
      long double sum1 = 1.0, sum2 = 0.0;
      __int128_t x1 = (__int128_t)x;
      double x2 = s21_fmod(x, (double)x1);

      for (int i = 1; i <= x1; ++i) {
        sum1 *= s21_row(1, 0, 1, 0, 1);
      }
      if (x2 > 0.0) {
        sum2 = s21_row(1, 0, 1, 0, x2);
      }
      if (sum2 == 0.0) {
        sum2 = 1.0;
      }

      sum = sum1 * sum2;
    } else {
      sum = s21_row(1, 0, 1, 0, x);
    }

    if (sign_flag == 1) {
      sum = 1 / sum;
    }
  }
  return sum;
}

long double s21_sin(double x) {
  long double res = s21_fmod(x, (2 * S21_PI));
  if (x != x) {
    res = S21_NANF;
  } else if (x == 0) {
    res = x;
  } else {
    res = s21_row(0, 1, 2, 1, res);
    res = (double)res;
  }
  return res;
}

long double s21_cos(double x) {
  long double res = s21_fmod(x, (2 * S21_PI));
  if (x != x || x == S21_NANF) {
    res = S21_NANF;
  } else if (x == S21_INFL || x == (-1) * S21_INFL) {
    res = S21_NANF;
  } else {
    res = s21_row(1, -1, 2, 0, res);
    res = (double)res;
  }
  return res;
}

long double s21_tan(double x) {
  long double res = s21_fmod(x, (2 * S21_PI));
  if (x != x) {
    res = S21_NANF;
  } else if (x == 0) {
    res = x;
  } else if (res != S21_PI / 2 && res != -(S21_PI / 2)) {
    res = (s21_sin(res)) / (s21_cos(res));
  } else if (res == S21_PI / 2) {
    res = 16331239353195370;
  } else {
    res = -16331239353195370;
  }
  res = (double)res;
  return res;
}

long double s21_log(double x) {
  long double res = (long double)x;
  if (x == S21_INFL) {
    res = x;
  } else if (x == 1) {
    res = 0;
  } else if (x != x || x == (-1) * S21_INFL || x < 0) {
    res = S21_NANF;
  } else if (x == 0) {
    res = (-1) * S21_INFL;
  } else if (res > 0) {
    res = (res - 1) / (res + 1);
    res = 2 * s21_row(0, -2, 2, 1, res);
  }
  res = (double)res;
  return res;
}

long double s21_atan(double x) {
  long double res = (long double)x;
  int sign = 0, obr = 0;
  if (res < 0) {
    res = s21_fabs(res);
    sign = 1;
  }
  if (res > 1) {
    res = 1 / res;
    obr = 1;
  }
  int i = 0;
  while (res > 0.9) {
    res = (res * s21_sqrt(3) - 1) / (res + s21_sqrt(3));
    i++;
  }
  res = s21_row(0, -3, 2, 1, res) + (i * S21_PI / 6);
  if (obr == 1) {
    res = (S21_PI / 2) - res;
  }
  if (sign == 1) {
    res = res * (-1);
  }
  res = (double)res;
  return res;
}

long double s21_asin(double x) {
  long double res = (long double)x;
  if (x > 1 || x < -1) {
    res = S21_NANF;
  } else if (x != x || x == S21_INFL || x == (-1) * S21_INFL) {
    res = S21_NANF;
  } else if (x == 0.0) {
    res = x;
  } else if (x <= 1 && x >= -1) {
    if (res != 1 && res != -1) {
      res = s21_atan(res / s21_sqrt(1 - (res * res)));
    } else if (res == 1) {
      res = S21_PI / 2;
    } else {
      res = (S21_PI / 2) * (-1);
    }
  }
  res = (double)res;
  return res;
}

long double s21_acos(double x) {
  long double res = (long double)x;
  if (x > 1 || x < -1) {
    res = S21_NANF;
  } else if (x != x || x == S21_INFL || x == (-1) * S21_INFL) {
    res = S21_NANF;
  } else if (x == 1) {
    res = 0;
  } else if (res <= 1 && res >= -1) {
    if (res != 1 && res != -1) {
      res = (S21_PI / 2) - s21_asin(res);
    } else if (res == 1) {
      res = 0;
    } else {
      res = S21_PI;
    }
  }
  res = (double)res;
  return res;
}

/* int main() {
  long int N = 100000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow(-1, i) * (double)(rand()) / RAND_MAX * N;
    printf("\n\n%lf\n", x);
    double res_s21 = s21_atan(x);
    double res_origin = atan(x);
    printf("S21: %lf\n", res_s21);
    printf("ORIGIN: %lf\n", res_origin);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      printf("WIN");
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_atan(x);
    double res_origin = atan(x);
    printf("\n\n%lf\n", x);
    printf("\n\nS21: %lf\n", res_s21);
    printf("ORIGIN: %lf\n\n", res_origin);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      printf("WIN");
    }
  }
} */
