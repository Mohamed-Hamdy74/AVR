#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(value,bit) value=value|(1<<bit)
#define CLR_BIT(value,bit) value=value&(~(1<<bit))
#define TOG_BIT(value,bit) value=value^(1<<bit)
#define GET_BIT(value,bit) (value >> (bit)) & 1

#endif