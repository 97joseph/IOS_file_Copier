cmake_minimum_required (VERSION 3.8)

project ("temp")

if (MSVC_VERSION GREATER_EQUAL "1900")
	include(CheckCXXCompilerFlag)
		CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
		if (_cpp_latest_flag_supported)
			add_compile_options("/std:c++latest")
		endif()
endif()
add_executable(${PROJECT_NAME} src/main.cpp)

//_cpp_latest_flag_supported