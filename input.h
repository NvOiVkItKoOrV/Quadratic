#ifndef INPUT_H
#define INPUT_H

const int MAX_BUF_VAL = 50;

void          get_all_coefficients (coefficients *ptr_coeff);
input_results get_one_coefficient  (double       *ptr_coeff);
void          reading_interface    (double       *ptr_coeff);
void          coeff_to_buf         (char *buf, int size);

#endif /*INPUT_H*/
