# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Declares and names the project.

PROJECT("Blockinger-master")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

ADD_LIBRARY ( led SHARED led.c )
ADD_LIBRARY ( buzzer SHARED buzzer.c )
ADD_LIBRARY ( native-lib SHARED native-lib.cpp )
ADD_LIBRARY ( 7segment SHARED 7segment.c )
ADD_LIBRARY ( lcd SHARED lcd.c )
ADD_LIBRARY ( dotmatrix SHARED dotmatrix.c )
ADD_LIBRARY ( pushbutton SHARED pushbutton.c )
ADD_LIBRARY ( motor SHARED motor.c )
# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        lcd
        led
        buzzer
        native-lib
        7segment
        dotmatrix
        pushbutton
        motor
        # Links the target library to the log library
        # included in the NDK.
        )
