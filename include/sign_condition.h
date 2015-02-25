/*
 * sign_condition.h
 *
 *  Created on: Apr 3, 2014
 *      Author: dejan
 */

#pragma once

#include "poly.h"

#include <stdio.h>

/**
 * Sign condition contains two signs, both either -1, 0, 1, in ascending order.
 * If the second sign is equal to the first one, then only the first one is
 * relevant.
 */
enum lp_sign_condition_enum {
  /** <  0 */
  LP_SGN_LT_0,
  /** <= 0 */
  LP_SGN_LE_0,
  /** == 0 */
  LP_SGN_EQ_0,
  /** != 0 */
  LP_SGN_NE_0,
  /** >  0 */
  LP_SGN_GT_0,
  /** >= 0 */
  LP_SGN_GE_0
};

typedef enum lp_sign_condition_enum lp_sign_condition_t;

/**
 * Negate the sign condition.
 */
static inline
lp_sign_condition_t lp_sign_condition_negate(lp_sign_condition_t sgn_condition) {
  switch (sgn_condition) {
  case LP_SGN_LT_0:
    return LP_SGN_GE_0;
  case LP_SGN_LE_0:
    return LP_SGN_GT_0;
  case LP_SGN_EQ_0:
    return LP_SGN_NE_0;
  case LP_SGN_NE_0:
    return LP_SGN_EQ_0;
  case LP_SGN_GT_0:
    return LP_SGN_LE_0;
  case LP_SGN_GE_0:
    return LP_SGN_LT_0;
  }
  // Just for compilers
  return LP_SGN_EQ_0;
}


