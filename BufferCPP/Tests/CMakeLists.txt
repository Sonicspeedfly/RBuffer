add_executable(TestBufferCPP buffer.cpp)
target_include_directories(TestBufferCPP PUBLIC ..)
target_link_libraries(TestBufferCPP BufferCPP)
add_test(TestBufferCPP TestBufferCPP)
