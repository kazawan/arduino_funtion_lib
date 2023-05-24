void animation(float *a, float *a_trg, uint8_t n)
{
  if (fabs(*a - *a_trg) < 0.15)
    *a = *a_trg;
  if (*a != *a_trg)
    *a += (*a_trg - *a) / (n / 10.0);
}
