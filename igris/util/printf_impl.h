#ifndef PRINTF_IMPL_H_
#define PRINTF_IMPL_H_

#include <stdarg.h>
#include <igris/compiler.h>

__BEGIN_DECLS

int __printf ( 
	void (*printchar_handler)(void *d, int c), 
	void* printchar_data,
	const char *format, 
	va_list args );

__END_DECLS

#endif
