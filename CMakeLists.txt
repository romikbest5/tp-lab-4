file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
	
	
	set(SRC_FILES1 ${PROJECT_SOURCE_DIR}/src/main1.cpp)
	set(SRC_FILES2 ${PROJECT_SOURCE_DIR}/src/main2.cpp)
	set(SRC_FILES3 ${PROJECT_SOURCE_DIR}/src/main3.cpp)
	set(SRC_FILES1 ${PROJECT_SOURCE_DIR}/src/automata.cpp)
	
	set(CMAKE_CXX_STANDARD 11)
	
	#add_library(task1_lib ${SRC_FILES1})
	#add_library(task2_lib ${SRC_FILES2})
	#add_library(task3_lib ${SRC_FILES3})
	add_library(task1_lib ${SRC_FILES1} include/automata.h)
	add_executable(task1 ${PROJECT_SOURCE_DIR}/src/main.cpp )
	
	add_executable(task1 ${SRC_FILES1})
	add_executable(task2 ${SRC_FILES2})
	add_executable(task3 ${SRC_FILES3})
	
	#target_link_libraries(task1 task1_lib)
	#target_link_libraries(task2 task2_lib)
	#target_link_libraries(task3 task3_lib)
	target_link_libraries(task1 task1_lib)
	
	
	################################
	# Testing
 @@ -62,8 +55,7 @@ if (BUILD_TESTS)
	  target_link_libraries(runUnitTests gtest gtest_main)
	
	  # Extra linking for the project.
	  #target_link_libraries(runUnitTests task1_lib task2_lib task3_lib)
	
	  target_link_libraries(runUnitTests task1_lib)
	  # This is so you can do 'make test' to see all your tests run, instead of
	  # manually running the executable runUnitTests to see those specific tests.
	  add_test(UnitTests runUnitTests)
 @@ -78,4 +70,5 @@ if (BUILD_TESTS)
	    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
	  endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"
	
	endif() 
	
	endif()