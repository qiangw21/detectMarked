set(EXE_NAME DetectMarked)

file(GLOB ${EXE_NAME}_SRCS *.cpp)
	
file(GLOB ${EXE_NAME}_MOC_SRCS *.h)
	
file(GLOB ${EXE_NAME}_UI_SRCS Resources/UI/*.ui)

set(${EXT_NAME}_RESOURCES Resources/detectMarked.qrc)

set(${EXE_NAME}_TARGET_LIBRARIES 
	Qt5::Widgets
	qDetectMarkedWidgets
	)

set(${EXE_NAME}_INCLUDE_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	)
	
list(APPEND ${EXE_NAME}_SRCS Resources/detectMarked.rc)

#generating ui file
QT5_WRAP_UI(${EXE_NAME}_UI_CXX ${${EXE_NAME}_UI_SRCS})

#generate executable
add_executable(${EXE_NAME} 
	${${EXE_NAME}_SRCS} 
	${${EXE_NAME}_MOC_SRCS}
	${${EXE_NAME}_UI_CXX} 
	${${EXT_NAME}_RESOURCES}
	)
target_link_libraries(${EXE_NAME} ${${EXE_NAME}_TARGET_LIBRARIES})
target_include_directories(${EXE_NAME} PRIVATE ${${EXE_NAME}_INCLUDE_DIRS})