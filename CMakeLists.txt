cmake_minimum_required(VERSION 3.23)
project(Burger_Shop)

set(APP_ICON_RESOURCE_WINDOWS "C:/Users/User/CLionProjects/Burger_Shop/icon/appicon.rc")

add_executable(${BurgerShop}
        WIN32
        BurgerShop.cpp
        ${APP_ICON_RESOURCE_WINDOWS}
        )

set(CMAKE_CXX_STANDARD 14)

add_executable(Burger_Shop C:/Users/User/CLionProjects/Burger_Shop/ ClientStruct.h BurgerStruct.h QueueOrders.h BurgerShop.cpp CSVManip.h  ${APP_ICON_RESOURCE_WINDOWS})
