project(qDetectMarkedWidgets VERSION 1.0.0 LANGUAGES CXX)

set(KIT ${PROJECT_NAME})

file(GLOB ${KIT}_SRCS *.cpp)

file(GLOB ${KIT}_MOC_SRCS *.h)

file(GLOB ${KIT}_UI_SRCS Resources/UI/*.ui)

set(${KIT}_TARGET_LIBRARIES Qt5::Widgets)
	
set(${KIT}_INCLUDE_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	)

#generating ui file
QT5_WRAP_UI(${KIT}_UI_CXX ${${KIT}_UI_SRCS})

add_library(${KIT} SHARED ${${KIT}_UI_CXX} ${${KIT}_MOC_SRCS} ${${KIT}_SRCS})
target_link_libraries(${KIT} ${${KIT}_TARGET_LIBRARIES})
target_include_directories(${KIT} PUBLIC ${${KIT}_INCLUDE_DIRS})