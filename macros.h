/*
 ============================================================================
 Name        : macros.h
 Author      : Afroz Mohiuddin
 Version     : 1
 Description : Certain useful macros.
 ============================================================================
 */

#ifndef __MACROS_H__
#define __MACROS_H__

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#define LOG \
std::cout << __DATE__ << " - " << __TIME__ << " [" << __FILE__ << ":" << \
__LINE__ << "] "\

#define ILOG(fp, ...) \
do { \
  fprintf(fp, "%s - %s [%s:%d] ", __DATE__, __TIME__, __FILE__,  __LINE__); \
  fprintf(fp, __VA_ARGS__); \
  fprintf(fp, "\n"); \
} \
while (0)

#define LOG_ERROR(...) ILOG(stderr, __VA_ARGS__)
#define LOG_INFO(...) ILOG(stdout, __VA_ARGS__)

#define LOG_FATAL(...) LOG_ERROR(__VA_ARGS__); exit(EXIT_FAILURE);

#define CHECK(x) \
do { \
  if (!x) { \
    LOG_FATAL(#x " is false!"); \
  } \
} \
while (0)

#define CHECK_NOTNULL(x) CHECK(!(x == NULL))

#define ABSTRACT = 0;

#endif  /* __MACROS_H__ */
