#include "littletest.hpp"
#include <string>

std::string output;

extern "C" void debug_putchar(char c) { output.push_back(c); }

LT_BEGIN_SUITE(igris_test_suite)
	void set_up()
	{}

	void tear_down()
	{}
LT_END_SUITE(igris_test_suite)

LT_BEGIN_SUITE(dprint_suite)
	void set_up()
	{}

	void tear_down()
	{
		output.clear();
	}
LT_END_SUITE(dprint_suite)

#include "trent.hpp"
#include "osutil.hpp"
#include "bits.hpp"
#include "util.hpp"
#include "sync.hpp"
#include "dprint.hpp"
#include "serialize.hpp"
#include "event.hpp"
#include "argvc.hpp"
#include "signature.hpp"
#include "numconvert.hpp"
#include "test_allocator.hpp"
#include "chunked_vector.hpp"

#include "container/unbounded_array.hpp"
#include "container/array_view.hpp"

LT_BEGIN_AUTO_TEST_ENV()
    AUTORUN_TESTS()
LT_END_AUTO_TEST_ENV()