#define MASK(i) (1 << (i))                 // make mask
#define COUNT_BIT(x) __builtin_popcount(x) // counting set-on bits of x
#define STATE(x, i) ((x) & (1 << (i)))     // state of ith bit of x
#define SET_ON(x, i) ((x) | (1 << (i)))    // set the ith bit of x on
#define SET_OFF(x, i) ((x) & ~(1 << (i)))  // set the ith bit of x off
#define LEAST_BIT(x) ((x) & (-x))
