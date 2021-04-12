cmake_minimum_required(VERSION 3.17)
project(dataStructer C)

set(CMAKE_C_STANDARD 99)

add_executable(dataStructer main.c )
add_executable(linkListMain linkList.c)
add_executable(staticListMain staticList.c)
add_executable(doubleLinkList doubleLinkList.c)
add_executable(stackForSub stackForSub.c)
add_executable(stackForLinkList stackForLinkList.c)
add_executable(simpleQueue queue/simpleQueue.c)
add_executable(circuQueue queue/circuQueue.c)