add_executable(RBuffer rBuffer.cpp)
target_include_directories(RBuffer PUBLIC ../BufferCPP)
target_link_libraries(RBuffer BufferCPP)