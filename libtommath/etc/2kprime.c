/* Makes safe primes of a 2k nature */
#include <tommath.h>
#include <time.h>

static int sizes[] = {256, 512, 768, 1024, 1536, 2048, 3072, 4096};

int main(void)
{
   char buf[2000];
   size_t x;
   bool y;
   mp_int q, p;
   FILE *out;
   clock_t t1;
   mp_digit z;

   mp_init_multi(&q, &p, NULL);

   out = fopen("2kprime.1", "w");
   if (out != NULL) {
      for (x = 0; x < (sizeof(sizes) / sizeof(sizes[0])); x++) {
top:
         mp_2expt(&q, sizes[x]);
         mp_add_d(&q, 3uL, &q);
         z = -3;

         t1 = clock();
         for (;;) {
            mp_sub_d(&q, 4uL, &q);
            z += 4uL;

            if (z > MP_MASK) {
               printf("No primes of size %d found\n", sizes[x]);
               break;
            }

            if ((clock() - t1) > CLOCKS_PER_SEC) {
               printf(".");
               fflush(stdout);
               /*            sleep((clock() - t1 + CLOCKS_PER_SEC/2)/CLOCKS_PER_SEC); */
               t1 = clock();
            }

            /* quick test on q */
            mp_prime_is_prime(&q, 1, &y);
            if (!y) {
               continue;
            }

            /* find (q-1)/2 */
            mp_sub_d(&q, 1uL, &p);
            mp_div_2(&p, &p);
            mp_prime_is_prime(&p, 3, &y);
            if (!y) {
               continue;
            }

            /* test on q */
            mp_prime_is_prime(&q, 3, &y);
            if (!y) {
               continue;
            }

            break;
         }

         if (!y) {
            ++sizes[x];
            goto top;
         }

         mp_to_decimal(&q, buf, sizeof(buf));
         printf("\n\n%d-bits (k = %lu) = %s\n", sizes[x], z, buf);
         fprintf(out, "%d-bits (k = %lu) = %s\n", sizes[x], z, buf);
         fflush(out);
      }
      fclose(out);
   }

   return 0;
}
