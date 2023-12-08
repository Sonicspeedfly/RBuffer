add_executable(TestBufferCPP buffer.cpp)
target_include_directories(TestBufferCPP PUBLIC ..)
target_link_libraries(TestBufferCPP BufferCPP)
add_test(TestBufferCPP TestBufferCPP)

add_executable(TestInsertBufferCPP insert.cpp)
target_include_directories(TestInsertBufferCPP PUBLIC ..)
target_link_libraries(TestInsertBufferCPP BufferCPP)
add_test(TestInsertBufferCPP TestInsertBufferCPP)

add_executable(TestDeleteBufferCPP delete.cpp)
target_include_directories(TestDeleteBufferCPP PUBLIC ..)
target_link_libraries(TestDeleteBufferCPP BufferCPP)
add_test(TestDeleteBufferCPP TestDeleteBufferCPP)

add_executable(TestDeleteAllBufferCPP deleteAll.cpp)
target_include_directories(TestDeleteAllBufferCPP PUBLIC ..)
target_link_libraries(TestDeleteAllBufferCPP BufferCPP)
add_test(TestDeleteAllBufferCPP TestDeleteAllBufferCPP)

add_executable(TestFindBufferCPP find.cpp)
target_include_directories(TestFindBufferCPP PUBLIC ..)
target_link_libraries(TestFindBufferCPP BufferCPP)
add_test(TestFindBufferCPP TestBufferCPP)
