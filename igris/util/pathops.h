#ifndef IGRIS_PATHOPS_H
#define IGRIS_PATHOPS_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <igris/util/bug.h>

static inline
int path_is_single_dot(const char *path)
{
	char nc = *(path + 1);

	return *path == '.' && (nc == '/' || nc == '\0');
}

static inline
const char *path_next(const char *path, unsigned int *p_len)
{

	if (!path)
	{
		return NULL;
	}

	// Skip leading slashes.
	// XXX Skip single dots too
	while (*path == '/' || path_is_single_dot(path))
	{
		++path;
	}

	if (!*path)
	{
		return NULL;
	}

	if (p_len)
	{
		const char *end = path;

		while (*end && *end != '/')
		{
			++end;
		}

		*p_len = end - path;
	}

	return path;
}

static inline
int path_is_double_dot(const char *path)
{
	return *path == '.' && *(path + 1) == '.'
	       && (*(path + 2) == '/' || *(path + 2) == '\0');
}

static inline
int path_is_abs(const char *path)
{
	return path[0] == '/';
}

static inline
int path_is_simple(const char *path)
{
	char c;

	//for(c = *path++; c; c = *path++)
	while ((c = *path++))
		if (c == '/')
			return false;

	return true;
}

static inline
const char* path_last_node(const char* path)
{
	const char* it = path + strlen(path);

	do
	{
		--it;
	}
	while (*it != '\\' && it != path);

	if (*it == '\\') it++;

	return it;
}

static inline 
int path_simplify(char* dst, const char* src) 
{
	BUG();
	return 0;
}

static inline 
int path_simplify_join(char* dst, const char* src1, const char* src2) 
{
	BUG();
	return 0;
}

#endif
