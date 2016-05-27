cmake_minimum_required(VERSION 3.4)
project(Server)

set(SOURCE_FILES_SERVER mq.h server.c server.h msg_linked_set.c msg_linked_set.h)
set(CMAKE_C_FLAGS "-pthread")
add_executable(Server ${SOURCE_FILES_SERVER})

project(Client)

set(SOURCE_FILES_CLIENT mq.h client.c client.h)
add_executable(Client ${SOURCE_FILES_CLIENT})


project(SetTest)

set(SOURCE_FILES_LIST_TEST msg_linked_set.c msg_linked_set.h set_test.c)
add_executable(SetTest ${SOURCE_FILES_LIST_TEST})